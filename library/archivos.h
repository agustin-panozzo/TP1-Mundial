#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include <iostream>
#include <fstream>
#include <string>
#include "pais.h"
#include "equipos.h"
#include "constantes.h"
#include "funcionesEquipos.h"

/*
Pre: Recibe un tipo de dato string con el formato "Pais Grupo" separado por un espacio entremedio
Post: Devuelve un puntero a Struct Pais generado con la informacion recibida por parametro
*/
Pais* procesar_equipos(const std::string& linea);

/*
Pre: -
Post: Carga los datos del archivo de equipos en el Struct Equipos
*/
void cargar_archivo_equipos(Equipos* equipos);

/*
Pre: Recibe un dato de tipo string con el formato "equipo1,goles1,penales1,equipo2,goles2,penales2"
Post: Carga los datos en el struct Equipos
*/
void procesar_resultados(const std::string& linea, const int& fase, Equipos* equipos);

/*
Pre: -
Post: Carga los datos del archivo resultados en el Struct Equipos
*/
void cargar_archivo_resultados(Equipos* equipos);

#endif // ARCHIVOS_H