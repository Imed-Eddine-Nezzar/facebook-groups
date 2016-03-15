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
#include "student.h"

int isEmpty(Student *last) {
    return (last == NULL);
}

Student *initStack(Student *last) {
    last = NULL;
    return last;
}

Student *pushStudent(
        char firstName[],
        char lastName[],
        char serialNumber[],
        unsigned short group,
        Student *last){
    /*
     * Create and push a student struct on the student stack
     */

    // creating a new student and filling the data
    Student *temp = (Student*)malloc(sizeof(Student));
    // copy information
    strcpy(temp->firstName, firstName);
    strcpy(temp->lastName, lastName);
    strcpy(temp->serialNumber, serialNumber);
    temp->group = group;

    // pushing the student in the stack
    temp->next = last;
    last = temp;

    // returning the stack top
    return last;
}

Student *getFirstStudent (Student *last) {
    Student *cur = last,
            *pre = last;
    while (cur != NULL) {
        pre = cur;
        cur = cur->next;
    }
    return pre;
}

Student *clearStack(Student *last) {
    /*
     * free allocated memory of student objects
     */
    Student *temp = last;
    while (temp != NULL) {
        last = last->next;
        free(temp);
        temp = last;
    }
    return NULL;
}
#endif
