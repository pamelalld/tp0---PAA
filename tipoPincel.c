#ifndef TIPOPINCEL
#define TIPOPINCEL

#include "tipoPincel.h"
#include <stdlib.h>
#include <time.h>

TipoPincel* inicializaX(int id){

    TipoPincel *item;
    item = (TipoPincel*) malloc (sizeof(TipoPincel));
    item->caractere='*';
    item->tipoFig='x';
    item->idFigura=id;

    return item;
}
TipoPincel* inicializaPonto(int id){

    TipoPincel *item;
    item = (TipoPincel*) malloc (sizeof(TipoPincel));
    item->caractere='*';
    item->tipoFig='*';
    item->idFigura=id;

    return item;

}
TipoPincel* inicializaCruz(int id){

    TipoPincel *item;
    item = (TipoPincel*) malloc (sizeof(TipoPincel));
    item->caractere='*';
    item->tipoFig='+';
    item->idFigura=id;

    return item;

}

#endif