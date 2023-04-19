#ifndef PAIS_H
#define PAIS_H

#include <iostream>

struct Pais {
    std::string nombre;
    std::string grupo;
    int fase;
    int titulo;
    int puntajes[6]; // [puntaje_grupos, puntaje_octavos_, puntaje_cuartos, puntaje_semifinal, puntaje_final, puntaje_tercer_fase]
    int puntajeTotal;
};

#endif // PAIS_H