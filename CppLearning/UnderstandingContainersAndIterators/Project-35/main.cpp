/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief map Example: Bank Account
 * @version 0.1
 * @date 2025-07-03
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <iostream>
#include <map>

class BankAccount final
{
public:
    BankAccount(int acctNum, std::string_view name) : mAcctNum(acctNum), mClientName(name) {}

    void setAcctNum(int acctNum) { mAcctNum = acctNum; }
    int getAcctNum() const { return mAcctNum; }

    void setClientName(std::string_view name) { mClientName = name; }
    std::string_view getClientName() const { return mClientName; }

private:
    int mAcctNum;
    std::string mClientName;
};

class BankDB final
{
public:
    // Adds account to the bank database. If an account exists already
    // with that number, the new account is not added. Returns true
    // if the account is added, false if it's not.
    bool addAccount(const BankAccount &account);

    // Removes the account acctNum from the database.
    void deleteAccount(int acctNum);

    // Returns a reference to the account represented
    // by its number or the client name.
    // Throws out_of_range if the account is not found.
    BankAccount &findAccount(int acctNum);
    BankAccount &findAccount(std::string_view name);

    // Adds all the accounts from db to this database.
    // Deletes all the accounts from db.
    void mergeDatabase(BankDB &db);

private:
    std::map<int, BankAccount> mAccounts;
};

bool BankDB::addAccount(const BankAccount &acct)
{
    // Do the actual insert, using the account number as the key
    auto res = mAccounts.emplace(acct.getAcctNum(), acct);
    // or: auto res = mAccounts.insert(make_pair(acct.getAcctNum(), acct));

    // Return the bool field of the pair specifying success or failure
    return res.second;
}

void BankDB::deleteAccount(int acctNum)
{
    mAccounts.erase(acctNum);
}

BankAccount &BankDB::findAccount(int acctNum)
{
    // Finding an element via its key can be done with find()
    auto it = mAccounts.find(acctNum);
    if (it == end(mAccounts))
    {
        throw std::out_of_range("No account with that number.");
    }
    // Remember that iterators into maps refer to pairs of key/value
    return it->second;
}

BankAccount &BankDB::findAccount(std::string_view name)
{
    // Finding an element by a non-key attribute requires a linear
    // search through the elements. Uses C++17 structured bindings.
    for (auto &[acctNum, account] : mAccounts)
    {
        if (account.getClientName() == name)
        {
            return account; // found it!
        }
    }
    // If your compiler doesn't support the above C++17 structured
    // bindings yet, you can use the following implementation
    // for (auto& p : mAccounts) {
    // if (p.second.getClientName() == name)
    // {
    //     return p.second;
    // }
    //}

    throw std::out_of_range("No account with that name.");
}

void BankDB::mergeDatabase(BankDB &db)
{
    // Use C++17 merge().
    mAccounts.merge(db.mAccounts);
    // Or: mAccounts.insert(begin(db.mAccounts), end(db.mAccounts));

    // Now clear the source database.
    db.mAccounts.clear();
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    BankDB db;
    db.addAccount(BankAccount(100, "Nicholas Solter"));
    db.addAccount(BankAccount(200, "Scott Kleper"));

    try
    {
        auto &acct = db.findAccount(100);
        std::cout << "Found account 100" << std::endl;
        acct.setClientName("Nicholas A Solter");

        auto &acct2 = db.findAccount("Scott Kleper");
        std::cout << "Found account of Scott Kleper" << std::endl;

        auto &acct3 = db.findAccount(1000);
    }
    catch (const std::out_of_range &caughtException)
    {
        std::cout << "Unable to find account: " << caughtException.what() << std::endl;
    }

    return 0;
}
