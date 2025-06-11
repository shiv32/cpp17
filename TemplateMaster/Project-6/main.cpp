#include <iostream>
#include <vector>
#include <stdexcept>

template <typename T>
class Stack
{
private:
    std::vector<T> data;
 
public:
    void push(const T &item)
    {
        data.push_back(item);
    }

    void pop()
    {
        if (data.empty())
            throw std::underflow_error("Stack is empty!");
        data.pop_back();
    }

    T top() const
    {
        if (data.empty())
            throw std::underflow_error("Stack is empty!");
        return data.back();
    }

    bool empty() const
    {
        return data.empty();
    }

    void display() const
    {
        std::cout << "Stack: ";
        for (auto it = data.rbegin(); it != data.rend(); ++it)
        {
            std::cout << *it << " ";
        }
        std::cout << '\n';
    }
};

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    std::cout << "=== Integer Stack ===\n";
    Stack<int> intStack;
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);

    intStack.display();
    intStack.pop();
    intStack.display();

    std::cout << "Top element: " << intStack.top() << "\n";

    std::cout << "\n=== String Stack ===\n";
    Stack<std::string> strStack;
    strStack.push("Hello");
    strStack.push("World");
    
    strStack.display();
    strStack.pop();
    strStack.display();

    return 0;
}
