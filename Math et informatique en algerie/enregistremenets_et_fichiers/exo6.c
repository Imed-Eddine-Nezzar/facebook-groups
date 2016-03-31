#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FEILD_MAX_LENGHT 30
#define LIST_SIZE 10

typedef struct Person {
    char first_name[FEILD_MAX_LENGHT],
         last_name[FEILD_MAX_LENGHT];
    unsigned short age;
} Person;

Person* make_person(
    char first_name[FEILD_MAX_LENGHT],
    char last_name[FEILD_MAX_LENGHT],
    unsigned short age
    ) {

    Person* person = (Person*) malloc (sizeof(Person));

    strncpy(person->first_name, first_name, FEILD_MAX_LENGHT);
    strncpy(person->last_name, last_name, FEILD_MAX_LENGHT);
    person->age = age;

    return person;
}

void destroy_person(Person* person) { free(person); }

void sort(Person* list[], int list_size) {
    int i = 1, k = 0;
    short swapped;
    do {
        swapped = 0;
        for(i = 1; i < list_size - k; ++i) {
            if (strcmp(list[i]->first_name, list[i-1]->first_name) < 0) {
                Person* tmp = list[i];
                list[i] = list[i - 1];
                list[i - 1] = tmp;
                swapped = 1;
            }
        }
        ++k;
    } while (swapped);
}

int main() {
    // TODO: implement this
    return 0;
}