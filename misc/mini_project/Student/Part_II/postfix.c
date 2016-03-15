#ifndef POSTFIXE_C
#define POSTFIXE_C

#include "postfix.h"

TPile * postfixe (TPile * sommet, char Type, int nb) {
    int nb1, nb2;
    switch(Type) {
        case 'N':
            sommet = Emplier(sommet, nb);
            break;
        case '+':
            sommet = Depiler(sommet, &nb2);
            sommet = Depiler(sommet, &nb1);
            nb = nb1 + nb2;
            sommet = Emplier(sommet, nb);
            break;
        case '-':
            // TODO: check this snippet
            sommet = Depiler(sommet, &nb2);
            sommet = Depiler(sommet, &nb1);
            nb = nb1 - nb2;
            sommet = Emplier(sommet, nb);
            break;
        case '*':
            // TODO: check this snippet
            sommet = Depiler(sommet, &nb2);
            sommet = Depiler(sommet, &nb1);
            nb = nb1 * nb2;
            sommet = Emplier(sommet, nb);
            break;
        case '/':
            // TODO: check this snippet
            if (nb2 != 0) {
                sommet = Depiler(sommet, &nb2);
                sommet = Depiler(sommet, &nb1);
                nb = nb1 / nb2;
                sommet = Emplier(sommet, nb);
            } else exit(1);
            break;
    }
    return sommet;
}
#endif
