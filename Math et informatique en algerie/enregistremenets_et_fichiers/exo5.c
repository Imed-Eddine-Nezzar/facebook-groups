#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FIELD_SIZE 30
#define EMPLOYEE_COUNT 5

typedef struct Employee {
    int id;
    char name[MAX_FIELD_SIZE],
          state;
    double salery;
} Employee;

Employee* make_employee(
    int id,
    char name[MAX_FIELD_SIZE],
    char state,
    double salery) {

    Employee* emp = (Employee*) malloc(sizeof(Employee));

    emp->id = id;
    strcpy(emp->name, name);
    emp->state = state;
    emp->salery = salery;

    return emp;
}

void print_employee(Employee* employee) {
    printf("Name: %s\n"
           "ID: %d\n"
           "Salery: %.2f\n"
           "State: %c\n",
           employee->name,
           employee->id,
           employee->salery,
           employee->state);
}

void filter_by_salery(double base_salery, Employee* list[], int list_size) {
    int i;
    for (i = 0; i < list_size; ++i) {
        if (list[i]->salery >= base_salery && list[i]->state == 'M')
            print_employee(list[i]);
    }
}

int main() {
    // TODO: implement tests
}