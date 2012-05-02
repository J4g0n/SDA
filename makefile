
VPATH = src:includes:bin
BIN = bin/
SRC = src/
CC = gcc
TARGET = InfiniteRPG
CFLAGS = -Wall -g
INC =-Iincludes

all:$(TARGET)

$(TARGET):main.o combat.o salle.o graphics.o univers.o global.o inventaire.o
	$(CC) -o $@ $(BIN)main.o $(BIN)salle.o $(BIN)graphics.o $(BIN)univers.o $(BIN)combat.o $(BIN)global.o $(BIN)inventaire.o 

main.o:main.c univers.h global.h objet.h inventaire.h
	$(CC) -c  $< $(INC) -o $(BIN)$@ $(CFLAGS) 

salle.o: salle.c salle.h objet.h global.h graphics.h 
	$(CC) -c  $< $(INC) -o $(BIN)$@ $(CFLAGS) 

graphics.o:graphics.c  graphics.h
	$(CC) -c  $< $(INC) -o $(BIN)$@ $(CFLAGS) 

univers.o: univers.c salle.h univers.h objet.h global.h inventaire.h 
	$(CC) -c  $< $(INC) -o $(BIN)$@ $(CFLAGS) 

global.o:global.c global.h  objet.h inventaire.h graphics.h
	$(CC) -c  $< $(INC) -o $(BIN)$@ $(CFLAGS) 

inventaire.o:inventaire.c inventaire.h graphics.h
	$(CC) -c  $< $(INC) -o $(BIN)$@ $(CFLAGS) 

combat.o:combat.c combat.h graphics.h objet.h
	$(CC) -c $< $(INC) -o $(BIN)$@ $(CFLAGS)

clean:
	rm $(BIN)*.o 
	rm InfiniteRPG

doxy:
	doxygen
