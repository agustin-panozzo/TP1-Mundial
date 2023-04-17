#include "../library/funcionesAuxiliares.h"

using namespace std;

int calcular_largo_string(const string& cadena){
    int indice = 0;
    while(cadena[indice] != '\0'){
        indice++;
    }

    return indice;
}

bool mayor_string(const string& cadena1, const string& cadena2){
    int longitudCadena1 = calcular_largo_string(cadena1);
    int longitudCadena2 = calcular_largo_string(cadena2);
    int longitudMinima = min(longitudCadena1, longitudCadena2);
    bool esMayor = false;
    int indice = 0;

    if(tolower(cadena1[indice]) > tolower(cadena2[indice])){ //Comparo el primer caracter
        esMayor = true;
    }

    else{ 
        while(tolower(cadena1[indice]) == tolower(cadena2[indice]) && esMayor == false && indice < longitudMinima){
        indice++;

        if(cadena1[indice] > cadena2[indice]){
            esMayor = true;
        }
        }
    }

    return esMayor;
}

bool comparar_strings(const string& cadena1, const string& cadena2){
    bool sonIguales = true;
    int largoCadena1 = calcular_largo_string(cadena1);
    int largoCadena2 = calcular_largo_string(cadena2);

    if(largoCadena1 != largoCadena2){
        sonIguales = false;
    }

    for(int i = 0; i < min(largoCadena1, largoCadena2); i++){
        if(tolower(cadena1[i]) != tolower(cadena2[i])){
            sonIguales = false;
        }
    }

    return sonIguales;
}

