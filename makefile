CC = gcc
CFLAGS = -Wall

SRC = ./Src
BUILD = ./Build
BIN = ./Bin
UNITY = ./Unity
TEST = ./Test

executables = 1-01 1-02 1-03 1-04 1-05 1-06 1-07 1-08 1-09 1-10 1-11 1-12 1-13a 1-13b 1-14a 1-14b 1-15 1-16 1-17 1-18 1-19 1-20 1-21 1-22 1-23 1-24 2-01 2-02 2-03 2-04 2-05 2-06 2-07 2-08 2-09 2-10 3-01 3-02 3-03 3-04 3-05 3-06 4-01 4-02 4-03 4-04 4-05 4-06 4-07 4-08 4-09 4-10 4-12 4-13 4-14
tests = Test-1-15 Test-1-16 Test-1-18 Test-1-19 Test-1-22 Test-1-23 Test-1-24 Test-2-03 Test-2-04 Test-2-05 Test-2-06 Test-2-07 Test-2-08 Test-2-09 Test-2-10 Test-3-01 Test-3-02 Test-3-03

%: $(SRC)/%.c
	$(CC) $(CFLAGS) -o $(BUILD)/$@ $?

all: $(executables)

# everything up to 1-14 is build using pattern rules
# so is 4-07
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
4-03: $(SRC)/4-03.c $(SRC)/4-03func.c $(SRC)/4-0-RPN.c
4-04: $(SRC)/4-04.c $(SRC)/4-03func.c $(SRC)/4-0-RPN.c

4-05: $(SRC)/4-05.c $(SRC)/4-05func.c $(SRC)/4-0-RPN.c
	$(CC) $(CFLAGS) -o $(BUILD)/$@ $? -lm

4-06: $(SRC)/4-06.c $(SRC)/4-06func.c $(SRC)/4-0-RPN.c
	$(CC) $(CFLAGS) -o $(BUILD)/$@ $? -lm

4-10: $(SRC)/4-10.c $(SRC)/4-10func.c $(SRC)/4-0-RPN.c $(SRC)/1-16func.c
	$(CC) $(CFLAGS) -o $(BUILD)/$@ $? -lm

%: $(TEST)/%.c $(UNITY)/unity.c
	$(CC) $(CFLAGS) -o $(BUILD)/$@ $?

test: $(tests)

clean:
	$(RM) $(BUILD)/* $(BIN)/*
