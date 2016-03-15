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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "student.h" // include the student header file

int main (void) {
    Student *last;
    last = initStack(last); // initializing the stack

    // adding records
    last = pushStudent( "Imad Eddine", "Nezzar", "F17/12/05324", 5, last);
    last = pushStudent( "Skouliou", "Mckodi", "M12/74/90224", 8, last);

    // getting the first student information
    Student *first = getFirstStudent(last);
    printf( "First Name: %s\n"
            "Last Name: %s\n"
            "Serial Number: %s\n"
            "Group: %d\n",
            first->firstName,
            first->lastName,
            first->serialNumber,
            first->group );
    last = clearStack(last);
    return 0;
}
