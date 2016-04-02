#include <stdio.h>
#include <string.h>

int cast_int(char c);

int main() {
    char numbers[] = "0123456789";
    int n = sizeof(numbers) / sizeof(char);

    int freq[n - 1], x;
    memset(freq, 0, n);

    FILE* f = fopen("./text.txt", "r");

    char cursor;
    for(cursor = fgetc(f); cursor != EOF; cursor = fgetc(f)) {
        x = cast_int(cursor);
        if (x != -1)
            freq[x] += 1;
    }

    int i;
    for (i = 0; i < 10; ++i)
        printf("%c: %d\n", numbers[i], freq[i]);
    return 0;
}

int cast_int(char c) {
    char digits[] = "0123456789";
    int i;
    for (i = 0; i < 10; ++i)
        if (c == digits[i]) return i;

    return -1;
}
