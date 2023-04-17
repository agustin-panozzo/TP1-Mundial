#include "library/archivos.h"

using namespace std;

Pais* procesar_equipos(const string& linea){
    int indice = 0;
    string palabras[2];

    for(char c : linea){
        if(c == ' '){
            indice++;
        }

        else if(c == '_'){
            palabras[indice] += ' ';
        }

        else{
            palabras[indice] += c;
        }
        }

    return generar_equipo(palabras[0], palabras[1]);
}

void cargar_archivo_equipos(Equipos* equipos){
    string linea;
    string palabras[2];

    ifstream archivo(ARCHIVO_EQUIPOS);
    while(getline(archivo, linea)){
        Pais* pais = procesar_equipos(linea);
        cargar_equipo(pais, equipos);
    }

    archivo.close();
}

void procesar_resultados(const string& linea, const int& fase, Equipos* equipos){
    string lineaProcesada[6]; //equipo1,goles1,penales1,equipo2,goles2,penales2
    int indice = 0;
    for(char c : linea){
        if((indice == 2 || indice == 5) && (fase == GRUPOS)){  //Me salteo las posiciones de penales
            indice++;
        }
        
        if(c == ','){
            indice++;
        }
        else{
            lineaProcesada[indice] += c;
        }
    }

    determinar_ganador(lineaProcesada, fase, equipos);
}


void cargar_archivo_resultados(Equipos* equipos){
    string linea;
    int fase;
    ifstream archivo(ARCHIVO_RESULTADOS);
    while(getline(archivo, linea)){

        if(verificar_fase(linea)){
            fase = linea_a_fase(linea);
        }
        else{
            procesar_resultados(linea, fase, equipos);
        }   
    }

    archivo.close();
}