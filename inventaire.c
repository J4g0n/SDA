#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inventaire.h"

inventaire stockVide() {
	inventaire inv=(inventaire) calloc(1,sizeof(str_inventaire));
	inv->place=50;
	return inv;
}

inventaire ajoutRef(inventaire inv, type t) {
	if (existe(inv,t)!=1) {
		if (t.tpIt==CARTE) inv->it[t.ref].tp=t;
		if (t.tpIt==POTION) inv->it[t.ref].tp=t;
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
	if (existe(inv,t)!=1) ajoutRef(inv,t);		
	if (inv->place+qte<=50) {
		if (inv->it[t.ref].qte+qte<10) inv->it[t.ref].qte+=qte;	
		else inv->it[t.ref].qte=9;
	}
	return inv;
}

inventaire supprQte(inventaire inv, type t, int qte) {
	if (inv->place+qte<=50) inv->place+=qte;
	else inv->place=50;
	if (existe(inv,t)==1) {
		if (inv->it[t.ref].qte-qte>=0) inv->it[t.ref].qte-=qte;  
		else inv->it[t.ref].qte=0;
	}
	return inv;
}

int existe(inventaire inv, type t) {
	if (inv->it[t.ref].tp.ref!=0) return 1;
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
