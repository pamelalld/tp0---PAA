#ifndef FIGURAS
#define FIGURAS

#include "tipoPincel.h"

void criaQuadroVazio (int linhas,int colunas, TipoPincel quadro[linhas][colunas]);
void sorteiaCores(int quant, int vetorID[], int vetorCores[]);
void selecionaCor(int id);
void imprimeQuadro(int quantFiguras, int linhas, int colunas, TipoPincel quadro[linhas][colunas]);
void insereAsterisco(int quantidade,int linhas,int colunas,TipoPincel quadro[linhas][colunas],int* id);
void insereCruz(int quantidade,int linhas,int colunas,TipoPincel quadro[linhas][colunas],int* id);
void insereX(int quantidade,int linhas,int colunas,TipoPincel quadro[linhas][colunas],int* id);
void sorteiaFigura (int quantidade,int linhas,int colunas,TipoPincel quadro[linhas][colunas],int* id);

#endif
