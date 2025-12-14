#include <iostream>
#include <string>
using namespace std;

// 🔧 Function Template to find maximum
template <typename T>
T getMax(T a, T b)
{
    return (a > b) ? a : b;
}

// ✅ Class Template for Student
template <typename T>
class Student
{
    string name;
    int roll;
    T marks1, marks2;

public:
    Student(string n, int r, T m1, T m2) : name(n), roll(r), marks1(m1), marks2(m2) {}

    void display()
    {
        cout << "Name: " << name << ", Roll: " << roll
             << ", Marks1: " << marks1 << ", Marks2: " << marks2 << endl;
        cout << "Highest Marks: " << getMax(marks1, marks2) << "\n";
    }
};

// 🎮 Main Program
int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    cout << "=== Student Record System ===\n";

    // Integer type student
    // Student<int> s1("Alice", 101, 78, 88);
    Student s1("Alice", 101, 78, 88); // C++ 17 feature
    s1.display();

    // Float type student
    // Student<float> s2("Bob", 102, 85.5f, 92.3f);
    Student s2("Bob", 102, 85.5f, 92.3f); // C++ 17 feature
    s2.display();

    return 0;
}
