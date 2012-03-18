#ifndef __objet_h_
#define __objet_h_
#include <stdlib.h>
#include <stdio.h>
#include "global.h"
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
	bool ouvert;
	enum tresor t;
	union contenu {
		int po;
		enum bonus B;
    };
}coffre;
//fin coffre


//debut hero
typedef struct {

} *inventaire, str_inventaire;

typedef struct {
    int HP;
    char * nom;
    inventaire InvHero;
} *hero, strHero;
//fin hero


//debut monstre
typedef struct {
} *monstre, strMonstre;
//fin monstre


//debut zone
enum terrain {
	mur,
	sol,
};

enum objet {
	HERO,
	MONSTRE,
	COFFRE,
	NEUTRE,         // Sinon toute les cases sont forcement soit des monstres soit des heros soit des coffres
};

typedef struct {
	enum terrain ter;
	enum objet obj;
	union {
		hero H;
		monstre mobs;
		coffre C;

	} u;
} *zone, strZone;
//fin zone


#endif
