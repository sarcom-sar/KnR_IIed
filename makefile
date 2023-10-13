CC = gcc
CFLAGS = -Wall

SRC = ./Src
BUILD = ./Build
BIN = ./Bin
UNITY = ./Unity
TEST = ./Test

executables = 1-01 1-02 1-03 1-04 1-05 1-06 1-07 1-08 1-09 1-10 1-11 1-12 1-13a 1-13b 1-14a 1-14b 1-15 1-16
tests = Test-1-15 Test-1-16

all: $(executables) 

%: $(SRC)/%.c
	$(CC) $(CFLAGS) -o $(BUILD)/$@ $?

# everything up to 1-14 is build using pattern rules
1-15: $(SRC)/1-15.c $(SRC)/1-15func.c
1-16: $(SRC)/1-16.c $(SRC)/1-16func.c

test: $(tests)

Test-1-15: $(TEST)/Test-1-15.c $(SRC)/1-15func.c $(UNITY)/unity.c
	$(CC) $(CFLAGS) -o $@ $?

Test-1-16: $(TEST)/Test-1-16.c $(SRC)/1-16func.c $(UNITY)/unity.c
	$(CC) $(CFLAGS) -o $@ $?

clean:
	$(RM) $(BUILD)/* $(BIN)/*
