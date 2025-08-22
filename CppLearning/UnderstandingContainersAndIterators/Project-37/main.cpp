/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief set Example: Access Control List
 * @version 0.1
 * @date 2025-07-03
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <iostream>
#include <set>
#include <vector>

class AccessList final
{
public:
    // Default constructor
    AccessList() = default;

    // Constructor to support uniform initialization.
    AccessList(std::initializer_list<std::string_view> initlist);

    // Adds the user to the permissions list.
    void addUser(std::string_view user);

    // Removes the user from the permissions list.
    void removeUser(std::string_view user);

    // Returns true if the user is in the permissions list.
    bool isAllowed(std::string_view user) const;

    // Returns a vector of all the users who have permissions.
    std::vector<std::string> getAllUsers() const;

private:
    std::set<std::string> mAllowed;
};

AccessList::AccessList(std::initializer_list<std::string_view> initlist)
{
    mAllowed.insert(begin(initlist), end(initlist));
}

void AccessList::addUser(std::string_view user)
{
    mAllowed.emplace(user);
}

void AccessList::removeUser(std::string_view user)
{
    mAllowed.erase(std::string(user));
}

bool AccessList::isAllowed(std::string_view user) const
{
    return (mAllowed.count(std::string(user)) != 0);
}

std::vector<std::string> AccessList::getAllUsers() const
{
    return {begin(mAllowed), end(mAllowed)};

    // or
    // std::vector<std::string> users(begin(mAllowed), end(mAllowed));
    // return users;
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    AccessList fileX = {"pvw", "mgregoire", "baduser"};

    fileX.removeUser("baduser");

    if (fileX.isAllowed("mgregoire"))
    {
        std::cout << "mgregoire has permissions" << std::endl;
    }

    if (fileX.isAllowed("baduser"))
    {
        std::cout << "baduser has permissions" << std::endl;
    }
    else
    {
        std::cout << "baduser has no permissions" << std::endl;
    }

    auto users = fileX.getAllUsers();

    for (const auto &user : users)
    {
        std::cout << user << " ";
    }

    return 0;
}
