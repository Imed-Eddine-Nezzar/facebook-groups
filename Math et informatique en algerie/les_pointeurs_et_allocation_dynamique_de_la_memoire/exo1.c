#include <stdio.h>
#include <stdlib.h>

int sum (int* a, int* b) {
    return *a + *b;
}

int main(void) {
    int* p;
    /*
    *p = 5; // ERROR: segmentation fault
    printf("%d\n", *p);
    */
    p = (int*)malloc(sizeof(int));
    printf("%d\n", *p);
    
    *p = 30;
    printf("%d\n", *p);
    
    int (*pf)(int*, int*) = &sum;
    
    int* a = (int*)malloc(sizeof(int)); *a = 10;
    int* b = (int*)malloc(sizeof(int)); *b = 15;
    int res = (*pf)(a, b);
    printf("%d\n", res);
    
    free(p);
    free(a);
    free(b);
    return 0;
}
