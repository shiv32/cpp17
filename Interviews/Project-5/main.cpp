#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>

//-------------------------------------------------------------
// 1. SINGLETON
//-------------------------------------------------------------
class Singleton
{
private:
    Singleton() { std::cout << "Singleton created\n"; }

public:
    Singleton(const Singleton &) = delete;
    Singleton &operator=(const Singleton &) = delete;
    static Singleton &instance()
    {
        static Singleton inst;
        return inst;
    }
    void hello() { std::cout << "Hello from Singleton\n"; }
};

//-------------------------------------------------------------
// 2. FACTORY METHOD
//-------------------------------------------------------------
class Product
{
public:
    virtual void use() = 0;
    virtual ~Product() = default;
};

class ConcreteProductA : public Product
{
public:
    void use() override { std::cout << "Using Product A\n"; }
};

class ConcreteProductB : public Product
{
public:
    void use() override { std::cout << "Using Product B\n"; }
};

class Creator
{
public:
    virtual std::unique_ptr<Product> createProduct() = 0;
    virtual ~Creator() = default;
};

class ConcreteCreatorA : public Creator
{
public:
    std::unique_ptr<Product> createProduct() override
    {
        return std::make_unique<ConcreteProductA>();
    }
};

class ConcreteCreatorB : public Creator
{
public:
    std::unique_ptr<Product> createProduct() override
    {
        return std::make_unique<ConcreteProductB>();
    }
};

//-------------------------------------------------------------
// 3. ABSTRACT FACTORY
//-------------------------------------------------------------
class Button
{
public:
    virtual void draw() = 0;
    virtual ~Button() = default;
};

class WinButton : public Button
{
public:
    void draw() override { std::cout << "Windows Button\n"; }
};

class MacButton : public Button
{
public:
    void draw() override { std::cout << "Mac Button\n"; }
};

class GUIFactory
{
public:
    virtual std::unique_ptr<Button> createButton() = 0;
    virtual ~GUIFactory() = default;
};

class WinFactory : public GUIFactory
{
public:
    std::unique_ptr<Button> createButton() override
    {
        return std::make_unique<WinButton>();
    }
};

class MacFactory : public GUIFactory
{
public:
    std::unique_ptr<Button> createButton() override
    {
        return std::make_unique<MacButton>();
    }
};

//-------------------------------------------------------------
// 4. BUILDER
//-------------------------------------------------------------
class House
{
public:
    std::string walls, roof;
    void show() { std::cout << "House with " << walls << " walls and " << roof << " roof\n"; }
};

class HouseBuilder
{
protected:
    std::unique_ptr<House> house;

public:
    HouseBuilder() : house(std::make_unique<House>()) {}
    virtual ~HouseBuilder() = default;
    virtual HouseBuilder &buildWalls() = 0;
    virtual HouseBuilder &buildRoof() = 0;
    std::unique_ptr<House> getHouse() { return std::move(house); }
};

class WoodenHouseBuilder : public HouseBuilder
{
public:
    HouseBuilder &buildWalls() override
    {
        house->walls = "wooden";
        return *this;
    }
    HouseBuilder &buildRoof() override
    {
        house->roof = "wooden";
        return *this;
    }
};

class Engineer
{
public:
    std::unique_ptr<House> construct(HouseBuilder &builder)
    {
        return builder.buildWalls().buildRoof().getHouse();
    }
};

//-------------------------------------------------------------
// 5. PROTOTYPE
//-------------------------------------------------------------
class Shape
{
public:
    virtual std::unique_ptr<Shape> clone() const = 0;
    virtual void draw() const = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape
{
public:
    int radius;
    Circle(int r) : radius(r) {}
    std::unique_ptr<Shape> clone() const override
    {
        return std::make_unique<Circle>(*this);
    }
    void draw() const override
    {
        std::cout << "Drawing Circle with radius " << radius << "\n";
    }
};

//-------------------------------------------------------------
// MAIN
//-------------------------------------------------------------
int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    std::cout << "\n--- Singleton ---\n";
    Singleton::instance().hello();

    std::cout << "\n--- Factory Method ---\n";
    ConcreteCreatorA creatorA;
    auto productA = creatorA.createProduct();
    productA->use();

    std::cout << "\n--- Abstract Factory ---\n";
    WinFactory winFactory;
    auto winButton = winFactory.createButton();
    winButton->draw();

    std::cout << "\n--- Builder ---\n";
    WoodenHouseBuilder whb;
    Engineer engineer;
    auto house = engineer.construct(whb);
    house->show();

    std::cout << "\n--- Prototype ---\n";
    Circle circle(10);
    auto circleClone = circle.clone();
    circleClone->draw();

    return 0;
}
