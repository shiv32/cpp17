#include <iostream>
#include <vector>

using std::cout;
using std::vector;

int main()
{
    vector<int> vec = {1, 2, 3, 4, 5};

    // Add elements dynamically
    vec.push_back(6);
    vec.push_back(7);

    // Access and modify elements
    vec[2] = 10;

    // Print elements
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }

    return 0;
}