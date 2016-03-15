#include <iostream>
using namespace std;

enum Job {
    ANALYZER,
    PROGRAMMER,
    OPERATOR,
    SECRETARY
};

typedef struct Employee {
    /*
    Usage:
        Employee e = Employee("Imed Eddine", "Nezzar", 1, 22, 0, PROGRAMMER);
        e.details();

    output:
        Name: Imed Eddine Nezzar
        Age: 22
        Employee Number: 1
        Job: Programmer
    */
    private:
        string _fname, _lname;        // First Name, Last Name
        unsigned _employeeNumber;    // Employee Number (n >= 0)
        unsigned short _age;         // Age (0 <= age <= 255)
        int _assuranceNumber;        // Assurance Number
        Job _job;                    // Job (ANALYZER, PROGRAMMER, OPERATOR, SECRETARY)
    public:
        // Constructor
        Employee(string fname, string lname, unsigned employeeNumber,
                 unsigned short age, int assurenceNumber, Job job) {
            _fname = fname;
            _lname = lname;
            _employeeNumber = employeeNumber;
            _age = age;
            _assuranceNumber = assurenceNumber;
            _job = job;
        }
        void details() {
            cout << 
                "\nName: " << _fname << " " <<_lname << 
                "\nAge: " << _age <<
                "\nEmployee Number: " << _employeeNumber <<
                "\nJob: ";
            switch (_job) {
                case PROGRAMMER: cout << "Programmer"; break;
                case ANALYZER: cout << "Analyzer"; break;
                case SECRETARY: cout << "Secretary"; break;
                case OPERATOR: cout << "Operator"; break;
            }
            cout << endl;
        }
} Employee;

int main(void) {
    // Test
    Employee e = Employee("Imed Eddine", "Nezzar", 1, 22, 0, PROGRAMMER);
    e.details();
    // code goes here
    return 0;
}