#ifndef _combat_h_
#define _combat_h_
#include<stdlib.h>
#include<stdio.h>
#include "objet.h"


typedef struct str_paquet {
	carte card;
	struct str_paquet *suiv;
} *paquet, strPaquet;

paquet paquetVide();
paquet ajouterCarte(paquet,carte);
paquet supprimerCarte(paquet);
carte sommetPaquet(paquet);
Bool testVide(paquet);
paquet rotationPaquet(paquet);

paquet paquetGen(inventaire);
int combat(monstre,hero);
int bataille(monstre,hero);

#endif
