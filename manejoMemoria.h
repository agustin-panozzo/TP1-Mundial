#ifndef MANEJO_MEMORIA_H
#define MANEJO_MEMORIA_H

#include "equipos.h"

/*
Pre: Recibe un puntero a Struct Equipos creado en memoria dinámica
Post: -
*/
void liberar_memoria(Equipos* equipos);

/*
Pre: Recibe un puntero a Struct Equipos creado en memoria dinámica
Post: Amplia el tamaño del vector
*/
void ampliar_vector_equipos(Equipos* equipos);

/*
Pre: Recibe un puntero a Struct Equipos creado en memoria dinámica
Post: Verifica la memoria del vector "paises" y solicita memoria en caso de ser necesario
*/
void verificar_memoria(Equipos* equipos);

#endif // MANEJO_MEMORIA_H