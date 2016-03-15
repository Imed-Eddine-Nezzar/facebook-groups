#include <stdio.h>
#include <string.h> // for string manipulation
#include <stdlib.h> // for using maloc() and free()
#include "pile.h"
#include "util.h"
#include "postfix.h"

void AfficherPile (TPile * sommet) {
    TPile * courant;
    int i;
    printf("\n----- Contenu de la pile -----\n");
    for (courant = sommet, i = 0; courant != NULL; i++, courant = courant->suiv){
        printf("element en position %d: %d\n", i, courant->nb);
    }
    printf("---------------Fin--------------\n\n");
}

int main(void) {
    TPile * sommet;
    int nb;
    char Type;
    sommet = InitPile(sommet);
    do {
        Type = LireNombreOperateur(&nb);
        sommet = postfixe(sommet, Type, nb);
        AfficherPile(sommet);
    } while (Type != '.');
    if (! PileVide(sommet)) printf("\nRESULTAT = %d\n", sommet->nb);
    else printf("operation non valide\n");
    return 0;
}
