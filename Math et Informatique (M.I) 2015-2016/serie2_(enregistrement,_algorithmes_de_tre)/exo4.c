#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char** string;

int min(string list[], int list_size) {
    int m = 0,
        i;
    for (i = 1; i < list_size; ++i) {
        if (strcmp(*list[i-1], *list[i]) < 0)
            m = i;
    }
    return m;
}

void swap(string s1, string s2) {
    char* t = *s1;
    *s1 = *s2;
    *s2 = t;
}

void selection_sort(string list[], int list_size) {
    int i, j, min;
    for (i = 0; i < list_size; ++i) {
        min = i;
        for (j = i; j < list_size; ++j) {
            if (list[i] < list[min])
                min = j;
        }
        swap(list[i], list[min]);
    }
}

int main() {
    // code goes here
    return 0;
}
