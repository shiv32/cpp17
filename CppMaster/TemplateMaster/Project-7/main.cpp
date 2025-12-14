#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// -------------------- Entity Structs --------------------
struct User
{
    int id;
    std::string name;
};

struct Product
{
    int id;
    std::string title;
    float price;
};

// Overloads for display
std::ostream &operator<<(std::ostream &os, const User &u)
{
    return os << "User { id: " << u.id << ", name: " << u.name << " }";
}

std::ostream &operator<<(std::ostream &os, const Product &p)
{
    return os << "Product { id: " << p.id << ", title: " << p.title << ", price: " << p.price << " }";
}

// -------------------- Repository Template --------------------
template <typename T>
class Repository
{
private:
    std::vector<T> items;

public:
    void add(const T &item)
    {
        items.push_back(item);
    }

    bool remove(int id)
    {
        auto it = std::remove_if(items.begin(), items.end(),
                                 [id](const T &item)
                                 { return item.id == id; });

        if (it != items.end())
        {
            items.erase(it, items.end());
            return true;
        }
        return false;
    }

    T *findById(int id)
    {
        for (auto &item : items)
        {
            if (item.id == id)
                return &item;
        }
        return nullptr;
    }

    void listAll() const
    {
        for (const auto &item : items)
            std::cout << item << '\n';
    }
};

// -------------------- Main --------------------
int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    Repository<User> userRepo;
    userRepo.add({1, "Alice"});
    userRepo.add({2, "Bob"});
    std::cout << "All Users:\n";
    userRepo.listAll();

    if (User *user = userRepo.findById(1))
    {
        std::cout << "Found User: " << *user << "\n";
    }

    userRepo.remove(1);
    std::cout << "Users after removal:\n";
    userRepo.listAll();

    Repository<Product> productRepo;
    productRepo.add({101, "Keyboard", 999.99f});
    productRepo.add({102, "Mouse", 499.49f});
    std::cout << "\nAll Products:\n";
    productRepo.listAll();

    return 0;
}
