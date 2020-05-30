CC := gcc
CFLAG := -Og -Wall

BIN := bin
INTERMEIDATES := intermediates
SRC := .
PREFIX := CH07_

SOURCES := $(wildcard $(patsubst %, %/*.c, $(SRC)))
OBJECTS := $(patsubst ./%.c, $(INTERMEIDATES)/%.o, $(SOURCES))

all: $(OBJECTS)

01: $(BIN)/$(PREFIX)01

run01: 01 
	./$(BIN)/$(PREFIX)01

$(BIN)/$(PREFIX)01: $(BIN)/%: %.c
	$(CC) $(CFLAG) $< -o $@

.PHONY: cl01
cl01:
	-$(RM) $(BIN)/$(PREFIX)01

02: $(BIN)/$(PREFIX)02

run02: 02 
	./$(BIN)/$(PREFIX)02

$(BIN)/$(PREFIX)02: $(BIN)/%: %.c
	$(CC) $(CFLAG) $< -o $@

.PHONY: cl02
cl02:
	-$(RM) $(BIN)/$(PREFIX)02

03: $(BIN)/$(PREFIX)03

run03: 03
	./$(BIN)/$(PREFIX)03

$(BIN)/$(PREFIX)03: $(BIN)/%: %.c
	$(CC) $(CFLAG) $< -o $@ -lm

.PHONY: cl03
cl03:
	-$(RM) $(BIN)/$(PREFIX)03
    
04: $(BIN)/$(PREFIX)04

run04: 04
	./$(BIN)/$(PREFIX)04

$(BIN)/$(PREFIX)04: $(BIN)/%: %.c
	$(CC) $(CFLAG) $< -o $@ -lm

.PHONY: cl04
cl04:
	-$(RM) $(BIN)/$(PREFIX)04

05: $(BIN)/$(PREFIX)05

run05: 05
	./$(BIN)/$(PREFIX)05

$(BIN)/$(PREFIX)05: $(BIN)/%: %.c
	$(CC) $(CFLAG) $< -o $@ -lm

.PHONY: cl05
cl05:
	-$(RM) $(BIN)/$(PREFIX)05

06: $(BIN)/$(PREFIX)06

run06: 06
	./$(BIN)/$(PREFIX)06

$(BIN)/$(PREFIX)06: $(BIN)/%: %.c
	$(CC) $(CFLAG) $< -o $@ -lm

.PHONY: cl06
cl06:
	-$(RM) $(BIN)/$(PREFIX)06

$(OBJECTS): $(INTERMEIDATES)/%.o: %.c
	$(CC) $(CFLAG) -c $? -o $@