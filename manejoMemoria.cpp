#include "manejoMemoria.h"

void liberar_memoria(Equipos* equipos){
    for(size_t i = 0; i < equipos->totalPaises; i++){
        delete equipos->paises[i];
    }

    delete[] equipos->paises;
    delete equipos;
}

void ampliar_vector_equipos(Equipos* equipos){
    equipos->tamanio += 1;
    Pais** vectorAmpliado = new Pais* [equipos->tamanio];

    for(size_t i = 0; i < equipos->totalPaises; i++){
        vectorAmpliado[i] = equipos->paises[i];
    }

    delete[] equipos->paises;
    equipos->paises = vectorAmpliado;
    
}

void verificar_memoria(Equipos* equipos){
    if(equipos->totalPaises >= equipos->tamanio){
        ampliar_vector_equipos(equipos);
    }
}