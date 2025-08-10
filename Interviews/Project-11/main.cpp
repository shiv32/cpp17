#include <iostream>
#include <memory>
#include <string>

// Simple class to track object lifecycle
class Demo
{
    std::string name;

public:
    Demo(std::string n) : name(std::move(n)) { std::cout << name << " constructed\n"; }
    ~Demo() { std::cout << name << " destroyed\n"; }
    void greet() const { std::cout << "Hello from " << name << "\n"; }
};

int main()
{

    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // 1. unique_ptr - sole ownership
    {
        std::unique_ptr<Demo> p1 = std::make_unique<Demo>("Unique1");
        p1->greet();

        // Transfer ownership
        std::unique_ptr<Demo> p2 = std::move(p1);
        if (!p1)
            std::cout << "p1 is now null after move\n";
        p2->greet();
    } // p2 goes out of scope, object destroyed

    std::cout << "--------------------------------\n";

    // 2. shared_ptr - shared ownership
    {
        std::shared_ptr<Demo> sp1 = std::make_shared<Demo>("Shared1");
        {
            std::shared_ptr<Demo> sp2 = sp1; // reference count increases
            std::cout << "use_count: " << sp1.use_count() << "\n";
            sp2->greet();
        } // sp2 destroyed, ref count decreases
        std::cout << "use_count after sp2 destroyed: " << sp1.use_count() << "\n";
    } // last shared_ptr destroyed, object destroyed

    std::cout << "--------------------------------\n";

    // 3. weak_ptr - non-owning reference
    {
        std::shared_ptr<Demo> sp = std::make_shared<Demo>("Weak1");
        std::weak_ptr<Demo> wp = sp; // no increase in use_count

        std::cout << "use_count with weak_ptr: " << sp.use_count() << "\n";

        if (auto locked = wp.lock())
        { // lock() creates a shared_ptr if still alive
            locked->greet();
        }

        sp.reset(); // destroy the managed object
        if (wp.expired())
        {
            std::cout << "Object expired, weak_ptr can't access it\n";
        }
    }

    std::cout << "--------------------------------\n";

    // 4. unique_ptr with custom deleter
    {
        auto deleter = [](Demo *d)
        {
            std::cout << "Custom deleting " << "\n";
            delete d;
        };
        std::unique_ptr<Demo, decltype(deleter)> p3(new Demo("CustomDel"), deleter);
        p3->greet();
    } // custom deleter called

    return 0;
}
