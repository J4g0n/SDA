#ifndef __salle_h_
#define __salle_h_
#include "objet.h"

#define MIN_TAILLE 5      // Taille minimal des salles
#define MAX_TAILLE 15      //Taille maximal des salles
#define MIN_COFFRE 0      // Nombre minimal de coffres
#define MAX_COFFRE 2       // Nombre maximal de coffres
#define MIN_MONSTRE 1      // Nombre minimal de monstres
#define MAX_MONSTRE 3      // Nombre maximal de monstres

typedef struct salle {
	int numero;
	zone **z;
	int taille;      // vu que c'est creer aleatoirement mieux vos stocker la taille de la salle dans la str
} *salle, strSalle;

salle creerSalle();

#endif
