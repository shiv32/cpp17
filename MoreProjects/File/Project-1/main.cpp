#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

const string DB_FILE = "../db/contacts.db";

struct Contact 
{
    string name;
    string phone;
    string email;
};

// ---------------- File Helpers ----------------

vector<Contact> loadContacts() 
{
    vector<Contact> contacts;
    ifstream file(DB_FILE);
    string line;

    while (getline(file, line)) 
    {
        stringstream ss(line);
        Contact c;
        getline(ss, c.name, ',');
        getline(ss, c.phone, ',');
        getline(ss, c.email, ',');

        if (!c.name.empty())
            contacts.push_back(c);
    }

    return contacts;
}

void saveContacts(const vector<Contact>& contacts) 
{
    ofstream file(DB_FILE, ios::trunc);//truncate mode, rewrite the entire file

    for (const auto& c : contacts) 
    {
        file << c.name << ","<< c.phone << ","<< c.email << "\n";
    }
}

// ---------------- Operations ----------------

void addContact() 
{
    Contact c;

    cout << "Name   : ";
    getline(cin, c.name);
    
    cout << "Phone  : ";
    getline(cin, c.phone);
    
    cout << "Email  : ";
    getline(cin, c.email);

    ofstream file(DB_FILE, ios::app);// append mode, add new records, preserve old data
    file << c.name << "," << c.phone << "," << c.email << "\n";

    cout << "✔ Contact added successfully\n";
}

void viewContacts() 
{
    auto contacts = loadContacts();

    cout << "\n---- Contact List ----\n";
    for (const auto& c : contacts) 
    {
        cout << "Name  : " << c.name << "\n";
        cout << "Phone : " << c.phone << "\n";
        cout << "Email : " << c.email << "\n";
        cout << "----------------------\n";
    }
}

void searchContact() 
{
    auto contacts = loadContacts();
    string name;

    cout << "Enter name to search: ";
    getline(cin, name);

    bool found = false;
    for (const auto& c : contacts) 
    {
        if (c.name == name) 
        {
            cout << "\nFound Contact:\n";
            cout << "Name  : " << c.name << "\n";
            cout << "Phone : " << c.phone << "\n";
            cout << "Email : " << c.email << "\n";
            found = true;
            break;
        }
    }

    if (!found)
        cout << "❌ Contact not found\n";
}

void deleteContact() 
{
    auto contacts = loadContacts();
    string name;

    cout << "Enter name to delete: ";
    getline(cin, name);

    // auto it = remove_if(contacts.begin(), contacts.end(),
    //     [&](const Contact& c) { //bad practise [&]
    //         return c.name == name;
    //     });

    auto it = remove_if(contacts.begin(), contacts.end(),
    [name](const Contact& c) {
        return c.name == name;
    });

    if (it != contacts.end()) 
    {
        contacts.erase(it, contacts.end());
        saveContacts(contacts);
        cout << "✔ Contact deleted\n";
    } else 
    {
        cout << "❌ Contact not found\n";
    }
}

// ---------------- Main Menu ----------------

int main() {
    while (true) 
    {
        cout << "\n==== Contact Management System ====\n";
        cout << "1. Add Contact\n";
        cout << "2. View Contacts\n";
        cout << "3. Search Contact\n";
        cout << "4. Delete Contact\n";
        cout << "5. Exit\n";
        cout << "Choose: ";

        int choice;
        cin >> choice;
        cin.ignore(); // clear newline

        switch (choice) 
        {
            case 1: addContact(); break;
            case 2: viewContacts(); break;
            case 3: searchContact(); break;
            case 4: deleteContact(); break;
            case 5: return EXIT_SUCCESS;
            default: cout << "Invalid choice\n";
        }
    }
}
