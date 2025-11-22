#include "colaJugadores.h"
#include "cargajugadores.h"
#include "corteControlEquipos.h"

void menu();
void mostrarEquipos(FILE *);
void manejoDeEquipos();
void hacerCambio();
void corteControl();

FILE *archivo;
tColaJugadores cola;

int main() {
	archivo = NULL;          //inicializacon del archivo para almacenar los equipos conformados por los lotes de registros de los jugadores
    iniciar(&archivo);
    
	iniciarCola(&cola);       //inicializacon de la cola par alos JUGADORES
	
	menu();
	
    finalizar(&archivo);                // cerramos el archivo con todos los equipos
    printf("\n\nProceso finalizado.\n");
    
    return 0;
}

void menu(){
	int op;
	printf("###SISTEMA ESTADISTICO APLICADO A EQUIPOS DE FUTBOL###\n");
	
	do{
		printf("\nIngrese una opcion:\n");
		printf("1-Ver equipos existentes en el archivo\n");
		printf("2-Cargar un nuevo equipo\n");
		printf("3-Ver estadisticas de los equipos (corte de control)\n");
		printf("0-Salir\n");
		scanf("%d", &op);
		switch(op){
			case 1:
				mostrarEquipos(archivo);
			break;
			case 2:
				manejoDeEquipos();
			break;
			case 3:
				corteControl();
			break;
			case 0:
				break;
			default :
				printf("Opcion no valida\n");
		}
		
	}while(op != 0);
	
}
void mostrarEquipos(FILE *pArchivo){
	tJugador jugador;
	rewind(pArchivo); //como el archivo se abre con cursor a ultima posicion, usamos rewind para asegurarnos que siempre se lea desde el inicio
	fread(&jugador, sizeof(tJugador), 1, pArchivo);
	tString equipoAnt;
	printf("--------------------------------------------------------------------------\n");
	printf("\n=== EQUIPOS EXISTENTES EN EL ARCHIVO ===\n");
	
    while(!feof(pArchivo)){
    	printf("\n%s\n", jugador.club);
    	strcpy(equipoAnt, jugador.club);
    	while(strcmp(equipoAnt, jugador.club) == 0 && !feof(pArchivo)){
    		printf("Jugador: %s | Edad: %d | Goles: %d | Asistencias: %d\n", jugador.nombreJugador,jugador.edad, jugador.goles, jugador.asistencias);
        	fread(&jugador, sizeof(tJugador), 1, pArchivo);
    	}
        
    }
   printf("--------------------------------------------------------------------------\n");
}

void manejoDeEquipos(){
	char opCambio;       //para cambios
	int continuarJugador; //para continuar almacenamiento temporal previo a la carga persistente de jugadores
	tNodoJugadores *nuevo;
	tString club;
	
    printf("\n--------------------------------------------------------------------------\n");
    printf("Ingrese nombre del club: ");
    scanf(" %[^\n]", club);
    
	printf("\n= CARGA DE JUGADORES DE %s =\n", club);
    do{  //para cargar jugadores
        nuevo = crearNodo(club);
        if(nuevo != NULL){
        	encolar(&cola, nuevo);
        }else{
        	printf("\nError al asignar memoria\n");
        }
		printf("¿Desea cargar otro JUGADOR? 1-si/0-no\n");
		scanf("%d", &continuarJugador);
    }while(continuarJugador == 1);
    
    //cambiar jugadores (si lo desea el usuario) antes de ordenar las edades y valores
	printf("¿Desea realizar algun cambio? s/n\n");
	scanf(" %c", &opCambio);
	while(opCambio == 's' || opCambio == 'S'){
		hacerCambio();
		printf("¿Desea hacer algun otro cambio? s/n: ");      
		scanf(" %c", &opCambio);
	}
    
	// se carga el equipo antes de vaciar la cola y preguntar si se quiere volver a cargar la cola con algun otro equipo
	printf("\n~~~Cargando equipo jugador a jugador~~~\n");
    cargarEquipos(&cola, archivo);     //carga los campos jugador de los nodos en archivo
    while(!colaVacia(&cola)){
        desencolar(&cola);            //se desencolan todos los jugadores de la cola del equipo para cargar uno nuevo desde el inicio
    }
    printf("\n~~Equipo cargado con exito~~\n");
    printf("--------------------------------------------------------------------------\n\n");
}

void hacerCambio(){
		if(!colaVacia(&cola)){
            tString jugadorModificar; //para buscar el jugador que se quiere cambiar por su nombre
            printf("Ingrese el nombre del jugador a modificar: ");
            scanf(" %[^\n]", jugadorModificar); 
            cambioJugador(&cola, jugadorModificar);
        } else {
            printf("No hay equipo cargado actualmente.\n");
        }
}

void corteControl(){
	inicio(archivo);
	printf("--------------------------------------------------------------------------\n");
	procesoCorte(archivo);
	fin();
	printf("--------------------------------------------------------------------------\n");
}

