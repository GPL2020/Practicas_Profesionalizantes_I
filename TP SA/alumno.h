#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED
#define MAX_AS 100

#include <string>

using namespace std;

// Estructura con las asistencias del alumno
typedef struct {
    string fecha;
    char estado;    // A Ausente; P Presente
} tEstado;

typedef struct {
    string nombre;
    string apellido;
    string id;
    tEstado asistencias[MAX_AS] = {""};
} tAlumno;

#endif // ALUMNO_H_INCLUDED
