#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>

//-------------------------------------------------------------
// 1. CHAIN OF RESPONSIBILITY
//-------------------------------------------------------------
class Handler
{
    std::unique_ptr<Handler> next;

public:
    void setNext(std::unique_ptr<Handler> n) { next = std::move(n); }
    virtual void handle(int req)
    {
        if (next)
            next->handle(req);
    }
    virtual ~Handler() = default;
};

class ConcreteHandler : public Handler
{
    int limit;

public:
    ConcreteHandler(int l) : limit(l) {}
    void handle(int req) override
    {
        if (req < limit)
            std::cout << "Handled by limit " << limit << "\n";
        else
            Handler::handle(req);
    }
};

//-------------------------------------------------------------
// 2. COMMAND
//-------------------------------------------------------------
class Command
{
public:
    virtual void execute() = 0;
    virtual ~Command() = default;
};

class Receiver
{
public:
    void action() { std::cout << "Receiver action performed\n"; }
};

class ConcreteCommand : public Command
{
    Receiver &r;

public:
    ConcreteCommand(Receiver &rec) : r(rec) {}
    void execute() override { r.action(); }
};

class Invoker
{
    std::unique_ptr<Command> cmd;

public:
    void setCommand(std::unique_ptr<Command> c) { cmd = std::move(c); }
    void run()
    {
        if (cmd)
            cmd->execute();
    }
};

//-------------------------------------------------------------
// 3. INTERPRETER
//-------------------------------------------------------------
class Expression
{
public:
    virtual int interpret() = 0;
    virtual ~Expression() = default;
};

class Number : public Expression
{
    int val;

public:
    Number(int v) : val(v) {}
    int interpret() override 
    { 
        return val; 
    }
};

class Add : public Expression
{
    std::unique_ptr<Expression> left, right;

public:
    Add(std::unique_ptr<Expression> l, std::unique_ptr<Expression> r)
    : left(std::move(l)), 
      right(std::move(r)) 
    {

    }

    int interpret() override 
    { 
        return left->interpret() + right->interpret(); 
    }
};

//-------------------------------------------------------------
// 4. ITERATOR
//-------------------------------------------------------------
template <typename T>
class Iterator
{
    const std::vector<T> &data;
    size_t idx = 0;

public:
    Iterator(const std::vector<T> &d) : data(d) {}
    bool hasNext() const { return idx < data.size(); }
    T next() { return data[idx++]; }
};

//-------------------------------------------------------------
// 5. MEDIATOR
//-------------------------------------------------------------
class Mediator;

class Colleague
{
protected:
    Mediator &mediator;

public:
    Colleague(Mediator &m) : mediator(m) {}
    virtual void receive(const std::string &msg) = 0;
    virtual void send(const std::string &msg) = 0;
    virtual ~Colleague() = default;
};

class Mediator
{
    std::vector<Colleague *> colleagues;

public:
    void add(Colleague *c) { colleagues.push_back(c); }
    void distribute(Colleague *sender, const std::string &msg)
    {
        for (auto *c : colleagues)
            if (c != sender)
                c->receive(msg);
    }
};

class ConcreteColleague : public Colleague
{
public:
    using Colleague::Colleague;
    void receive(const std::string &msg) override
    {
        std::cout << "Received: " << msg << "\n";
    }
    void send(const std::string &msg) override
    {
        mediator.distribute(this, msg);
    }
};

//-------------------------------------------------------------
// 6. MEMENTO
//-------------------------------------------------------------
class Memento
{
    std::string state;

public:
    Memento(std::string s) : state(std::move(s)) {}
    std::string getState() const { return state; }
};

class Originator
{
    std::string state;

public:
    void setState(const std::string &s) { state = s; }
    std::string getState() const { return state; }
    
    Memento save() { return Memento(state); }
    void restore(const Memento &m) { state = m.getState(); }
};

//-------------------------------------------------------------
// 7. OBSERVER
//-------------------------------------------------------------
class Observer
{
public:
    virtual void update(int val) = 0;
    virtual ~Observer() = default;
};

class Subject
{
    std::vector<Observer *> observers;
    int value = 0;

public:
    void attach(Observer *o) { observers.push_back(o); }
    void setValue(int v)
    {
        value = v;
        for (auto *o : observers)
            o->update(value);
    }
};

class ConcreteObserver : public Observer
{
    std::string name;

public:
    ConcreteObserver(std::string n) : name(std::move(n)) {}
    void update(int val) override
    {
        std::cout << name << " observed value " << val << "\n";
    }
};

//-------------------------------------------------------------
// 8. STATE
//-------------------------------------------------------------
class Context;

class State
{
public:
    virtual void handle(Context &ctx) = 0;
    virtual ~State() = default;
};

class Context
{
    std::unique_ptr<State> state;

public:
    Context(std::unique_ptr<State> s) : state(std::move(s)) {}
    void setState(std::unique_ptr<State> s) { state = std::move(s); }
    void request() { state->handle(*this); }
};

class StateA : public State
{
public:
    void handle(Context &ctx) override;
};

class StateB : public State
{
public:
    void handle(Context &ctx) override;
};

void StateA::handle(Context &ctx)
{
    std::cout << "StateA handling\n";
    ctx.setState(std::make_unique<StateB>());
}

void StateB::handle(Context &ctx)
{
    std::cout << "StateB handling\n";
    ctx.setState(std::make_unique<StateA>());
}

//-------------------------------------------------------------
// 9. STRATEGY
//-------------------------------------------------------------
class Strategy
{
public:
    virtual int doOp(int a, int b) = 0;
    virtual ~Strategy() = default;
};

class AddOp : public Strategy
{
public:
    int doOp(int a, int b) override { return a + b; }
};

class ContextStrat
{
    std::unique_ptr<Strategy> strat;

public:
    ContextStrat(std::unique_ptr<Strategy> s) : strat(std::move(s)) {}
    int execute(int a, int b) { return strat->doOp(a, b); }
};

//-------------------------------------------------------------
// 10. TEMPLATE METHOD
//-------------------------------------------------------------
class AbstractClass
{
public:
    void templateMethod()
    {
        baseStep();
        requiredStep();
        hook();
    }
    virtual ~AbstractClass() = default;

protected:
    void baseStep() { std::cout << "Base step\n"; }
    virtual void requiredStep() = 0;
    virtual void hook() {}
};

class ConcreteClass : public AbstractClass
{
protected:
    void requiredStep() override { std::cout << "Concrete required step\n"; }
    void hook() override { std::cout << "Hook step\n"; }
};

//-------------------------------------------------------------
// 11. VISITOR
//-------------------------------------------------------------
class Element;

class Visitor
{
public:
    virtual void visit(Element &e) = 0;
    virtual ~Visitor() = default;
};

class Element
{
public:
    virtual void accept(Visitor &v) = 0;
    virtual ~Element() = default;
};

class ConcreteElement : public Element
{
public:
    void accept(Visitor &v) override { v.visit(*this); }
};

class ConcreteVisitor : public Visitor
{
public:
    void visit(Element &) override { std::cout << "Visited element\n"; }
};

//-------------------------------------------------------------
// MAIN
//-------------------------------------------------------------
int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    std::cout << "--- Chain of Responsibility ---\n";
    auto h1 = std::make_unique<ConcreteHandler>(10);
    auto h2 = std::make_unique<ConcreteHandler>(20);
    h1->setNext(std::move(h2));
    h1->handle(5);
    h1->handle(15);

    std::cout << "\n--- Command ---\n";
    Receiver rec;
    Invoker inv;
    inv.setCommand(std::make_unique<ConcreteCommand>(rec));
    inv.run();

    std::cout << "\n--- Interpreter ---\n";
    Add expr(std::make_unique<Number>(1), std::make_unique<Number>(2));
    std::cout << "1+2=" << expr.interpret() << "\n";

    std::cout << "\n--- Iterator ---\n";
    std::vector<int> nums = {1, 2, 3};
    Iterator<int> it(nums);
    while (it.hasNext())
        std::cout << it.next() << " ";
    std::cout << "\n";

    std::cout << "\n--- Mediator ---\n";
    Mediator med;
    ConcreteColleague c1(med), c2(med);
    med.add(&c1);
    med.add(&c2);
    c1.send("Hello!");

    std::cout << "\n--- Memento ---\n";
    Originator org;
    org.setState("State1");
    auto mem = org.save();
    org.setState("State2");
    org.restore(mem);
    std::cout << "Restored state: " << org.getState() << "\n";

    std::cout << "\n--- Observer ---\n";
    Subject subj;
    ConcreteObserver o1("Obs1"), o2("Obs2");
    subj.attach(&o1);
    subj.attach(&o2);
    subj.setValue(42);

    std::cout << "\n--- State ---\n";
    Context ctx(std::make_unique<StateA>());
    ctx.request();
    ctx.request();

    std::cout << "\n--- Strategy ---\n";
    ContextStrat strat(std::make_unique<AddOp>());
    std::cout << "3+4=" << strat.execute(3, 4) << "\n";

    std::cout << "\n--- Template Method ---\n";
    ConcreteClass cc;
    cc.templateMethod();

    std::cout << "\n--- Visitor ---\n";
    ConcreteElement e;
    ConcreteVisitor v;
    e.accept(v);

    return 0;
}
