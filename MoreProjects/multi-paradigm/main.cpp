#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <future>

// ---------------- Procedural ----------------
int add(int a, int b) {
    return a + b;
}

// ---------------- OOP ----------------
class Shape {
public:
    virtual void draw() const = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
public:
    void draw() const override { std::cout << "Drawing Circle\n"; }
};

// ---------------- Generic Programming ----------------
template<typename T>
T multiply(T a, T b) {
    return a * b;
}

// ---------------- Functional (lambda) ----------------
void printSquares(const std::vector<int>& nums) {
    std::for_each(nums.begin(), nums.end(),
                  [](int n){ std::cout << n*n << " "; });
    std::cout << "\n";
}

// ---------------- Metaprogramming ----------------
constexpr int factorial(int n) {
    return n <= 1 ? 1 : n * factorial(n - 1);
}

// ---------------- Concurrency ----------------
int computeHeavyTask(int x) {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    return x * x;
}

int main() {
    // Procedural
    std::cout << "Sum (procedural): " << add(3, 4) << "\n";

    // OOP
    Shape* shape = new Circle();
    shape->draw();
    delete shape;

    // Generic Programming
    std::cout << "Multiply (generic): " << multiply(2.5, 4.0) << "\n";

    // Functional
    std::vector<int> nums{1,2,3,4};
    std::cout << "Squares (functional): ";
    printSquares(nums);

    // Metaprogramming
    static_assert(factorial(5) == 120);
    std::cout << "Factorial at compile-time: " << factorial(6) << "\n";

    // Concurrency
    std::future<int> result = std::async(std::launch::async, computeHeavyTask, 10);
    std::cout << "Heavy task result (concurrent): " << result.get() << "\n";

    return 0;
}
