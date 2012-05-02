#include <stdlib.h>
#include <stdio.h>
#include "univers.h"

univ initUniv() {
	univ depart=(univ) malloc(sizeof(strUniv));
	depart->s=creerSalle();
	depart->droite=NULL;
	depart->gauche=NULL;
  remplirSalle(depart->s);
	depart->numero=1;
	return depart;
}

univ elmtDroite(univ elmt) {
	if (elmt->droite==NULL) {
		elmt->droite=initUniv();
		elmt->droite->gauche=elmt;
		elmt->droite->numero=elmt->numero+1;
	}
	return elmt->droite;
}

univ elmtGauche(univ elmt) {
	if (elmt->gauche==NULL) {
		elmt->gauche=initUniv();
		elmt->gauche->droite=elmt;
	}
	if (elmt->numero==1)
		return elmt;
	else
		return elmt->gauche;
}

/*Fonction qui enclenche le changement de salle si le hero se trouve sur le seuil d'une
 * porte,si la salle suivante n'existe pas,elle sera alors creer*/
univ changement_salle(hero h,salle s,univ univers){
	if(h->x == s->taille-1 && h->y == s->taille/2 ){

	/*le hero est supprimer du seuil de la porte de la salle qu'il vient de quitter*/
			s->z[s->taille-1][s->taille/2].obj=NEUTRE;
			s->z[s->taille-1][s->taille/2].H=NULL;

	/*Creation d'une nouvelle salle a droite,ou si elle existe deja, on y accede*/
			univers=elmtDroite(univers);

	/*On met les coordonner du hero sur le seuil de la porte gauche de la "nouvelle" salle*/
			h->y=univers->s->taille/2;
			h->x=0;

	/*On changer les attribut de la zone sur laquelle se trouve a present les hero*/
			univers->s->z[0][univers->s->taille/2].obj=HERO;
			univers->s->z[0][univers->s->taille/2].H=h;

		}
	else
	/*meme proceder,on placant le hero sur le seuil de la porte droite,de la "nouvelle"
	 * salle a gauche*/	
		if(univers->numero!=1){
			if(h->x == 0 && h->y == s->taille/2 ){

				s->z[s->taille-1][s->taille/2].obj=NEUTRE;
				s->z[s->taille-1][s->taille/2].H=NULL;

				univers=elmtGauche(univers);

				h->y=univers->s->taille/2;
				h->x=univers->s->taille-1;

				univers->s->z[univers->s->taille-1][univers->s->taille/2].obj=HERO;
				univers->s->z[univers->s->taille-1][univers->s->taille/2].H=h;
			}
		}
	return univers;
}
	/*Affiche le titre et le numero de la salle courante*/
void TitreSalle(univ univers){
	SePositionner(20,2);
	ChangerCouleurTexte(35);
	ChangerCouleurFond(36);
	printf("Salle n*%d",univers->numero);
	ReinitialiserCouleur();
	}
/*Destruction de l'univers*/
void DetruireUnivers(univ univers){
	univ tmp=NULL;
/*On se place d'abord completement a gauche de la liste doublement chainee*/
	while (univers->gauche!=NULL){
		univers=univers->gauche;
	}
/*On supprime ensuite les maillons "univers",en se deplacant vers la droite*/
	while (univers->droite!=NULL){
		detruireSalle(univers->s);
		tmp=univers->droite;
		free(univers);
		univers=tmp;
	}
}	
