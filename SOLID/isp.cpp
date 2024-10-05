/*
    Interface Segregation Principle
        Clients should not be forced to depend on methods that they don’t need.

        g++ isp.cpp -o test

        g++ isp.cpp -o test && ./test && rm test
*/

#include <iostream>
#include <memory>
/*
//Violate ISP

class FileInterface
{
    virtual void Read() = 0;
    virtual void Write() = 0;
    virtual ~FileInterface() = default;
};

*/

// follow ISP

class ReadInterface
{
public:
    virtual void Read() = 0;
    virtual ~ReadInterface() = default;
};

class WriteInterface
{
public:
    virtual void Write() = 0;
    virtual ~WriteInterface() = default;
};

class FileRead final : public ReadInterface
{
public:
    void Read() override;
    ~FileRead() = default;
};

void FileRead::Read()
{
    std::cout << "File read from FileRead class." << std::endl;
}

class FileWrite final : public WriteInterface
{
public:
    void Write() override;
    ~FileWrite() = default;
};

void FileWrite::Write()
{
    std::cout << "File write from FileWrite class." << std::endl;
}

class FileReadWrite final : public ReadInterface, public WriteInterface
{
public:
    void Read() override;
    void Write() override;
    ~FileReadWrite() = default;
};

void FileReadWrite::Read()
{
    std::cout << "File read from FileReadWrite class." << std::endl;
}

void FileReadWrite::Write()
{
    std::cout << "File write from FileReadWrite class." << std::endl;
}

main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // std::unique_ptr<FileRead> fr = std::make_unique<FileRead>();
    // std::unique_ptr<FileWrite> fw = std::make_unique<FileWrite>();
    // std::unique_ptr<FileReadWrite> frw = std::make_unique<FileReadWrite>();

    // or

    auto fr = std::make_unique<FileRead>();
    auto fw = std::make_unique<FileWrite>();
    auto frw = std::make_unique<FileReadWrite>();

    fr->Read();
    fw->Write();

    frw->Read();
    frw->Write();

    return 0;
}