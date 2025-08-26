#include <iostream>
#include <memory>
#include <vector>

//-------------------------------------------------------------
// 1. SRP – Single Responsibility Principle
//    A class should have only one reason to change
//-------------------------------------------------------------
class InvoiceData
{
public:
    void addItem(const std::string &item) 
    { 
        items.push_back(item); 
    }
    
    void print() const
    {
        for (auto &i : items)
            std::cout << i << "\n";
    }

private:
    std::vector<std::string> items;
};

class InvoicePrinter
{
public:
    static void print(const InvoiceData &inv)
    {
        std::cout << "Invoice:\n";
        inv.print();
    }
};

//-------------------------------------------------------------
// 2. OCP – Open/Closed Principle
//    Open for extension, closed for modification
//-------------------------------------------------------------
class Shape
{
public:
    virtual double area() const = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape
{
    double r;

public:
    Circle(double r_) : r(r_) {}
    double area() const override { return 3.14 * r * r; }
};

class Rectangle : public Shape
{
    double w, h;

public:
    Rectangle(double w_, double h_) : w(w_), h(h_) {}
    double area() const override { return w * h; }
};

double totalArea(const std::vector<std::unique_ptr<Shape>> &shapes)
{
    double sum = 0;
    for (auto &s : shapes)
        sum += s->area();
    return sum;
}

//-------------------------------------------------------------
// 3. LSP – Liskov Substitution Principle
//    Subtypes must be substitutable for their base types
//-------------------------------------------------------------
class Bird
{
public:
    virtual void fly() { std::cout << "Flying\n"; }
    virtual ~Bird() = default;
};

class Sparrow : public Bird
{
public:
    void fly() override { std::cout << "Sparrow flying\n"; }
};

//-------------------------------------------------------------
// 4. ISP – Interface Segregation Principle
//    Clients should not depend on interfaces they do not use
//-------------------------------------------------------------
class IPrinter
{
public:
    virtual void print() = 0;
    virtual ~IPrinter() = default;
};

class IScanner
{
public:
    virtual void scan() = 0;
    virtual ~IScanner() = default;
};

class SimplePrinter : public IPrinter
{
public:
    void print() override { std::cout << "Printing only\n"; }
};

//-------------------------------------------------------------
// 5. DIP – Dependency Inversion Principle
//    Depend on abstractions, not concrete classes
//-------------------------------------------------------------
class IMessageSender
{
public:
    virtual void send(const std::string &msg) = 0;
    virtual ~IMessageSender() = default;
};

class EmailSender : public IMessageSender
{
public:
    void send(const std::string &msg) override
    {
        std::cout << "Email: " << msg << "\n";
    }
};

class Notification
{
    IMessageSender &sender;

public:
    Notification(IMessageSender &s) : sender(s) {}
    void notify(const std::string &msg) { sender.send(msg); }
};

//-------------------------------------------------------------
// MAIN
//-------------------------------------------------------------
int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux
    
    std::cout << "--- SRP ---\n";
    InvoiceData inv;
    inv.addItem("Pen");
    inv.addItem("Book");
    InvoicePrinter::print(inv);

    std::cout << "\n--- OCP ---\n";
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.push_back(std::make_unique<Circle>(2));
    shapes.push_back(std::make_unique<Rectangle>(3, 4));
    std::cout << "Total area = " << totalArea(shapes) << "\n";

    std::cout << "\n--- LSP ---\n";
    Bird *b = new Sparrow();
    b->fly();
    delete b;

    std::cout << "\n--- ISP ---\n";
    SimplePrinter sp;
    sp.print();

    std::cout << "\n--- DIP ---\n";
    EmailSender es;
    Notification notif(es);
    notif.notify("Hello World");

    return 0;
}
