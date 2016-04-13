#include <stdio.h>
#include <stdlib.h>

void array_sum(int* fst, int* snd, int* res, int size) {
    int i;
    for (i = 0; i < size; ++i)
        res[i] = fst[i] + snd[i];
}

void print_array(int* arr, int size) {
    int i;
    for (i = 0; i < size; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

void delete_shift(int* arr, int index, int size) {
    int i;
    for (i = index; i < size - 1; ++i)
        arr[i] = arr[i + 1];
    arr[size - 1] = 0;
}

void delete_realloc(int* arr, int index, int size) {
    int i;
    for (i = index; i < size - 1; ++i)
        arr[i] = arr[i + 1];
    int* tmp = realloc(arr, (size - 1) * sizeof(int));
    arr = tmp;
}

void reset_array(int* arr, int size) {
    int i;
    for (i = 0; i < size; ++i)
        arr[i] = 0;
}

void inverse(int* arr, int size) {
    int i;
    for (i = 0; i < size; ++i)
        arr[i] = - arr[i];
}

void square(int* arr, int size) {
    int i;
    for (i = 0; i < size; ++i)
        arr[i] = arr[i] * arr[i];
}

int main(void) {
    // testing
    const int size = 5;
    int fst_arr[] = {1, 2, 3, 4, 5};
    int snd_arr[] = {5, 4, 3, 2, 1};
    int res[size];
    array_sum(fst_arr, snd_arr, res, size);
    // output result
    print_array(fst_arr, size);
    print_array(snd_arr, size);
    print_array(res, size);
    
    // allocate an array from heap
    int* dynamic = (int*) malloc (sizeof(int) * size);
    int i;
    for (i = 0; i < size; ++i) dynamic[i] = i;
    print_array(dynamic, size);
    
    // delete a value in a staticly declared array
    delete_shift(fst_arr, 2, size);
    print_array(fst_arr, size - 1);
    
    // delete a value in a dynamicly allocated array
    delete_realloc(dynamic, 1, size);
    print_array(dynamic, size - 1);
    // free memory
    free(dynamic);
    
    reset_array(fst_arr, size);
    print_array(fst_arr, size);
    
    inverse(snd_arr, size);
    print_array(snd_arr, size);
    
    square(res, size);
    print_array(res, size);
    return 0;
}
