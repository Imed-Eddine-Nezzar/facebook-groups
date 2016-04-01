#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FIELD_LENGTH 30

typedef struct Student {
    int id;
    char full_name[MAX_FIELD_LENGTH];
    int groupe;
    float score;
} Student;

Student* init_student(int id, char* full_name, int groupe, float score) {
    Student* s = (Student*) malloc(sizeof(Student));

    s->id = id;
    strncpy(s->full_name, full_name, MAX_FIELD_LENGTH);
    s->groupe = groupe;
    s->score = score;

    return s;
}

void destroy_student(Student* s) { free(s); }

void destroy_students_list(Student* list[], int list_size) {
    while (list_size--) destroy_student(list[list_size]);
}

void display_student(Student* s) {
    printf(
        "\nStudent\n"
        "=======\n"
        "ID: %d\n"
        "Name: %s\n"
        "Groupe: %d\n"
        "Score: %.2f\n",
        s->id,
        s->full_name,
        s->groupe,
        s->score);
}

void find(Student* student_list[], int list_size, int groupe) {
    int i;
    for (i = 0; i < list_size; ++i) {
        if (student_list[i]->groupe == groupe
            && student_list[i]->score < 10) {
            display_student(student_list[i]);
        }
    }
}

int main() {
    const int students_count = 3;
    Student* students_list[students_count];

    char name[30];
    int groupe;
    float score;

    int i;
    for (i = 0; i < students_count; ++i) {
        printf("\nName: "); scanf("%29s", name);
        printf("Groupe: "); scanf("%d", &groupe);
        printf("Score: "); scanf("%f", &score);

        students_list[i] = init_student(i, name, groupe, score);
    }

    find(students_list, students_count, 2);

    destroy_students_list(students_list, students_count);

    return 0;
}
