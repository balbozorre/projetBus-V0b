#ifndef LIGNEBUS_H_INCLUDED
#define LIGNEBUS_H_INCLUDED

#include <stdbool.h>
#include "types.h"

Tbus creeBus( int idBus, TlisteStation start );
Tstation *creeArret( int posX, int posY, char* nomStation, int idStation, int coutM, t_date dateDerniereM);
Tstation *creeTroncon( int idLigneBus, Tstation* depart, Tstation *arrivee, int coutTemps, int coutDistance, int coutM, t_date dateDerniereM);

//TlisteStation* initReseauLignesDeBus(int *nbLignes);
TlisteStation creeLigneDeBus1(void);
TlisteStation creeLigneDeBus2(void);
TlisteStation creeLigneDeBus3(void);
void afficheConsoleLigneBus( TlisteStation l);

TlisteStation getNextStation( TlisteStation l);
TlisteStation getNextTroncon( TlisteStation l);
TlisteStation getPreviousStation( TlisteStation l);
bool ligneBusVide( TlisteStation l);

int getPosXListeStation( TlisteStation myStationInListe );
int getPosYListeStation( TlisteStation myStationInListe );

//renseigne incX et incY pour le d�placement du sprite dans le main, ET modifie la position du bus qd il atteint les coord X Y de la station d'arriv�e
void deplaceBus(Tbus myBus, TsensParcours sens_deplacement, int *incX, int *incY);

void busSurStation( Tbus myBus, TlisteStation myStation, TsensParcours sens);
void busSurLigneX( Tbus myBus, int idLigneX );
TlisteStation stationSuivantePourLeBus(Tbus myBus);

void afficheCoordonneesBus( Tbus myBus );

// ****   Lister ci-dessous vos fonctions  ****

//fonctions generales
t_date creerDate();
int calculDistance(Tstation *a, Tstation *b);

//sauvegarde et chargement via un fichier
int sauvegardeLigne(TlisteStation ligne, TlisteStation positionBus);
int sauvegardeBus(Tbus bus);
void sauvegarde(TlisteStation ligne, Tbus bus);
int chargement(Tbus bus, TlisteStation ligne);

#endif // LIGNEBUS_H_INCLUDED
