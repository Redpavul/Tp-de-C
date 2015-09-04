BIN = executable

OBJECTS = main.o traitement_image.o entree_sortie.o

CC = gcc

all : $(BIN)

$(BIN) : $(OBJECTS)
	$(CC) $(OBJECTS) -o $(BIN)

main.o : main.c
	$(CC) -c main.c

traitement_image.o : traitement_image.c traitement_image.h
	$(CC) -c traitement_image.c

entree_sortie.o : entree_sortie.c entree_sortie.h
	$(CC) -c entree_sortie.c

clean :
	rm $(OBJECTS) $(BIN)
