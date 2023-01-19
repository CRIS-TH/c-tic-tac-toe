BIN = ttt
SRC = main.c
CCFLAGS = 

all: $(BIN)

debug: CCFLAGS += -DDEBUG -g
debug: $(BIN)

$(BIN): $(SRC)
	$(CC) $(CCFLAGS) $< -o $@ 

clean:
	rm $(BIN)
