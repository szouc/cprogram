CC := gcc
CFLAG := -Og -Wall

BIN := bin
SRC := .

SOURCES := $(wildcard $(patsubst %, %/*.c, $(SRC)))
OBJECTS := $(patsubst %.c, %.o, $(SOURCES))

01: $(BIN)/01
02: $(BIN)/02
03: $(BIN)/03
22: $(BIN)/22

all: $(OBJECTS)

.PHONY: cl22
cl22:
	-$(RM) $(BIN)/22
	-$(RM) $(OBJECTS)

run22: 22
	./$(BIN)/22

$(BIN)/22: $(BIN)/%: CH06_%.c
	$(CC) $(CFLAG) $< -o $@

$(OBJECTS): %.o: %.c
	$(CC) $(CFLAG) -c $? -o $@