#ifndef FUNCIONES_EQUIPOS_H
#define FUNCIONES_EQUIPOS_H

#include <iostream>
#include <string>
#include "pais.h"
#include "equipos.h"
#include "funcionesAuxiliares.h"
#include "manejoMemoria.h"
#include "constantes.h"

/*
Pre: -
Post: Inicializa un Struct Pais en memoria dinamica y devuelve el puntero
*/
Pais* generar_equipo(std::string nombrePais, std::string grupo);

/*
Pre: Recibe un valor numerico mayor a cero
Post: Rellena el Struct Equipos
*/
void inicializar_equipos(Equipos* equipos, const size_t tamanio);

/*
Pre: -
Post: Inserta el Struct Pais dentro del vector contenido en Struct Equipos utilizando ordenamiento por insercion
*/
void insercion_por_alfabeto(Pais* pais, Equipos* equipos);

/*
Pre: -
Post: Llama a funciones auxiliares para insertar el Struct Pais dentro del Struct Equipos
*/
void cargar_equipo(Pais* pais, Equipos* equipos);

/*
Pre: -
Post: Devuelve un puntero al Struct Pais que coincida con el nombre recibido por parametro
*/
Pais* encontrar_pais(const std::string& nombre, Equipos* equipos);

/*
Pre: -
Post: Devuelve true si el string recibido coincide con una de las fases del torneo y false en caso contrario
*/
bool verificar_fase(const std::string& linea);

/*
Pre: El parametro recibido debe ser una fase del torneo
Post: Convierte el tipo de dato string a su equivalente en entero considerando el enum FASES y lo devuelve
*/
int linea_a_fase(const std::string& linea);

/*
Pre: -
Post: Convierte el tipo de dato entero a su equivalente en string considerando el enum TITULOS y lo devuelve
*/
std::string titulo_a_string(const int& titulo);

/*
Pre: El pais debe de existir en el listado de equipos.
Post: Actualiza los datos del Struct Pais en funcion de los resultados del partido
*/
void actualizar_datos_equipo(const std::string& paisNombre, const int &fase, Equipos* equipos, const int& resultadoPartido);

/*
Pre: Recibe un vector con el formato [pais1, goles1, penales1, pais2, goles2, penales2]
Post: Define quien es el ganador del partido y en base a eso asigna los puntos llamando a una funcion auxiliar
*/
void determinar_ganador(const std::string lineaProcesada[], int fase, Equipos* equipos);

/*
Pre: -
Post: Convierte el tipo de dato entero a su equivalente en string considerando el enum FASES y lo devuelve
*/
std::string fase_a_string(const int& fase);

/*
Pre: -
Post: Devuelve un puntero a Struct Pais que coincida con el titulo recibido por parametro
*/
Pais* buscar_por_titulo(Equipos* equipos, const int& titulo);

#endif // FUNCIONES_EQUIPOS_H