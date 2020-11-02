#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#define MAX_AL 100
#define MAX_FECHAS 30

#include <iostream>
#include "alumno.h"

using namespace std;

typedef tAlumno tArray[MAX_AL];

typedef struct {
    tArray estudiantes;
    int cont = 0;
} tLista;

void tomarAsistencia(tLista &l, string f[MAX_FECHAS]);
void mostrarAsistenciasPorAlumno(tLista l);
void mostrarAsistenciasPorFecha(tLista l, string f[MAX_FECHAS]);
void ordenarPorApellido(tLista &l);

#endif // LISTA_H_INCLUDED
