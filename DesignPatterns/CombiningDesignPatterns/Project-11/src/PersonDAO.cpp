#include "PersonDAO.h"
#include "Database.h"
#include <iostream>

void PersonDAO::addPerson(const std::string &name, const std::string &mobile)
{
    std::string query = "INSERT INTO person (name, mobile) VALUES ('" + name + "', '" + mobile + "');";
    Database::getInstance().execute(query);
}

void PersonDAO::updatePerson(int id, const std::string &name, const std::string &mobile)
{
    std::string query = "UPDATE person SET name='" + name + "', mobile='" + mobile + "' WHERE id=" + std::to_string(id) + ";";
    Database::getInstance().execute(query);
}

void PersonDAO::deletePerson(int id)
{
    std::string query = "DELETE FROM person WHERE id=" + std::to_string(id) + ";";
    Database::getInstance().execute(query);
}

std::vector<Person> PersonDAO::listPeople()
{
    std::vector<Person> people;
    
    std::string query = "SELECT id, name, mobile FROM person;";
    sqlite3_stmt *stmt;

    if (sqlite3_prepare_v2(Database::getInstance().getConnection(), query.c_str(), -1, &stmt, nullptr) == SQLITE_OK)
    {
        while (sqlite3_step(stmt) == SQLITE_ROW)
        {
            Person p;
            
            p.id = sqlite3_column_int(stmt, 0);
            p.name = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1));
            p.mobile = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2));

            people.push_back(p);
        }
    }

    sqlite3_finalize(stmt);

    return people;
}
