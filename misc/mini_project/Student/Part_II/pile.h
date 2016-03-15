#ifndef PILE_H
#define PILE_H

typedef struct sElement {
    int nb;
    struct sElement *suiv;
} TPile;

TPile * InitPile (TPile * sommet);
int PileVide (TPile * sommet);
TPile * Empiler (TPile * sommet, int nb);
TPile * Depiler (TPile * sommet, int * nb);
void AfficherPile (TPile * sommet);

#include "pile.c"
#endif
