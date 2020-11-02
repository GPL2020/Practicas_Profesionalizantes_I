#include "lista.h"

void tomarAsistencia(tLista &l, string f[MAX_FECHAS]) {
    char estado;
    string fechaActual;

    cout << "Ingrese la fecha actual (AAAA/MM/DD): ";
    cin >> fechaActual;

    for (int i = 0; i < l.cont; i++) {
        cout << "Alumno: " << l.estudiantes[i].apellido + " "
                           << l.estudiantes[i].nombre << endl;
        cout << "Estado (P/A): ";
        cin >> estado;
        estado = toupper(estado);

        // Corro todo a la derecha si hay espacio
        for (int j = MAX_AS - 1; j > 0; j--)
            l.estudiantes[i].asistencias[j] = l.estudiantes[i].asistencias[j - 1];
        // Inserto al principio
        l.estudiantes[i].asistencias[0].fecha = fechaActual;
        l.estudiantes[i].asistencias[0].estado = estado;
        cout << endl;
    }

    // Se inserta al principio en el arreglo de fechas
    for (int i = MAX_FECHAS - 1; i > 0; i--)
        f[i] = f[i - 1];
    f[0] = fechaActual;
}

void mostrarAsistenciasPorAlumno(tLista l) {

    for (int i = 0; i < l.cont; i++) {
        cout << l.estudiantes[i].nombre << " " << l.estudiantes[i].apellido << endl;
        for (int j = 0; j < MAX_AS; j++)
            if (l.estudiantes[i].asistencias[j].fecha != "")
                cout << l.estudiantes[i].asistencias[j].fecha << " -> ("
                     << l.estudiantes[i].asistencias[j].estado << ")" << endl;
        cout << endl;
    }
}

void mostrarAsistenciasPorFecha(tLista l, string f[MAX_FECHAS]) {
    string aux[MAX_FECHAS];
    for (int i = 0; i < MAX_FECHAS; i++)
        aux[i] = f[i];

    cout << "-Listado de asistencias-" << endl;
    for (int i = 0; i < MAX_FECHAS; i++) {
        if (f[i] != "") {
            cout << "(" << f[i] << ")" << endl;
        }
        for (int j = 0; j < l.cont; j++) {
            for (int k = 0; k < MAX_AS; k++) {
                if ((f[i] != "") && (f[i] == l.estudiantes[j].asistencias[k].fecha))
                    cout << l.estudiantes[j].nombre << " " << l.estudiantes[j].apellido
                         << " (" << l.estudiantes[j].asistencias[k].estado << ")" << endl;
            }
        }
        if (f[i] != "")
            cout << endl;
    }
}

// Ordenamiento por burbuja
void ordenarPorApellido(tLista &l) {
    tAlumno aux;

    for (int i = 0; i < l.cont; i++)
        for (int j = 0; j < l.cont - 1; j++)
            if (l.estudiantes[j].apellido > l.estudiantes[j + 1].apellido) {
                aux = l.estudiantes[j];
                l.estudiantes[j] = l.estudiantes[j + 1];
                l.estudiantes[j + 1] = aux;
            }
}
