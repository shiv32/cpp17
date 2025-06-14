#pragma once
#include <string>

class DBMigrator {
public:
    DBMigrator(const std::string& dbPath, const std::string& migrationsDir);
    void applyMigrations();
    void showStatus();
    void reset();

private:
    std::string dbPath;
    std::string migrationsDir;
    void ensureMigrationTable();
    bool isMigrationApplied(const std::string& name);
    void markMigrationApplied(const std::string& name);
};
