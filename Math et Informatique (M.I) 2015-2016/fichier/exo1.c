#include <stdio.h>

int concate(FILE* fst_file, FILE* snd_file, FILE* out_file) {
    if (fst_file == NULL ||
        snd_file == NULL ||
        out_file == NULL)
        return 1;

    char cursor;
    for (cursor = fgetc(fst_file); cursor != EOF; cursor = fgetc(fst_file))
        fputc(cursor, out_file);

    for (cursor = fgetc(snd_file); cursor != EOF; cursor = fgetc(snd_file))
        fputc(cursor, out_file);

    return 0;
}

int main() {
    // Testing
    FILE* fst = fopen("./fst.txt", "r");
    FILE* snd = fopen("./snd.txt", "r");
    FILE* out = fopen("./out.txt", "w");

    concate(fst, snd, out);

    fclose(fst);
    fclose(snd);
    fclose(out);
    return 0;
}
