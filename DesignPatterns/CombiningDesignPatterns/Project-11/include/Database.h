#pragma once

#include <sqlite3.h>
#include <string>

class Database
{
private:
    sqlite3 *db;
    Database();

    Database(const Database &) = delete;
    Database &operator=(const Database &) = delete;

public:
    static Database &getInstance();
    sqlite3 *getConnection();
    void execute(const std::string &query);
    ~Database();
};
