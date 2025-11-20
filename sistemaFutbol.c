#include "colaJugadores.h"
#include "cargajugadores.h"
#include "corteControlEquipos.h"

void manejoDeEquipos();
void hacerCambio();
void corteControl();


tColaJugadores cola;
FILE *archivo;
int main() {
    iniciarCola(&cola);       //inicializacon de la cola par alos JUGADORES
    
	archivo = NULL;          //inicializacon del archivo para almacenar los equipos conformados por los lotes de registros de los jugadores
    iniciar(&archivo);
    
    
	manejoDeEquipos();      // almacenamiento dinamico de los jugadores en una cola y almacenamiento persistente de lotes de jugadores en un registro
	
	printf("\n=== CORTE DE CONTROL EN EQUIPOS ===\n");
	corteControl();
	
    finalizar(&archivo);                // cerramos el archivo con todos los equipos
    printf("\n\nProceso finalizado.\n");
    
    return 0;
}

void manejoDeEquipos(){
	char op;
	int continuarEquipo = 1;
	int continuarJugador = 1;

	tNodoJugadores *nuevo;
	
	while(continuarEquipo == 1){      //para cargar conjuntos de jugadores
		printf("\n=== CARGA DE UN NUEVO EQUIPO ===\n");
	    tString club;
	    continuarJugador = 1; //para volver a cargar jugadores (condicion para while)
	    printf("Ingrese nombre del club: ");
	    scanf(" %[^\n]", club);
	    
		printf("\n=== CARGA DE JUGADORES DE %s ===\n", club);
	    while(continuarJugador == 1){  //para cargar jugadores
	    	
	        nuevo = crearNodo(club);
	        if(nuevo != NULL){
	        	encolar(&cola, nuevo);
	        }else{
	        	printf("\nError al asignar memoria\n");
	        }
				printf("¿Desea cargar otro JUGADOR? (hasta 31 jugadores)- 1-si/0-no\n");   //carga de jugadores dentro del equipo
				scanf("%d", &continuarJugador);
	       
	    }
	    
	    //cambiar jugadores (si lo desea el usuario) antes de ordenar las edades y valores
		printf("¿Desea realizar algun cambio? s/n\n");
		scanf(" %c", &op);
		while(op == 's' || op == 'S'){
			hacerCambio();
			printf("¿Desea hacer algun otro cambio? s/n: ");      
			scanf(" %c", &op);
		}
		
		// se carga el equipo antes de vaciar la cola y preguntar si se quiere volver a cargar la cola con algun otro equipo
		printf("\n*** Cargando JUGADORES del EQUIPO ***");
	    cargarEquipos(&cola, archivo);     //carga de equipo en archivo
	    while(!colaVacia(&cola)){
	        desencolar(&cola);            //se desencolan todos los jugadores de la cola del equipo para cargar uno nuevo desde el inicio
	    }
	    printf("\n*** EQUIPO CARGADO CON EXITO ***\n");
	    printf("¿Desea cargar mas EQUIPOS? 1-si     0-no\n");
	    scanf("%d", &continuarEquipo);
	};
}

void hacerCambio(){
		if(!colaVacia(&cola)){
            tString jugadorModificar;
            printf("Ingrese el nombre del jugador a modificar: ");
            scanf(" %[^\n]", jugadorModificar);
            cambioJugador(&cola, jugadorModificar);
        } else {
            printf("No hay equipo cargado actualmente.\n");
        }
}

void corteControl(){
	inicio(archivo);
	procesoCorte(archivo);
	fin();
}
