CC = gcc
CFLAGS = -Wall -c -g 
LDFLAGS = -o

INC = ./inc/
SRC = ./src
OBJ = ./obj
BIN = ./bin

IFLAGS = -I $(INC)

all: project

project: $(OBJ)/sample1.o 
	$(CC) $(LDFLAGS) $(BIN)/project $(OBJ)/sample1.o

$(OBJ)/sample1.o: $(SRC)/sample1.c
	$(CC) $(CFLAGS) $(SRC)/sample1.c $(IFLAGS)
	mv *.o $(OBJ)/

clean:
	rm -f $(OBJ)/*
	rm -f $(BIN)/*
	@echo "Cleaning Done!"




