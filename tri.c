#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tri.h"
#include "types.h"

int comparer_maintenance(Tstation *a, Tstation *b) {
    return b->coutMaintenance - a->coutMaintenance;
}

int comparer_date_maintenance(Tstation *a, Tstation *b) {
    if (a->dateDerniereMaintenance.annee != b->dateDerniereMaintenance.annee)
        return a->dateDerniereMaintenance.annee - b->dateDerniereMaintenance.annee;
    if (a->dateDerniereMaintenance.mois != b->dateDerniereMaintenance.mois)
        return a->dateDerniereMaintenance.mois - b->dateDerniereMaintenance.mois;
    return a->dateDerniereMaintenance.jour - b->dateDerniereMaintenance.jour;
}

void trier_liste_station(T_liste *liste, int (*compar)(Tstation*, Tstation*)) {
    if (!liste || !(*liste))
        return;

    T_liste sorted = NULL;

    while (*liste) {
        T_liste current = *liste;
        *liste = (*liste)->suiv;

        current->prec = current->suiv = NULL;

        if (!sorted) {
            sorted = current;
        } else {
            T_liste temp = sorted;
            T_liste prev = NULL;

            while (temp && compar(current->pdata, temp->pdata) > 0) {
                prev = temp;
                temp = temp->suiv;
            }

            if (!prev) {
                current->suiv = sorted;
                sorted->prec = current;
                sorted = current;
            } else {
                current->suiv = prev->suiv;
                current->prec = prev;
                if (prev->suiv) prev->suiv->prec = current;
                prev->suiv = current;
            }
        }
    }

    *liste = sorted;
}

void afficher_liste(T_liste liste) {
    while (liste) {
        printf("Station %s | Cout : %d k€ | Derniere maintenance : %02d/%02d/%d\n",
            liste->pdata->nomStation,
            liste->pdata->coutMaintenance,
            liste->pdata->dateDerniereMaintenance.jour,
            liste->pdata->dateDerniereMaintenance.mois,
            liste->pdata->dateDerniereMaintenance.annee);
        liste = liste->suiv;
    }
}

