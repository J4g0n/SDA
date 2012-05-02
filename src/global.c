#include "global.h"

/*Cache le curseur dans un coin en bas a droite de la console*/
void PlanquerCurseur(){
	SePositionner(70,70);
}

/*Affiche le menu du jeu*/
int menu(){
	int entree=0;
	int posMenu=5;

	while(entree!=TOUCHE_ECHAP){
		ChangerCouleurFond(37);
		/*I*/
		SePositionner(10,10);
		printf(" ");
		SePositionner(11,10);
		printf(" ");
		SePositionner(12,10);
		printf(" ");
		SePositionner(11,11);
		printf(" ");
		SePositionner(11,11);
		printf(" ");
		SePositionner(10,12);
		printf(" ");
		SePositionner(11,12);
		printf(" ");
		SePositionner(12,12);
		printf(" ");
		/*N*/
		SePositionner(14,10);
		printf(" ");
		SePositionner(17,10);
		printf(" ");
		SePositionner(14,11);
		printf(" ");
		SePositionner(14,12);
		printf(" ");
		SePositionner(15,11);
		printf(" ");
		SePositionner(16,12);
		printf(" ");
		SePositionner(17,11);
		printf(" ");
		SePositionner(17,12);
		printf(" ");
		/*F*/
		SePositionner(19,10);
		printf(" ");
		SePositionner(20,10);
		printf(" ");
		SePositionner(21,10);
		printf(" ");
		SePositionner(19,11);
		printf(" ");
		SePositionner(20,11);
		printf(" ");
		SePositionner(19,12);
		printf(" ");
		/*i*/
		SePositionner(23,10);
		printf(" ");
		SePositionner(23,11);
		printf(" ");
		SePositionner(23,12);
		printf(" ");

		/*N*/
		SePositionner(25,10);
		printf(" ");
		SePositionner(28,10);
		printf(" ");
		SePositionner(25,11);
		printf(" ");
		SePositionner(25,12);
		printf(" ");
		SePositionner(26,11);
		printf(" ");
		SePositionner(27,12);
		printf(" ");
		SePositionner(28,11);
		printf(" ");
		SePositionner(28,12);
		printf(" ");

		/*i*/
		SePositionner(30,10);
		printf(" ");
		SePositionner(30,11);
		printf(" ");
		SePositionner(30,12);
		printf(" ");

		/*T*/

		SePositionner(32,10);
		printf(" ");
		SePositionner(33,10);
		printf(" ");
		SePositionner(34,10);
		printf(" ");
		SePositionner(33,11);
		printf(" ");
		SePositionner(33,12);
		printf(" ");
		/*E*/
		SePositionner(36,10);
		printf(" ");
		SePositionner(37,10);
		printf(" ");
		SePositionner(38,10);
		printf(" ");
		SePositionner(36,11);
		printf(" ");
		SePositionner(37,11);
		printf(" ");
		SePositionner(36,12);
		printf(" ");
		SePositionner(37,12);
		printf(" ");
		SePositionner(38,12);
		printf(" ");
		/*A la ligne*/
		/*Q*/
		SePositionner(20,15);
		printf(" ");
		SePositionner(21,14);
		printf(" ");
		SePositionner(21,16);
		printf(" ");
		SePositionner(22,15);
		printf(" ");
		SePositionner(22,16);
		printf(" ");
		/*U*/
		SePositionner(24,14);
		printf(" ");
		SePositionner(24,15);
		printf(" ");
		SePositionner(24,16);
		printf(" ");
		SePositionner(25,16);
		printf(" ");
		SePositionner(26,14);
		printf(" ");
		SePositionner(26,15);
		printf(" ");
		SePositionner(26,16);
		printf(" ");
		/*E*/
		SePositionner(28,14);
		printf(" ");
		SePositionner(29,14);
		printf(" ");
		SePositionner(30,14);
		printf(" ");
		SePositionner(28,15);
		printf(" ");
		SePositionner(29,15);
		printf(" ");
		SePositionner(28,16);
		printf(" ");
		SePositionner(29,16);
		printf(" ");
		SePositionner(30,16);
		printf(" ");

		/*S*/
		SePositionner(32,15);
		printf(" ");
		SePositionner(32,17);
		printf(" ");
		SePositionner(33,14);
		printf(" ");
		SePositionner(33,16);
		printf(" ");
		/*T*/
		SePositionner(35,14);
		printf(" ");
		SePositionner(36,14);
		printf(" ");
		SePositionner(37,14);
		printf(" ");
		SePositionner(36,15);
		printf(" ");
		SePositionner(36,16);
		printf(" ");

		ReinitialiserCouleur();
		PlanquerCurseur();		
		if(posMenu==5){
			SePositionner(15,20);
			printf("Continuer");
			SePositionner(15,21);
			printf("Quitter");
			posMenu=0;
			PlanquerCurseur();		
		}

		entree=RecupererAppuiTouche();


		if(entree==TOUCHE_FLECHE_BAS){
			if(posMenu<NBR_MENU)
				posMenu++;
		}
		else 
			if(entree==TOUCHE_FLECHE_HAUT){
				if(posMenu>0)
					posMenu--;
			}else
				if(entree==TOUCHE_ENTREE){
					return posMenu;
				}

		if(posMenu==0){
			ChangerCouleurFond(33);
			ChangerCouleurTexte(30);
			SePositionner(15,20);
			printf("Continuer");
			ReinitialiserCouleur();

			SePositionner(15,21);
			printf("Quitter");
			PlanquerCurseur();		
		}
		else 
			if(posMenu==1){
				SePositionner(15,20);
				printf("Continuer");

				ChangerCouleurFond(33);
				ChangerCouleurTexte(30);
				SePositionner(15,21);
				printf("Quitter");
				ReinitialiserCouleur();
				PlanquerCurseur();		
			}
		PlanquerCurseur();		
	}	

	EffacerEcran();
	return 0;

}

/*Creation du hero en debut de partie*/

hero creerHero(){
	hero h=(strHero*) malloc(sizeof(strHero));
	h->nom=(char*) malloc(TAILLE_NOM_MAX*sizeof(char));
	h->nom[14]='\0';
	h->invHero=creerInvHero(); //remplacement de NULL par un inventaire 

	SePositionner(20,10);
	ChangerCouleurTexte(34);
	printf("Quelle nom a le hero ? (14 caractere max)");
	ReinitialiserCouleur();
	SePositionner(20,11);
	scanf("%s",h->nom);

	h->x=3;
	h->y=3;
	h->pieces=10;
	h->HP=30;

	return h;
}

/*Creation et destruction d'un monstre*/

monstre creerMonstre() {
	monstre m=(strMonstre*) malloc(sizeof(strMonstre));
	m->HP=rand()%5+5;
	m->pieces=rand()%5+1;
	m->invMobs=creerInvMobs();
	return m;
}

void detruireMonstre(monstre m) {
	free(m->nom);
	free(m->invMobs);
	free(m);
}

/*Creation et destruction d'un coffre*/

coffre creerCoffre() {
	coffre c=(coffre) calloc(1,sizeof(str_coffre));
	c->t=rand()%2;
	if (c->t==OR) c->pieces=rand()%10+1;
	if (c->t==BONUS) c->inv=creerInvCoffre();
	return c;
}

void detruireCoffre(coffre c) {
	free(c->inv);
	free(c);
}

/*affiche la vie du hero sous forme de barre rouge,une case valant 1Pv */
void AfficherVie(hero h){

	int i=0;

	SePositionner(40,20);
	ChangerCouleurTexte(32);
	printf("Vie:");
	ChangerCouleurFond(31);

	for(i=0;i<(h->HP);i++){
		SePositionner(40+i,21);
		printf(" ");
	}
	ReinitialiserCouleur();
}
/*affiche l'or du hero*/
void afficherOr(hero h) {
	SePositionner(40,23);
	ChangerCouleurTexte(32);
	printf("Or: %d",h->pieces);
}

/*Liberation de la structure hero*/
void DetruireHero(hero h){
	free(h->nom);
	free(h->invHero);
	free(h);
} 



