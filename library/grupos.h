#ifndef GRUPOS_H
#define GRUPOS_H

#include <iostream>
#include "../library/equipos.h"
#include "../library/funcionesAuxiliares.h"
#include "../library/constantes.h"
#include "../library/funcionesEquipos.h"

struct Grupos {
    std::string* listaGrupos = nullptr;
    size_t tamanio;
    size_t totalGrupos;
};

#endif // GRUPOS_H