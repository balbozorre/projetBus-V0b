#include "tri.h"

void swap(T_liste a, T_liste b) {
    struct T_cell *suiv_b = b->suiv;
    struct T_cell *prec_b = b->prec;

    b->prec = a->prec;
    b->suiv = a->suiv;

    a->prec = prec_b;
    a->suiv = suiv_b;
}
