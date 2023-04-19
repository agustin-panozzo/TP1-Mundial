#ifndef FUNCIONES_GRUPOS_H
#define FUNCIONES_GRUPOS_H

#include <iostream>
#include "grupos.h"
#include "constantes.h"

/*
Pre: -
Post: Ordena los grupos alfabeticamente
*/
void ordenar_grupos_alfabeticamente(std::string* grupos, const size_t& tamanio);

/*
Pre: -
Post: Verifica si el grupo ya existe en el vector de grupos
*/
bool verificar_grupo(std::string* grupos, const std::string& grupo, const size_t& totalGrupos);

/*
Pre: -
Post: Amplia el tamaño del vector grupos
*/
void ampliar_vector_grupos(std::string*& grupos, const size_t& totalGrupos, std::size_t& tamanio);

/*
Pre: -
Post: Verifica si el vector grupos necesita ampliarse
*/
void verificar_vector_grupos(std::string*& grupos, const size_t& totalGrupos, size_t& tamanio);

/*
Pre: -
Post: Inicializa el struct grupos
*/
void inicializar_grupos(Grupos* grupos);

/*
Pre: -
Post: Carga el vector grupos con los grupos del struct equipos
*/
void obtener_grupos(Equipos* equipos, Grupos* grupos);

/*
Pre: -
Post: Carga el vector paisesPorGrupo con el pais correspondiente en funcion del puntaje en la fase especificada
*/
void insertar_pais_por_insercion(Pais** paisesPorGrupo, Pais* pais, size_t& indice, FASES fase);

/*
Pre: -
Post: Muestra el puntaje de los paises por grupos ordenados por puntaje descendente
*/
void mostrar_puntaje_por_grupos(Grupos* grupos, Equipos* equipos);

/*
Pre: -
Post: Muestra el puntaje de los paises en la fase especificada ordenados por puntaje descendente
*/
void mostrar_puntaje_general(Equipos* equipos, FASES fase);

#endif // FUNCIONES_GRUPOS_H