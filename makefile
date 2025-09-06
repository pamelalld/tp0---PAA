compile: src/cartas.c src/figuras.c src/main.c
	@gcc src/cartas.c src/figuras.c src/main.c -Iinclude -Wall -Wextra -g -o bin/main.exe

run: 
	@bin/main.exe
