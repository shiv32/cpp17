#include <iostream>
#include <fstream>
#include <set>
#include <string>

struct Student
{
    std::string name;
    int score;

    // Sort by score descending, if equal sort by name
    bool operator<(const Student &other) const
    {
        if (score == other.score)
            return name < other.name;

        return score > other.score; // descending order
    }
};

class RankingSystem
{
private:
    std::multiset<Student> students;
    const std::string filename = "../data/students.txt";

public:
    void load()
    {
        std::ifstream file(filename);

        if (!file)
            return;

        Student s;

        while (file >> s.name >> s.score)
        {
            students.insert(s);
        }
    }

    void save()
    {
        std::ofstream file(filename);

        for (const auto &s : students)
        {
            file << s.name << " " << s.score << "\n";
        }
    }

    void addStudent(const std::string &name, int score)
    {
        students.insert({name, score});
    }

    void showRanking() const
    {
        int rank = 1;

        for (const auto &s : students)
        {
            std::cout << rank++ << ". "<< s.name << " - "<< s.score << "\n";
        }
    }
};

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    RankingSystem system;
    system.load();

    int choice;
    do
    {
        std::cout << "\n1. Add Student\n2. Show Ranking\n3. Exit\nChoice: ";
        std::cin >> choice;

        if (choice == 1)
        {
            std::string name;
            int score;
            
            std::cout << "Enter name and score: ";
            std::cin >> name >> score;

            system.addStudent(name, score);
            system.save();
        }
        else if (choice == 2)
        {
            system.showRanking();
        }

    } while (choice != 3);

    return EXIT_SUCCESS;
}
