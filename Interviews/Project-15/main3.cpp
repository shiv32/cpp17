// Vector + Algorithm Interview Pack (C++17)

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <numeric>

// Utility to print vector
void print(const std::vector<int> &v, const std::string &msg)
{
    std::cout << msg << ": ";
    for (int x : v)
        std::cout << x << " ";
    std::cout << "\n";
}

/* 1️⃣ Remove duplicates (preserve order) */
std::vector<int> removeDuplicates(const std::vector<int> &v)
{
    std::vector<int> result;

    for (int x : v)
    {
        if (std::find(result.begin(), result.end(), x) == result.end())
        {
            result.push_back(x);
        }
    }

    return result;
}

/* 2️⃣ Move zeros to end */
void moveZeros(std::vector<int> &v)
{
    std::stable_partition(v.begin(), v.end(),
                          [](int x)
                          { return x != 0; });
}

/* 3️⃣ Second largest element */
int secondLargest(const std::vector<int> &v)
{
    std::vector<int> tmp = v;
    std::sort(tmp.begin(), tmp.end());

    // print(tmp,"sorted");

    // std::cout<<"size : "<<tmp.size()<<std::endl;

    return tmp[tmp.size() - 2];
}

/* 4️⃣ Check sorted */
bool isSorted(const std::vector<int> &v)
{
    return std::is_sorted(v.begin(), v.end());
}

/* 5️⃣ Extract even numbers */
std::vector<int> getEvens(const std::vector<int> &v)
{
    std::vector<int> evens;
    std::copy_if(v.begin(), v.end(),
                 std::back_inserter(evens),
                 [](int x)
                 { return x % 2 == 0; });
    return evens;
}

/* 6️⃣ Rotate right by k */
void rotateRight(std::vector<int> &v, int k)
{
    k %= v.size();
    std::rotate(v.begin(), v.end() - k, v.end());
}

/* 7️⃣ Majority element (> n/2) */
int majorityElement(std::vector<int> v)
{
    std::nth_element(v.begin(),
                     v.begin() + v.size() / 2,
                     v.end());
    return v[v.size() / 2];
}

/* 8️⃣ Remove odd numbers */
void removeOdds(std::vector<int> &v)
{
    v.erase(std::remove_if(v.begin(), v.end(),
                           [](int x)
                           { return x % 2 != 0; }),
            v.end());
}

/* 9️⃣ Pair with given sum */
bool hasPairWithSum(std::vector<int> v, int target)
{
    std::sort(v.begin(), v.end());
    int l = 0, r = v.size() - 1;

    while (l < r)
    {
        int sum = v[l] + v[r];
        if (sum == target)
            return true;
        sum < target ? ++l : --r;
    }
    return false;
}

/* 🔟 Intersection of two vectors */
std::vector<int> intersection(std::vector<int> a, std::vector<int> b)
{
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    std::vector<int> result;
    std::set_intersection(a.begin(), a.end(),
                          b.begin(), b.end(),
                          std::back_inserter(result));
    return result;
}

void back_insert_demo()
{
    std::vector<int> src{1, 2, 3, 4, 5};
    std::vector<int> dest;

    std::copy(src.begin(), src.end(), std::back_inserter(dest));

    print(dest, "back_insert_demo");
}

int main()
{
    std::vector<int> v{1, 0, 2, 3, 0, 2, 4, 5, 3};

    print(v, "Original");

    auto noDup = removeDuplicates(v);
    print(noDup, "After removing duplicates");

    moveZeros(v);
    print(v, "After moving zeros");

    std::cout << "Second largest: "
              << secondLargest(v) << "\n";

    std::cout << "Is sorted? "
              << std::boolalpha << isSorted(v) << "\n";

    auto evens = getEvens(v);
    print(evens, "Even numbers");

    rotateRight(v, 2);
    print(v, "After rotating right by 2");

    std::vector<int> majorityTest{2, 2, 1, 2, 2, 3, 2};
    std::cout << "Majority element: "
              << majorityElement(majorityTest) << "\n";

    removeOdds(v);
    print(v, "After removing odds");

    std::cout << "Has pair with sum 6? "
              << hasPairWithSum(v, 6) << "\n";

    std::vector<int> a{1, 2, 3, 4};
    std::vector<int> b{3, 4, 5, 6};

    auto inter = intersection(a, b);
    print(inter, "Intersection");

    back_insert_demo();

    return 0;
}
