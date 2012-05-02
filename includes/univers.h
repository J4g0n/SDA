#ifndef _univers_h_
#define _univers_h_
#include "salle.h"
#include "objet.h"

typedef struct Univ {
	salle s;
	int numero;
	struct Univ *droite;
	struct Univ *gauche;
} *univ,strUniv;

univ initUniv();
univ elmtGauche(univ);
univ elmtDroite(univ);
univ changement_salle(hero h,salle s,univ univers);
void TitreSalle(univ univers);
void DetruireUnivers(univ univers);
#endif

