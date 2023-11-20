CC = gcc
CFLAGS = -Wall

SRC = ./Src
BUILD = ./Build
BIN = ./Bin
UNITY = ./Unity
TEST = ./Test

executables = 1-01 1-02 1-03 1-04 1-05 1-06 1-07 1-08 1-09 1-10 1-11 1-12 1-13a 1-13b 1-14a 1-14b 1-15 1-16 1-17 1-18 1-19 1-20 1-21 1-22 1-23 1-24 2-01 2-02 2-03 2-04 2-05 2-06 2-07 2-08 2-09 2-10 3-01 3-02 3-03
tests = Test-1-15 Test-1-16 Test-1-18 Test-1-19 Test-1-22 Test-1-23 Test-2-03 Test-2-04 Test-2-05 Test-2-06 Test-2-07 Test-2-08 Test-2-09 Test-2-10 Test-3-01 Test-3-02

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
2-03: $(SRC)/2-03.c $(SRC)/1-16func.c $(SRC)/2-03func.c
2-04: $(SRC)/2-04.c $(SRC)/2-04func.c
2-05: $(SRC)/2-05.c $(SRC)/2-05func.c
2-06: $(SRC)/2-06.c $(SRC)/2-06func.c
2-07: $(SRC)/2-07.c $(SRC)/2-07func.c
2-08: $(SRC)/2-08.c $(SRC)/2-08func.c
2-09: $(SRC)/2-09.c $(SRC)/2-09func.c
2-10: $(SRC)/2-10.c $(SRC)/2-10func.c
3-01: $(SRC)/3-01.c $(SRC)/3-01func.c
3-02: $(SRC)/3-02.c $(SRC)/3-02func.c
3-03: $(SRC)/3-03.c $(SRC)/3-03func.c

test: $(tests)

%: $(TEST)/%.c $(UNITY)/unity.c
	$(CC) $(CFLAGS) -o $(BUILD)/$@ $?

Test-1-15: $(TEST)/Test-1-15.c $(UNITY)/unity.c
Test-1-16: $(TEST)/Test-1-16.c $(UNITY)/unity.c
Test-1-18: $(TEST)/Test-1-18.c $(UNITY)/unity.c
Test-1-19: $(TEST)/Test-1-19.c $(UNITY)/unity.c
Test-1-22: $(TEST)/Test-1-22.c $(UNITY)/unity.c
Test-1-23: $(TEST)/Test-1-23.c $(UNITY)/unity.c
Test-2-03: $(TEST)/Test-2-03.c $(UNITY)/unity.c
Test-2-04: $(TEST)/Test-2-04.c $(UNITY)/unity.c
Test-2-05: $(TEST)/Test-2-05.c $(UNITY)/unity.c
Test-2-06: $(TEST)/Test-2-06.c $(UNITY)/unity.c
Test-2-07: $(TEST)/Test-2-07.c $(UNITY)/unity.c
Test-2-08: $(TEST)/Test-2-08.c $(UNITY)/unity.c
Test-2-09: $(TEST)/Test-2-09.c $(UNITY)/unity.c
Test-2-10: $(TEST)/Test-2-10.c $(UNITY)/unity.c
Test-3-01: $(TEST)/Test-3-01.c $(UNITY)/unity.c
Test-3-02: $(TEST)/Test-3-02.c $(UNITY)/unity.c

clean:
	$(RM) $(BUILD)/* $(BIN)/*
