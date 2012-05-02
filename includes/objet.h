#ifndef _objet_h_
#define _objet_h_
#include <stdlib.h>
#include <stdio.h>
#include "inventaire.h"

typedef unsigned int Bool;
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

typedef struct Coffre{
	Bool ouvert;
	enum tresor t;
	int pieces;
	inventaire inv;
	enum bonus B;
}str_coffre,*coffre;
//fin coffre




//debut hero
typedef struct {
    int HP;
    char* nom;
		int x;
		int y;
		int pieces;
    inventaire invHero;
} strHero,*hero ;
//fin hero


//debut monstre
typedef struct {
	int HP;
	char *nom; 
	int pieces;
	inventaire invMobs;
} *monstre, strMonstre;
//fin monstre

#endif
