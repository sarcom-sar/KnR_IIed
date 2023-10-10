CC = gcc
CFLAGS = -Wall

SRC = ./Src
BUILD = ./Build

SRCS = $(wildcard $(SRC)/*.c)
PROGS = $(SRCS:$(SRC)/%.c=%)

all: $(PROGS)

%: $(SRC)/%.c
	$(CC) $(CFLAGS) -o $(BUILD)/$@ $<

clean:
	$(RM) $(BUILD)/*
