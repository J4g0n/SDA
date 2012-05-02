#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"inventaire.h"

type potSante = {.card={ 1, POTION, "potion de soin", 5, 0, 0}} ;
type fantassin = {.card={ 20, CARTE, "fantassin", 4, 3, 2}};
type guerrier = {.card={ 21, CARTE, "guerrier", 6, 8, 4}};
type barbare = {.card={ 22, CARTE, "barbare", 10, 7, 3}};
type tour = {.card={ 23, CARTE, "tour", 30, 5, 0}};
type sorcier = {.card={ 24, CARTE, "sorcier", 15, 4, 1}};

inventaire stockVide() {
	inventaire inv=(inventaire) calloc(1,sizeof(str_inventaire));
	inv->place=TAILLE_INVENTAIRE;
	return inv;
}

inventaire ajoutRef(inventaire inv, type t) {
	int i;
	if (existe(inv,t)!=1) {
		inv->it[t.ref].tp.ref=t.ref;
		inv->it[t.ref].tp.po.tpIt=t.po.tpIt;
		inv->it[t.ref].tp.po.HP=t.po.HP;
		inv->it[t.ref].tp.card.attaque=t.card.attaque;
		inv->it[t.ref].tp.card.defense=t.card.defense;
		for(i=0;i<20;i++) {
			inv->it[t.ref].tp.po.nom[i]=t.po.nom[i];
		}
	}
	return inv;
}

inventaire supprRef(inventaire inv, type t) {
	if (existe(inv,t)==1) {
		inv->it[t.ref].tp.ref=0;
		inv->it[t.ref].qte=0;
	}
	return inv;
}

inventaire ajoutQte(inventaire inv, type t, int qte) {
	int dispo=9-inv->it[t.ref].qte;
	int rempli;
	if (qte<dispo) rempli=qte;
	else rempli=dispo;
	if (inv->place-rempli<0) {
		rempli=inv->place;
	}
	
	inv->it[t.ref].qte+=rempli;	
	inv->place-=rempli;
	
	return inv;
}

inventaire supprQte(inventaire inv, type t, int qte) {
	int rempli=inv->it[t.ref].qte;
	if (qte>rempli){
		inv->it[t.ref].qte=0;
		inv->place+=rempli;
	}
	else {
		inv->it[t.ref].qte-=qte;
		inv->place+=qte;
	}
	
	return inv;
}

int existe(inventaire inv, type t) {
	if (inv->it[t.ref].tp.ref==t.ref) return 1;
	else return 0;
}

int quantite(inventaire inv, type t) {
	return inv->it[t.ref].qte;
}

int nombreRef(inventaire inv) {
	int i,ref; ref=0;
	for(i=0;i<TAILLE_INVENTAIRE;i++) {
		if (inv->it[i].tp.ref!=0) ref++;
	}
	return ref;
}

inventaire transfert(inventaire invX, inventaire invHero) {
	int i;
	for(i=0;i<TAILLE_INVENTAIRE;i++) {
		if (invX->it[i].tp.ref!=0) {
			if (invHero->it[i].tp.ref==0) {
				invHero=ajoutRef(invHero,invX->it[i].tp);
			}
			invHero=ajoutQte(invHero,invX->it[i].tp,invX->it[i].qte);
		}
	}
	return invHero;
}

inventaire creerInvHero() {
	inventaire inv=stockVide();

	ajoutRef(inv, potSante);
	ajoutQte(inv, potSante, 3);
	
	ajoutRef(inv, fantassin);
	ajoutQte(inv, fantassin, 4);
	
	ajoutRef(inv, guerrier);
	ajoutQte(inv, guerrier, 3);
	
	ajoutRef(inv, barbare);
	ajoutQte(inv, barbare, 3);
	
	ajoutRef(inv, tour);	
	ajoutQte(inv, tour, 2);

	ajoutRef(inv, sorcier);
	ajoutQte(inv, sorcier, 2);
	
	return inv;
}

inventaire creerInvMobs(){
	inventaire inv=stockVide();
	
	ajoutRef(inv, fantassin);
	ajoutQte(inv, fantassin, rand()%9+1);
	
	ajoutRef(inv, guerrier);
	ajoutQte(inv, guerrier, rand()%3+1);
	
	ajoutRef(inv, barbare);
	ajoutQte(inv, barbare, rand()%3+1);
	
	ajoutRef(inv, tour);	
	ajoutQte(inv, tour, rand()%4+1);

	ajoutRef(inv, sorcier);
	ajoutQte(inv, sorcier, rand()%3+1);
	
	return inv;
}

inventaire creerInvCoffre(){
	inventaire inv=stockVide();

	ajoutRef(inv, potSante);
	ajoutQte(inv, potSante, rand()%2);
	
	ajoutRef(inv, fantassin);
	ajoutQte(inv, fantassin, rand()%2);
	
	ajoutRef(inv, guerrier);
	ajoutQte(inv, guerrier, rand()%2);
	
	ajoutRef(inv, barbare);
	ajoutQte(inv, barbare, rand()%2);
	
	ajoutRef(inv, tour);	
	ajoutQte(inv, tour, rand()%2);

	ajoutRef(inv, sorcier);
	ajoutQte(inv, sorcier, rand()%2);
	
	return inv;
}

