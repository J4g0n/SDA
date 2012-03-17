#ifndef __salle_h_
#define __salle_h_
#include "objet.h"

typedef struct salle {
	int numero;
	zone **z;
} *salle, strSalle;

salle creerSalle();

#endif
