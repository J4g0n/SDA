#include <stdio.h>
#include <stdlib.h>
#include"combat.h"

paquet paquetVide() {
	return NULL;
}

paquet ajouterCarte(paquet P,carte C) {
	paquet P2,tete;
	P2 = (paquet) malloc(sizeof(strPaquet));
	P2->card=C;
	if (P==NULL) {
		P2->suiv=P2;
		free(P);
	}
	else {
		tete=P->suiv;
		P->suiv=P2;
		P2->suiv=tete;
	}
	return P2;
}

paquet supprimerCarte(paquet P) {
	paquet tmp;
	if (P!=NULL) {
		if (P!=P->suiv) {
			tmp=P->suiv;
			P->suiv=P->suiv->suiv;
			free(tmp);
		}
		else {
			tmp=P;
			free(tmp);
			P=paquetVide();
		}
	}
	return P;
}

carte sommetPaquet(paquet P) {
	return P->suiv->card;
}

Bool testVide(paquet P) {
	return (P==NULL)?1:0;
}

paquet rotationPaquet(paquet P) {
	return P->suiv;
}


paquet paquetGen(inventaire inv) {
	int i,j; int k=0;
	paquet P=paquetVide();
	carte *C=(carte*) calloc(TAILLE_INVENTAIRE,sizeof(carte));
	
	//on insère les cartes dans un tableau
	for(i=0;i<TAILLE_INVENTAIRE;i++) {
		if ((inv->it[i].tp.ref!=0)&&(inv->it[i].tp.card.tpIt==CARTE)&&(inv->it[i].qte>0)) {
			for(j=0;j<inv->it[i].qte;j++) {
				if (k<TAILLE_INVENTAIRE) {
					C[k]=inv->it[i].tp.card;
					k++;
				}
			}
		}
	}
	
	//on cree la liste de combat aléatoirement a partir du tableau
	while(k>0) {
		k--;
		if (k>1) {
			j=rand()%k;
		}
		else {
			j=k;
		}
		P=ajouterCarte(P,C[j]);
		C[j]=C[k];
	}
	//P=ajouterCarte(P,C[0]);
	
	free(C);

	return P;
}

int combat(monstre mobs, hero oreh) {
	paquet pqtMobs, pqtHero; carte cardMobs, cardHero;
	pqtMobs=paquetGen(mobs->invMobs);
	pqtHero=paquetGen(oreh->invHero);
	
	while ((pqtMobs!=NULL)&&(pqtHero!=NULL)) {
		cardHero=sommetPaquet(pqtHero);
		cardMobs=sommetPaquet(pqtMobs);
		if (cardMobs.attaque>cardHero.defense) {
			pqtHero->suiv->card.HP-=(cardMobs.attaque-cardHero.defense);
		}
		if (cardMobs.defense<cardHero.attaque) {
			pqtMobs->suiv->card.HP-=(cardHero.attaque-cardMobs.defense);
		}
		if (pqtHero->suiv->card.HP<=0) {
			pqtHero=supprimerCarte(pqtHero);
			if (pqtMobs->suiv->card.HP<=0) pqtMobs=supprimerCarte(pqtMobs);
			else pqtMobs=rotationPaquet(pqtMobs);
		}
		else {
			pqtHero=rotationPaquet(pqtHero);
			if (pqtMobs->suiv->card.HP<=0) pqtMobs=supprimerCarte(pqtMobs);
			else pqtMobs=rotationPaquet(pqtMobs);
		}
	}

	if (pqtMobs==NULL) {
		mobs->HP--;
		return 0;
	}
	else {
		oreh->HP--;
		return 1;
	}
}

int bataille(monstre mobs, hero oreh) {
	int r;
	while ((mobs->HP>0)&&(oreh->HP>0)) {
		r=combat(mobs,oreh);
	}
	return r;
}
