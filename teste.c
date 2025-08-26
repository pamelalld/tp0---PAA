#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definições de cores ANSI
#define RESET  "\x1b[0m"
#define BLUE   "\x1b[1;34m"

// Cores possíveis para os demais elementos
const char* cores[] = {
    "\x1b[31m", // vermelho
    "\x1b[32m", // verde
    "\x1b[33m", // amarelo
    "\x1b[35m", // magenta
};

int main(void) {
    char matriz[4][4] = {
        {' ', '*', '*', '*'},
        {'*', '*', '*', '*'},
        {'*', '*', '*', '*'},
        {' ', '*', ' ', '*'}
    };

    srand(time(NULL)); // inicializa o gerador de números aleatórios

    // sorteia a cor para todos os elementos "não azuis"
    int corIndex = rand() % (sizeof(cores) / sizeof(cores[0]));
    const char* corEscolhida = cores[corIndex];

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if ((i == 1 && j == 2) || (i == 1 && j == 3)) {
                printf(BLUE "%c " RESET, matriz[i][j]); // azul fixo
            } else {
                printf("%s%c " RESET, corEscolhida, matriz[i][j]); // mesma cor sorteada
            }
        }
        printf("\n");
    }

    return 0;
}
