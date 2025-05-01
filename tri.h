#ifndef TRI_H_INCLUDED
#define TRI_H_INCLUDED

#include <stdbool.h>
#include "types.h"

int comparer_maintenance(Tstation *a, Tstation *b);
int comparer_date_maintenance(Tstation *a, Tstation *b);
void trier_liste_station(T_liste *liste, int (*compar)(Tstation*, Tstation*));
void afficher_liste(T_liste liste);



#endif // TRI_H_INCLUDED
