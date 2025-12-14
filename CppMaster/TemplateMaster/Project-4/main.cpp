#include <iostream>
#include <string>
using namespace std;

// Function Template to Search Item
template <typename T>
bool searchItem(T arr[], int size, T key)
{
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] == key)
            return true;
    }

    return false;
}

// Class Template for Inventory Item
template <typename T>
class Inventory
{
    string name;
    T id;

public:
    Inventory(string n, T i) : name(n), id(i) {}

    void show()
    {
        cout << "Item: " << name << ", ID: " << id << endl;
    }

    T getId() { return id; }
};

// 🎮 Main Program
int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    cout << "=== Generic Inventory System ===\n";

    // Integer-based IDs
    // Inventory<int> inv1("Hammer", 1001);
    // Inventory<int> inv2("Wrench", 1002);

    // C++ 17 feature
    Inventory inv1("Hammer", 1001);
    Inventory inv2("Wrench", 1002);

    inv1.show();
    inv2.show();

    int idArr[] = {1001, 1002, 1003};
    int searchId = 1002;

    cout << "Searching for ID " << searchId << ": ";
    cout << (searchItem(idArr, 3, searchId) ? "Found\n" : "Not Found\n");

    // String-based IDs
    // Inventory<string> inv3("Drill", "D-501");
    Inventory inv3("Drill", "D-501"); // C++ 17 feature
    inv3.show();

    string strArr[] = {"D-500", "D-501", "D-502"};
    string searchStr = "D-501";

    cout << "Searching for ID " << searchStr << ": ";
    cout << (searchItem(strArr, 3, searchStr) ? "Found\n" : "Not Found\n");

    return 0;
}
