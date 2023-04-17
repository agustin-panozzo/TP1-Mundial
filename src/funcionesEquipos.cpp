#include "../library/funcionesEquipos.h"

using namespace std;

Pais* generar_equipo(string nombrePais, string grupo){
    Pais* pais = new Pais;

    pais->nombre = nombrePais;
    pais->grupo = grupo;
    pais->titulo = -1;
    pais->fase = GRUPOS;
    pais->puntajeTotal = 0;
    
    for(int i = 0; i < 6; i++){
        pais->puntajes[i] = 0; //Establezco los puntajes en cero
    }

    return pais;
}

void inicializar_equipos(Equipos* equipos, const size_t tamanio){
    equipos->paises = new Pais* [tamanio];
    equipos->tamanio = tamanio;
}

void insercion_por_alfabeto(Pais* pais, Equipos* equipos){
    size_t posicion = equipos->totalPaises;

    while(posicion > 0 && mayor_string(equipos->paises[posicion - 1]->nombre, pais->nombre)){
        equipos->paises[posicion] = equipos->paises[posicion - 1];
        posicion--;
    }

    equipos->paises[posicion] = pais;
}

void cargar_equipo(Pais* pais, Equipos* equipos){ 
    verificar_memoria(equipos);
    insercion_por_alfabeto(pais, equipos);
    equipos->totalPaises++;

}

Pais* encontrar_pais(const string& nombre, Equipos* equipos){
    size_t indice = 0;
    Pais* paisBuscado = nullptr;

    while(!comparar_strings(nombre, equipos->paises[indice]->nombre) && indice < equipos->totalPaises){
        indice++;
    }

    if(comparar_strings(nombre, equipos->paises[indice]->nombre)){
        paisBuscado = equipos->paises[indice];
    }

    return paisBuscado;
}

bool verificar_fase(const string& linea){
    bool esFase = false;

    if(comparar_strings(linea, "GRUPOS")){
        esFase = true;
    }
    else if(comparar_strings(linea, "OCTAVOS")){
        esFase = true;
    }
    else if(comparar_strings(linea, "CUARTOS")){
        esFase = true;
    }
    else if(comparar_strings(linea, "SEMIFINALES")){
        esFase = true;
    }
    else if(comparar_strings(linea, "FINAL")){
        esFase = true;
    }

    else if(comparar_strings(linea, "TERCER PUESTO"))
        esFase = true;

    return esFase;
}

int linea_a_fase(const string& linea){
    int fase;

    if(comparar_strings(linea, "GRUPOS")){
        fase = GRUPOS;
    }
    else if(comparar_strings(linea, "OCTAVOS")){
        fase = OCTAVOS;
    }
    else if(comparar_strings(linea, "CUARTOS")){
        fase = CUARTOS;
    }
    else if(comparar_strings(linea, "SEMIFINALES")){
        fase = SEMIFINALES;
    }
    else if(comparar_strings(linea, "FINAL")){
        fase = FINAL;
    }

    else if(comparar_strings(linea, "TERCER PUESTO")){
        fase = POR_TERCER_PUESTO;
    }

    return fase;
}

string fase_a_string(const int& fase){
    string faseCadena;

    
    if(fase == GRUPOS){
        faseCadena = "GRUPOS";
    }

    else if(fase == OCTAVOS){
        faseCadena = "OCTAVOS";
    }

    else if(fase == CUARTOS){
        faseCadena = "CUARTOS";
    }

    else if(fase == SEMIFINALES){
        faseCadena = "SEMIFINALES";
    }

    else if(fase == FINAL){
        faseCadena = "FINALES";
    }

    else if(fase == POR_TERCER_PUESTO){
        faseCadena = "TERCER PUESTO";
    }

    return faseCadena;
}

string titulo_a_string(const int& titulo){
    string cadenaTitulo;
    
    if(titulo == -1){
        cadenaTitulo = "No posee";
    }

    else if(titulo == CAMPEON){
        cadenaTitulo = "CAMPEON";
    }

    else if(titulo == SUBCAMPEON){
        cadenaTitulo = "SUBCAMPEON";
    }

    else if(titulo == TERCER_PUESTO){
        cadenaTitulo = "TERCER PUESTO";
    }

    else if(titulo == CUARTO_PUESTO){
        cadenaTitulo = "CUARTO PUESTO";
    }

    return cadenaTitulo;
}

void actualizar_datos_equipo(const string& paisNombre, const int &fase, Equipos* equipos, const int& resultadoPartido){
    Pais* pais = encontrar_pais(paisNombre, equipos);
    pais->puntajes[fase] += resultadoPartido;
    pais->puntajeTotal += resultadoPartido;

    if(pais->fase < fase){
    pais->fase = fase;
    }

    if(fase == FINAL){
        if(resultadoPartido == VICTORIA || resultadoPartido == VICTORIA_POR_PENALES){
            pais->titulo = CAMPEON;
        }
        else{
            pais->titulo = SUBCAMPEON;
        }
    }

    else if(fase == POR_TERCER_PUESTO){
        if(resultadoPartido == VICTORIA || resultadoPartido == VICTORIA_POR_PENALES){
            pais->titulo = TERCER_PUESTO;
        }
        else{
            pais->titulo = CUARTO_PUESTO;
        }
    }
}

void determinar_ganador(const string lineaProcesada[], int fase, Equipos* equipos){

    if(stoi(lineaProcesada[GOLES_1]) > stoi(lineaProcesada[GOLES_2])){
        actualizar_datos_equipo(lineaProcesada[NOMBRE_PAIS_1], fase, equipos, VICTORIA);
        actualizar_datos_equipo(lineaProcesada[NOMBRE_PAIS_2], fase, equipos, DERROTA);
    }

    else if(stoi(lineaProcesada[GOLES_1]) < stoi(lineaProcesada[GOLES_2])){
        actualizar_datos_equipo(lineaProcesada[NOMBRE_PAIS_2], fase, equipos, VICTORIA);
        actualizar_datos_equipo(lineaProcesada[NOMBRE_PAIS_1], fase, equipos, DERROTA);
    }

    else if(fase == GRUPOS){ //Considero empate solo en fase de grupos
        actualizar_datos_equipo(lineaProcesada[NOMBRE_PAIS_1], fase, equipos, EMPATE);
        actualizar_datos_equipo(lineaProcesada[NOMBRE_PAIS_2], fase, equipos, EMPATE);
    }

    else{
        if(stoi(lineaProcesada[PENALES_1]) > stoi(lineaProcesada[PENALES_2])){
            actualizar_datos_equipo(lineaProcesada[NOMBRE_PAIS_1], fase, equipos, VICTORIA_POR_PENALES);
            actualizar_datos_equipo(lineaProcesada[NOMBRE_PAIS_2], fase, equipos, DERROTA_POR_PENALES);
        }
        else if(stoi(lineaProcesada[PENALES_1]) > stoi(lineaProcesada[PENALES_2])){
            actualizar_datos_equipo(lineaProcesada[NOMBRE_PAIS_2], fase, equipos, VICTORIA_POR_PENALES);
            actualizar_datos_equipo(lineaProcesada[NOMBRE_PAIS_1], fase, equipos, DERROTA_POR_PENALES);
        }
    }
}

Pais* buscar_por_titulo(Equipos* equipos, const int& titulo){
    Pais* pais = nullptr;

    for(size_t i = 0; i < equipos->totalPaises; i++){
        if(equipos->paises[i]->titulo == titulo){
            pais = equipos->paises[i];
        }
    }

    return pais;
}