CC = gcc
CFLAGS = -Wall

SRC = ./Src
BUILD = ./Build
BIN = ./Bin
UNITY = ./Unity
TEST = ./Test

executables = 1-01 1-02 1-03 1-04 1-05 1-06 1-07 1-08 1-09 1-10 1-11 1-12 1-13a 1-13b 1-14a 1-14b 1-15 1-16 1-17 1-18 1-19 1-20 1-21 1-22 1-23 1-24 2-01
tests = Test-1-15 Test-1-16 Test-1-18 Test-1-19 Test-1-20 Test-1-21 Test-1-22 Test-1-23

all: $(executables)

%: $(SRC)/%.c
	$(CC) $(CFLAGS) -o $(BUILD)/$@ $?

# everything up to 1-14 is build using pattern rules
1-15: $(SRC)/1-15.c $(SRC)/1-15func.c
1-16: $(SRC)/1-16.c $(SRC)/1-16func.c
1-17: $(SRC)/1-17.c $(SRC)/1-16func.c #1-17 uses exact same functions as 1-16
1-18: $(SRC)/1-18.c $(SRC)/1-16func.c $(SRC)/1-18func.c
1-19: $(SRC)/1-19.c $(SRC)/1-16func.c $(SRC)/1-19func.c
1-20: $(SRC)/1-20.c $(SRC)/1-16func.c $(SRC)/1-20func.c
1-21: $(SRC)/1-21.c $(SRC)/1-16func.c $(SRC)/1-21func.c
1-22: $(SRC)/1-22.c $(SRC)/1-16func.c $(SRC)/1-22func.c
1-23: $(SRC)/1-23.c $(SRC)/1-16func.c $(SRC)/1-23func.c
1-24: $(SRC)/1-24.c $(SRC)/1-16func.c $(SRC)/1-24func.c

test: $(tests)

Test-1-15: $(TEST)/Test-1-15.c $(UNITY)/unity.c
	$(CC) $(CFLAGS) -o $(BUILD)/$@ $?

Test-1-16: $(TEST)/Test-1-16.c $(UNITY)/unity.c
	$(CC) $(CFLAGS) -o $(BUILD)/$@ $?

Test-1-18: $(TEST)/Test-1-18.c $(UNITY)/unity.c
	$(CC) $(CFLAGS) -o $(BUILD)/$@ $?

Test-1-19: $(TEST)/Test-1-19.c $(UNITY)/unity.c
	$(CC) $(CFLAGS) -o $(BUILD)/$@ $?

Test-1-20: $(TEST)/Test-1-20.c $(UNITY)/unity.c
	$(CC) $(CFLAGS) -o $(BUILD)/$@ $?

Test-1-21: $(TEST)/Test-1-21.c $(UNITY)/unity.c
	$(CC) $(CFLAGS) -o $(BUILD)/$@ $?

Test-1-22: $(TEST)/Test-1-22.c $(UNITY)/unity.c
	$(CC) $(CFLAGS) -o $(BUILD)/$@ $?

Test-1-23: $(TEST)/Test-1-23.c $(UNITY)/unity.c
	$(CC) $(CFLAGS) -o $(BUILD)/$@ $?

clean:
	$(RM) $(BUILD)/* $(BIN)/*
