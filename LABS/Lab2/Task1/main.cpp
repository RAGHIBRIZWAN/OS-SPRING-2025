#include <iostream>
#include "Student.h"
#include "Teacher.h"
#include "Course.h"

int main() {
    // Create students
    Student s1("Raghib");
    Student s2("Rizwan");
    Student s3("Rabani");

    // Create teachers
    Teacher t1("Bilal");
    Teacher t2("Qaiser");

    // Create courses
    Course c1("Os");
    Course c2("Coal");

    c1.enrollStudent(&s1);
    c1.enrollStudent(&s2);
    c2.enrollStudent(&s2);
    c2.enrollStudent(&s3);

    c1.assignTeacher(&t1);
    c2.assignTeacher(&t2);

    c1.displayStudents();
    c1.displayTeachers();
    
    c2.displayStudents();
    c2.displayTeachers();

    s1.displayCourses();
    s2.displayCourses();
    s3.displayCourses();

    t1.displayCourses();
    t2.displayCourses();

    return 0;
}
