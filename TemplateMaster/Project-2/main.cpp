#include <iostream>
#include <string>
using namespace std;

// 1. Generic Pair
template <typename T1, typename T2>
class MyPair
{
    T1 first;
    T2 second;

public:
    MyPair(T1 a, T2 b) : first(a), second(b) {}

    void display()
    {
        cout << "First: " << first << ", Second: " << second << endl;
    }
};

// 2. Generic Box
template <typename T>
class Box
{
    T value;

public:
    void set(T val) { value = val; }
    T get() { return value; }
};

// 3. Generic Simple Queue
template <typename T>
class SimpleQueue
{
    T data[100];
    int front = 0, rear = 0;

public:
    void enqueue(T val) { data[rear++] = val; }
    T dequeue() { return data[front++]; }
    bool isEmpty() { return front == rear; }
};

// 4. Calculator Class Template
template <typename T>
class Calculator
{
    T a, b;

public:
    Calculator(T x, T y) : a(x), b(y) {}
    T add() { return a + b; }
    T subtract() { return a - b; }
};

// 5. Data Holder Template with size
template <typename T, int N>
class DataHolder
{
    T data[N];

public:
    void set(int index, T value) { data[index] = value; }
    T get(int index) { return data[index]; }
};

// CLI
int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    int choice;
    do
    {
        cout << "\n--- Class Template Mini Projects ---\n";
        cout << "1. Generic Pair\n";
        cout << "2. Box\n";
        cout << "3. Simple Queue\n";
        cout << "4. Calculator\n";
        cout << "5. Data Holder\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            // MyPair<int, string> p(100, "Shiv");
            MyPair p(100, "Shiv"); //C++ 17 feature ctor deduce
            p.display();
            break;
        }
        case 2:
        {
            Box<string> b;
            b.set("Templates are powerful!");
            cout << "Box content: " << b.get() << endl;
            break;
        }
        case 3:
        {
            SimpleQueue<int> q;

            q.enqueue(1);
            q.enqueue(2);
            q.enqueue(3);

            while (!q.isEmpty())
            {
                cout << "Dequeued: " << q.dequeue() << endl;
            }

            break;
        }
        case 4:
        {
            // Calculator<float> calc(10.5f, 4.2f);
            Calculator calc(10.5f, 4.2f); //C++ 17 feature ctor deduce
            cout << "Add: " << calc.add() << ", Subtract: " << calc.subtract() << endl;

            break;
        }
        case 5:
        {
            DataHolder<int, 3> dh;

            dh.set(0, 10);
            dh.set(1, 20);
            dh.set(2, 30);

            for (int i = 0; i < 3; ++i)
                cout << "Index " << i << ": " << dh.get(i) << endl;

            break;
        }
        case 0:
        {
            cout << "Goodbye!\n";
            break;
        }
        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}
