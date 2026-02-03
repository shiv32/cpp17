#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

// ---------------- Log Level ----------------
enum class LogLevel 
{ 
    INFO, 
    WARN, 
    ERROR, 
    UNKNOWN 
};

string toString(LogLevel level) 
{
    switch (level) 
    {
        case LogLevel::INFO: return "INFO";
        case LogLevel::WARN: return "WARN";
        case LogLevel::ERROR: return "ERROR";
        default: return "UNKNOWN";
    }
}

LogLevel parseLevel(const string& s) 
{
    if (s == "INFO") return LogLevel::INFO;
    if (s == "WARN") return LogLevel::WARN;
    if (s == "ERROR") return LogLevel::ERROR;
    return LogLevel::UNKNOWN;
}

// ---------------- Data Model ----------------
struct LogEntry 
{
    string date;
    string time;
    LogLevel level;
    string message;
};

// ---------------- Parser ----------------
class LogParser 
{
public:
    static vector<LogEntry> parseFile(const string& filename) 
    {
        ifstream file(filename);
        vector<LogEntry> logs;

        if (!file) 
        {
            cerr << "Failed to open log file: " << filename << endl;
            return logs;
        }

        string line;
        while (getline(file, line)) 
        {
            if (line.empty()) continue;
            logs.push_back(parseLine(line));
        }
        
        return logs;
    }

private:
    static LogEntry parseLine(const string& line) 
    {
        stringstream ss(line);
        LogEntry entry;
        string levelStr;

        ss >> entry.date;
        ss >> entry.time;
        ss >> levelStr;

        getline(ss, entry.message);

        entry.level = parseLevel(levelStr);

        // trim leading space
        if (!entry.message.empty() && entry.message[0] == ' ')
            entry.message.erase(0, 1);

        return entry;
    }
};

// ---------------- Analyzer ----------------
class LogAnalyzer 
{
public:
    explicit LogAnalyzer(const vector<LogEntry>& logs) : logs(logs) 
    {

    }

    void analyze() 
    {
        for (const auto& log : logs) 
        {
            levelCount[log.level]++;

            if (log.level == LogLevel::ERROR) 
            {
                errorFrequency[log.message]++;
            }
        }
    }

    void generateReport(const string& outputFile) const 
    {
        ofstream report(outputFile, ios::trunc);//truncate mode, rewrite the entire file

        if (!report) 
        {
            cerr << "Failed to write report file" << endl;
            return;
        }

        report << "Log Summary Report\n";
        report << "==================\n\n";

        report << "Total Entries : " << logs.size() << "\n\n";

        report << "By Level:\n";
        report << "INFO  : " << getCount(LogLevel::INFO) << "\n";
        report << "WARN  : " << getCount(LogLevel::WARN) << "\n";
        report << "ERROR : " << getCount(LogLevel::ERROR) << "\n\n";

        report << "Error Frequency:\n";
        if (errorFrequency.empty()) 
        {
            report << "No errors found.\n";
        } 
        else 
        {
            for (const auto& [msg, count] : errorFrequency) 
            {
                report << count << "x - " << msg << "\n";
            }
        }
    }

private:
    const vector<LogEntry>& logs;

    map<LogLevel, int> levelCount;
    map<string, int> errorFrequency;

    int getCount(LogLevel level) const 
    {
        auto it = levelCount.find(level);
        return (it != levelCount.end()) ? it->second : 0;
    }
};

// ---------------- Main ----------------
int main(int argc, char* argv[]) 
{
    if (argc < 3) 
    {
        cout << "Usage: " << argv[0] << " <log_file> <report_file>\n";
        return EXIT_FAILURE;
    }

    string logFile = argv[1];
    string reportFile = argv[2];

    auto logs = LogParser::parseFile(logFile);

    if (logs.empty()) 
    {
        cerr << "No logs to analyze." << endl;
        return EXIT_FAILURE;
    }

    LogAnalyzer analyzer(logs);
    analyzer.analyze();
    analyzer.generateReport(reportFile);

    cout << "Report generated: " << reportFile << endl;

    return EXIT_SUCCESS;
}

