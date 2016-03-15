// Copyright (c) 2016 Imed Eddine Nezzar.
#include <stdio.h>
#define true 1
#define false 0

void swap(int* a, int* b);              // helper function to swap values
void bubble_sort   (int v[], int size); // bubble sort
void insertion_sort(int v[], int size); // insertion sort
void selection_sort(int v[], int size); // selection sort

int main(void) {
    // TODO: make tests.
    return 0;
}

// helper function to swap two values
void swap(int* a, int* b) { int t = *a; *a = *b; *b = t; }

// bubble sort implementation
void bubble_sort(int v[], int size) {
    int swaped;
    int k = 0; // optimization
    do {
        swaped = false;
        for (int i = 1; i < size - k; ++i)
            if (v[i - 1] > v[i]) {
                swap(&v[i - 1], &v[i]);
                swaped = true;
            }
        ++k;
    } while (swaped);
}

// insertion sort implementation
void insertion_sort(int v[], int size) {
    for (int i = 1,  j; i < size; ++i) {
        j = i;
        while (j > 0 && v[j - 1] > v[j]) {
            swap(&v[j - 1], &v[j]);
            --j;
        }
    }
}

// selectoin sort implementation
void selection_sort(int v[], int size) {
    for (int i = 0, min = v[i]; i < size; ++i) {
        min = i;
        for (int j = i + 1; j < size; ++j) {
            if (v[j] < v[min]) min = j;
        }
        swap(&v[i], &v[min]);
    }
}
