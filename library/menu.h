#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include "equipos.h"
#include "funcionesEquipos.h"
#include "funcionesGrupos.h"

/*
Pre: -
Post: Imprime el menu y solicita al usuario que ingrese una opcion
*/
int menu();

/*
Pre: -
Post: Imprime los equipos con sus respecticos grupos
*/
void mostrar_equipos(Equipos* equipos);

/*
Pre: -
Post: Solicita al usuario el nombre del pais e imprime los datos
*/
void buscar_equipo(Equipos* equipos);

/*
Pre: -
Post: Imprime los paises con el titulo de campeon, subcampeon y tercer lugar junto con el puntaje total
*/
void mostrar_top3(Equipos* equipos);

/*
Pre: -
Post: Muestra el puntaje de todos los paises por fase ordenados de forma descendente
*/
void mostrar_por_puntaje(Equipos* equipos);

#endif // MENU_H