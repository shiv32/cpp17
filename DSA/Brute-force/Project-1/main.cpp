#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/*
    Brute force
    Checks all possible pairs
    Time complexity: O(n²)
    Simple but slow for large n
*/
bool hasPairBrute(const std::vector<int> &a, int target)
{
    for (size_t i = 0; i < a.size(); ++i)
    {
        for (size_t j = i + 1; j < a.size(); ++j)
        {
            if (a[i] + a[j] == target)
                return true;
        }
    }

    return false;
}

/*
    NOT Brute force
    Uses hashing
    Avoids checking all pairs
    Time complexity: O(n) average
    Space complexity: O(n)
*/
bool hasPairFast(const std::vector<int> &a, int target)
{
    unordered_set<int> seen;

    for (int x : a)
    {
        if (seen.count(target - x)) 
            return true;

        seen.insert(x);
    }

    return false;
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    vector<int> a{2, 7, 11, 15};
    //vector<int> a{20, 7, 11, 15};

    cout << hasPairBrute(a, 9) << endl;
    cout << hasPairFast(a, 9) << endl;

    return 0;
}