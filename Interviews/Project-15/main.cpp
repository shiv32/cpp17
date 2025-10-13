#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
#include <string>

int main()
{
    // --- 1️⃣ VECTOR ---
    std::vector<int> nums = {5, 2, 9, 1, 5, 6};

    // Sort ascending
    std::sort(nums.begin(), nums.end());

    // Remove duplicates
    nums.erase(std::unique(nums.begin(), nums.end()), nums.end());

    // Transform (square each)
    std::transform(nums.begin(), nums.end(), nums.begin(),
                   [](int x)
                   { return x * x; });

    // Print
    std::cout << "Vector elements: ";
    for (int n : nums)
        std::cout << n << " ";
    std::cout << "\n";

    // --- 2️⃣ SET ---
    std::set<int> s(nums.begin(), nums.end());
    s.insert(100);

    std::cout << "Set contains: ";
    for (auto v : s)
        std::cout << v << " ";
    std::cout << "\n";

    // --- 3️⃣ MAP ---
    std::map<std::string, int> scores = {
        {"Alice", 90}, {"Bob", 75}, {"Charlie", 85}};

    // Find and update
    auto it = scores.find("Bob");
    if (it != scores.end())
        it->second += 10;

    // Use for_each to print
    std::for_each(scores.begin(), scores.end(),
                  [](const auto &p)
                  {
                      std::cout << p.first << ": " << p.second << "\n";
                  });

    // --- 4️⃣ ACCUMULATE ---
    int total = std::accumulate(nums.begin(), nums.end(), 0);
    std::cout << "Sum of vector elements = " << total << "\n";

    // --- 5️⃣ FIND_IF ---
    auto found = std::find_if(nums.begin(), nums.end(),
                              [](int x)
                              { return x > 25; });
    if (found != nums.end())
        std::cout << "First element > 25 is " << *found << "\n";

    // --- 6️⃣ REMOVE_IF ---
    nums.erase(std::remove_if(nums.begin(), nums.end(),
                              [](int x)
                              { return x < 10; }),
               nums.end());
               
    std::cout << "After remove_if (<10): ";
    for (int n : nums)
        std::cout << n << " ";
    std::cout << "\n";

    return 0;
}
