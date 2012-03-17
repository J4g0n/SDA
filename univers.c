#include <stdlib.h>
#include "univers.h"

univ initUniv() {
	univ depart=(univ) malloc(sizeof(strUniv));
	depart->s=creerSalle();
	depart->droite=NULL;
	depart->gauche=NULL;
	return depart;
}

univ elmtDroite(univ elmt) {
	if (elmt->droite==NULL) {
		elmt->droite=initUniv();
		elmt->droite->gauche=elmt->droite;
	}
	return elmt->droite;
}
	
univ elmtGauche(univ elmt) {
	if (elmt->gauche==NULL) {
		elmt->gauche=initUniv();
		elmt->gauche->droite=elmt->gauche;
	}
	return elmt->gauche;
}
