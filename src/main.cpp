#include "../library/archivos.h"
#include "../library/menu.h"
#include "../library/funcionesEquipos.h"

using namespace std;

int main(){
    int opcion;
    Equipos* equipos = new Equipos;
    inicializar_equipos(equipos, TAMANIO);
    cargar_archivo_equipos(equipos);
    cargar_archivo_resultados(equipos);

    do{
        opcion = menu();
        switch (opcion)
        {
        case 1:
            mostrar_equipos(equipos);
            break;
        
        case 2:
            mostrar_top3(equipos);
            break;

        case 3:
            buscar_equipo(equipos);
            break;  
        

        case 4:
            mostrar_por_puntaje(equipos);
            break;
        }

    }while(opcion != 5);

    cout << "Terminando programa..." << endl;

    liberar_memoria(equipos);
    return 0;
}