## Absolute minimal Makefile: always compiles everything in one gcc call.

.PHONY: all clean run kill

EXE = time_dilation.exe
CC  = gcc
CFLAGS = -std=c99 -Wall -O0 -g -Iinclude -IC:/raylib/raylib/src -D_DEFAULT_SOURCE
LDFLAGS = -LC:/raylib/raylib/src
LDLIBS = -lraylib -lopengl32 -lgdi32 -lwinmm
SRC = src/main.c src/DC.c src/DG.c src/mapping.c src/constants.c src/simulation.c src/hud.c

DEL_CMD = rm -f "$(EXE)"

all:
	$(info [BUILD] $(EXE))
	@$(DEL_CMD)
	$(CC) $(CFLAGS) $(SRC) $(LDFLAGS) $(LDLIBS) -o $(EXE)
	$(info Built $(EXE))

clean:
	$(info Cleaning...)
	@$(DEL_CMD)
	$(info Clean done)

run: all
	$(info Running $(EXE))
	$(EXE)

kill:
	$(info Killing $(EXE) if running)
	-taskkill /IM $(EXE) /F > NUL 2>&1 || echo Not running
