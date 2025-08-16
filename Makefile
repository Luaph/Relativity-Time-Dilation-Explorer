CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -Iinclude -lm
SRC = src/main.c src/DG.c src/DC.c
OBJ = $(SRC:.c=.o)
EXEC = time_dilation

all: $(EXEC)

$(EXEC): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	del /Q src\*.o 2>nul
	del /Q $(EXEC).exe 2>nul

.PHONY: all clean
