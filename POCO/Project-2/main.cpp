#include <Poco/Data/Session.h>
#include <Poco/Data/SQLite/Connector.h>
#include <Poco/Data/Statement.h>
#include <Poco/Data/RecordSet.h>
#include <iostream>
#include <string>
//#include <vector>

using namespace Poco::Data;
using namespace Poco::Data::Keywords;
using namespace std;


void createTable(Session &session)
{
    session << R"(
        CREATE TABLE IF NOT EXISTS contacts (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            name TEXT NOT NULL,
            phone TEXT NOT NULL
        )
    )",
        now;
}

void insertContact(Session &session, const string &name, const string &phone)
{
    string nameCopy = name;
    string phoneCopy = phone;

    Statement insert(session);
    insert << "INSERT INTO contacts (name, phone) VALUES (?, ?)", use(nameCopy), use(phoneCopy), now;

    int lastId = 0;
    session << "SELECT last_insert_rowid()", into(lastId), now;

    cout << "Contact added with ID: " << lastId << "\n";
}

void listContacts(Session &session)
{
    std::vector<int> ids;
    std::vector<string> names;
    std::vector<string> phones;

    Statement select(session);

    select << "SELECT id, name, phone FROM contacts",
        into(ids),
        into(names),
        into(phones),
        now;

    cout << "\nID\tName\tPhone\n";
    
    for (size_t i = 0; i < ids.size(); ++i)
    {
        cout << ids[i] << "\t" << names[i] << "\t" << phones[i] << "\n";
    }
}

void updateContact(Session &session, int id, const string &name, const string &phone)
{
    string nameCopy = name;
    string phoneCopy = phone;

    session << "UPDATE contacts SET name=?, phone=? WHERE id=?",
        use(nameCopy), use(phoneCopy), use(id), now;

    cout << "Contact updated.\n";
}

void deleteContact(Session &session, int id)
{
    session << "DELETE FROM contacts WHERE id=?", use(id), now;
    cout << "Contact deleted.\n";
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    SQLite::Connector::registerConnector();

    Session session("SQLite", "contacts.db");

    createTable(session);

    while (true)
    {
        cout << "\nCRUD Menu:\n"
             << "1. List Contacts\n"
             << "2. Add Contact\n"
             << "3. Update Contact\n"
             << "4. Delete Contact\n"
             << "5. Exit\n"
             << "Choose option: ";

        int choice;
        cin >> choice;
        cin.ignore(); // discard newline

        if (choice == 1)
        {
            listContacts(session);
        }
        else if (choice == 2)
        {
            string name, phone;
            cout << "Enter name: ";
            getline(cin, name);
            cout << "Enter phone: ";
            getline(cin, phone);
            insertContact(session, name, phone);
        }
        else if (choice == 3)
        {
            int id;
            cout << "Enter contact ID to update: ";
            cin >> id;
            cin.ignore();
            string name, phone;
            cout << "Enter new name: ";
            getline(cin, name);
            cout << "Enter new phone: ";
            getline(cin, phone);
            updateContact(session, id, name, phone);
        }
        else if (choice == 4)
        {
            int id;
            cout << "Enter contact ID to delete: ";
            cin >> id;
            cin.ignore();
            deleteContact(session, id);
        }
        else if (choice == 5)
        {
            break;
        }
        else
        {
            cout << "Invalid option\n";
        }
    }

    SQLite::Connector::unregisterConnector();

    return 0;
}
