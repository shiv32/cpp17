/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief multimap Example: Buddy Lists
 * @version 0.1
 * @date 2025-07-03
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <iostream>
#include <map>
#include <vector>

class BuddyList final
{
public:
    // Adds buddy as a friend of name.
    void addBuddy(const std::string &name, const std::string &buddy);

    // Removes buddy as a friend of name
    void removeBuddy(const std::string &name, const std::string &buddy);

    // Returns true if buddy is a friend of name, false otherwise.
    bool isBuddy(const std::string &name, const std::string &buddy) const;

    // Retrieves a list of all the friends of name.
    std::vector<std::string> getBuddies(const std::string &name) const;

private:
    std::multimap<std::string, std::string> mBuddies;
};

void BuddyList::addBuddy(const std::string &name, const std::string &buddy)
{
    // Make sure this buddy isn't already there. We don't want
    // to insert an identical copy of the key/value pair.
    if (!isBuddy(name, buddy))
    {
        mBuddies.insert({name, buddy}); // Using initializer_list
    }
}

void BuddyList::removeBuddy(const std::string &name, const std::string &buddy)
{
    // Obtain the beginning and end of the range of elements with
    // key 'name'. Use both lower_bound() and upper_bound() to demonstrate
    // their use. Otherwise, it's more efficient to call equal_range().
    auto begin = mBuddies.lower_bound(name); // Start of the range
    auto end = mBuddies.upper_bound(name);
    // End of the range

    // Iterate through the elements with key 'name' looking
    // for a value 'buddy'. If there are no elements with key 'name',
    // begin equals end, so the loop body doesn't execute.
    for (auto iter = begin; iter != end; ++iter)
    {
        if (iter->second == buddy)
        {
            // We found a match! Remove it from the map.
            mBuddies.erase(iter);
            break;
        }
    }
}

bool BuddyList::isBuddy(const std::string &name, const std::string &buddy) const
{
    // Obtain the beginning and end of the range of elements with
    // key 'name' using equal_range(), and C++17 structured bindings.
    auto [begin, end] = mBuddies.equal_range(name);

    // Iterate through the elements with key 'name' looking
    // for a value 'buddy'.
    for (auto iter = begin; iter != end; ++iter)
    {
        if (iter->second == buddy)
        {
            // We found a match!
            return true;
        }
    }

    // No matches
    return false;
}

std::vector<std::string> BuddyList::getBuddies(const std::string &name) const
{
    // Obtain the beginning and end of the range of elements with
    // key 'name' using equal_range(), and C++17 structured bindings.
    auto [begin, end] = mBuddies.equal_range(name);

    // Create a vector with all names in the range (all buddies of name).
    std::vector<std::string> buddies;

    for (auto iter = begin; iter != end; ++iter)
    {
        buddies.push_back(iter->second);
    }

    return buddies;
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    BuddyList buddies;
    
    buddies.addBuddy("Harry Potter", "Ron Weasley");
    buddies.addBuddy("Harry Potter", "Hermione Granger");
    buddies.addBuddy("Harry Potter", "Hagrid");
    buddies.addBuddy("Harry Potter", "Draco Malfoy");

    // That's not right! Remove Draco.
    buddies.removeBuddy("Harry Potter", "Draco Malfoy");

    buddies.addBuddy("Hagrid", "Harry Potter");
    buddies.addBuddy("Hagrid", "Ron Weasley");
    buddies.addBuddy("Hagrid", "Hermione Granger");

    auto harrysFriends = buddies.getBuddies("Harry Potter");

    std::cout << "Harry's friends: " << std::endl;

    for (const auto &name : harrysFriends)
    {
        std::cout << "\t" << name << std::endl;
    }

    return 0;
}
