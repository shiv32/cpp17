#include <iostream>
#include <unordered_map>
#include <fstream>
#include <string>
#include <memory>

// =========================
// Singleton: FileManager
// =========================
class FileManager
{
private:
    std::string filename = "../data/users.txt";

    FileManager() {} // private constructor

public:
    static FileManager &getInstance()
    {
        static FileManager instance;
        return instance;
    }

    std::unordered_map<std::string, std::string> load()
    {
        std::unordered_map<std::string, std::string> data;
        std::ifstream file(filename);

        std::string user, pass;
        while (file >> user >> pass)
        {
            data[user] = pass;
        }

        return data;
    }

    void save(const std::unordered_map<std::string, std::string> &data)
    {
        std::ofstream file(filename, std::ios::trunc);

        for (const auto &pair : data)
        {
            file << pair.first << " " << pair.second << "\n";
        }
    }
};

// =========================
// Repository Pattern
// =========================
class UserRepository
{
private:
    std::unordered_map<std::string, std::string> users;

public:
    UserRepository()
    {
        users = FileManager::getInstance().load();
    }

    bool exists(const std::string &username)
    {
        return users.find(username) != users.end();
    }

    void addUser(const std::string &username, const std::string &password)
    {
        users[username] = password;
        FileManager::getInstance().save(users);
    }

    std::string getPassword(const std::string &username)
    {
        return users[username];
    }

    const std::unordered_map<std::string, std::string> &getAll() const
    {
        return users;
    }
};

// =========================
// Strategy Pattern
// =========================
class IAuthStrategy
{
public:
    virtual bool authenticate(const std::string &storedPass, const std::string &inputPass) = 0;
    virtual ~IAuthStrategy() = default;
};

class PlainTextAuth : public IAuthStrategy
{
public:
    bool authenticate(const std::string &storedPass, const std::string &inputPass) override
    {
        return storedPass == inputPass;
    }
};

// =========================
// Service Layer
// =========================
class AuthService
{
private:
    UserRepository repo;
    std::unique_ptr<IAuthStrategy> strategy;

public:
    AuthService(std::unique_ptr<IAuthStrategy> strat): strategy(std::move(strat)) 
    {

    }

    void registerUser()
    {
        std::string user, pass;
        std::cout << "Username: ";
        std::cin >> user;

        if (repo.exists(user))
        {
            std::cout << "User already exists!\n";
            return;
        }

        std::cout << "Password: ";
        std::cin >> pass;

        repo.addUser(user, pass);
        std::cout << "Registered successfully.\n";
    }

    void login()
    {
        std::string user, pass;
        std::cout << "Username: ";
        std::cin >> user;

        if (!repo.exists(user))
        {
            std::cout << "User not found!\n";
            return;
        }

        std::cout << "Password: ";
        std::cin >> pass;

        if (strategy->authenticate(repo.getPassword(user), pass))
        {
            std::cout << "Login successful!\n";
        }
        else
        {
            std::cout << "Invalid password!\n";
        }
    }

    void showUsers()
    {
        for (const auto &pair : repo.getAll())
        {
            std::cout << pair.first << "\n";
        }
    }
};

// =========================
// Main
// =========================
int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    AuthService service(std::make_unique<PlainTextAuth>());

    int choice;

    while (true)
    {
        std::cout << "\n1.Register\n2.Login\n3.Show Users\n4.Exit\nChoice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            service.registerUser();
            break;
        case 2:
            service.login();
            break;
        case 3:
            service.showUsers();
            break;
        case 4:
            return EXIT_SUCCESS;
        default:
            std::cout << "Invalid option\n";
        }
    }
}
