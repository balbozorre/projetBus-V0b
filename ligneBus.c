#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "types.h"
#include "ligneBus.h"
#include "listeDouble.h"


Tbus creeBus( int idBus, TlisteStation start ){
    Tbus myBus = (Tbus)malloc(sizeof(Typebus));
    myBus->idBus = idBus;
    busSurStation( myBus, start, depart_vers_arrivee);
    busSurLigneX ( myBus, getIdLigneTroncon(getPtrData(getNextTroncon(start))));
    return myBus;
}


Tstation *creeArret( int posX, int posY, char* nomStation, int idStation, int coutM, t_date dateDerniereM){
    Tstation* newStation = (Tstation*)malloc(sizeof(Tstation));

    newStation->arret_ou_troncon = ARRET;

    //champs utiles si ARRET
    newStation->posX = posX;
    newStation->posY = posY;
    strcpy(newStation->nomStation, nomStation);
    newStation->idStation = idStation;

    //champs non utiles si ARRET
    newStation->depart = NULL;
    newStation->arrivee = NULL;
    newStation->coutTemps = 0;
    newStation->coutDistance = 0;
    newStation->idLigneBus= -1;  //id inexistant
    //Ajouts
    newStation->coutMaintenance = coutM;
    newStation->dateDerniereMaintenance = dateDerniereM;

    return newStation;
}

Tstation *creeTroncon(int idLigneBus, Tstation* depart, Tstation *arrivee, int coutTemps, int coutDistance, int coutM, t_date dateDerniereM){
    Tstation* newStation = (Tstation*)malloc(sizeof(Tstation));

    newStation->arret_ou_troncon = TRONCON;

    //champs non utiles si TRONCON
    newStation->posX = 0;
    newStation->posY = 0;
    strcpy(newStation->nomStation, "");
    newStation->idStation = -1;  //id inexistant

    //champs utiles si TRONCON
    newStation->idLigneBus=idLigneBus;
    newStation->depart = depart;
    newStation->arrivee = arrivee;
    newStation->coutTemps = coutTemps;
    newStation->coutDistance = coutDistance;
    //Ajouts
    newStation->coutMaintenance = coutM;
    newStation->dateDerniereMaintenance = dateDerniereM;

    return newStation;
}

//genere une date aleatoire
t_date creerDate(){
    t_date a = {getRandomValue(1, 31), getRandomValue(1, 12), getRandomValue(2000, 2025)};
    return a;
}

//calcule la distance entre deux stations
int calculDistance(Tstation *a, Tstation *b) {
    int x = getPosXStation(b) - getPosXStation(a);
    int y = getPosYStation(b) - getPosYStation(a);
    return sqrt(x*x + y*y);
}

TlisteStation creeLigneDeBus1(){
    TlisteStation newLigne;
    Tstation *dep,*troncon,*arr;
    int distance;

    initListe(&newLigne);

    //creation en m_moire des stations et troncons
    //modif
    dep = creeArret(10,10,"Charles de Gaulle",1, getRandomValue(10, 100), creerDate());
    arr = creeArret(300,400,"Jules Ferry",2, getRandomValue(10, 100), creerDate());
    distance = calculDistance(dep, arr);
    troncon = creeTroncon(1,dep,arr,distance,distance, getRandomValue(10, 100), creerDate());

    //ajout de ces stations et troncons dans la liste doublement chain_e  (champ pdata)
    newLigne = ajoutEnFin(newLigne, dep);  //donc la t_te)
    newLigne = ajoutEnFin(newLigne, troncon);
    newLigne = ajoutEnFin(newLigne, arr);

    dep = creeArret(10,410,"Jacques Brel",3, getRandomValue(10, 100), creerDate());
    distance = calculDistance(arr, dep);
    troncon = creeTroncon(1,arr,dep,40,160, getRandomValue(10, 100), creerDate());
    newLigne = ajoutEnFin(newLigne, troncon);
    newLigne = ajoutEnFin(newLigne, dep);

    arr = creeArret(200,350,"Saint Exupery",4, getRandomValue(10, 100), creerDate());
    distance = calculDistance(dep, arr);
    troncon = creeTroncon(1,dep,arr,45,200, getRandomValue(10, 100), creerDate());
    newLigne = ajoutEnFin(newLigne, troncon);
    newLigne = ajoutEnFin(newLigne, arr);

    dep = creeArret(500,410,"Stalingrad",5, getRandomValue(10, 100), creerDate());
    distance = calculDistance(arr, dep);
    troncon = creeTroncon(1,arr,dep,40,160, getRandomValue(10, 100), creerDate());
    newLigne = ajoutEnFin(newLigne, troncon);
    newLigne = ajoutEnFin(newLigne, dep);

    return newLigne;
}


TlisteStation creeLigneDeBus2(){
    TlisteStation newLigne;
    Tstation *dep,*troncon,*arr;

    initListe(&newLigne);

    //creation en m_moire des stations et troncons
    dep = creeArret(10,100,"Republique",6, getRandomValue(10, 100), creerDate());
    arr = creeArret(30,300,"Jules Ferry",7, getRandomValue(10, 100), creerDate());
    troncon = creeTroncon(2,dep,arr,35,280, getRandomValue(10, 100), creerDate());

    //ajout de ces stations et troncons dans la liste doublement chain_e  (champ pdata)
    newLigne = ajoutEnFin(newLigne, dep);  //donc la t_te)
    newLigne = ajoutEnFin(newLigne, troncon);
    newLigne = ajoutEnFin(newLigne, arr);

    dep = creeArret(100,40,"PLace d'armes",8, getRandomValue(10, 100), creerDate());
    troncon = creeTroncon(2,arr,dep,40,160, getRandomValue(10, 100), creerDate());
    newLigne = ajoutEnFin(newLigne, troncon);
    newLigne = ajoutEnFin(newLigne, dep);

    arr = creeArret(300,30,"Place de l'etoile",9, getRandomValue(10, 100), creerDate());
    troncon = creeTroncon(2,dep,arr,45,200, getRandomValue(10, 100), creerDate());
    newLigne = ajoutEnFin(newLigne, troncon);
    newLigne = ajoutEnFin(newLigne, arr);

    dep = creeArret(400,210,"Bobigny",10, getRandomValue(10, 100), creerDate());
    troncon = creeTroncon(2,arr,dep,40,160, getRandomValue(10, 100), creerDate());
    newLigne = ajoutEnFin(newLigne, troncon);
    newLigne = ajoutEnFin(newLigne, dep);

    return newLigne;
}

TlisteStation creeLigneDeBus3(){
    TlisteStation newLigne;
    Tstation *dep,*troncon,*arr;


    initListe(&newLigne);


    //creation en m_moire des stations et troncons

    dep = creeArret(150,10,"Clemenceau",11, getRandomValue(10, 100), creerDate());
    arr = creeArret(300,100,"Montmartre",12, getRandomValue(10, 100), creerDate());
    troncon = creeTroncon(3,dep,arr,35,280, getRandomValue(10, 100), creerDate());

    //ajout de ces stations et troncons dans la liste doublement chain_e  (champ pdata)
    newLigne = ajoutEnFin(newLigne, dep);  //donc la t_te)
    newLigne = ajoutEnFin(newLigne, troncon);
    newLigne = ajoutEnFin(newLigne, arr);

    dep = creeArret(600,610,"Tour eiffel",13, getRandomValue(10, 100), creerDate());
    troncon = creeTroncon(3,arr,dep,40,160, getRandomValue(10, 100), creerDate());
    newLigne = ajoutEnFin(newLigne, troncon);
    newLigne = ajoutEnFin(newLigne, dep);

    arr = creeArret(70,350,"Les invalides",14, getRandomValue(10, 100), creerDate());
    troncon = creeTroncon(3,dep,arr,45,200, getRandomValue(10, 100), creerDate());
    newLigne = ajoutEnFin(newLigne, troncon);
    newLigne = ajoutEnFin(newLigne, arr);

    dep = creeArret(150,510,"Gare du nord",15, getRandomValue(10, 100), creerDate());
    troncon = creeTroncon(3,arr,dep,40,160, getRandomValue(10, 100), creerDate());
    newLigne = ajoutEnFin(newLigne, troncon);
    newLigne = ajoutEnFin(newLigne, dep);

    return newLigne;
}


void afficheConsoleLigneBus( TlisteStation l){
    afficheListe(l);
}

TlisteStation getNextStation( TlisteStation l){
    if (ligneBusVide(l)) return NULL;
    else {
            if (getTypeNoeud(getPtrData(l))==ARRET) {
                    if (ligneBusVide( getNextCell(l) )) return NULL;  //nous sommes sur un terminus
                    else return getNextCell( getNextCell( l ) );  //le prochain arret est dans 2 cellules dans la liste, la cellule suivaante �tant un TRONCON
            }
            else return getNextCell( l );  //si on est sur un TRONCON alors la prochaine cellule est la prochaine station (ARRET)
    }
}

TlisteStation getNextTroncon( TlisteStation l){
    if (ligneBusVide(l)) return NULL;
    else {
            if (getTypeNoeud(getPtrData(l))==ARRET) {
                return getNextCell(l);  //la prochaine cellule est un TRONCON, peut �tre �gale � NULL si on est sur un terminus
            }
            else{
                    printf("\n(getNextTroncon) erreur algo, on est deja sur un troncon");
                    return l;  //on retourne le troncon actuel
            }
    }
}

TlisteStation getPreviousStation( TlisteStation l){
    if (ligneBusVide(l)) return NULL;
    else {
            if (getTypeNoeud(getPtrData(l))==ARRET) {
                    if (ligneBusVide( getPrevCell(l) )) return NULL;  //nous sommes sur un terminus
                    return getPrevCell( getPrevCell( l ) );  //le prochain arret est dans 2 cellules dans la liste, la cellule suivaante �tant un TRONCON
            }
            else return getPrevCell( l );  //si on est sur un TRONCON alors la prochaine cellule est la prochaine station (ARRET)
    }
}

bool ligneBusVide( TlisteStation l){
    return listeVide( l );
}

int getPosXListeStation( TlisteStation myStationInListe ){
    return getPosXStation(getPtrData(myStationInListe));
}

int getPosYListeStation( TlisteStation myStationInListe ){
    return getPosYStation(getPtrData(myStationInListe));
}

void deplaceBus(Tbus myBus, TsensParcours sens_deplacement, int *incXSprite, int *incYSprite){
    TlisteStation dest;
    int xdep, ydep, xarr, yarr, pas;
    float ratio;
    pas = 2;  //�quivalent au parametre d'erreur dans le trac� de Segment de Bresenham
    //https://fr.wikipedia.org/wiki/Algorithme_de_trac%C3%A9_de_segment_de_Bresenham


    if (sens_deplacement == depart_vers_arrivee) dest = getNextStation(getActualStation(myBus));
        else dest = getPreviousStation(getActualStation(myBus));

    //par d�faut: pas de d�placement du bus
    *incXSprite = 0; *incYSprite = 0;

    //si un prochain arret existe?
    if (ligneBusVide(dest)){
        //printf("\nBus id%d est au terminus de la ligne %d sur la station id=%d %s", getIdBus(myBus), getIdLigneActuelleDuBus(myBus),getIdStation(getPtrData(getActualStation(myBus))),getNomStation(getPtrData(getActualStation(myBus))));
    }
    else //s'il existe:
    {
        //soit on est arriv�, soit on est en cours de trajet
        //r�cup�ration des coordonn�es
        xdep = getPosXBus(myBus);
        ydep = getPosYBus(myBus);
        xarr = getPosXListeStation(dest);
        yarr = getPosYListeStation(dest);

        //sommes-nous arriv�s?
        if ((abs(xdep-xarr)<=pas) && (abs(ydep-yarr)<=pas)){
            //alors mise � jour de la station actuelle du bus
            setActualStation( myBus, dest );
            printf("\nLe Bus id%d arrive sur la station id%d %s",getIdBus(myBus),getIdStation(getPtrData(getActualStation(myBus))),getNomStation(getPtrData(getActualStation(myBus))));
        }
        else{
            //sinon on calcule les offsets de d�placements pour la boucle main qui r�alise les affichages
            ratio = (float)(abs(yarr-ydep))/(float)(abs(xarr-xdep)); //div euclydienne

            //algo de Bresenham "simplifi� de fa�on ad hoc" et non optimis� (� cause des floats)
            if (xarr>xdep) *incXSprite = pas;
            else if (xarr<xdep) *incXSprite = -pas;

            if (yarr>ydep) *incYSprite = (int)((float)(pas) * ratio);             //pour un d�placement proportionnel en Y selon Y/X
            else if (yarr<ydep) *incYSprite = (int)((float)(-pas) * ratio);

            //remmarque: si xarr==ydep alors *incXSprite reste � 0, idem en Y

            //maj des coord du bus
            setPosXBus(myBus, getPosXBus(myBus) + *incXSprite);
            setPosYBus(myBus, getPosYBus(myBus) + *incYSprite);
        }
    }
}

//Setteurs
void setActualStation( Tbus myBus, TlisteStation arrivalStation );
void setPosXBus(Tbus myBus, int newX);
void setPosYBus(Tbus myBus, int newY);
void setIdLigneBus(Tbus myBus, int idLigne);
void setSensParcours(Tbus myBus, TsensParcours sens );

void setPositionSurLaLigneDeBus( Tbus myBus, TlisteStation myStation);


void busSurStation( Tbus myBus, TlisteStation myStation, TsensParcours sens){

    //Exemple encapsulation: on a pr�f�r� les fonctions setteurs � un acc�s direct aux champs

    setPositionSurLaLigneDeBus( myBus, myStation);
    //myBus->positionSurLaLigneDeBus = myStation;  //interdit

    setSensParcours( myBus, sens);
    //myBus->sensParcours = sens;

    setPosXBus( myBus, getPosXListeStation( myStation ) );
    //myBus->posXBus = getPosXListeStation( myStation );

    setPosYBus( myBus, getPosYListeStation( myStation ) );
    //myBus->posYBus = getPosYListeStation( myStation );

    //idem : on passe ci-dessous par les getteurs et non par un acc�s direct via les champs
    printf("\nBus id%d est en (x = %d, y = %d) sur la ligne %d, station %s", getIdBus(myBus), getPosXBus(myBus), getPosYBus(myBus), getIdLigneActuelleDuBus(myBus), getNomStation(getPtrData(myStation)));
}

void busSurLigneX( Tbus myBus, int idLigneX ){
    setIdLigneBus(myBus, idLigneX);
}

TlisteStation stationSuivantePourLeBus(Tbus myBus){
    TlisteStation prochaineStation;
    if (getSensParcours(myBus)==depart_vers_arrivee) prochaineStation = getNextStation(getActualStation(myBus));
    else prochaineStation = getPreviousStation(getActualStation(myBus));
    return prochaineStation;
}

void afficheCoordonneesBus( Tbus myBus ){
    char *nomProchaineStation;
    TlisteStation prochaineStation = stationSuivantePourLeBus(myBus);

    if (ligneBusVide(prochaineStation)) printf("\nBus id: %d est en (x = %d, y = %d) ligne %d, derniere station %s (Terminus)", getIdBus(myBus), getPosXBus(myBus), getPosYBus(myBus), getIdLigneActuelleDuBus(myBus), getNomStation(getPtrData(getActualStation(myBus))));
    else {
            nomProchaineStation = getNomStation(getPtrData(prochaineStation));
            printf("\nBus id: %d est en (x = %d, y = %d) ligne %d, derniere station %s, prochaine station %s", getIdBus(myBus), getPosXBus(myBus), getPosYBus(myBus), getIdLigneActuelleDuBus(myBus), getNomStation(getPtrData(getActualStation(myBus))), nomProchaineStation);
    }
}


//Cr�er ci-dessous vos fonctions

#define fichier "sauvegarde.data"
#define erreur "log.txt"

/*
structure du fichier de sauvegarde :
    #   structure Typebus

    #   entier nbr_station
    #   nbr_station x Tstation

    #   entier nbr_station
    #   nbr_station x Tstation

    #   entier nbr_station
    #   nbr_station x Tstation
    #   ...
*/

//ecrit dans le fichier de sauvegarde les donnees des station d'une ligne, à la suite de la structure Typebus.
//les stations sont dans l'ordre, ce qui permettra de reconstituer la liste chainee lors du chargement.
//la position actuelle du bus est passee en parametre afin de l'enregistrer dans le fichier.
int ecritureLigne(TlisteStation ligne, TlisteStation positionBus) {
    FILE *f_save = fopen(fichier, "ab");
    TlisteStation position = ligne;
    int nbr_station = 0;

    if(f_save == NULL) {
        FILE *f_log = fopen(erreur, "w");
        fprintf(f_log, "Erreur a l'ouverture du fichier %s dans la fonction sauvegardeLigne\n", fichier);
        fclose(f_log);

        return EXIT_FAILURE;
    }

    printf("\nok6\n");

    //calcul du nombre de station
    while(position != NULL) {
        nbr_station++;
        position = position->suiv;
    }

    position = ligne;

    //ecriture du nombre de station dans le fichier avant les stations
    fwrite(&nbr_station, sizeof(int), 1, f_save);

    printf("\nok7\n");
    int nbr = 0;

    while(position != NULL) {
        Tstation copie = *(position->pdata);
        nbr++;
        printf("sauvegarde station %d\n", nbr);

        //on met la valeur null dans les pointeurs pour eviter de charger des pointeur incorrects
        copie.arrivee = NULL;
        copie.depart = NULL;

        //si le bus etait sur cet emplacement, on laisse une valeur dans le pointeur.
        //le pointeur prendra ensuite une valeur valide lors de la constitution de la liste chainee
        if(position == positionBus) {
            copie.depart = &copie;
        }

        //ecrit le contenu de la structure Tstation dans le fichier de sauvegarde
        fwrite(&copie, sizeof(Tstation), 1, f_save);

        position = position->suiv;
    }

    fclose(f_save);
    return EXIT_SUCCESS;
}

int ecritureBus(Tbus bus) {
    FILE *f_save = fopen(fichier, "wb");

    if(f_save == NULL) {
        FILE *f_log = fopen(erreur, "w");
        fprintf(f_log, "Erreur a l'ouverture du fichier %s dans la fonction sauvegardeBus\n", fichier);
        fclose(f_log);

        return EXIT_FAILURE;
    }

    printf("\nok1\n");

    Typebus copie = *bus;
    printf("\nok2\n");
    //suppression du pointeur pour ne pas enregistrer un pointeur incorrect
    copie.positionSurLaLigneDeBus = NULL;
    printf("\nok3\n");
    fwrite(&copie, sizeof(Typebus), 1, f_save);
    printf("\nok4\n");

    fclose(f_save);
    return EXIT_SUCCESS;
}

//ecrit le contenu des structures Tbus et TlisteStation dans cet ordre.
void sauvegarde(TlisteStation ligne, Tbus bus) {
    TlisteStation positionBus = bus->positionSurLaLigneDeBus;
    printf("\nok-1\n");
    ecritureBus(bus);
    printf("\nok5\n");
    ecritureLigne(ligne, positionBus);
}

int lectureBus(Tbus bus) {
    FILE *f_save = fopen(fichier, "rb");

    if(f_save == NULL) {
        FILE *f_log = fopen(erreur, "w");
        fprintf(f_log, "Erreur a l'ouverture du fichier %s dans la fonction chargement\n", fichier);
        fclose(f_log);
        return EXIT_FAILURE;
    }

    fread(bus, sizeof(Tbus), 1, f_save);;

    fclose(f_save);
    return EXIT_SUCCESS;
}

int lectureLigne(TlisteStation ligne, Tbus bus) {
    FILE *f_save = fopen(fichier, "rb");
    int nbr_station = 0;
    Tstation *last_station = NULL;
    TlisteStation last_cell = NULL;

    if(f_save == NULL) {
        FILE *f_log = fopen(erreur, "w");
        fprintf(f_log, "Erreur a l'ouverture du fichier %s dans la fonction chargement\n", fichier);
        fclose(f_log);
        return EXIT_FAILURE;
    }

    effacerListe(ligne);
    fread(&nbr_station, sizeof(int), 1, f_save);

    //cette boucle va lire chaque station de la ligne dans le fichier, puis recreer la liste
    //chainee a partir de ces informations
    for(int i=0; i<nbr_station; i++) {
        Tstation *sauv_station = (Tstation *)malloc(sizeof(Tstation));
        T_cellule* cell = malloc(sizeof(T_cellule));

        fread(sauv_station, sizeof(Tstation), 1, f_save);

        //associe la liste chainee a la variable de la ligne passee en parametre
        if(i == 0) {
            ligne = cell;
        }
        //lie le bus a son ancienne position sur la ligne
        if(sauv_station->depart) {
            bus->positionSurLaLigneDeBus = cell;
        }
        //on met l'adresse de la station precedente dans le champ depart s'il s'agit d'un troncon
        if(getTypeNoeud(sauv_station) == TRONCON) {
            sauv_station->depart = last_station;
        }
        //on met l'adresse de la station actuelle dans le champ arrivee du troncon d'avant
        if(getTypeNoeud(sauv_station) == ARRET && i>0) {
            last_station->arrivee = sauv_station;
            //ce NULL sert juste a eviter des problemes si le bus était arrêté ici,
            //car on modifie le pointeur pour marquer l'emplacement du bus
            sauv_station->depart = NULL;
        }

        //information de la liste chainee pour la cellule N et N-1
        cell->pdata = sauv_station;
        cell->suiv = NULL;
        cell->prec = last_cell;
        last_cell->suiv = cell;

        //mise a jour des pointeurs pour la cellule N-1
        last_station = sauv_station;
        last_cell = cell;
    }

    fclose(f_save);
    return EXIT_SUCCESS;
}

//lit dans le fichier de sauvegarde les donnees du bus et des lignes.
int chargement(Tbus bus, TlisteStation ligne) {
    lectureBus(bus);
    lectureLigne(ligne, bus);

    return EXIT_SUCCESS;
}


//############################## question 5 #########################################


int concatenationLignes(TlisteStation A, TlisteStation B) {
    if(B == NULL || B->pdata == NULL || A == NULL || A->pdata == NULL) {
        FILE *f_log = fopen(erreur, "w");
        fprintf(f_log, "erreur dans concatenation Lignes : l'une des lignes ne contient rien\n");
        fclose(f_log);

        return EXIT_FAILURE;
    }

    TlisteStation pos = A;

    while(pos->suiv != NULL) {
        pos = pos->suiv;
    }

    Tstation *troncon = NULL;
    Tstation *data = getPtrData(pos);

    if(data->arret_ou_troncon == TRONCON) {
        FILE *f_log = fopen(erreur, "w");
        fprintf(f_log, "erreur dans concatenationLignes : la ligne se termine par un troncon\n");
        fclose(f_log);

        return EXIT_FAILURE;
    }
    else if(data->arret_ou_troncon == ARRET && pos->prec != NULL && B->pdata->arret_ou_troncon == ARRET) {
        Tstation *prec_troncon = pos->prec->pdata;
        troncon = creeTroncon(
            getIdLigneTroncon(prec_troncon),
            pos->pdata,
            B->pdata,
            calculDistance(pos->pdata, B->pdata),
            calculDistance(pos->pdata, B->pdata),
            getRandomValue(10, 100),
            creerDate()
        );

        B = ajoutEnTete(B, troncon);
        B->prec = pos;
        pos->suiv = B;
    }

    return EXIT_SUCCESS;
}
