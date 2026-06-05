#include <iostream>
#include "DArray.hpp"
#include "AArray.hpp"

using namespace std;

void printArray(const Array<int> &arr)
{
    // cout<<arr.getSize()<<"\n";

    for (size_t i = 0; i < arr.getSize(); i++)
    {
        cout << arr[i] << " "; // Calls the const operator[] because arr is a const object.
    }

    // cout << arr[100] << " ";

    cout << endl;
}

void test1()
{
    Array<int> myArray;

    for (size_t i = 0; i < 10; i++)
    {
        myArray.setElementAt(i, 100);
    }

    for (size_t i = 0; i < 10; i++)
    {
        cout << myArray.getElementAt(i) << " ";
    }

    cout << "\n";
}

void test2()
{
    Array<int> myArray;

    for (size_t i = 0; i < 10; i++)
    {
        myArray[i] = 100;
    }

    for (size_t i = 0; i < 10; i++)
    {
        cout << myArray[i] << " ";
    }

    cout << "\n";
}

void test3()
{
    Array<int> myArray;
    
    for (size_t i = 0; i < 10; i++)
    {
        myArray[i] = 100; // Calls the non-const operator[] because myArray is a non-const object.
    }

    printArray(myArray);
}

void test4()
{
    AssociativeArray<int> myArray;
    
    myArray["Key 1"] = 11;
    myArray["Key 2"] = 22;
    myArray["Key 3"] = 33;

    try
    {
        cout << myArray["Key 1"] << endl;
        cout << myArray["Key 2"] << endl;

        // Test const operator[]
        const AssociativeArray<int> &c = myArray;

        cout << c["Key 3"] << endl;
        cout << c["Key 4"] << endl;
    }
    catch (const invalid_argument &ex)
    {
        cout << "Caught exception: " << ex.what() << endl;
    }
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // test1();
    // test2();
    // test3();
    test4();

    return 0;
}