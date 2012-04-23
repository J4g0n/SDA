#include <stdio.h>
#include <stdlib.h>
#include "objet.h"
#include "combat.h"

paquet paquetVide() {
	return NULL;
}

paquet ajouterCarte(paquet P,carte C) {
	paquet P2,tmp;
	P2 = (paquet) malloc(sizeof(strPaquet));
	if (P==NULL) {
		P2->card=C;
		P2->suiv=P2;
		free(P);
	}
	else {
		tmp=P->suiv;
		P->suiv=P2;
		P2->suiv=tmp;
	}
	return P2;
}

paquet supprimerCarte(paquet P) {
	paquet tmp;
	if (P!=NULL) {
		tmp=P->suiv;
		P->suiv=P->suiv->suiv;
		free(tmp);
	}
	return P;
}

carte sommetPaquet(paquet P) {
	return P->suiv->card;
}

Bool testVide(paquet P) {
	return (P==NULL)?vrai:faux;
}

paquet rotationPaquet(paquet P) {
	return P->suiv;
}


paquet paquetGen(inventaire inv) {
	int i,j;
	paquet P=paquetVide();
	for(i=20;i<TAILLE_INVENTAIRE;i++) {
		for(j=inv->it[i].qte;j>0;j++) P=ajouterCarte(P,inv->it[i].tp.card);
	}
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
			cardHero.HP=cardHero.HP-(cardMobs.attaque-cardHero.defense);
		}
		if (cardMobs.defense<cardHero.attaque) {
			cardMobs.HP=cardMobs.HP-(cardHero.attaque-cardMobs.defense);
		}
		if (cardHero.HP<=0) {
			supprimerCarte(pqtHero);
			if (cardMobs.HP<=0) supprimerCarte(pqtMobs);
			else rotationPaquet(pqtMobs);
		}
		else {
			rotationPaquet(pqtHero);
			if (cardMobs.HP<=0) supprimerCarte(pqtMobs);
			else rotationPaquet(pqtMobs);
		}
	}

	if (pqtMobs==NULL) 
		mobs->HP--;
	if (pqtHero==NULL) 
		oreh->HP--;

	return 0;
}

