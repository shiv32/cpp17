#include <iostream>
#include <string>

class Stream
{
    std::string m_Filename;

public:
    Stream(const std::string &filename) : m_Filename(filename)
    {
        std::cout << "Stream(const std::string&)" << std::endl;
    };

    const std::string &GetFilename() const
    {
        return m_Filename;
    }

    ~Stream()
    {
        std::cout << "~Stream()" << std::endl;
    }
};

class Outputstream : virtual public Stream
{
    std::ostream &out;

public:
    Outputstream(std::ostream &o, const std::string &FileName) : out(o), Stream(FileName)
    {
        std::cout << "Outputstream" << std::endl;
    }

    std::ostream & operator << (const std::string &data)
    {
        out << data <<std::endl;
        return out;
    }

    ~Outputstream()
    {

        std::cout << "~Outputstream()" << std::endl;
    }
};

class Inputstream : virtual public Stream
{
    std::istream &in;

public:
    Inputstream(std::istream &i, const std::string &FileName) : in(i), Stream(FileName)
    {
        std::cout << "Inputstream" << std::endl;
    }

    std::istream & operator >> (std::string &data)
    {
        in >> data;
        return in;
    }

    ~Inputstream()
    {
        std::cout << "~Inputstream()" << std::endl;
    }
};

class IOstream : public Outputstream, public Inputstream
{
public:
    IOstream(const std::string &FileName) : Outputstream(std::cout, FileName),
     Inputstream(std::cin, FileName),
     Stream(FileName)
    {
        std::cout << "IOstream()" << std::endl;
    }

    ~IOstream()
    {
        std::cout << "~IOstream()" << std::endl;
    }
};

int main()
{

 //  std::cout << "hello shiv" << std::endl;

    IOstream stream("doc.txt");
    std::string data;

    stream >> data;
    stream << data;

    stream << stream.GetFilename();


    return 0;
}