#ifndef _inventaire_h_
#define _inventaire_h_
#include<stdio.h>
#include<stdlib.h>

#define TAILLE_INVENTAIRE 50
#define NOMBRE_DE_CARTES 4

enum typeItem { CARTE, POTION };

//type carte
typedef struct { 
	int ref;
	enum typeItem tpIt;
	char nom[20];
	int HP;
	int attaque;
	int defense;
} carte; 

//type potion
typedef struct {
	int ref;
	enum typeItem tpIt;
	char nom[20];
	int HP;
} potion;

//type item
typedef union {
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
inventaire transfert(inventaire, inventaire);
int existe(inventaire, type);
int quantite(inventaire, type);
int nombreRef(inventaire);

inventaire transfert(inventaire, inventaire);

inventaire creerInvHero();
inventaire creerInvMobs();
inventaire creerInvCoffre();

//objets de base de l'inventaire
/*
extern type potSante = {.po={POTION, 1, "potion de soin", 5}} ;
extern type fantassin = {.card={CARTE, 20, "fantassin", 4, 3, 2}};
extern type guerrier = {.card={CARTE, 21, "guerrier", 6, 8, 4}};
extern type barbare = {.card={CARTE, 22, "barbare", 10, 7, 3}};
extern type tour = {.card={CARTE, 23, "tour", 30, 5, 0}};
extern type sorcier = {.card={CARTE, 24, "sorcier", 15, 4, 1}};
*/
/*type tabCarte[NOMBRE_DE_CARTES]={
	{.po={POTION, 1, "potion de soin", 5}},
	{ CARTE, 21, "guerrier", 6, 8, 4 },
	{ CARTE, 22, "barbare", 10,7, 3 },
	{ CARTE, 23, "tour", 30, 6, 0 }
};*/


#endif
