#include <stdio.h>

void inicio(FILE *);
void procesoCorte();
void fin();
void principioCorte();
void unJugador();
void finCorte();
tJugador jugador, jugadorAnt;

int cantJugadoresEquipo, edadEquipo;
float valorEquipo, promEdadEquipo;

tString equipoMasCaro;
int cantEquipos, valorEquipoMasCaro;

void inicio(FILE *pArchivo){
	fread(jugador, sizeof(tJugador), 1, pArchivo);
	cantEquipos = 0;
	valorEquipoMasCaro = 0;
	jugadorAnt = jugador;
}

void procesoCorte(){
	while(!feof(pArchivo)){
		principioCorte();
		while(strcmp(jugador.club,jugadorAnt.club) == 0){
			unJugador();
		}
		finCorte();
	}
}
void principioCorte(){
	cantJugadoresEquipo = 0;
	valorEquipo = 0;
}

void unJugador(){
	cantJugadoresEquipo++;
	valorEquipo+=jugador.valor;
	edadEquipo +=jugador.edad;
}

void finCorte(){
	promEdadEquipo = (float)edadEquipo / cantJugadoresEquipo;
	printf("Equipo %s\n\t", jugadorAnt.club);
	printf("Total De Jugadores: %d\n\t", cantJugadoresEquipo);
	printf("Promedio de edad Del equipo: %.2f\n\t", promEdadEquipo);
	printf("Valor Del Equipo: %.2f\n", valorEquipo);
	if(valorEquipoMasCaro < valorEquipo){
		valorEquipoMasCaro = valorEquipo;
		equipoMasCaro = jugadorAnt.club;
	}
	cantEquipos++;
}

void fin(){
	printf("Cantidad de equipos registrados: %d", cantEquipos);
	printf("Equipo de mayor valor total: %s, $%.2f", equipoMasCaro, valorEquipoMasCaro);
}
