#include <stdlib.h>
#include <stdio.h>
#include "salle.h"
#include "global.h"

int numeroSalle=0; /*variable global pour incrementer facilement le numero de la nouvelle salle
                    creer, sujet a changement */

/* creer un coffre aleatoire

coffre randomCoffre(stock s){
	}
*/

int randIntervalle (int a , int b){ // a < b, pour la randomisation des tailles de salles
    return rand()%(b-a)+a;
}

salle creerSalle() { // alloue en memoire une salle et initialise toute les zones en sol
	int i=0,v=0;
	int tailleSalle=randIntervalle(MIN_TAILLE,MAX_TAILLE);

	salle tmp =(strSalle*) malloc(sizeof(strSalle));           // malloc sur la struct
	tmp->z =(zone**) malloc(tailleSalle*sizeof(zone*));  // malloc des pointeurs sur zone du tableau de pointeur

	for (i=0;i<tailleSalle;i++){
		tmp->z[i]=(zone*) malloc(tailleSalle*sizeof(zone));  // boucle : malloc sur les zones
	}

	for (i=0;i<tailleSalle;i++){
		for (v=0;v<tailleSalle;v++){
		tmp->z[i][v].H=NULL;
		tmp->z[i][v].mobs=NULL;
		tmp->z[i][v].C=NULL;
		}
	}

	tmp->numero=numeroSalle++;
	tmp->taille=tailleSalle;

	return tmp;
}



salle remplirSalle(salle s){                          // Big-ass fonction qui remplis la salle avec des mobs,des coffres ;
	int monstre=randIntervalle(MIN_MONSTRE,MAX_MONSTRE);
	int coffre=randIntervalle(MIN_COFFRE,MAX_COFFRE);
	int i=0,v=0;
	int tmpRandL=0,tmpRandH=0;

/*Initialise la salle en mettant du sol partout, et en mettrant des objet neutres*/
	for(i=0;i<s->taille;i++){
		for(v=0;v<s->taille;v++){
			s->z[i][v].ter=1;
			s->z[i][v].obj=3;
		}
	}
/*Entoure la salle de murs*/
	for(i=0;i<s->taille;i++){                
		s->z[0][i].ter=0;               // haut de la salle 
		s->z[s->taille-1][i].ter=0;			// bas de la salle
		s->z[i][0].ter=0;								// cote gauche
		s->z[i][s->taille-1].ter=0;			// cote droit
	}

/*Creer les portes*/	
		s->z[0][s->taille/2].ter=1;           // Ouverture a gauche
		s->z[s->taille-1][s->taille/2].ter=1; // Ouverture a droite
		
/* placements et choix des monstres*/		
	for(i=monstre;i>0;i--){
		tmpRandL = randIntervalle(1,s->taille-1);
		tmpRandH = randIntervalle(1,s->taille-1);

		s->z[tmpRandL][tmpRandH].obj=1;  // La case est occupee par un monstre
		s->z[tmpRandL][tmpRandH].mobs=creerMonstre();
	}

/*placement et choix des coffres*/
	while(coffre!=0){
		tmpRandL = randIntervalle(1,s->taille-1);
		tmpRandH = randIntervalle(1,s->taille-1);
		
		if(s->z[tmpRandL][tmpRandH].obj!=2 ){
		s->z[tmpRandL][tmpRandH].obj=2;  // La case est occupee par un coffre
		s->z[tmpRandL][tmpRandH].C=creerCoffre();
		}
	coffre--;	
	}

return s;
}


/*Affichage d'une salle*/
void afficheSalle(salle s){
int i=0,v=0;
EffacerEcran();
	for(i=0;i<s->taille;i++){
		for(v=0;v<s->taille;v++){
			/*Affichage du fond:soit un mur,soit du sol*/
			if (s->z[i][v].ter==0){
				SePositionner(i+10,v+10);
				ChangerCouleurFond(37);
				printf(" ");
			} else
			if(s->z[i][v].ter==1){
				SePositionner(i+10,v+10);
				ChangerCouleurFond(30);
				printf(" ");
			}
			/*Affichage des coffres,heros et monstres*/		
			if(s->z[i][v].obj==0){
				SePositionner(i+10,v+10);
				ChangerCouleurTexte(37);
				printf("H");
			} else 
			if(s->z[i][v].obj==1){
				SePositionner(i+10,v+10);
				ChangerCouleurTexte(32);
				printf("M");
			} else 
			if(s->z[i][v].obj==2){
				SePositionner(i+10,v+10);
				ChangerCouleurTexte(33);
				printf("C");
			} 

		}
	}
	ReinitialiserCouleur();
}
/*Free d'une salle et de sa matrice associe*/
void detruireSalle(salle s){
	int i,j;

	for (i=0;i<s->taille;i++){
		for(j=0;j<s->taille;j++) {
			if (s->z[i][j].obj==MONSTRE) detruireMonstre(s->z[i][j].mobs);
			if (s->z[i][j].obj==COFFRE) detruireCoffre(s->z[i][j].C);
		}
		free(s->z[i]);
	}
	
	free(s->z);
	free(s);
}
/*Fonction de deplacement du hero qui renvoie vrai si l'entree correspond a un mouvement */
Bool deplacement(hero h,salle s,int entree){
	/*Deplacement vers le bas*/
	if(entree==TOUCHE_FLECHE_BAS){
		if(h->y<s->taille-2){
			s->z[h->x][h->y].obj=NEUTRE;
			s->z[h->x][h->y].H=NULL;
			s->z[h->x][h->y+1].obj=HERO;		
			s->z[h->x][h->y+1].H=h;
			h->y=h->y+1;
			return vrai;
		}
	}
	else
		/*Deplacement vers le haut*/
		if(entree==TOUCHE_FLECHE_HAUT){
			if(h->y>1){
				s->z[h->x][h->y].obj=NEUTRE;
				s->z[h->x][h->y].H=NULL;
				s->z[h->x][h->y-1].obj=HERO;		
				s->z[h->x][h->y-1].H=h;		
				h->y=h->y-1;
			return vrai;
			}
		}
	else
		/*deplacement a droite*/
		if(entree==TOUCHE_FLECHE_DROITE){
			if(h->x<s->taille-2){
				s->z[h->x][h->y].obj=NEUTRE;
				s->z[h->x][h->y].H=NULL;
				s->z[h->x+1][h->y].obj=HERO;		
				s->z[h->x+1][h->y].H=h;		
				h->x=h->x+1;
			return vrai;
			}
		}
	else 
		/*deplacement a gauche*/
		if(entree==TOUCHE_FLECHE_GAUCHE){
			if(h->x>1){
				s->z[h->x][h->y].obj=NEUTRE;
				s->z[h->x][h->y].H=NULL;
				s->z[h->x-1][h->y].obj=HERO;		
				s->z[h->x-1][h->y].H=h;		
				h->x=h->x-1;
			return vrai;
			}
		}

	 /*Deplacement dans le cas des portes gauche et droite*/
		if(entree==TOUCHE_FLECHE_GAUCHE){
			if(h->x==1 && h->y==(s->taille/2)){
				s->z[h->x][h->y].obj=NEUTRE;
				s->z[h->x][h->y].H=NULL;

				s->z[h->x-1][h->y].obj=HERO;		
				s->z[h->x-1][h->y].H=h;		
				h->x=h->x-1;
			return vrai;
			}
		}
		else if(entree==TOUCHE_FLECHE_DROITE){
			if(h->x==s->taille-2 && h->y==s->taille/2){
				s->z[h->x][h->y].obj=NEUTRE;
				s->z[h->x][h->y].H=NULL;

				s->z[h->x+1][h->y].obj=HERO;		
				s->z[h->x+1][h->y].H=h;		
				h->x=h->x+1;
			return vrai;
			}
		}
/*retourne faux s'il n'y a pas de mouvement reussie*/
return faux;		
}

/*Si le hero rencontre un monstre en ce deplacant,on renvoie le monstre et on le supprime
 * de la salle*/
monstre CaseMonstre(salle s,hero h){
	monstre ACombattre=NULL;
	if(s->z[h->x][h->y].mobs!=NULL){
		ACombattre=s->z[h->x][h->y].mobs;
		s->z[h->x][h->y].mobs=NULL;
		s->z[h->x][h->y].obj=NEUTRE;
	}
	return ACombattre;
}

/*Si le hero rencontre un coffre en ce deplacant,on le supprime
 * de la salle et on ajoute son contenu au hero*/
void OuvrirCoffre(salle s,hero h){
	if(s->z[h->x][h->y].C!=NULL){
		if((s->z[h->x][h->y]).C->ouvert==faux){
		
		s->z[h->x][h->y].C->ouvert=vrai;
		}
	}
}
/*Pour placer le hero dans la premiere salle,ou pour des evenement precis*/
void insererHero(salle s,hero h){
	s->z[h->x][h->y].H=h;
	s->z[h->x][h->y].obj=HERO;
	}

