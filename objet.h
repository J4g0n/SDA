#ifndef __objet_h_
#define __objet_h_

//coffre
enum tresor {
	OR;
	BONUS;
};

typedef struct {
	bool ouvert;
	enum tresor t;
	union {
		int po;
		bonus B;
} coffre;
//fin coffre


//debut hero
typedef struct {
} *hero, strHero;
//fin hero


//debut monstre
typedef struct {
} *monstre, strMonstre;
//fin monstre


//debut zone
enum terrain {
	mur;
	sol;
};

enum objet {
	HERO;
	MONSTRE;
	COFFRE;
};

typedef struct {
	enum terrain ter;
	enum objet obj;
	union {
		hero H;
		monstre mobs;
		coffre C;
	} u;
} *zone, strZone;
//fin zone


