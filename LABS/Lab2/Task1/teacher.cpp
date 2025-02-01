#include "Teacher.h"
#include "Course.h"
#include <iostream>

Teacher::Teacher(const std::string& name) : name(name) {}

void Teacher::assignCourse(Course* course) {
    courses.push_back(course);
}

void Teacher::displayCourses() const {
    std::cout << "Teacher: " << name << " is teaching:\n";
    for (const auto& course : courses) {
        std::cout << "- " << course->getName() << "\n";
    }
}

std::string Teacher::getName() const {
    return name;
}
