CC = gcc
CFLAGS = -Wall -c -g 
LDFLAGS = -o

INC = ./inc/
SRC = ./src
OBJ = ./obj
BIN = ./bin

IFLAGS = -I $(INC)

all: project

project: $(OBJ)/sample1.o $(OBJ)/myfunctions.o
	$(CC) $(LDFLAGS) $(BIN)/project $(OBJ)/sample1.o $(OBJ)/myfunctions.o

$(OBJ)/sample1.o: $(SRC)/sample1.c
	$(CC) $(CFLAGS) $(SRC)/sample1.c $(IFLAGS)
	mv *.o $(OBJ)/

$(OBJ)/myfunctions.o: $(SRC)/myfunctions.c
	$(CC) $(CFLAGS) $(SRC)/myfunctions.c $(IFLAGS)
	mv *.o $(OBJ)/

clean:
	rm -f $(OBJ)/*
	rm -f $(BIN)/*
	@echo "Cleaning Done!"




