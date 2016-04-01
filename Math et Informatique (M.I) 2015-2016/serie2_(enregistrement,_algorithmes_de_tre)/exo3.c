#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FIELD_LENGTH 26


typedef struct Student {
    char first_name[MAX_FIELD_LENGTH],
         last_name[MAX_FIELD_LENGTH];
    int birth_day[3];           // day / month / year
} Student;

Student* init_student(char* first_name, char* last_name, int day, int month, int year) {
    Student* s = (Student*) malloc(sizeof(Student));

    strncpy(s->first_name, first_name, MAX_FIELD_LENGTH);
    strncpy(s->last_name, last_name, MAX_FIELD_LENGTH);
    s->birth_day[0] = day;
    s->birth_day[1] = month;
    s->birth_day[2] = year;

    return s;
}

void destroy_student(Student* s) { free(s); }

void display_student(Student* s) {
    printf(
        "\nStudent\n"
        "=======\n"
        "First Name: %s\n"
        "Last Name: %s\n",
        s->first_name,
        s->last_name
    );
}

void display(Student* list[], int list_size, int month) {
    int i;
    for (i = 0; i < list_size; ++i) {
        if (list[i]->birth_day[2] == month)
            display_student(list[i]);
    }
}

int main() {
    // code goes here
    return 0;
}
