CC=cc
CFLAGS=-Wall
DBFLAGS=-Og -ggdb3
RLFLAGS=-O2
LIBS=
OBJ_DIR=./obj
SRC_DIR=./src
SRC=$(wildcard $(SRC_DIR)/*.c)
OBJ=$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
PROG=a.out

all: release

debug: CFLAGS+=$(DBFLAGS)
debug: $(PROG)
release: CFLAGS+=$(RLFLAGS)
release: $(PROG)

$(PROG):$(OBJ)|$(BIN_DIR)
	$(CC) $(CFLAGS) $(LIBS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c|$(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all debug release
