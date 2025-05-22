#include "CommandFactory.h"
#include "PersonDAO.h"
#include <iostream>
#include <memory>
#include <vector>
#include <regex>

class AddCommand : public Command
{
public:
    void execute() override
    {
        std::string name, mobile;
        std::regex mobile_regex("^\\d{10}$");

        std::cout << "Enter name: ";
        std::cin.ignore();
        std::getline(std::cin, name);

        // std::cout << "Enter mobile: ";
        // std::getline(std::cin, mobile);
        while (true)
        {
            std::cout << "Enter mobile: ";
            std::getline(std::cin, mobile);
            if (std::regex_match(mobile, mobile_regex))
            {
                break;
            }
            std::cout << "Invalid mobile number. Please enter exactly 10 digits.\n";
        }

        PersonDAO().addPerson(name, mobile);
    }
};

class UpdateCommand : public Command
{
public:
    void execute() override
    {
        int id;
        std::string name, mobile;
        std::cout << "Enter ID to update: ";
        std::cin >> id;
        std::cin.ignore();
        std::cout << "Enter new name: ";
        std::getline(std::cin, name);
        std::cout << "Enter new mobile: ";
        std::getline(std::cin, mobile);
        PersonDAO().updatePerson(id, name, mobile);
    }
};

class DeleteCommand : public Command
{
public:
    void execute() override
    {
        int id;
        std::cout << "Enter ID to delete: ";
        std::cin >> id;
        PersonDAO().deletePerson(id);
    }
};

class ListCommand : public Command
{
public:
    void execute() override
    {
        auto people = PersonDAO().listPeople();
        for (const auto &p : people)
        {
            std::cout << "ID: " << p.id << ", Name: " << p.name << ", Mobile: " << p.mobile << std::endl;
        }
    }
};

std::unique_ptr<Command> CommandFactory::createCommand(const std::string &cmdName)
{
    if (cmdName == "add")
        return std::make_unique<AddCommand>();
    if (cmdName == "update")
        return std::make_unique<UpdateCommand>();
    if (cmdName == "delete")
        return std::make_unique<DeleteCommand>();
    if (cmdName == "list")
        return std::make_unique<ListCommand>();
    return nullptr;
}
