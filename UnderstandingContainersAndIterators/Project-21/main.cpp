/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief list Example: Determining Enrollment
 * @version 0.1
 * @date 2024-09-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <list>
#include <vector>

// courseStudents is a vector of lists, one for each course. The lists
// contain the students enrolled in those courses. They are not sorted.
//
// droppedStudents is a list of students who failed to pay their
// tuition and so were dropped from their courses.
//
// The function returns a list of every enrolled (non-dropped) student in
// all the courses.

using listOfStudent = std::list<std::string>;
using listOfStudentContainer = std::vector<listOfStudent>;

listOfStudent getTotalEnrollment(const listOfStudentContainer &courseStudents,
                                 const listOfStudent &droppedStudents)
{
    listOfStudent allStudents;

    // Concatenate all the course lists onto the master list
    for (auto &lst : courseStudents)
    {
        allStudents.insert(cend(allStudents), cbegin(lst), cend(lst));
    }

    // Sort the master list
    allStudents.sort();

    // Remove duplicate student names (those who are in multiple courses).
    allStudents.unique();

    // Remove students who are on the dropped list.
    // Iterate through the dropped list, calling remove on the
    // master list for each student in the dropped list.
    for (auto &str : droppedStudents)
    {
        allStudents.remove(str);
    }

    // done!
    return allStudents;
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    listOfStudent droppedStudents = {"amit", "manoj"};

    listOfStudent mathClass = {"bhanu", "shilpa", "shiv"};
    listOfStudent physicsClass = {"bhanu", "mohan"};
    listOfStudent chemistryClass = {"shilpa", "mohan"};
    listOfStudent cppClass = {"shiv", "surbhi"};

    listOfStudentContainer courseStudents{mathClass, physicsClass, chemistryClass, cppClass};

    //listOfStudentContainer courseStudents;

    // courseStudents.emplace_back(mathClass);
    // courseStudents.emplace_back(physicsClass);
    // courseStudents.emplace_back(chemistryClass);
    // courseStudents.emplace_back(cppClass);

    // for (auto &&cls : {mathClass, physicsClass, chemistryClass, cppClass})
    // {
    //     courseStudents.emplace_back(std::move(cls));
    // }

    listOfStudent totalEnroledStudent = getTotalEnrollment(courseStudents, droppedStudents);

    for (std::string student : totalEnroledStudent)
        std::cout << student << std::endl;

    return 0;
}