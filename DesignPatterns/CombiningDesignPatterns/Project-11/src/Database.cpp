#include "Database.h"
#include <iostream>

Database::Database()
{
    int rc = sqlite3_open("people.db", &db);

    if (rc)
    {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        db = nullptr;
    }
    else
    {
        execute("CREATE TABLE IF NOT EXISTS person (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, mobile TEXT);");
    }
}

Database::~Database()
{
    if (db)
    {
        sqlite3_close(db);
    }
}

Database &Database::getInstance()
{
    static Database instance;
    return instance;
}

sqlite3 *Database::getConnection()
{
    return db;
}

void Database::execute(const std::string &query)
{
    char *errMsg = nullptr;

    int rc = sqlite3_exec(db, query.c_str(), nullptr, nullptr, &errMsg);

    if (rc != SQLITE_OK)
    {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
}
