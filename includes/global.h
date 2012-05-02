#ifndef _global_h_
#define _global_h_
#include <stdlib.h>
#include <stdio.h>
#include "objet.h"
#include "graphics.h"

#define vrai 1
#define faux 0
#define NBR_MENU 1
#define TAILLE_NOM_MAX 15
//#define TAILLE_BESTIAIRE 10



int menu();


hero creerHero();
monstre creerMonstre();
coffre creerCoffre();
void detruireCoffre(coffre);
void detruireMonstre(monstre);
void AfficherVie(hero);
void afficherOr(hero);
void PlanquerCurseur();
void DetruireHero(hero h);




#endif
