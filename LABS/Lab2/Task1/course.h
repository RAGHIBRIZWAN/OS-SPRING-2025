#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <vector>
#include "Student.h"
#include "Teacher.h"

class Course {
private:
    std::string name;
    std::vector<Student*> students;
    std::vector<Teacher*> teachers;

public:
    Course(const std::string& name);
    void enrollStudent(Student* student);
    void assignTeacher(Teacher* teacher);
    void displayStudents() const;
    void displayTeachers() const;
    std::string getName() const;
};

#endif
