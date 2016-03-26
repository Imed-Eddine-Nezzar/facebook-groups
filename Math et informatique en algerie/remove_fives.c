#include <stdio.h>

int main() {
    int size = 10, 
        i, arr[size];
    printf("Enter array elements (%d elements): ", size);
    for (i = 0; i < size; ++i) scanf("%d", &arr[i]);

    int j = 0;
        i = 0;
    while (j < size) {
        if (arr[j] % 5 != 0) {
            arr[i] = arr[j];
            ++i;
        }
        ++j;
    }
    size = i;
    printf("New array: ");
    for (i = 0; i < size; ++i) printf("%d ", arr[i]); printf("\n");
    return 0;
}
