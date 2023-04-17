#include "../library/menu.h"

using namespace std;

int menu(){
    int opcion;
    cout << "1.Listar equipos." << endl;
    cout << "2.Mostrar los equipos en primer, segundo y tercer lugar." << endl;
    cout << "3.Buscar equipo por nombre." << endl;
    cout << "4.Mostrar por fase los paises ordenados por puntaje" << endl;
    cout << "5.Salir." << endl;
    
    cout << "Elige una opcion: ";
    cin >> opcion;

    return opcion;

}

void mostrar_equipos(Equipos* equipos){
    for(size_t i = 0; i < equipos->totalPaises; i++){
        cout << "Pais: "<< equipos->paises[i]->nombre << " Grupo: " << equipos->paises[i]->grupo << endl;
    }

    cout << endl;
}

void buscar_equipo(Equipos* equipos){
    string nombrePais;
    Pais* pais;

    cout << "Ingrese el nombre del pais: " << endl;
    getline(cin >> ws, nombrePais);

    if(encontrar_pais(nombrePais, equipos) != nullptr){
        pais = encontrar_pais(nombrePais, equipos);

        cout << "Pais: " << pais->nombre << endl;
        cout << "Grupo: "<< pais->grupo << endl;
        cout << "Fase: " << fase_a_string(pais->fase) << endl;
        cout << "Titulo: " << titulo_a_string(pais->titulo) << endl;
    }
    else{
        cout << "La busqueda no arrojo resultados." << endl;
    }

    cout << endl;
}

void mostrar_top3(Equipos* equipos){
    Pais* top3[3];

    top3[0] = buscar_por_titulo(equipos, CAMPEON);
    top3[1] = buscar_por_titulo(equipos, SUBCAMPEON);
    top3[2] = buscar_por_titulo(equipos, TERCER_PUESTO);

    for(int i = 0; i < 3; i++){
        cout << "Pais: " << top3[i]->nombre << " Puntaje Total: " << top3[i]->puntajeTotal << endl;
    }

    cout << endl;
}

