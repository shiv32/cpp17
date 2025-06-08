/**
 * @file main2.cpp
 * @author your name (you@domain.com)
 * @brief C++17, sqlite project, desing patterns
 * @version 0.1
 * @date 2025-06-09
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <sqlite3.h>
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <functional>

using namespace std;

// --- Contact entity ---
struct Contact {
    int id;
    string name;
    string phone;
};

// --- Singleton for SQLite DB connection ---
class Database {
public:
    static Database& instance() {
        static Database db;
        return db;
    }

    sqlite3* getConnection() {
        return db_;
    }

private:
    sqlite3* db_;

    Database() : db_(nullptr) {
        int rc = sqlite3_open("contacts.db", &db_);
        if (rc) {
            cerr << "Can't open database: " << sqlite3_errmsg(db_) << "\n";
            exit(1);
        }
        // Create table if not exists
        const char* sql = "CREATE TABLE IF NOT EXISTS contacts ("
                          "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                          "name TEXT NOT NULL,"
                          "phone TEXT NOT NULL);";
        char* errmsg = nullptr;
        rc = sqlite3_exec(db_, sql, nullptr, nullptr, &errmsg);
        if (rc != SQLITE_OK) {
            cerr << "SQL error: " << errmsg << "\n";
            sqlite3_free(errmsg);
            exit(1);
        }
    }

    ~Database() {
        if (db_) sqlite3_close(db_);
    }

    // disable copy/move
    Database(const Database&) = delete;
    Database& operator=(const Database&) = delete;
};

// --- DAO class ---
class ContactDAO {
public:
    ContactDAO(sqlite3* db) : db_(db) {}

    void insert(const string& name, const string& phone) {
        sqlite3_stmt* stmt;
        const char* sql = "INSERT INTO contacts (name, phone) VALUES (?, ?);";

        if (sqlite3_prepare_v2(db_, sql, -1, &stmt, nullptr) != SQLITE_OK) {
            cerr << "Failed to prepare statement\n";
            return;
        }
        sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 2, phone.c_str(), -1, SQLITE_TRANSIENT);

        if (sqlite3_step(stmt) != SQLITE_DONE) {
            cerr << "Failed to insert data\n";
        } else {
            cout << "Inserted contact.\n";
        }
        sqlite3_finalize(stmt);
    }

    vector<Contact> listAll() {
        vector<Contact> contacts;
        sqlite3_stmt* stmt;
        const char* sql = "SELECT id, name, phone FROM contacts;";

        if (sqlite3_prepare_v2(db_, sql, -1, &stmt, nullptr) != SQLITE_OK) {
            cerr << "Failed to prepare statement\n";
            return contacts;
        }

        while (sqlite3_step(stmt) == SQLITE_ROW) {
            Contact c;
            c.id = sqlite3_column_int(stmt, 0);
            c.name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
            c.phone = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
            contacts.push_back(c);
        }
        sqlite3_finalize(stmt);
        return contacts;
    }

    void update(int id, const string& name, const string& phone) {
        sqlite3_stmt* stmt;
        const char* sql = "UPDATE contacts SET name = ?, phone = ? WHERE id = ?;";

        if (sqlite3_prepare_v2(db_, sql, -1, &stmt, nullptr) != SQLITE_OK) {
            cerr << "Failed to prepare statement\n";
            return;
        }
        sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 2, phone.c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_int(stmt, 3, id);

        if (sqlite3_step(stmt) != SQLITE_DONE) {
            cerr << "Failed to update contact\n";
        } else {
            cout << "Updated contact.\n";
        }
        sqlite3_finalize(stmt);
    }

    void remove(int id) {
        sqlite3_stmt* stmt;
        const char* sql = "DELETE FROM contacts WHERE id = ?;";

        if (sqlite3_prepare_v2(db_, sql, -1, &stmt, nullptr) != SQLITE_OK) {
            cerr << "Failed to prepare statement\n";
            return;
        }
        sqlite3_bind_int(stmt, 1, id);

        if (sqlite3_step(stmt) != SQLITE_DONE) {
            cerr << "Failed to delete contact\n";
        } else {
            cout << "Deleted contact.\n";
        }
        sqlite3_finalize(stmt);
    }

private:
    sqlite3* db_;
};

// --- Command pattern ---
class ICommand {
public:
    virtual ~ICommand() = default;
    virtual void execute() = 0;
};

class ListCommand : public ICommand {
public:
    ListCommand(ContactDAO& dao) : dao_(dao) {}
    void execute() override {
        auto contacts = dao_.listAll();
        cout << "\nID\tName\tPhone\n";
        for (auto& c : contacts) {
            cout << c.id << "\t" << c.name << "\t" << c.phone << "\n";
        }
    }
private:
    ContactDAO& dao_;
};

class AddCommand : public ICommand {
public:
    AddCommand(ContactDAO& dao) : dao_(dao) {}
    void execute() override {
        string name, phone;
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter phone: ";
        getline(cin, phone);
        dao_.insert(name, phone);
    }
private:
    ContactDAO& dao_;
};

class UpdateCommand : public ICommand {
public:
    UpdateCommand(ContactDAO& dao) : dao_(dao) {}
    void execute() override {
        int id;
        cout << "Enter contact ID to update: ";
        cin >> id;
        cin.ignore();
        string name, phone;
        cout << "Enter new name: ";
        getline(cin, name);
        cout << "Enter new phone: ";
        getline(cin, phone);
        dao_.update(id, name, phone);
    }
private:
    ContactDAO& dao_;
};

class DeleteCommand : public ICommand {
public:
    DeleteCommand(ContactDAO& dao) : dao_(dao) {}
    void execute() override {
        int id;
        cout << "Enter contact ID to delete: ";
        cin >> id;
        cin.ignore();
        dao_.remove(id);
    }
private:
    ContactDAO& dao_;
};

class ExitCommand : public ICommand {
public:
    void execute() override {
        cout << "Exiting...\n";
        exit(0);
    }
};

// --- Command Factory ---
class CommandFactory {
public:
    CommandFactory(ContactDAO& dao) : dao_(dao) {
        creators_[1] = [&]() { return make_unique<ListCommand>(dao_); };
        creators_[2] = [&]() { return make_unique<AddCommand>(dao_); };
        creators_[3] = [&]() { return make_unique<UpdateCommand>(dao_); };
        creators_[4] = [&]() { return make_unique<DeleteCommand>(dao_); };
        creators_[5] = [&]() { return make_unique<ExitCommand>(); };
    }

    unique_ptr<ICommand> createCommand(int choice) {
        auto it = creators_.find(choice);
        if (it != creators_.end()) {
            return it->second();
        }
        return nullptr;
    }

private:
    ContactDAO& dao_;
    map<int, function<unique_ptr<ICommand>()>> creators_;
};

// --- Main ---
int main() {
    auto& db = Database::instance();
    ContactDAO dao(db.getConnection());
    CommandFactory factory(dao);

    while (true) {
        cout << "\nMenu:\n"
             << "1. List Contacts\n"
             << "2. Add Contact\n"
             << "3. Update Contact\n"
             << "4. Delete Contact\n"
             << "5. Exit\n"
             << "Choose option: ";

        int choice;
        cin >> choice;
        cin.ignore();

        auto cmd = factory.createCommand(choice);
        if (cmd) {
            cmd->execute();
        } else {
            cout << "Invalid option. Try again.\n";
        }
    }
}
