//Interview question

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Custom stack class using vector

push
pop
search

1 2 3 4 5
    ^

*/

class Stack
{
public:
    void display()
    {
        for (const auto d : data)
        {
            cout << d << ", ";
        }

        cout << "\n";
    }

    void push(int item)
    {
        data.emplace_back(item);
    }

    void pop(int item)
    {
        auto beg = begin(data);
        auto en = end(data);

        auto fi = find(beg, en, item);

        if (fi != en)
        {
            data.erase(fi);
        }
    }

    void search(int item)
    {
        auto beg = begin(data);
        auto en = end(data);

        auto fi = find(beg, en, item);

        if (fi != en)
        {
            std::cout << "Found " << item;
        }
        else
        {
            std::cout << "Not Found " << item;
        }

        std::cout << std::endl;
    }

private:
    vector<int> data{};
};

int main()
{
    Stack st;

    st.push(1);
    st.push(2);
    st.push(3);

    st.display();

    st.search(2);

    st.pop(2);

    st.display();

    st.search(2);

    return 0;
}