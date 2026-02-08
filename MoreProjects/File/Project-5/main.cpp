#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

const string DB_FILE = "../Data/students.txt";

void load(multimap<string, string> &db)
{
    ifstream in(DB_FILE);
    string student, course;

    while (in >> student >> course)
    {
        db.insert({student, course});
    }
}

void save(const multimap<string, string> &db)
{
    ofstream out(DB_FILE, ios::trunc);

    for (const auto &[student, course] : db)
    {
        out << student << " " << course << "\n";
    }
}

void add(multimap<string, string> &db)
{
    string student, course;

    cout << "Student name: ";
    cin >> student;

    cout << "Course name: ";
    cin >> course;

    db.insert({student, course});
}

void show(const multimap<string, string> &db)
{
    string student;
    cout << "Enter student name: ";
    cin >> student;

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

int main()
{
    multimap<string, string> db;
    load(db);

    int choice;
    do
    {
        cout << "\n1. Add entry\n2. Show courses\n3. Save & Exit\nChoice: ";
        cin >> choice;

        if (choice == 1)
            add(db);
        else if (choice == 2)
            show(db);

    } while (choice != 3);

    save(db);
    cout << "Data saved. Bye!\n";

    return EXIT_SUCCESS;
}
