#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <unordered_map>

//-------------------------------------------------------------
// 1. ADAPTER
//-------------------------------------------------------------
class OldPrinter
{
public:
    void oldPrint(const std::string &msg) { std::cout << "OldPrinter: " << msg << "\n"; }
};

class Printer
{
public:
    virtual void print(const std::string &msg) = 0;
    virtual ~Printer() = default;
};

class PrinterAdapter : public Printer
{
    OldPrinter old;

public:
    void print(const std::string &msg) override { old.oldPrint(msg); }
};

//-------------------------------------------------------------
// 2. BRIDGE
//-------------------------------------------------------------
class DrawingAPI
{
public:
    virtual void drawCircle(int x, int y, int r) = 0;
    virtual ~DrawingAPI() = default;
};

class DrawingAPI1 : public DrawingAPI
{
public:
    void drawCircle(int x, int y, int r) override
    {
        std::cout << "API1.circle at (" << x << "," << y << "), r=" << r << "\n";
    }
};

class DrawingAPI2 : public DrawingAPI
{
public:
    void drawCircle(int x, int y, int r) override
    {
        std::cout << "API2.circle at (" << x << "," << y << "), r=" << r << "\n";
    }
};

class Shape
{
protected:
    DrawingAPI &api;

public:
    Shape(DrawingAPI &a) : api(a) {}
    virtual void draw() = 0;
    virtual ~Shape() = default;
};

class CircleShape : public Shape
{
    int x, y, r;

public:
    CircleShape(int x_, int y_, int r_, DrawingAPI &a) : Shape(a), x(x_), y(y_), r(r_) {}
    void draw() override { api.drawCircle(x, y, r); }
};

//-------------------------------------------------------------
// 3. COMPOSITE
//-------------------------------------------------------------
class Graphic
{
public:
    virtual void draw() = 0;
    virtual ~Graphic() = default;
};

class Line : public Graphic
{
public:
    void draw() override { std::cout << "Draw Line\n"; }
};

class Picture : public Graphic
{
    std::vector<std::unique_ptr<Graphic>> children;

public:
    void add(std::unique_ptr<Graphic> g) { children.push_back(std::move(g)); }
    void draw() override
    {
        std::cout << "Picture:\n";
        for (auto &g : children)
            g->draw();
    }
};

//-------------------------------------------------------------
// 4. DECORATOR
//-------------------------------------------------------------
class Widget
{
public:
    virtual void draw() = 0;
    virtual ~Widget() = default;
};

class TextField : public Widget
{
public:
    void draw() override { std::cout << "TextField\n"; }
};

class BorderDecorator : public Widget
{
    std::unique_ptr<Widget> wid;

public:
    BorderDecorator(std::unique_ptr<Widget> w) : wid(std::move(w)) {}
    void draw() override
    {
        wid->draw();
        std::cout << "  + Border\n";
    }
};

//-------------------------------------------------------------
// 5. FACADE
//-------------------------------------------------------------
class CPU
{
public:
    void start() { std::cout << "CPU start\n"; }
};

class Memory
{
public:
    void load() { std::cout << "Memory load\n"; }
};

class HardDrive
{
public:
    void read() { std::cout << "HardDrive read\n"; }
};

class ComputerFacade
{
    CPU cpu;
    Memory mem;
    HardDrive hd;

public:
    void start()
    {
        cpu.start();
        mem.load();
        hd.read();
        std::cout << "Computer ready\n";
    }
};

//-------------------------------------------------------------
// 6. FLYWEIGHT
//-------------------------------------------------------------
class Glyph
{
    char symbol;

public:
    Glyph(char s) : symbol(s) {}
    void draw(int pos) { std::cout << "Draw '" << symbol << "' at " << pos << "\n"; }
};

class GlyphFactory
{
    std::unordered_map<char, std::shared_ptr<Glyph>> pool;

public:
    std::shared_ptr<Glyph> get(char c)
    {
        if (!pool[c])
            pool[c] = std::make_shared<Glyph>(c);
        return pool[c];
    }
};

//-------------------------------------------------------------
// 7. PROXY
//-------------------------------------------------------------
class Image
{
public:
    virtual void display() = 0;
    virtual ~Image() = default;
};

class RealImage : public Image
{
    std::string filename;

public:
    RealImage(std::string f) : filename(std::move(f))
    {
        std::cout << "Loading " << filename << "\n";
    }
    void display() override { std::cout << "Displaying " << filename << "\n"; }
};

class ProxyImage : public Image
{
    std::string filename;
    std::unique_ptr<RealImage> real;

public:
    ProxyImage(std::string f) : filename(std::move(f)) {}
    void display() override
    {
        if (!real)
            real = std::make_unique<RealImage>(filename);
        real->display();
    }
};

//-------------------------------------------------------------
// MAIN
//-------------------------------------------------------------
int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    std::cout << "--- Adapter ---\n";
    PrinterAdapter adapter;
    adapter.print("Hello Adapter");

    std::cout << "\n--- Bridge ---\n";
    DrawingAPI1 api1;
    DrawingAPI2 api2;
    CircleShape c1(1, 2, 3, api1);
    CircleShape c2(4, 5, 6, api2);
    c1.draw();
    c2.draw();

    std::cout << "\n--- Composite ---\n";
    Picture pic;
    pic.add(std::make_unique<Line>());
    pic.add(std::make_unique<Line>());
    pic.draw();

    std::cout << "\n--- Decorator ---\n";
    std::unique_ptr<Widget> w = std::make_unique<BorderDecorator>(std::make_unique<TextField>());
    w->draw();

    std::cout << "\n--- Facade ---\n";
    ComputerFacade comp;
    comp.start();

    std::cout << "\n--- Flyweight ---\n";
    GlyphFactory gf;
    auto gA = gf.get('A');
    auto gB = gf.get('B');
    gA->draw(1);
    gB->draw(2);
    gf.get('A')->draw(3);

    std::cout << "\n--- Proxy ---\n";
    ProxyImage img("test.png");
    img.display(); // loads
    img.display(); // cached

    return 0;
}
