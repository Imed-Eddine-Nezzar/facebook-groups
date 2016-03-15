#include <iostream>
#include <vector>
using namespace std;


class Student {
    /*
        Student class:
        ==============
    */

public:
    int id;
    double exam, td, tp; 

    // student constructor
    Student(int id, int exam, int td, int tp) :
            id(id), exam(exam), td(td), tp(tp) {}

    inline double computeAverage() { 
        return ( ( exam * 0.6 + (td / 2 + tp) * 0.4) / 2);
    }
};

double sectionAverage(vector<Student> section) {
    /*
        Compute and return the Average of scores in
        the given section (vector)
    */
    // Sanity check
    if (section.empty()) return 0;
    double total = 0;
    for (vector<Student>::iterator student = section.begin();
         student != section.end();
         ++student) {

        total += student->computeAverage();
    }
    return total / section.size();
}

double search(vector<Student> section, int id) {
    /*
        Search vector (section) for the student (id)
        returns students average if found else returns
        -1 (not found)
    */
    for (vector<Student>::iterator student = section.begin();
         student != section.end();
         ++student) {

        if (student->id == id)
            return student->computeAverage();
    }
    return -1;
}

/**************************************************************
* Main
**************************************************************/
int main(void) {
    // code goes here
    return 0;
}