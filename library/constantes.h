#ifndef CONSTANTES_H    
#define CONSTANTES_H

#include <iostream>

const size_t TAMANIO = 1;
const std::string ARCHIVO_EQUIPOS = "../equipos.txt"; 
const std::string ARCHIVO_RESULTADOS = "../resultados.csv";

enum FASES {GRUPOS, OCTAVOS, CUARTOS, SEMIFINALES, FINAL, POR_TERCER_PUESTO};
enum RESULTADOS {NOMBRE_PAIS_1, GOLES_1, PENALES_1, NOMBRE_PAIS_2, GOLES_2, PENALES_2};
enum TITULOS {CUARTO_PUESTO, TERCER_PUESTO, SUBCAMPEON, CAMPEON};

const int VICTORIA = 3;
const int VICTORIA_POR_PENALES = 2;
const int EMPATE = 1;
const int DERROTA_POR_PENALES = 1;
const int DERROTA = 0;
const int TOTAL_FASES = 6;

#endif // CONSTANTES_H