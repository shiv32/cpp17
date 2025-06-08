#include <Poco/Data/Session.h>
#include <Poco/Data/SQLite/Connector.h>
#include <Poco/Data/Statement.h>
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <functional>

using namespace Poco::Data;
using namespace Poco::Data::Keywords;
using namespace Poco::Data::SQLite;
using namespace std;

// --- Contact entity ---
struct Contact
{
    int id;
    string name;
    string phone;
};

// --- Singleton: Database session ---
class Database
{
public:
    static Database &instance()
    {
        static Database db;
        return db;
    }

    Session &session() { return *_session; }

private:
    unique_ptr<Session> _session;

    Database()
    {
        SQLite::Connector::registerConnector();

        _session = make_unique<Session>("SQLite", "contacts.db");

        *_session << "CREATE TABLE IF NOT EXISTS contacts ("
                     "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                     "name TEXT,"
                     "phone TEXT);",
            now;
    }

    ~Database()
    {
        _session->close();
    }

    Database(const Database &) = delete;
    Database &operator=(const Database &) = delete;
};

// --- DAO ---
class ContactDAO
{
public:
    ContactDAO(Session &session) : _session(session) {}

    void insert(const string &name, const string &phone)
    {
        auto mName = name;
        auto mPhone = phone;

        _session << "INSERT INTO contacts (name, phone) VALUES (?, ?)", use(mName), use(mPhone), now;

        cout << "Inserted contact.\n";
    }

    std::vector<Contact> listAll()
    {
        std::vector<Contact> contacts;
        Contact c;
        Statement select(_session);

        select << "SELECT id, name, phone FROM contacts", into(c.id), into(c.name), into(c.phone), range(0, 1);

        while (!select.done())
        {
            if (select.execute())
            {
                contacts.push_back(c);
            }
        }

        return contacts;
    }

    void update(int id, const string &name, const string &phone)
    {
        auto mId = id;
        auto mName = name;
        auto mPhone = phone;

        _session << "UPDATE contacts SET name = ?, phone = ? WHERE id = ?", use(mName), use(mPhone), use(mId), now;

        cout << "Updated contact.\n";
    }

    void remove(int id)
    {
        auto mId = id;

        _session << "DELETE FROM contacts WHERE id = ?", use(mId), now;

        cout << "Deleted contact.\n";
    }

private:
    Session &_session;
};

// --- Command pattern ---
class ICommand
{
public:
    virtual ~ICommand() = default;
    virtual void execute() = 0;
};

class ListCommand : public ICommand
{
public:
    ListCommand(ContactDAO &dao) : dao_(dao) {}

    void execute() override
    {
        auto contacts = dao_.listAll();

        cout << "\nID\tName\tPhone\n";

        for (const auto &c : contacts)
        {
            cout << c.id << "\t" << c.name << "\t" << c.phone << "\n";
        }
    }

private:
    ContactDAO &dao_;
};

class AddCommand : public ICommand
{
public:
    AddCommand(ContactDAO &dao) : dao_(dao) {}

    void execute() override
    {
        string name, phone;

        cout << "Enter name: ";
        getline(cin, name);

        cout << "Enter phone: ";
        getline(cin, phone);

        dao_.insert(name, phone);
    }

private:
    ContactDAO &dao_;
};

class UpdateCommand : public ICommand
{
public:
    UpdateCommand(ContactDAO &dao) : dao_(dao) {}

    void execute() override
    {
        int id;
        cout << "Enter contact ID to update: ";
        cin >> id;
        cin.ignore(); // To discard that leftover newline before using getline()

        string name, phone;

        cout << "Enter new name: ";
        getline(cin, name);

        cout << "Enter new phone: ";
        getline(cin, phone);

        dao_.update(id, name, phone);
    }

private:
    ContactDAO &dao_;
};

class DeleteCommand : public ICommand
{
public:
    DeleteCommand(ContactDAO &dao) : dao_(dao) {}

    void execute() override
    {
        int id;

        cout << "Enter contact ID to delete: ";
        cin >> id;
        cin.ignore(); // To discard that leftover newline before using getline()

        dao_.remove(id);
    }

private:
    ContactDAO &dao_;
};

class ExitCommand : public ICommand
{
public:
    void execute() override
    {
        cout << "Exiting...\n";
        exit(0);
    }
};

// --- Factory ---
class CommandFactory
{
public:
    CommandFactory(ContactDAO &dao) : dao_(dao)
    {
        commands_[1] = [&]()
        { return make_unique<ListCommand>(dao_); };

        commands_[2] = [&]()
        { return make_unique<AddCommand>(dao_); };

        commands_[3] = [&]()
        { return make_unique<UpdateCommand>(dao_); };

        commands_[4] = [&]()
        { return make_unique<DeleteCommand>(dao_); };

        commands_[5] = [&]()
        { return make_unique<ExitCommand>(); };
    }

    unique_ptr<ICommand> createCommand(int choice)
    {
        auto it = commands_.find(choice);

        if (it != commands_.end())
            return it->second();

        return nullptr;
    }

private:
    ContactDAO &dao_;
    map<int, function<unique_ptr<ICommand>()>> commands_;
};

// --- Main ---
int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    auto &session = Database::instance().session();

    ContactDAO dao(session);

    CommandFactory factory(dao);

    while (true)
    {
        cout << "\nMenu:\n"
             << "1. List Contacts\n"
             << "2. Add Contact\n"
             << "3. Update Contact\n"
             << "4. Delete Contact\n"
             << "5. Exit\n"
             << "Choice: ";

        int choice;
        cin >> choice;
        cin.ignore(); // To discard that leftover newline before using getline()

        auto cmd = factory.createCommand(choice);

        if (cmd)
            cmd->execute();
        else
            cout << "Invalid option.\n";
    }
}
