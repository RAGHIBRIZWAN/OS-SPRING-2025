#include "Course.h"
#include <iostream>

Course::Course(const std::string& name) : name(name) {}

void Course::enrollStudent(Student* student) {
    students.push_back(student);
    student->enroll(this);
}

void Course::assignTeacher(Teacher* teacher) {
    teachers.push_back(teacher);
    teacher->assignCourse(this);
}

void Course::displayStudents() const {
    std::cout << "Course: " << name << " has the following students enrolled:\n";
    for (const auto& student : students) {
        std::cout << "- " << student->getName() << "\n";
    }
}

void Course::displayTeachers() const {
    std::cout << "Course: " << name << " is taught by:\n";
    for (const auto& teacher : teachers) {
        std::cout << "- " << teacher->getName() << "\n";
    }
}

std::string Course::getName() const {
    return name;
}
