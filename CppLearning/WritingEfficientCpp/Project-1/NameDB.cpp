#include <fstream>
#include "NameDB.hpp"

NameDB::NameDB(std::string_view nameFile)
{
    // Open the file and check for errors.
    std::ifstream inputFile(nameFile.data());

    if (!inputFile)
    {
        throw std::invalid_argument("Unable to open file");
    }

    // Read the names one at a time.
    std::string name;

    while (inputFile >> name)
    {
        // Look up the name in the database so far.
        if (nameExists(name))
        {
            // If the name exists in the database, just increment the count.
            incrementNameCount(name);
        }
        else
        {
            // If the name doesn't yet exist, add it with a count of 1.
            addNewName(name);
        }
    }
}

int NameDB::getNameRank(std::string_view name) const
{
    // Make use of the getAbsoluteNumber() method.
    int num = getAbsoluteNumber(name);

    // Check if we found the name.
    if (num == -1)
    {
        return -1;
    }

    // Now count all the names in the vector that have a
    // count higher than this one. If no name has a higher count,
    // this name is rank number 1. Every name with a higher count
    // decreases the rank of this name by 1.
    int rank = 1;
    for (auto &entry : mNames)
    {
        if (entry.second > num)
        {
            rank++;
        }
    }
    return rank;
}

int NameDB::getAbsoluteNumber(std::string_view name) const
{
    for (auto &entry : mNames)
    {
        if (entry.first == name)
        {
            return entry.second;
        }
    }
    return -1;
}

bool NameDB::nameExists(std::string_view name) const
{
    // Iterate through the vector of names looking for the name.
    for (auto &entry : mNames)
    {
        if (entry.first == name)
        {
            return true;
        }
    }
    return false;
}

void NameDB::incrementNameCount(std::string_view name)
{
    for (auto &entry : mNames)
    {
        if (entry.first == name)
        {
            entry.second++;
            return;
        }
    }
}

void NameDB::addNewName(std::string_view name)
{
    mNames.push_back(std::make_pair(name.data(), 1));
}
