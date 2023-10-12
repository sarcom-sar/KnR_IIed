CC = gcc
CFLAGS = -Wall

SRC = ./Src
BUILD = ./Build
BIN = ./Bin
UNITY = ./Unity
TEST = ./Test

all: 1-15.o 1-15func.o
	$(CC) $(CFLAGS) -o $(BUILD)/1-01 $(SRC)/1-01.c
	$(CC) $(CFLAGS) -o $(BUILD)/1-02 $(SRC)/1-02.c
	$(CC) $(CFLAGS) -o $(BUILD)/1-03 $(SRC)/1-03.c
	$(CC) $(CFLAGS) -o $(BUILD)/1-04 $(SRC)/1-04.c
	$(CC) $(CFLAGS) -o $(BUILD)/1-05 $(SRC)/1-05.c
	$(CC) $(CFLAGS) -o $(BUILD)/1-06 $(SRC)/1-06.c
	$(CC) $(CFLAGS) -o $(BUILD)/1-07 $(SRC)/1-07.c
	$(CC) $(CFLAGS) -o $(BUILD)/1-08 $(SRC)/1-08.c
	$(CC) $(CFLAGS) -o $(BUILD)/1-09 $(SRC)/1-09.c
	$(CC) $(CFLAGS) -o $(BUILD)/1-10 $(SRC)/1-10.c
	$(CC) $(CFLAGS) -o $(BUILD)/1-11 $(SRC)/1-11.c
	$(CC) $(CFLAGS) -o $(BUILD)/1-12 $(SRC)/1-12.c
	$(CC) $(CFLAGS) -o $(BUILD)/1-13a $(SRC)/1-13a.c
	$(CC) $(CFLAGS) -o $(BUILD)/1-13b $(SRC)/1-13b.c
	$(CC) $(CFLAGS) -o $(BUILD)/1-14a $(SRC)/1-14a.c
	$(CC) $(CFLAGS) -o $(BUILD)/1-14b $(SRC)/1-14b.c
	$(CC) $(CFLAGS) -o $(BUILD)/1-15 $(BIN)/1-15.o $(BIN)/1-15func.o

1-15.o: $(SRC)/1-15.c
	$(CC) $(CFLAGS) -c $? -o $(BIN)/$@

1-15func.o: $(SRC)/1-15func.c
	$(CC) $(CFLAGS) -c $? -o $(BIN)/$@

test:
	$(CC) $(CFLAGS) -o $(BUILD)/test-1-15 $(TEST)/Test1-15.c $(SRC)/1-15func.c $(UNITY)/unity.c

run-test:
	$(BUILD)/./test-*

clean:
	$(RM) $(BUILD)/* $(BIN)/*
