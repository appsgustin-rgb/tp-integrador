#include "colaJugadores.h"
#include "vectorJugadores.h"
#include "cargajugadores.h"
#define MAXJUGADORES 3

void manejoDeEquipos();
void mostrarValoresOrdenados();
void mostrarEdadesOrdenadas();
void hacerCambio();

tColaJugadores cola;
FILE *archivo;
int main() {
    iniciarCola(&cola);
    
	archivo = NULL;
    iniciar(&archivo);
    
	manejoDeEquipos();
	
    finalizar(&archivo);
    printf("\nProceso finalizado.\n");
    
    return 0;
}

void manejoDeEquipos(){
	char op;
	int continuar = 1;

	
	int i;
	
	while(continuar == 1){
		printf("\n=== CARGA DE UN NUEVO EQUIPO ===\n");
	    tString club;
	    printf("Ingrese nombre del club: ");
	    scanf(" %[^\n]", club);
	
	    for(i = 0; i < MAXJUGADORES; i++){
	        printf("\nJugador %d/%d:\n", i+1, MAXJUGADORES);
	        tNodoJugadores *nuevo = crearNodo(club);
	        encolar(&cola, nuevo);
	    }
	    
		printf("¿Desea realizar algun cambio? s/n\n");
		scanf(" %c", &op);
		if(op == 's'){
			hacerCambio();
		}
		
		mostrarValoresOrdenados();
		mostrarEdadesOrdenadas();
		
	    cargarEquipos(&cola, archivo);
	    while(!colaVacia(&cola)){
	        desencolar(&cola);
	    }
	    
	    printf("\n*** EQUIPO CARGADO CON EXITO ***\n");
	    printf("¿Desea cargar mas equipos? 1-si/0-no\n");
	    scanf("%d", &continuar);
	}
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

void mostrarValoresOrdenados(){
	tVectorValores vectorValores;
	int i;
	cargarVectorValores(&cola, vectorValores);
	ordenarVectorValores(vectorValores);
	printf("\n=== Valores de los jugadores ordenados de forma ascendente === \n");
	for(i = 0; i<MAXJUGADORES; i++){
		printf(" %.2f |", vectorValores[i]);
	}
	printf("\n");
}

void mostrarEdadesOrdenadas(){
	tVectorEdades vectorEdades;
	int i;
	cargarVectorEdades(&cola, vectorEdades);
	ordenarVectorEdades(vectorEdades);
	printf("\n=== Edades de los jugadores ordenadas de forma ascendente \n");
	for(i = 0; i<MAXJUGADORES; i++){
		printf(" %d |", vectorEdades[i]);
	}
	printf("\n");
}
