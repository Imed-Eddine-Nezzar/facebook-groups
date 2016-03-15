/*
    Copyright © 2015 Imed Eddine Nezzar

    Permission is hereby granted, free of charge, to any person obtaining
    a copy of this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation
    the rights to use, copy, modify, merge, publish, distribute, sublicense,
    and/or sell copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included
    in all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
    OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
    IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
    DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
    TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
    OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#ifndef STUDENT_C
#define STUDENT_C
#include "student.hpp"

/*******************************************************
 * Student member functions implementation
 ******************************************************/
std::string Student::getFirstName() { return firstName; }
std::string Student::getLastName() { return lastName;}
std::string Student::getSerialNumber() { return serialNumber; }
unsigned short Student::getGroup() { return group; }

/*******************************************************
 * Student Stack member functions implementation
 ******************************************************/
StudentStack::StudentStack() {
    /*
     * StudentStack constructor, initialize first and last
     * to a null point (nullptr)
     */
    first = nullptr;
    last = nullptr;
    studentCount = 0;
}
StudentStack::~StudentStack() {
    /*
     * free allocated memory of student objects
     */
    if (!isEmpty()) {
        Student *temp = last;
        while (temp) {
            last = last->next;
            delete temp;
            temp = last;
        }
    }
}

bool StudentStack::isEmpty() { return first == nullptr; }

void StudentStack::pushStudent(
        const std::string &firstName,
        const std::string &lastName,
        const std::string &serialNumber,
        const unsigned short &group
        ){
    /*
     * Create and push a student object on the student stack
     */

    // creating a new student and filling the data
    Student *temp = new Student;
    temp->firstName = firstName;
    temp->lastName = lastName;
    temp->serialNumber = serialNumber;
    temp->group = group;

    // if stack is empty push student as first entry
    if (isEmpty()) {
        temp->next = last; // last = nullptr

        // the student is both the first and last
        last = temp;
        first = temp;

    } else {
        temp->next = last;
        last = temp;
    }
    // increment the counter
    ++studentCount;
}

void StudentStack::popStudent() {
    /*
     * remove the last student from the stack
     */
    if (!isEmpty()) {
        Student *temp = last;
        last = last->next;
        delete temp;
        --studentCount; // update the counter
    }
}

Student *StudentStack::getFirstStudent() {
    /*
     * return a pointer to the first student object
     */
    return first;
}
#endif

int StudentStack::getStudentCount() { return studentCount; }
