#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node {
    char* string;
    struct Node* next;
} Node;

Node* make_node(const char* string, Node* next) {
    Node* n = (Node*) malloc(sizeof(Node));

    n->string = (char*) malloc(strlen(string) * sizeof(char) + 1);
    strcpy(n->string, string);
    n->next = next;

    return n;
}

void destroy_node(Node* n) {
    free(n->string);
    free(n);
}

void append(Node** list, const char* string) {
    Node* tmp = make_node(string, *list);
    *list = tmp;
}

void destroy_list(Node* list) {
    if (list != NULL && list->next == NULL)
        destroy_node(list);
    else destroy_list(list->next);
}

Node* as_linked(char** arr, int size) {
    Node* list = NULL;
    while (size--)
        append(&list, arr[size]);

    return list;
}

void print_list(const Node* list) {
    if (list != NULL) {
        printf("%s\n", list->string);
        print_list(list->next);
    }
}

int main() {
    int size = 5;
    char* strings[] = {"hello", "world", "happy", "birth", "day"};
    Node* list = as_linked(strings, size);
    print_list(list);
    destroy_list(list);
    return 0;
}
