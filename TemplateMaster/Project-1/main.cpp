#include <iostream>
#include <string>
using namespace std;

// 1. Template Calculator
template <typename T>
T add(T a, T b) { return a + b; }

template <typename T>
T subtract(T a, T b) { return a - b; }

// 2. Template Swap
template <typename T>
void mySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

// 3. Template Array Printer
template <typename T>
void printArray(T arr[], int size)
{
    cout << "Array: ";

    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";

    cout << endl;
}

// 4. Template Max Finder
template <typename T>
T myMax(T a, T b)
{
    return (a > b) ? a : b;
}

// 5. Template Stack
template <typename T>
class Stack
{
    T arr[100];
    int top = -1;

public:
    void push(T val) { arr[++top] = val; }
    T pop() { return arr[top--]; }
    bool isEmpty() { return top == -1; }
};

// Main CLI menu
int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux
    
    int choice;
    do
    {
        cout << "\nTemplate Mini Projects:\n";
        cout << "1. Calculator\n";
        cout << "2. Swap\n";
        cout << "3. Array Printer\n";
        cout << "4. Max Finder\n";
        cout << "5. Stack\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Add(3 + 4.5): " << add(3.0, 4.5) << endl;
            cout << "Subtract(10 - 4): " << subtract(10, 4) << endl;
            break;
        }
        case 2:
        {
            int a = 5, b = 10;
            cout << "Before Swap: a=" << a << ", b=" << b << endl;
            mySwap(a, b);
            cout << "After Swap: a=" << a << ", b=" << b << endl;
            break;
        }
        case 3:
        {
            int arr[] = {1, 2, 3, 4, 5};
            printArray(arr, 5);
            break;
        }
        case 4:
        {
            cout << "Max(2, 7): " << myMax(2, 7) << endl;
            cout << "Max(3.2, 1.9): " << myMax(3.2, 1.9) << endl;
            break;
        }
        case 5:
        {
            Stack<string> s;

            s.push("Hello");
            s.push("World");

            while (!s.isEmpty())
                cout << "Pop: " << s.pop() << endl;
                
            break;
        }
        case 0:
            cout << "Goodbye!\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}
