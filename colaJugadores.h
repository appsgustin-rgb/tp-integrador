#ifndef COLAJUGADORES_H
#define COLAJUGADORES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXSTRING 45

typedef char tString[MAXSTRING];

typedef struct {
    tString club;
    tString nombreJugador;
    int edad;
    float valor;
    int goles;
    int asistencias;
}tJugador;

typedef struct nodo {
    tJugador jugador;
    struct nodo *siguiente;
} tNodoJugadores;

typedef struct {
    tNodoJugadores *inicio;
    tNodoJugadores *fin;
} tColaJugadores;

void iniciarCola(tColaJugadores *);
bool colaVacia(tColaJugadores *);
tNodoJugadores *crearNodo(tString);
void encolar(tColaJugadores *, tNodoJugadores *);
void desencolar(tColaJugadores *);
void cambioJugador(tColaJugadores *, tString);

void iniciarCola(tColaJugadores *pCola) {
    pCola->inicio = NULL;
    pCola->fin = NULL;
}

bool colaVacia(tColaJugadores *pCola) {
    return (pCola->inicio == NULL);
}

tNodoJugadores *crearNodo(tString pClub) {

    tNodoJugadores *nuevoNodo = (tNodoJugadores *)malloc(sizeof(tNodoJugadores));
    if (nuevoNodo == NULL) {
        printf("Error al reservar memoria.\n");
        return NULL;
    }

    strcpy(nuevoNodo->jugador.club, pClub);

    printf("Ingrese nombre del jugador: ");
    scanf(" %[^\n]", nuevoNodo->jugador.nombreJugador);

    printf("Ingrese la edad del jugador: ");
    scanf("%d", &nuevoNodo->jugador.edad);

    printf("Ingrese la valoracion del jugador: $");
    scanf("%f", &nuevoNodo->jugador.valor);
    
    printf("Ingrese cantidad de goles: ");
    scanf("%d", &nuevoNodo->jugador.goles);
    
    printf("Ingrese cantidad de asistencias: ");
    scanf("%d", &nuevoNodo->jugador.asistencias);
    

    nuevoNodo->siguiente = NULL;

    return nuevoNodo;
}

void encolar(tColaJugadores *pCola, tNodoJugadores *pNodo) {
    if (colaVacia(pCola)) {
        pCola->inicio = pNodo;
        pCola->fin = pNodo;
    } else {
        pCola->fin->siguiente = pNodo;
        pCola->fin = pNodo;
    }
}

void desencolar(tColaJugadores *pCola) {
    if (colaVacia(pCola)) {
        printf("La cola está vacía.\n");
        return;
    }

    tNodoJugadores *aux = pCola->inicio;

    printf("\n--- JUGADOR ---\n");
	printf("%s	|", aux->jugador.nombreJugador); 
	printf("%d Anios	|", aux->jugador.edad);
    //printf("%s	", aux->jugador.club);
    
   
    
    printf("$%.2f USD\n", aux->jugador.valor);
	printf("G:%d ", aux->jugador.goles);
	printf("/A:%d ", aux->jugador.asistencias);
    pCola->inicio = aux->siguiente;

    if (pCola->inicio == NULL) {
        pCola->fin = NULL;
    }

    free(aux);
}

void cambioJugador(tColaJugadores *pCola, tString pJugador) {

    if (colaVacia(pCola)) {
        printf("Cola vacía.\n");
        return;
    }

    tNodoJugadores *aux = pCola->inicio;

    while (aux != NULL && strcmp(aux->jugador.nombreJugador, pJugador) != 0) {
        aux = aux->siguiente;
    }

    if (aux == NULL) {
        printf("Jugador no encontrado.\n");
        return;
    }
    printf("<<<Ingrese nuevo jugador para cambio>>>\n");
    printf("Nombre: ");
    scanf(" %[^\n]", aux->jugador.nombreJugador);

    printf("Edad: ");
    scanf("%d", &aux->jugador.edad);

    printf("Valoracion : $");
    scanf("%f", &aux->jugador.valor);
    
    printf("Goles: ");
    scanf("%d", &aux->jugador.goles);
    
    printf("Asistencias: ");
    scanf("%d", &aux->jugador.asistencias);
    
}

#endif
