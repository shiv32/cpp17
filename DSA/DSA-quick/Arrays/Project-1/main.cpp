#include <iostream>

using std::cout;

int main()
{
    int arr[5] = {1, 2, 3, 4, 5}; // Declaration and initialization

    // Accessing and modifying elements
    arr[2] = 10;

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}