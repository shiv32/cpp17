/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief
 *
 * @version 0.1
 * @date 2024-09-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <algorithm>
#include <functional>
#include <map>
#include <set>

using VotersMap = std::map<std::string, std::vector<std::string>>;
using DistrictPair = std::pair<const std::string, std::vector<std::string>>;

namespace avr1
{
    // Returns a set of all names that appear in more than one vector in the map.
    std::set<std::string> getDuplicates(const VotersMap &votersByDistrict)
    {
        // Collect all the names from all the vectors into one big vector.
        std::vector<std::string> allNames;
        for (auto &district : votersByDistrict)
        {
            allNames.insert(end(allNames), begin(district.second), end(district.second));
        }

        // Sort the vector.
        sort(begin(allNames), end(allNames));

        // Now it's sorted, all duplicate names will be next to each other.
        // Use adjacent_find() to find instances of two or more identical names
        // next to each other.
        // Loop until adjacent_find() returns the end iterator.
        std::set<std::string> duplicates;
        for (auto lit = cbegin(allNames); lit != cend(allNames); ++lit)
        {
            lit = adjacent_find(lit, cend(allNames));
            if (lit == cend(allNames))
            {
                break;
            }
            duplicates.insert(*lit);
        }
        return duplicates;
    }

    /*
        Expects a map of string/vector<string> pairs keyed on district names
        and containing vectors of all the registered voters in those districts.
        Removes from each vector any name on the convictedFelons vector and
        any name that is found on any other vector.
    */
    void auditVoterRolls(VotersMap &votersByDistrict, const std::vector<std::string> &convictedFelons)
    {
        // Get all the duplicate names.
        std::set<std::string> toRemove = getDuplicates(votersByDistrict);

        // Combine the duplicates and convicted felons -- we want
        // to remove names on both vectors from all voter rolls.
        toRemove.insert(cbegin(convictedFelons), cend(convictedFelons));

        // Now remove all the names we need to remove using
        // nested lambda expressions and the remove-erase-idiom.
        for_each(begin(votersByDistrict), end(votersByDistrict),

                 [&toRemove](DistrictPair &district)
                 {
                     auto it = remove_if(begin(district.second), end(district.second),
                                         [&toRemove](const std::string &name)
                                         {
                                             return (toRemove.count(name) > 0);
                                         });
                     district.second.erase(it, end(district.second));
                 });
    }

}

namespace avr2
{
    // Returns a set of all names that appear in more than one vector in the map.
    // uses C++17 structured bindings
    std::set<std::string> getDuplicates(const VotersMap &votersByDistrict)
    {
        std::set<std::string> allNames;
        std::set<std::string> duplicates;

        for (auto &[district, voters] : votersByDistrict)
        {
            for (auto &name : voters)
            {
                if (!allNames.insert(name).second)
                {
                    duplicates.insert(name);
                }
            }
        }

        return duplicates;
    }

    /*
        Expects a map of string/vector<string> pairs keyed on district names
        and containing vectors of all the registered voters in those districts.
        Removes from each vector any name on the convictedFelons vector and
        any name that is found on any other vector.
    */
    void auditVoterRolls(VotersMap &votersByDistrict, const std::vector<std::string> &convictedFelons)
    {
        // Get all the duplicate names.
        std::set<std::string> toRemove = getDuplicates(votersByDistrict);

        // Combine the duplicates and convicted felons -- we want
        // to remove names on both vectors from all voter rolls.
        toRemove.insert(cbegin(convictedFelons), cend(convictedFelons));

        // Now remove all the names we need to remove using
        // nested lambda expressions and the remove-erase-idiom.
        // C++17 structured bindings
        for (auto &[district, voters] : votersByDistrict)
        {
            auto it = remove_if(begin(voters), end(voters),
                                [&toRemove](const std::string &name)
                                {
                                    return (toRemove.count(name) > 0);
                                });
            voters.erase(it, end(voters));
        }
    }
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // Initialize map using uniform initialization
    VotersMap voters = {
        {"Orange", {"Amy Aardvark", "Bob Buffalo", "Charles Cat", "Dwayne Dog", "shiv"}},
        {"Los Angeles", {"Elizabeth Elephant", "Fred Flamingo", "Amy Aardvark"}},
        {"San Diego", {"George Goose", "Heidi Hen", "Fred Flamingo"}}};

    std::vector<std::string> felons = {"Bob Buffalo", "Charles Cat"};

    // Local lambda expression to print a district
    auto printDistrict = [](const DistrictPair &district)
    {
        std::cout << district.first << ":";
        for (auto &str : district.second)
        {
            std::cout << " {" << str << "}";
        }

        std::cout << std::endl;
    };

    std::cout << "Before Audit:" << std::endl;
    for (const auto &district : voters)
    {
        printDistrict(district);
    }
    std::cout << std::endl;

    avr1::auditVoterRolls(voters, felons);
    // avr2::auditVoterRolls(voters, felons);

    std::cout << "After Audit:" << std::endl;
    for (const auto &district : voters)
    {
        printDistrict(district);
    }
    std::cout << std::endl;

    return 0;
}