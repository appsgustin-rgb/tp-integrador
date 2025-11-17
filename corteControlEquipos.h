#include <stdio.h>

void inicio(FILE *);
void procesoCorte();
void fin();
void principioCorte();
void unJugador();
void finCorte();
tJugador jugador;

int totalEquipos, totalJugadores, jugadorMayor, jugadorMasCaro;

float valorEquipo, promEdadEquipo;
int totalEdadEquipo, jugadorMayorEquipo, jugadorMasCaro;
tString clubJugadorAnt;
void inicializaciones(FILE *pArchivo){
	fread(jugador, sizeof(tJugador), 1, pArchivo);
	totalEquipos = 0;
	totalJugadores = 0;
	jugadorMayor = 0;
	jugadorMasCaro =0;
}

void procesoCorte(){
	while(!feof(pArchivo)){
		principioCorte();
		while(strcpy(jugador.club, clubJugadorAnt) == 0){
			unJugador();
		}
		finCorte();
	}
}

void principioCorte(){
	valorEquipo = 0;
	totalEdadEquipo = 0;
	jugadorMayorEquipo = 0;
	jugadorMasCaro = 0;
}
