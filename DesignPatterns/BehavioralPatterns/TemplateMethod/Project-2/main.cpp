/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Template Method
 * @version 0.1
 * @date 2024-08-05
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <memory>

// Abstract base class
class DataProcessor
{
public:
    // Template method
    void process()
    {
        readData();
        processData();
        saveData();
    }

    virtual ~DataProcessor() = default;

protected:
    virtual void readData() = 0;    // Step to be defined by subclass
    virtual void processData() = 0; // Step to be defined by subclass

    void saveData()
    {
        std::cout << "Saving data to database...\n";
    }
};

// Concrete class
class CSVDataProcessor : public DataProcessor
{
protected:
    void readData() override
    {
        std::cout << "Reading data from CSV file...\n";
    }

    void processData() override
    {
        std::cout << "Processing CSV data...\n";
    }
};

// Another concrete class
class XMLDataProcessor : public DataProcessor
{
protected:
    void readData() override
    {
        std::cout << "Reading data from XML file...\n";
    }

    void processData() override
    {
        std::cout << "Processing XML data...\n";
    }
};

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // DataProcessor *processor1 = new CSVDataProcessor();
    // processor1->process();
    // delete processor1;

    // std::cout << "\n";

    // DataProcessor *processor2 = new XMLDataProcessor();
    // processor2->process();
    // delete processor2;

    // smart pointer---------------------------------------------------------------
    std::unique_ptr<DataProcessor> processor{nullptr};

    processor = std::make_unique<CSVDataProcessor>();
    processor->process();

    std::cout << "\n";

    processor = std::make_unique<XMLDataProcessor>();
    processor->process();

    return 0;
}