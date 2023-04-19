#ifndef FUNCIONES_GRUPOS_H
#define FUNCIONES_GRUPOS_H

#include <iostream>
#include "grupos.h"
#include "constantes.h"

void ordenar_grupos_alfabeticamente(std::string* grupos, const size_t& tamanio);
bool verificar_grupo(std::string* grupos, const std::string& grupo, const size_t& totalGrupos);
void ampliar_vector_grupos(std::string*& grupos, const size_t& totalGrupos, std::size_t& tamanio);
void verificar_vector_grupos(std::string*& grupos, const size_t& totalGrupos, size_t& tamanio);
void obtener_grupos(Equipos* equipos, Grupos* grupos);
#endif // FUNCIONES_GRUPOS_H