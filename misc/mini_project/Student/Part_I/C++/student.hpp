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
#ifndef STUDENT_H
#define STUDENT_H

/****************************************************
 * Student class definition
 ***************************************************/
class Student {
    /*
     * Student object definition
     */
    public: // interface
        std::string getFirstName();
        std::string getLastName();
        std::string getSerialNumber();
        unsigned short getGroup();
    private:
        std::string firstName,
                    lastName,
                    serialNumber;
        unsigned short group;
        Student *next; // pointer to the next student object
    friend class StudentStack; // grant access to StudentStack class
};

/****************************************************
 * StudentStack class definition
 ***************************************************/
class StudentStack {
    /*
     * Container to hold the student stack
     */
    public:
        StudentStack();
        ~StudentStack();
        bool isEmpty();
        void pushStudent(
                const std::string &,
                const std::string &,
                const std::string &,
                const unsigned short &);
        void popStudent();
        Student *getFirstStudent();
        int getStudentCount();

    private:
        int studentCount;
        Student *first,
                *last;
};

#include "student.cpp"
#endif
