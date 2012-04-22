#ifndef __inventaire_h_
#define __inventaire_h_
#include "global.h"

#define TAILLE_INVENTAIRE 50
#define NOMBRE_DE_CARTES 10

enum typeItem { CARTE, POTION };

//type carte
typedef struct { 
	enum typeItem tpIt;
	int ref;
	char nom[20];
	int HP;
	int attaque;
	int defense;
} carte; 

//type potion
typedef struct {
	enum typeItem tpIt;
	int ref;
	char nom[20];
	int HP;
} potion;

//type item
typedef union {
	enum typeItem tpIt;
	int ref;
	carte card;
	potion po;
} type;

typedef struct {
	type tp;
	int qte;
} item; 

//type inventaire
typedef struct {
	item it[TAILLE_INVENTAIRE];
	int place;
} *inventaire, str_inventaire;

inventaire stockVide();
inventaire ajoutRef(inventaire, type);
inventaire supprRef(inventaire, type);
inventaire ajoutQte(inventaire, type, int);
inventaire supprQte(inventaire, type, int);
int existe(inventaire, type);
int quantite(inventaire, type);
int nombreRef(inventaire);

//objets de base de l'inventaire
potion soin = { POTION, 1, "potion de soin", 30 };
carte fantassin = { CARTE, 20, "fantassin", 2, 3, 2 };
carte guerrier = { CARTE, 21, "guerrier", 6, 8, 6 };
carte barbare = { CARTE, 22, "barbare", 10,7, 3 };
carte tour = { CARTE, 23, "tour", 30, 4, 0 };

#endif
