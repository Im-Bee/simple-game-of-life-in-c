CC = gcc
CFLAGS = -Wall
GameOfLife: Main.o\
	Board.o\
	GameLogic.o
	$(CC) $(CFLAGS) Main.c Board.o GameLogic.o -o Program
