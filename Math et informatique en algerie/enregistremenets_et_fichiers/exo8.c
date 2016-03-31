#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FIELD_MAX_LENGTH 30

typedef struct Enterprise {
    unsigned id;
    char name[FIELD_MAX_LENGTH],
         grad;
    double salery;
} Enterprise;

Enterprise* make_enterprise(char name[], char grad, double salery) {
    Enterprise* e = (Enterprise*) malloc (sizeof(Enterprise));

    e->id = id;
    strncpy(e->name, name, FIELD_MAX_LENGTH);
    e->grad = grad;
    e->salery = salery;

    return e;
}

void destroy_enterprise(Enterprise* e) { free(e); }

Enterprise* filter(
    double salery_start,
    double salery_end,
    Enterprise* list[],
    int list_size
    ) {

    int i;
    for (i = 0; i < list_size; ++i) {
        if (salery_start <= list[i]->salery && 
            list[i]->salery <= salery_end)
            
            return list[i];
    }
    return NULL;
}

int main() {
    // TODO: implement this
    return 0;
}