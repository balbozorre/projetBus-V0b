#include "tri.h"

void swap(T_liste a, T_liste b) {
    struct T_cell *suiv_b = b->suiv;
    struct T_cell *prec_b = b->prec;

    b->prec = a->prec;
    b->suiv = a->suiv;

    a->prec = prec_b;
    a->suiv = suiv_b;
}

bool A_avant_B(t_date A, t_date B) {
    if (A.annee < B.annee)
        return true;
    else if (A.annee > B.annee)
        return false;

    if (A.mois < B.mois)
        return true;
    else if (A.mois > B.mois)
        return false;

    if (A.jour < B.jour)
        return true;

    return false;
}

bool cout_nodeAInfNodeB(Tstation *nodeA, Tstation *nodeB) {
    return *nodeA->coutMaintenance <= *nodeB->coutMaintenance;
}

bool date_nodeAInfNodeB(Tstation *nodeA, Tstation *nodeB) {
    return *nodeA->dateDerniereMaintenance <= *nodeB->coutMaintenance;
}
