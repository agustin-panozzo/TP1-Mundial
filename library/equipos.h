#ifndef EQUIPOS_H
#define EQUIPOS_H

#include <iostream>
#include "pais.h"

struct Equipos {
    Pais** paises = nullptr;   
    size_t tamanio;
    size_t totalPaises = 0;
};

#endif // EQUIPOS_H