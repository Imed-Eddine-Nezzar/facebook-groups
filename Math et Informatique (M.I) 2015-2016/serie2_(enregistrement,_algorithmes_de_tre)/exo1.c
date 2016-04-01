#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FIELD_LENGTH 30

typedef struct Person {
    char first_name[MAX_FIELD_LENGTH],
         last_name[MAX_FIELD_LENGTH];
    int age;
} Person;

Person* init_person(char* first_name, char* last_name, int age) {
    Person* p = (Person*) malloc(sizeof(Person));

    strncmp(p->first_name, first_name, MAX_FIELD_LENGTH);
    strncmp(p->last_name, last_name, MAX_FIELD_LENGTH);
    p->age = age;

    return p;
}

void destroy_person(Person* p) { free(p); }

int age_difference(Person* p1, Person* p2) {
    return p1->age - p2->age;
}

int main() {
    Person* p1 = init_person("Imed Eddine", "Nezzar", 23);
    Person* p2 = init_person("Oussama", "Nezzar", 18);

    printf("Age difference: %d\n", age_difference(p1, p2));

    destroy_person(p1);
    destroy_person(p2);
    return 0;
}
