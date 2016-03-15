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

#include <iostream>
#include "student.hpp" // include the student header file

using namespace std;

int main (void) {
    StudentStack stack; // creating a student stack

    // adding records
    stack.pushStudent( "Imad Eddine", "Nezzar", "F17/12/05324", 5);
    stack.pushStudent( "Skouliou", "Mckodi", "M12/74/90224", 8);
    // outputting the student counter
    cout << "Student count: " << stack.getStudentCount() << endl;

    // getting the first student information
    Student *first = stack.getFirstStudent();
    cout <<
        "First Name: " << first->getFirstName() <<
        "\nLast Name: " << first->getLastName() <<
        "\nSerial Number: " << first->getSerialNumber() <<
        "\nGroup: " << first->getGroup()
    << endl;

    stack.popStudent(); // removing the last student
    cout << "Student count: " << stack.getStudentCount() << endl;
    return 0;
}
