#ifndef CARGAJUGADORES_H
#define CARGAJUGADORES_H

#include <stdio.h>

void iniciar(FILE **);
void cargarEquipos(tColaJugadores *, FILE *);
void finalizar(FILE **);


void iniciar(FILE **pArchivo) {
	
    *pArchivo = fopen("Equipos.dat", "a+b");  //abrimos con cursor a la ultima posicion
	 
	if(*pArchivo == NULL){
			*pArchivo = fopen("Equipos.dat", "w+b");
	}

    if(*pArchivo == NULL){
        printf("Error al abrir el archivo.\n");
    }
}


void cargarEquipos(tColaJugadores *pCola, FILE *pArchivo) {

    if(pArchivo == NULL){
        printf("Archivo no abierto.\n");
        return;
    }

    tNodoJugadores *aux = pCola->inicio;

    while(aux != NULL){
        fwrite(&aux->jugador, sizeof(tJugador), 1, pArchivo);
        aux = aux->siguiente;
    }
}


void finalizar(FILE **pArchivo){
    if(*pArchivo != NULL){
        fclose(*pArchivo);
        *pArchivo = NULL;
    }
}

#endif
