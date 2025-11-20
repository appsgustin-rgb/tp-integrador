#ifndef CORTECONTROLEQUIPOS_H
#define CORTECONTROLEQUIPOS_H

#include <stdio.h>
#include <string.h>

void inicio(FILE*);
void procesoCorte(FILE*);
void fin();
void principioCorte(FILE*);
void unJugador();
void finCorte();

float valorEquipo, promEdadEquipo;            //por equipo
int goleador, asistidor, cantJugadoresEquipo, totalEdad;
tString nombreGoleador, nombreAsistidor;

float equipoMayorValor;
int totalEquipos, jugadorMasGoles, jugadorMasAsistencias;    //generales
tString nombreMasGoles, nombreMasAsistencias, nombreEquipoMayorValor;

tJugador jugador, jugadorAnt;

void inicio(FILE *pArchivo){
	rewind(pArchivo);    //colocar al inicio
	fread(&jugador, sizeof(tJugador), 1, pArchivo);
	equipoMayorValor = 0;
	totalEquipos = 0;
	jugadorMasGoles = 0;
	jugadorMasAsistencias = 0;
}

void procesoCorte(FILE *pArchivo){
	while(!feof(pArchivo)){
		principioCorte(pArchivo);
		while(strcmp(jugador.club, jugadorAnt.club) == 0 && !feof(pArchivo)){
			
			unJugador();
			fread(&jugador, sizeof(tJugador), 1, pArchivo);
		}
		finCorte();
	}
}

void principioCorte(FILE *pArchivo){
	valorEquipo = 0;
	goleador = 0;
	asistidor = 0;
	cantJugadoresEquipo = 0;
	totalEdad = 0;
	jugadorAnt = jugador;
}

void unJugador(){
	valorEquipo += jugador.valor;
	if(goleador<jugador.goles){
		goleador = jugador.goles;
		strcpy(nombreGoleador, jugador.nombreJugador);
	}
	if(asistidor<jugador.asistencias){
		asistidor = jugador.asistencias;
		strcpy(nombreAsistidor, jugador.nombreJugador);
	}
	cantJugadoresEquipo++;
	totalEdad += jugador.edad;
}

void finCorte(){
	promEdadEquipo = (float)totalEdad / cantJugadoresEquipo;
	printf("\n=== EQUIPO: %s ===\n", jugadorAnt.club);
	printf("VALOR $%.2f USD\t| ", valorEquipo);
	printf("EDAD PROMEDIO %.2f\t| ", promEdadEquipo);
	printf("NUMERO DE JUGADORES %d\n", cantJugadoresEquipo);
	printf("GOLEADOR %s (%d goles)\t| ", nombreGoleador, goleador);
	printf("ASISTIDOR %s (%d asistencias)\n", nombreAsistidor, asistidor);
	
	if(equipoMayorValor < valorEquipo){
		equipoMayorValor = valorEquipo;
		strcpy(nombreEquipoMayorValor, jugadorAnt.club);
	}
	
	if(jugadorMasGoles < goleador){
		jugadorMasGoles = goleador;
		strcpy(nombreMasGoles, nombreGoleador);
	}
	if(jugadorMasAsistencias < asistidor){
		jugadorMasAsistencias = asistidor;
		strcpy(nombreMasAsistencias, nombreAsistidor);
	}
	
	totalEquipos++;
}

void fin(){
	printf("TOTAL DE EQUIPOS: %d\n", totalEquipos);
	printf("\nEQUIPO DE MAYOR VALOR: %s, ($%.2f USD)\n", nombreEquipoMayorValor, equipoMayorValor);
	printf("MAXIMO GOLEADOR: %s (%d goles)\t| MAXIMO ASISTIDOR: %s (%d asistencias)\n", nombreMasGoles, jugadorMasGoles, nombreMasAsistencias, jugadorMasAsistencias);
}

#endif
