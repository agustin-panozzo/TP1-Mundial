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

void mostrar_puntaje_por_grupos(Grupos* grupos, Equipos* equipos){
    for(size_t i = 0; i < grupos->totalGrupos; i++){

        cout << "\nGRUPO " << grupos->listaGrupos[i] << endl;
        Pais* paisesPorGrupo[4];
        size_t indice = 0;

        for(size_t j = 0; j < equipos->totalPaises; j++){
            if(comparar_strings(grupos->listaGrupos[i], equipos->paises[j]->grupo)){
                paisesPorGrupo[indice] = equipos->paises[j];
                indice++;
            }
        }

        for(size_t j = 0; j < 4; j++){
            cout << paisesPorGrupo[j]->nombre << ": " << paisesPorGrupo[j]->puntajes[0] << " puntos"<< endl;
        }
    }

    cout << endl;
}

void mostrar_por_puntaje(Equipos* equipos){
    Grupos* grupos = new Grupos;
    inicializar_grupos(grupos);
    obtener_grupos(equipos, grupos);

    mostrar_puntaje_por_grupos(grupos, equipos);
    
    //----------------------------------------------

    delete grupos;
}