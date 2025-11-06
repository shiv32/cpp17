#include <iostream>
#include <functional>

using namespace std;

// A function that accepts a callback
void runCallback(function<void(int)> callback)
{
    cout << "Running callback with value 10...\n";
    callback(10);
}

// Normal function for callback
void normalFunc(int x)
{
    cout << "Normal function called, value = " << x << endl;
}

// Class with a member function callback
class MyClass
{
public:
    void memberFunc(int x)
    {
        cout << "Member function called, value = " << x << endl;
    }
};

// Function object (functor)
struct Functor
{
    void operator()(int x) const
    {
        cout << "Function object called, value = " << x << endl;
    }
};

int main()
{
    // Function pointer callback
    runCallback(normalFunc);

    // Object + member function callback
    MyClass obj;
    runCallback(bind(&MyClass::memberFunc, &obj, placeholders::_1));

    // Lambda callback
    runCallback([](int x)
                { cout << "Lambda called, value = " << x << endl; });

    //fun object or functor            
    runCallback(Functor{});

    return 0;
}
