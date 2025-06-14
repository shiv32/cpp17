#include "db_migrator.hpp"
#include <sqlite3.h>
#include <filesystem>
#include <fstream>
#include <iostream>

namespace fs = std::filesystem;

DBMigrator::DBMigrator(const std::string& dbPath, const std::string& migrationsDir)
    : dbPath(dbPath), migrationsDir(migrationsDir) {}

void DBMigrator::ensureMigrationTable() {
    sqlite3* db;
    sqlite3_open(dbPath.c_str(), &db);
    const char* sql = "CREATE TABLE IF NOT EXISTS migration_history (name TEXT PRIMARY KEY)";
    sqlite3_exec(db, sql, nullptr, nullptr, nullptr);
    sqlite3_close(db);
}

bool DBMigrator::isMigrationApplied(const std::string& name) {
    sqlite3* db;
    sqlite3_open(dbPath.c_str(), &db);
    std::string sql = "SELECT COUNT(*) FROM migration_history WHERE name = ?";
    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_TRANSIENT);
    int count = 0;
    if (sqlite3_step(stmt) == SQLITE_ROW)
        count = sqlite3_column_int(stmt, 0);
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return count > 0;
}

void DBMigrator::markMigrationApplied(const std::string& name) {
    sqlite3* db;
    sqlite3_open(dbPath.c_str(), &db);
    std::string sql = "INSERT INTO migration_history (name) VALUES (?)";
    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

void DBMigrator::applyMigrations() {
    ensureMigrationTable();
    for (auto& entry : fs::directory_iterator(migrationsDir)) {
        std::string filename = entry.path().filename().string();
        if (isMigrationApplied(filename)) continue;

        std::ifstream file(entry.path());
        std::string sql((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

        sqlite3* db;
        sqlite3_open(dbPath.c_str(), &db);
        char* err = nullptr;
        if (sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &err) == SQLITE_OK) {
            markMigrationApplied(filename);
            std::cout << "Applied: " << filename << "\n";
        } else {
            std::cerr << "Error applying " << filename << ": " << err << "\n";
        }
        sqlite3_close(db);
    }
}

void DBMigrator::showStatus() {
    ensureMigrationTable();
    sqlite3* db;
    sqlite3_open(dbPath.c_str(), &db);
    const char* sql = "SELECT name FROM migration_history ORDER BY name";
    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    std::cout << "Applied Migrations:\n";
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::cout << "- " << sqlite3_column_text(stmt, 0) << "\n";
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

void DBMigrator::reset() {
    sqlite3* db;
    sqlite3_open(dbPath.c_str(), &db);
    sqlite3_exec(db, "DROP TABLE IF EXISTS migration_history", nullptr, nullptr, nullptr);
    sqlite3_close(db);
    std::cout << "Reset migration history.\n";
}
