#ifndef PILE_C
#define PILE_C

#include "pile.h"

TPile *InitPile(TPile * sommet) {
    sommet = NULL;
    return sommet;
}
int PileVide (TPile * sommet) {
    return (sommet == NULL);
}

TPile * Emplier(TPile * sommet, int nb) {
    TPile * nouveau;
    nouveau = (TPile*) malloc(sizeof(TPile));
    if (nouveau == NULL)
        printf("Erreur d'allocation de memoire -- pile plaine\n");
    else {
        nouveau->nb = nb;
        nouveau->suiv = sommet;
        sommet = nouveau;
    }
    return sommet;
}

TPile * Depiler (TPile * sommet, int * nb) {
    TPile * elmt;
    if (PileVide(sommet)) exit(1);
    else {
        elmt = sommet;
        *nb = elmt->nb; // <-- memory leak
        sommet = elmt->suiv;
    }
    return sommet;
}

#endif
