#include "../library/grupos.h"

using namespace std;

void ordenar_grupos_alfabeticamente(string* grupos, const size_t& tamanio){
    for(size_t i = 0; i < tamanio; i++){
        for(size_t j = 0; j < tamanio - 1; j++){
            if(mayor_string(grupos[j], grupos[j + 1])){
                string aux = grupos[j];
                grupos[j] = grupos[j + 1];
                grupos[j + 1] = aux;
            }
        }
    }
}

bool verificar_grupo(string* grupos, const string& grupo, const size_t& totalGrupos){
    bool existeGrupo = false;

    for(size_t i = 0; i < totalGrupos; i++){
        if(comparar_strings(grupos[i], grupo)){
            existeGrupo = true;
        }
    }

    return existeGrupo;
}

void ampliar_vector_grupos(string*& grupos, const size_t& totalGrupos, size_t& tamanio){
    string* vectorAmpliado = new string [tamanio + 1];

    for(size_t i = 0; i < totalGrupos; i++){
        vectorAmpliado[i] = grupos[i];
    }

    delete[] grupos;
    grupos = vectorAmpliado;
    tamanio++;
}

void verificar_vector_grupos(string*& grupos, const size_t& totalGrupos, size_t& tamanio){
    if(tamanio <= totalGrupos){
        ampliar_vector_grupos(grupos, totalGrupos, tamanio);
    }
}

void inicializar_grupos(Grupos* grupos){
    grupos->listaGrupos = new string[1];
    grupos->tamanio = 1;
    grupos->totalGrupos = 0;
}

void obtener_grupos(Equipos* equipos, Grupos* grupos){
    size_t indice = 0;

    for(size_t i = 0; i < equipos->totalPaises; i++){

        if(!verificar_grupo(grupos->listaGrupos, equipos->paises[i]->grupo, grupos->totalGrupos)){
            verificar_vector_grupos(grupos->listaGrupos, grupos->totalGrupos, grupos->tamanio);
            grupos->listaGrupos[indice] = equipos->paises[i]->grupo;
            indice++;
            grupos->totalGrupos++;
        }
    }
    ordenar_grupos_alfabeticamente(grupos->listaGrupos, grupos->tamanio);
}

void insertar_pais_por_insercion(Pais** paisesPorGrupo, Pais* pais, size_t& indice, FASES fase){
    size_t i = indice;

    while (i > 0 && paisesPorGrupo[i - 1]->puntajes[fase] < pais->puntajes[fase]) {
        paisesPorGrupo[i] = paisesPorGrupo[i - 1];
        i--;
    }

    paisesPorGrupo[i] = pais;
    indice++;
}

void mostrar_puntaje_por_grupos(Grupos* grupos, Equipos* equipos){
    
    cout << "FASE GRUPOS" << endl;

    for(size_t i = 0; i < grupos->totalGrupos; i++){

        cout << "\nGRUPO " << grupos->listaGrupos[i] << endl;
        Pais* paisesPorGrupo[4];
        size_t indice = 0;

        for(size_t j = 0; j < equipos->totalPaises; j++){
            if(comparar_strings(grupos->listaGrupos[i], equipos->paises[j]->grupo)){
                insertar_pais_por_insercion(paisesPorGrupo, equipos->paises[j], indice, GRUPOS);
            }
        }

        for(size_t j = 0; j < 4; j++){
            cout << paisesPorGrupo[j]->nombre << ": " << paisesPorGrupo[j]->puntajes[GRUPOS] << " puntos"<< endl;
        }
    }

    cout << endl;
}

void mostrar_puntaje_general(Equipos* equipos, FASES fase){
    Pais* paisesPorPuntaje[equipos->totalPaises];
    size_t indice = 0;

    for(size_t i = 0; i < equipos->totalPaises; i++){
        insertar_pais_por_insercion(paisesPorPuntaje, equipos->paises[i], indice, fase);
    }

    for(size_t i = 0; i < equipos->totalPaises; i++){
        cout << paisesPorPuntaje[i]->nombre << ": " << paisesPorPuntaje[i]->puntajes[fase] << " puntos"<< endl;
    }
}

void mostrar_por_puntaje(Equipos* equipos){
    Grupos* grupos = new Grupos;
    inicializar_grupos(grupos);
    obtener_grupos(equipos, grupos);

    mostrar_puntaje_por_grupos(grupos, equipos);
    for(enum FASES i = OCTAVOS; i < TOTAL_FASES; i = FASES(i + 1)){
        cout << "\nFASE " << fase_a_string(i) << endl;
        mostrar_puntaje_general(equipos, i);
        cout << endl;
    }
    //----------------------------------------------

    delete grupos;
}