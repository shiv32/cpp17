#include <iostream>
#include <string>
#include <curl/curl.h>
#include <rapidjson/document.h>
#include <rapidjson/error/en.h>
#include <ctime>
#include <iomanip>

// Write callback for curl
size_t WriteCallback(void *contents, size_t size, size_t nmemb, std::string *output)
{
    size_t totalSize = size * nmemb;
    output->append((char *)contents, totalSize);
    return totalSize;
}

int ALPHA_VANTAGE(const std::string &symbol, const std::string &apiKey)
{

    std::string url = "https://www.alphavantage.co/query?function=TIME_SERIES_DAILY&symbol=" + symbol + "&apikey=" + apiKey;

    CURL *curl = curl_easy_init();
    std::string response;

    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        CURLcode res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        if (res != CURLE_OK)
        {
            std::cerr << "CURL Error: " << curl_easy_strerror(res) << std::endl;
            return 1;
        }
    }

    rapidjson::Document doc;
    if (doc.Parse(response.c_str()).HasParseError())
    {
        std::cerr << "JSON Parse Error: " << rapidjson::GetParseError_En(doc.GetParseError()) << std::endl;
        return 1;
    }

    if (!doc.HasMember("Time Series (Daily)"))
    {
        std::cerr << "Missing 'Time Series (Daily)' in response.\n";
        return 1;
    }

    const auto &timeSeries = doc["Time Series (Daily)"];
    std::cout << "Date       | Open     | High     | Low      | Close    | Volume\n";
    std::cout << "---------------------------------------------------------------\n";

    int count = 0;
    for (auto it = timeSeries.MemberBegin(); it != timeSeries.MemberEnd() && count < 5; ++it, ++count)
    {
        const char *date = it->name.GetString();
        const auto &data = it->value;

        std::string open = data["1. open"].GetString();
        std::string high = data["2. high"].GetString();
        std::string low = data["3. low"].GetString();
        std::string close = data["4. close"].GetString();
        std::string volume = data["5. volume"].GetString();

        std::cout << date << " | "
                  << open << " | " << high << " | " << low << " | "
                  << close << " | " << volume << "\n";
    }
}

void RapidAPI_Yahoo_Finance(const std::string &symbol, const std::string &apiKey)
{

    std::string url = "https://apidojo-yahoo-finance-v1.p.rapidapi.com/stock/v2/get-chart?interval=1d&symbol=" + symbol + "&range=5d&region=IN";

    CURL *curl = curl_easy_init();
    if (!curl)
    {
        std::cerr << "Failed to initialize CURL.\n";
        return;
    }

    std::string response;
    struct curl_slist *headers = nullptr;
    headers = curl_slist_append(headers, "X-RapidAPI-Host: apidojo-yahoo-finance-v1.p.rapidapi.com");
    headers = curl_slist_append(headers, ("X-RapidAPI-Key: " + apiKey).c_str());

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK)
    {
        std::cerr << "Request failed: " << curl_easy_strerror(res) << "\n";
        curl_easy_cleanup(curl);
    }
    curl_easy_cleanup(curl);
    curl_slist_free_all(headers);

    rapidjson::Document doc;
    if (doc.Parse(response.c_str()).HasParseError())
    {
        std::cerr << "JSON parse error: " << rapidjson::GetParseError_En(doc.GetParseError()) << "\n";
        return;
    }

    try
    {
        if (!doc.HasMember("chart") || !doc["chart"].HasMember("result") ||
            !doc["chart"]["result"].IsArray() || doc["chart"]["result"].Empty())
        {
            std::cerr << "Missing or invalid chart->result data\n";
            return;
        }

        const auto &result = doc["chart"]["result"][0];

        if (!result.HasMember("timestamp") || !result.HasMember("indicators") ||
            !result["indicators"].HasMember("quote") || !result["indicators"]["quote"].IsArray() ||
            result["indicators"]["quote"].Empty())
        {
            std::cerr << "Missing or invalid indicators->quote data\n";
            return;
        }

        const auto &timestamp = result["timestamp"];
        const auto &quote = result["indicators"]["quote"][0];

        if (!quote.HasMember("open") || !quote["open"].IsArray())
        {
            std::cerr << "Missing open data\n";
            return;
        }

        const auto &open = quote["open"];
        const auto &high = quote["high"];
        const auto &low = quote["low"];
        const auto &close = quote["close"];
        const auto &volume = quote["volume"];

        std::cout << "Date\t\tOpen\tHigh\tLow\tClose\tVolume\n";

        for (rapidjson::SizeType i = 0; i < timestamp.Size(); ++i)
        {
            std::time_t ts = timestamp[i].GetInt64();
            std::tm *tm_ptr = std::gmtime(&ts);
            char dateStr[11]; // YYYY-MM-DD\0
            std::strftime(dateStr, sizeof(dateStr), "%Y-%m-%d", tm_ptr);

            std::cout << dateStr << "\t"

                      << open[i].GetDouble() << "\t"
                      << high[i].GetDouble() << "\t"
                      << low[i].GetDouble() << "\t"
                      << close[i].GetDouble() << "\t"
                      << volume[i].GetInt64() << "\n";
        }
    }
    catch (...)
    {
        std::cerr << "Error extracting data from JSON.\n";
    }
}

void Twelve_Data(const std::string &symbol, const std::string &apiKey)
{
    CURL *curl = curl_easy_init();
    std::string response;

    if (curl)
    {
        std::string url = "https://api.twelvedata.com/time_series?symbol=" + symbol +
                          "&interval=1day&outputsize=5&apikey=" + apiKey;

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "libcurl-agent/1.0");

        if (curl_easy_perform(curl) != CURLE_OK)
        {
            std::cerr << "HTTP request failed.\n";
            curl_easy_cleanup(curl);
            return;
        }

        curl_easy_cleanup(curl);
    }
    else
    {
        std::cerr << "CURL init failed.\n";
        return;
    }

    rapidjson::Document doc;
    if (doc.Parse(response.c_str()).HasParseError())
    {
        std::cerr << "JSON parse error.\n";
        return;
    }

    if (!doc.HasMember("values") || !doc["values"].IsArray())
    {
        std::cerr << "Invalid API response or limit reached.\n";
        return;
    }

    const auto &values = doc["values"].GetArray();

    std::cout << std::left << std::setw(16) << "Date"
              << std::right << std::setw(10) << "Open"
              << std::setw(10) << "High"
              << std::setw(10) << "Low"
              << std::setw(10) << "Close"
              << std::setw(12) << "Volume" << "\n";

    for (int i = values.Size() - 1; i >= 0; --i)
    {
        const auto &entry = values[i];

        std::string date = entry["datetime"].GetString();
        float open = std::stof(entry["open"].GetString());
        float high = std::stof(entry["high"].GetString());
        float low = std::stof(entry["low"].GetString());
        float close = std::stof(entry["close"].GetString());
        long long volume = std::stoll(entry["volume"].GetString());

        std::cout << std::left << std::setw(16) << date
                  << std::right << std::fixed << std::setprecision(2)
                  << std::setw(10) << open
                  << std::setw(10) << high
                  << std::setw(10) << low
                  << std::setw(10) << close
                  << std::setw(12) << volume << "\n";
    }
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    std::string symbol = "IBM";        // Change to any symbol
    std::string apiKey{"test1234567"}; // Replace with real API key

    std::cout << "Twelve Data : " << "\n";
    // apiKey = "";
    Twelve_Data(symbol, apiKey);
    std::cout << std::endl;

    std::cout << "ALPHA VANTAGE : " << "\n";
    // apiKey = "";
    ALPHA_VANTAGE(symbol, apiKey);
    std::cout << std::endl;

    std::cout << "Yahoo Finance : " << "\n";
    // apiKey = "";
    RapidAPI_Yahoo_Finance(symbol, apiKey);
    std::cout << std::endl;

    return 0;
}
