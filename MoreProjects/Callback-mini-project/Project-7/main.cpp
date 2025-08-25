#include <iostream>
#include <source_location> //C++20

void Log(std::source_location sl = std::source_location::current())
{
    std::cout << sl.function_name() << "\n";
}

class Shape
{
public:
    // virtual void Draw()
    // {
    //     Log();
    // }

    // virtual void Erase()
    // {
    //     Log();
    // }

    virtual void Draw() = 0;
    virtual void Erase() = 0;
};

void Render(Shape *p)
{
    p->Draw();
    p->Erase();
}

class Line : public Shape
{
public:
    void Draw() override
    {
        Log();
    }

    void Erase() override
    {
        Log();
    }
};

class Circle : public Shape
{
public:
    void Draw() override
    {
        Log();
    }

    void Erase() override
    {
        Log();
    }
};

int main()
{
    Line l;
    Circle c;

    Render(&l);
    Render(&c);

    return 0;
}