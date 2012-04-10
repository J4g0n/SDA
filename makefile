univers.o: univers.h salle.h univers.c
	gcc -c -Wall univers.c
combat.o: combat.h objet.h combat.c
	gcc -c -Wall combat.c
