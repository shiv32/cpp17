#include <iostream>
#include <string>
#include <vector>

using namespace std;

// =========================
// DTO
// =========================

struct StudentDTO
{
    int id;
    string name;
    int age;
};

// =========================
// Repository
// =========================

class StudentRepository
{
private:
    vector<StudentDTO> students;

public:
    void addStudent(const StudentDTO &student)
    {
        students.push_back(student);
    }

    vector<StudentDTO> getAllStudents() const
    {
        return students;
    }
};

// =========================
// Service Layer
// =========================

class StudentService
{
private:
    StudentRepository repository;

public:
    void createStudent(int id, const string &name, int age)
    {
        StudentDTO dto;

        dto.id = id;
        dto.name = name;
        dto.age = age;

        repository.addStudent(dto);
    }

    void displayStudents() const
    {
        auto students = repository.getAllStudents();

        for (const auto &s : students)
        {
            cout << "ID   : " << s.id << '\n';
            cout << "Name : " << s.name << '\n';
            cout << "Age  : " << s.age << '\n';
            cout << "----------------------\n";
        }
    }
};

// =========================
// Main
// =========================

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    StudentService service;

    service.createStudent(1, "Shiv", 25);
    service.createStudent(2, "Ravi", 21);
    service.createStudent(3, "Anu", 22);

    service.displayStudents();

    return 0;
}
