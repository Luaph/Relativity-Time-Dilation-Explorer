## Absolute minimal Makefile: always compiles everything in one gcc call.

.PHONY: all clean run kill

EXE = time_dilation.exe
CC  = gcc
CFLAGS = -std=c99 -Wall -O0 -g -Iinclude -IC:/raylib/raylib/src -D_DEFAULT_SOURCE
LDFLAGS = -LC:/raylib/raylib/src
LDLIBS = -lraylib -lopengl32 -lgdi32 -lwinmm
SRC = src/main.c src/DC.c src/DG.c src/mapping.c src/constants.c src/simulation.c src/hud.c

all:
	@echo [BUILD] $(EXE)
	-del /Q $(EXE) 2> NUL || cmd /c exit 0
	$(CC) $(CFLAGS) $(SRC) $(LDFLAGS) $(LDLIBS) -o $(EXE)
	@echo Built $(EXE)
	@dir /-C $(EXE)

clean:
	@echo Cleaning...
	-del /Q $(EXE) 2> NUL || cmd /c exit 0
	@echo Clean done

run: all
	@echo Running $(EXE)
	$(EXE)

kill:
	@echo Killing $(EXE) if running
	-taskkill /IM $(EXE) /F > NUL 2>&1 || echo Not running
