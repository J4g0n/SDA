#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "salle.h"

int numeroSalle=0; /*variable global pour incrementer facilement le numero de la nouvelle salle
                    creer, sujet a changement */

int randIntervalle (int a , int b){ // a < b, pour la randomisation des tailles de salles
    return rand()%(b-a) +a;
}

salle creerSalle() { // alloue en memoire une salle et initialise toute les zones en sol
int i;
int tailleSalle=randIntervalle(MIN_TAILLE,MAX_TAILLE);

salle tmp =(salle) malloc(sizeof(strSalle));           // malloc sur la struct
tmp->z = (zone*) malloc(tailleSalle*sizeof(strZone*));  // malloc des pointeurs sur zone du tableau de pointeur

for (i=0;i<tailleSalle;i++)
    tmp->z[i]=(zone) malloc(tailleSalle*sizeof(strZone));  // boucle : malloc sur les zones

tmp->numero=numeroSalle++;
tmp->taille=tailleSalle;

return tmp;
}



salle remplirSalle(salle s, monstre* tableau_des_monstre){                          // Big-ass fonction qui remplis la salle avec des mobs,des coffres ;
int monstre=randIntervalle(MIN_MONSTRE,MAX_MONSTRE);
int coffre=randIntervalle(MIN_COFFRE,MAX_COFFRE);
int i;

for(i=monstre;i>0;monstre--){
    int tmpRandL = rand()%s->taille;
    int tmpRandH = rand()%s->taille;
(s->z[tmpRandL][tmpRandH])->ter=0;  // Le monstre est sur du sol aussi
(s->z[tmpRandL][tmpRandH])->obj=1;  // La case est occuper par un monstre
(s->z[tmpRandL][tmpRandH])u=tableau_des_monstre[s->numero];
}


while(coffre>0){
    int tmpRandL = rand()%s->taille;
    int tmpRandH = rand()%s->taille;
  //if
(s->z[tmpRandL][tmpRandH])->ter=0;  // Le Coffre est sur du sol aussi
(s->z[tmpRandL][tmpRandH])->obj=2;  // La case est occuper par un coffre
(s->z[tmpRandL][tmpRandH])->u=RandomCoffre();
}



}
