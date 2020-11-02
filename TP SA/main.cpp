#include <iostream>
#include "lista.h"
#include "bd.h"

int menu();
void pausa();

int main()
{
    tLista listado;
    string fechaClases[MAX_FECHAS]; // Va a contener todas las fechas de clases en el año
    int opcion;
    bool okArchivos = true, okArchFechas = true;

    levantarFechas("./bd/fechaClases.txt", fechaClases, okArchFechas);
    levantarDatosArchivos("./bd/datosAlumnos.txt", "./bd/estado.txt", listado, okArchivos);

    if ((listado.cont != 0) && okArchivos && okArchFechas)
        ordenarPorApellido(listado);
        do {
            opcion = menu();
            switch (opcion) {
                case 1:
                    tomarAsistencia(listado, fechaClases);
                    cout << "\"Fin del listado\"\n " << endl;
                    break;
                case 2:
                    mostrarAsistenciasPorAlumno(listado);
                    cout << endl;
                    break;
                case 3:
                    mostrarAsistenciasPorFecha(listado, fechaClases);
                    break;
                case 4:
                    persistirDatosArchivos("./bd/datosAlumnos.txt", "./bd/estado.txt", "./bd/fechaClases.txt", listado, fechaClases);
                    break;
            }
        } while (opcion != 4);

    return 0;
}

int menu() {
    int op;

    do {
        cout << "1) Tomar asistencia" << endl
             << "2) Ver asistencias (por Alumno/a)" << endl
             << "3) Ver asistencias (por Fecha)" << endl
             << "4) Salir" << endl
             << "Opcion: ";
        cin >> op;
        cout << endl;
    } while ((op < 1) || (op > 4));
}

void pausa() {
    cin.sync();
    cin.get();
}

