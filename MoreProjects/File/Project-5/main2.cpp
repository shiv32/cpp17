#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

const string DB_FILE = "../Data/students.txt";

/* ===============================
   Singleton: Database
   =============================== */
class Database
{
private:
    multimap<string, string> data;
    Database() {} // private constructor

public:
    Database(const Database &) = delete;
    Database &operator=(const Database &) = delete;

    static Database &instance()
    {
        static Database db;
        return db;
    }

    multimap<string, string> &getData()
    {
        return data;
    }
};

/* ===============================
   Repository Pattern
   =============================== */
class StudentRepository
{
public:
    void load()
    {
        ifstream in(DB_FILE);
        string student, course;
        auto &db = Database::instance().getData();

        while (in >> student >> course)
        {
            db.insert({student, course});
        }
    }

    void save()
    {
        ofstream out(DB_FILE, ios::trunc);
        auto &db = Database::instance().getData();

        for (const auto &[student, course] : db)
        {
            out << student << " " << course << "\n";
        }
    }

    void add(const string &student, const string &course)
    {
        Database::instance().getData().insert({student, course});
    }

    void show(const string &student)
    {
        auto &db = Database::instance().getData();
        auto range = db.equal_range(student);

        if (range.first == range.second)
        {
            cout << "No courses found\n";
            return;
        }

        cout << "Courses:\n";
        for (auto it = range.first; it != range.second; ++it)
        {
            cout << "- " << it->second << "\n";
        }
    }
};

/* ===============================
   Application (UI / Controller)
   =============================== */
int main()
{
    StudentRepository repo;
    repo.load();

    int choice;
    do
    {
        cout << "\n1. Add entry\n2. Show courses\n3. Save & Exit\nChoice: ";
        cin >> choice;

        if (choice == 1)
        {
            string student, course;
            cout << "Student: ";
            cin >> student;
            cout << "Course: ";
            cin >> course;
            repo.add(student, course);
        }
        else if (choice == 2)
        {
            string student;
            cout << "Student name: ";
            cin >> student;
            repo.show(student);
        }

    } while (choice != 3);

    repo.save();
    cout << "Data saved. Bye!\n";

    return EXIT_SUCCESS;
}
