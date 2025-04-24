#ifndef TRI_H_INCLUDED
#define TRI_H_INCLUDED

#include "types.h"
#include "ligneBus.h"

//fonctions utilitaires pour le tri
void swap(T_liste a, T_liste b);
bool cout_nodeAInfNodeB(Tstation *nodeA, Tstation *nodeB);
bool date_nodeAInfNodeB(Tstation *nodeA, Tstation *nodeB);

//fonctions servant au tri
/*valeur de retour à déterminer*/ quicksort(TlisteStation ligne, bool (*fcomparaison) (Tstation *nodeA, Tstation *nodeB) /*, bool mode_tri*/);
/*valeur de retour à déterminer*/ sort_ligne(TlisteStation ligne /*, bool mode_tri*/);


#endif // TRI_H_INCLUDED
