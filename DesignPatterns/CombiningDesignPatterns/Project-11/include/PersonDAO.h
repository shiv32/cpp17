#pragma once
#include "Person.h"
#include <vector>
#include <string>

class PersonDAO {
public:
    void addPerson(const std::string& name, const std::string& mobile);
    void updatePerson(int id, const std::string& name, const std::string& mobile);
    void deletePerson(int id);
    std::vector<Person> listPeople();
};
