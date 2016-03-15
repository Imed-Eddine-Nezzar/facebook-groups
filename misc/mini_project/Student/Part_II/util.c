#ifndef UTIL_C
#define UTIL_C
#include "util.h"

int VerifierNombre(char *ch, int *nb) {
    char type;
    int i = 0;
    *nb = 0;
    while (ch[i] != '\0') {
        if ((ch[i] >= '0') && (ch[i] <= '9')) {
            *nb = *nb * 10 + ch[i] - '0';
        } else if (ch[i] == '-'){
            *nb = (*nb) * -1;
            return 1;
        } else {
            return 0;
        }
        i++;
    }
    return 1;
}

int VerifierOperateur (char *ch) {
    if (strlen(ch) == 1) {
        if ( (ch[0] == '+') || (ch[0] == '-') || (ch[0] == '*') || (ch[0] == '/') ) {
            return 1;
        } else {
            return 0;
        }
    }
    return 0;
}

char LireNombreOperateur (int *nb) {
    char ch[10];
    char Type;
    printf("donner un numbre ou un operateur: ");
    scanf("%s", ch);
    if (VerifierOperateur(ch)) return ch[0];
    else if (VerifierNombre(ch, nb)) return 'N';
    else return '.';
}

#endif
