#ifndef __objet_h_
#define __objet_h_
#include <stdlib.h>
#include <stdio.h>
#include "global.h"

#define TAILLE_INVENTAIRE 50
#define NOMBRE_DE_CARTES 10

//coffre
enum tresor {
	OR,
	BONUS,
};

enum bonus {
    BONUS1,
    BONUS2,
    BONUS3,
};

typedef struct {
	Bool ouvert;
	enum tresor t;
	union contenu {
		int po;
		enum bonus B;
  } contenu;
}coffre;
//fin coffre


//type carte
typedef struct { 
	int attaque;
	int defense;
	int HP;
} carte; 

//type inventaire
typedef struct {
	carte card[TAILLE_INVENTAIRE];
	int occupe;
} *inventaire, str_inventaire;


//debut hero
typedef struct {
    int HP;
    char * nom;
    inventaire invHero;
} *hero, strHero;
//fin hero


//debut monstre
typedef struct {
	int HP;
	char *nom; 
	inventaire invMobs;
} *monstre, strMonstre;
//fin monstre

#endif
