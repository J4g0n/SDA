#ifndef __univers_h_
#define __univers_h_
#include "salle.h"

typedef struct univ {
	salle s;
	struct univ *droite;
	struct univ *gauche;
} *univ, strUniv;

univ initUniv();
univ elmtGauche(univ);
univ elmtDroite(univ);

#endif

