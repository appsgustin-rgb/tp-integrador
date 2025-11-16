#include <stdio.h>
#define MAXJUGADORES 3

typedef float tVectorValores[MAXJUGADORES];
typedef int tVectorEdades[MAXJUGADORES];

void cargarVectorValores(tColaJugadores*, tVectorValores);
void ordenarVectorValores(tVectorValores);
void cargarVectorEdades(tColaJugadores*, tVectorEdades);
void ordenarVectorEdades(tVectorEdades);

void cargarVectorValores(tColaJugadores *pCola, tVectorValores pVectorValores) {
    int i;
    tNodoJugadores *aux = pCola->inicio;
    
	if(aux == NULL){
        printf("ERROR: La cola no tiene suficientes jugadores.\n");
        return;
	}
	
    for(i = 0; i < MAXJUGADORES; i++){
        pVectorValores[i] = aux->jugador.valor;
        aux = aux->siguiente;
    }
}

void ordenarVectorValores(tVectorValores pVectorValores) {
    int i, j;
    float aux;

    for(i = 1; i < MAXJUGADORES; i++){
        aux = pVectorValores[i];
        j = i - 1;

        while(j >= 0 && pVectorValores[j] > aux){
            pVectorValores[j + 1] = pVectorValores[j];
            j--;
        }
        pVectorValores[j + 1] = aux;
    }
}

void cargarVectorEdades(tColaJugadores *pCola, tVectorEdades pVectorEdades) {
    int i;
    tNodoJugadores *aux = pCola->inicio;

    for(i = 0; i < MAXJUGADORES; i++){
        if(aux == NULL){
            printf("ERROR: La cola no tiene suficientes jugadores.\n");
            return;
        }
        pVectorEdades[i] = aux->jugador.edad;
        aux = aux->siguiente;
    }
}

void ordenarVectorEdades(tVectorEdades pVectorEdades) {
    int i, j;
    int aux;

    for(i = 1; i < MAXJUGADORES; i++){
        aux = pVectorEdades[i];
        j = i - 1;

        while(j >= 0 && pVectorEdades[j] > aux){
            pVectorEdades[j + 1] = pVectorEdades[j];
            j--;
        }
        pVectorEdades[j + 1] = aux;
    }
}
