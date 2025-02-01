#include "Student.h"
#include "Course.h"
#include <iostream>

Student::Student(const std::string& name) : name(name) {}

void Student::enroll(Course* course) {
    courses.push_back(course);
}

void Student::displayCourses() const {
    std::cout << "Student: " << name << " is enrolled in:\n";
    for (const auto& course : courses) {
        std::cout << "- " << course->getName() << "\n";
    }
}

std::string Student::getName() const {
    return name;
}
