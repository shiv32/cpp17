#include <iostream>
#include <memory>
#include <vector>

// ---------- PipelineStep (Template Method + Chain of Responsibility) ----------
template <typename T>
class PipelineStep
{
public:
    virtual ~PipelineStep() = default;

    void setNext(std::shared_ptr<PipelineStep<T>> next)
    {
        nextStep = next;
    }

    void handle(T data)
    {
        if (shouldProcess(data))
        {
            T result = process(data);
            
            if (nextStep)
                nextStep->handle(result);
        }
    }

protected:
    virtual T process(T data) = 0;
    virtual bool shouldProcess(T) { return true; }

private:
    std::shared_ptr<PipelineStep<T>> nextStep = nullptr;
};

// ---------- MultiplyStep (Strategy) ----------
template <typename T>
class MultiplyStep : public PipelineStep<T>
{
    T factor;

public:
    explicit MultiplyStep(T f) : factor(f) {}

protected:
    T process(T data) override
    {
        return data * factor;
    }
};

// ---------- FilterStep (Strategy) ----------
template <typename T>
class FilterStep : public PipelineStep<T>
{
    T minValue;

public:
    explicit FilterStep(T min) : minValue(min) {}

protected:
    T process(T data) override
    {
        return data; // Identity, since filtering happens in shouldProcess
    }

    bool shouldProcess(T data) override
    {
        return data >= minValue;
    }
};

// ---------- PrintStep ----------
template <typename T>
class PrintStep : public PipelineStep<T>
{
protected:
    T process(T data) override
    {
        std::cout << "Output: " << data << '\n';
        return data;
    }
};

// ---------- Main ----------
int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    using T = int;

    auto multiply = std::make_shared<MultiplyStep<T>>(2);
    auto filter = std::make_shared<FilterStep<T>>(10);
    auto printer = std::make_shared<PrintStep<T>>();

    multiply->setNext(filter);
    filter->setNext(printer);

    std::vector<T> data = {1, 4, 6, 10, 15};

    for (T value : data)
    {
        multiply->handle(value);
    }

    return 0;
}
