#include <stdio.h>

// helper functions
void swap (int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
void printMatrixt(int m[10][10]) {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            printf(" %d ", m[i][j]);
        }
        printf("\n\n");
    }
}
int main (void) {
    int matrix[10][10];
    // fill the matrix with place holders
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            matrix[i][j] = j;
        }
    }
    printMatrixt(matrix);
    // swapping the diagonals
    int t;
    for (int i = 0, j = 9; i < 10; ++i, --j) {
        swap(&matrix[i][i], &matrix[i][j]);
    }
    printf(" ------------Swap------------\n");
    printMatrixt(matrix);
    return 0;
}
