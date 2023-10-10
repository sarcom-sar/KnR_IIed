CC = gcc
CFLAGS = -Wall
all:
	$(CC) Src/1.01.c -o Build/1-01
	$(CC) Src/1.02.c -o Build/1-02
	$(CC) Src/1.03.c -o Build/1-03
	$(CC) Src/1.04.c -o Build/1-04
	$(CC) Src/1.05.c -o Build/1-05
	$(CC) Src/1.06.c -o Build/1-06
