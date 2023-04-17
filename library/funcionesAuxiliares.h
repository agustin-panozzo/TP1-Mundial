#ifndef FUNCIONES_AUXILIARES
#define FUNCIONES_AUXILIARES

#include <iostream>


/*
Pre: Recibe un dato de tipo string
Post: Devuelve la cantidad de caracteres que contiene la cadena
*/
int calcular_largo_string(const std::string& cadena);


/*
Pre: Recibe dos datos de tipo string
Post: Devuelve true si la primer cadena es mayor que la segunda (en orden lexicografico) y false en caso contrario
*/
bool mayor_string(const std::string& cadena1, const std::string& cadena2);

/*
Pre: Recibe dos datos de tipo string
Post: Devuelve true si las dos cadenas son iguales y false en caso contrario
*/
bool comparar_strings(const std::string& cadena1, const std::string& cadena2);

#endif // FUNCIONES_AUXILIARES