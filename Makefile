BIN = graph

.PHONY: run clean

run: 
	make $(BIN) && ./$(BIN)

$(BIN): main.c graph.c utils.c coloring.c 
	gcc main.c \
		graph.c \
		utils.c \
		coloring.c \
	-o $(BIN) \
	-Wall

clean: 
	rm $(BIN)