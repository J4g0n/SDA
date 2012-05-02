#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include"univers.h"
#include"global.h"
#include"combat.h"


int main(){
	int entree=0;
	int valmenu=0;
	int mortHero;
	srand(time(NULL));
	univ test=initUniv();

	EffacerEcran();
	hero h=creerHero();
	monstre m;
	ActiverModeRaw();
	insererHero(test->s,h);
	afficheSalle(test->s);
	while(valmenu!=1){
		AfficherVie(h);
		afficherOr(h);
		TitreSalle(test);
		PlanquerCurseur();
		entree=RecupererAppuiTouche();
		if (entree==TOUCHE_M_MIN){
			EffacerEcran();
			valmenu=menu();
			EffacerEcran();
			afficheSalle(test->s);
		}
		else if((deplacement(h,test->s,entree))==vrai){
			test=changement_salle(h,test->s,test);
			if ((m=CaseMonstre(test->s,h))!=NULL) {
				if ((mortHero=bataille(m,h))==0) {
					h->pieces+=m->pieces;
				}
			}
			OuvrirCoffre(test->s,h);
			afficheSalle(test->s);
		}
	}
	EffacerEcran();
	DesactiverModeRaw();
	DetruireUnivers(test);
	DetruireHero(h);
	return 0;	
}

