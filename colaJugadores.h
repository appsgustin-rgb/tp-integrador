#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXSTRING 45

typedef char tString[MAXSTRING];

typedef struct {
    tString club;
    tString nombreJugador;
    tString posicion;
    int numero;
    int edad;
    float valor;
} tJugador;

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
    if (!nuevoNodo) {
        printf("Error al reservar memoria.\n");
        exit(1);
    }

    strcpy(nuevoNodo->jugador.club, pClub);

    printf("Ingrese nombre del jugador: ");
    scanf(" %[^\n]", nuevoNodo->jugador.nombreJugador);

    printf("Ingrese posicion del jugador: ");
    scanf(" %[^\n]", nuevoNodo->jugador.posicion);

    printf("Ingrese el numero que utiliza el jugador: ");
    scanf("%d", &nuevoNodo->jugador.numero);

    printf("Ingrese la edad del jugador: ");
    scanf("%d", &nuevoNodo->jugador.edad);

    printf("Ingrese la valoracion del jugador: ");
    scanf("%f", &nuevoNodo->jugador.valor);

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
    printf("Club: %s\n", aux->jugador.club);
    printf("Nombre: %s\n", aux->jugador.nombreJugador);
    printf("Posicion: %s\n", aux->jugador.posicion);
    printf("Numero: %d\n", aux->jugador.numero);
    printf("Edad: %d\n", aux->jugador.edad);
    printf("Valoracion: %.2f\n", aux->jugador.valor);

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

    printf("Ingrese nuevo nombre: ");
    scanf(" %[^\n]", aux->jugador.nombreJugador);

    printf("Ingrese nueva posicion: ");
    scanf(" %[^\n]", aux->jugador.posicion);

    printf("Ingrese nuevo numero: ");
    scanf("%d", &aux->jugador.numero);

    printf("Ingrese nueva edad: ");
    scanf("%d", &aux->jugador.edad);

    printf("Ingrese nueva valoracion: ");
    scanf("%f", &aux->jugador.valor);
}



