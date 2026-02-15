#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <memory>

//////////////////////////
// Model
//////////////////////////
struct Student
{
    std::string name;
    int score;
};

//////////////////////////
// Strategy Pattern
//////////////////////////
class SortStrategy
{
public:
    virtual bool compare(const Student &a, const Student &b) const = 0;
    virtual ~SortStrategy() = default;
};

class ScoreDescending : public SortStrategy
{
public:
    bool compare(const Student &a, const Student &b) const override
    {
        if (a.score == b.score)
            return a.name < b.name;

        return a.score > b.score;
    }
};

//////////////////////////
// Comparator Adapter
//////////////////////////
class StudentComparator
{
    const SortStrategy &strategy;

public:
    StudentComparator(const SortStrategy &s) : strategy(s)
    {
    }

    bool operator()(const Student &a, const Student &b) const
    {
        return strategy.compare(a, b);
    }
};

//////////////////////////
// Singleton Pattern
//////////////////////////
class FileManager
{
private:
    FileManager()
    {
    }

public:
    static FileManager &instance()
    {
        static FileManager fm;
        return fm;
    }

    void save(const std::string &file, const std::multiset<Student, StudentComparator> &data)
    {
        std::ofstream out(file); //default truncate mode

        for (const auto &s : data)
            out << s.name << " " << s.score << "\n";
    }

    void load(const std::string &file, std::multiset<Student, StudentComparator> &data)
    {
        std::ifstream in(file);
        Student s;

        while (in >> s.name >> s.score)
            data.insert(s);
    }
};

//////////////////////////
// Repository Pattern
//////////////////////////
class RankingRepository
{
private:
    std::unique_ptr<SortStrategy> strategy;
    std::multiset<Student, StudentComparator> students;
    std::string filename = "../data/students.txt";

public:
    RankingRepository() : strategy(std::make_unique<ScoreDescending>()), students(StudentComparator(*strategy))
    {
    }

    void add(const std::string &name, int score)
    {
        students.insert({name, score});
    }

    void show() const
    {
        int rank = 1;

        for (const auto &s : students)
            std::cout << rank++ << ". "<< s.name << " - "<< s.score << "\n";
    }

    void save()
    {
        FileManager::instance().save(filename, students);
    }

    void load()
    {
        FileManager::instance().load(filename, students);
    }
};

//////////////////////////
// Main
//////////////////////////
int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    RankingRepository repo;
    repo.load();

    int choice;

    do
    {
        std::cout << "\n1.Add\n2.Show\n3.Exit\nChoice: ";
        std::cin >> choice;

        if (choice == 1)
        {
            std::string name;
            int score;

            std::cout << "Enter name & score: ";
            std::cin >> name >> score;

            repo.add(name, score);
            repo.save();
        }
        else if (choice == 2)
        {
            repo.show();
        }

    } while (choice != 3);

    return EXIT_SUCCESS;
}
