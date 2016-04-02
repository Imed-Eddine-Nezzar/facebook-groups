#include <stdio.h>

void copy(FILE* in_file, FILE* out_file) {
    char cursor;
    for (cursor = fgetc(in_file); cursor != EOF; cursor = fgetc(in_file)) {
        cursor = (cursor == 'c') ? 'o' : cursor;
        fputc(cursor, out_file);
    }
}

int main() {
    // code here
    FILE* fst = fopen("./fst.txt", "r");
    FILE* snd = fopen("./snd.txt", "w");
    
    copy(fst, snd);

    fclose(fst);
    fclose(snd);
    return 0;
}
