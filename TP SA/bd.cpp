#include "bd.h"

void levantarFechas(string archivo, string f[MAX_FECHAS], bool &ok) {
    ifstream archivoFechas(archivo);
    int i = 0;

    if (archivoFechas.is_open()) {
        while (!archivoFechas.eof() && (i < MAX_FECHAS)) {
            archivoFechas >> f[i];
            i++;
        }
        archivoFechas.close();
    }
    else {
        cout << "\"Error al abrir archivo " << " (" << archivo << ")\"" << endl;
        ok = false;
    }
}

void levantarDatosArchivos(string archivo1, string archivo2, tLista &l, bool &ok) {
    ifstream archivoDatos(archivo1);
    ifstream archivoEstado;
    string registro = ""; // Va a contener una linea completa del archivo1
    int i = 0, j = 0, pos;
    string idAl;
    string fechaEstado;
    char estado;

    if (archivoDatos.is_open()) {
        while (!archivoDatos.eof() && ok) {

            getline(archivoDatos, registro); // obtengo los datos principales del alumno

            if (registro != "") {
                registro = to_upper(registro);
                pos = registro.find("|");       // Busco la primera posición del separador
                l.estudiantes[i].id = registro.substr(0, pos); // Obtengo el id
                registro.erase(0, pos + 1);     // Elimino del string el id + separador

                pos = registro.find("|");      // Obtengo la pos del siguiente separador
                l.estudiantes[i].nombre = registro.substr(0, pos);  // Obtengo el nombre
                registro.erase(0, pos + 1);

                l.estudiantes[i].apellido = registro.substr(0, registro.length()); // Obtengo el apellido
                registro.erase(0, registro.length());   // Vacío el registro

                // obtengo del archivo estado, las fechas y las asistencias del alumno i
                // y las cargo en el arreglo de estructuras asistencias

                archivoEstado.open(archivo2);
                if (archivoEstado.is_open()) {
                    j = 0; // índice para asistencias
                    /* Nota: El EOF Necesita siempre una primera lectura antes de verificar si terminó!!!!
                       cuando se utiliza insertor */
                    archivoEstado >> idAl;         // Obtengo id alumno
                    while (!archivoEstado.eof()) {
                        // leo el id
                        archivoEstado >> fechaEstado;  // Obtengo la fecha del estado
                        archivoEstado >> estado;       // Obtengo el estado
                        // Verifico no leer una linea vacia del archivo
                        if ((idAl != "") && (idAl == l.estudiantes[i].id))  { // Si es igual agrego en arreglo asistencias
                            l.estudiantes[i].asistencias[j].fecha = fechaEstado;
                            l.estudiantes[i].asistencias[j].estado = estado;
                        }
                        j++;
                        archivoEstado >> idAl;         // Obtengo id alumno
                    }
                    archivoEstado.close();
                }
                else {
                    cout << "\"Error al abrir archivo " << " (" << archivo2 << ")\"" << endl;
                    ok = false;
                }
                i++;
                l.cont++;
            }
        }
        archivoDatos.close();
    }
    else {
        cout << "\"Error al abrir archivo " << " (" << archivo1 << ")\"" << endl;
        ok = false;
    }
}

void persistirDatosArchivos(string archivo1, string archivo2, string archivo3, tLista l, string f[MAX_FECHAS]) {
    ofstream archivoDatos(archivo1);
    ofstream archivoEstado(archivo2);
    string registro = ""; // Contendrá la línea completa para guardar en archivo de Datos Alumnos

    /* Persisto los archivos de datos de los alumnos
       y los datos del estado de esistencias */
    for (int i = 0; i < l.cont; i++) {
        registro = armarRegistro(l.estudiantes[i]);
        // Guardo la línea completa en el archivo
        if (i != l.cont - 1)  // Controlo que sea el último registro para no guardar un endl al final
            archivoDatos << registro << endl;
        else
            archivoDatos << registro;
        // Ahora guardo en el archivo de estado de asistencias

        for (int j = 0; j < MAX_AS; j++) {
            // SI fecha == "", entonces no hay más datos por guardar (ID + Fecha + Estado)
            if (l.estudiantes[i].asistencias[j].fecha != "") {
                archivoEstado << l.estudiantes[i].id << " "
                              << l.estudiantes[i].asistencias[j].fecha << " "
                              << l.estudiantes[i].asistencias[j].estado << endl;
            }
        }
    }
    archivoEstado.close();
    archivoDatos.close();

    // Guardo los datos en el archivo de Fechas
    ofstream archivoFechas(archivo3);
    for (int i = 0; i < MAX_FECHAS; i++)
        if (f[i] == "")
            /* Controlo que el siguiente sea "", para no guardad un endl;
               también por no haber creado un lista con un contador :( */
            if (f[i + 1] != "")
                archivoFechas << f[i] << endl;
            else
                archivoFechas << f[i];
    archivoFechas.close();
}

string armarRegistro(tAlumno a) {
    string strAlumno = "";

    strAlumno.append(a.id);
    strAlumno.append("|");
    strAlumno.append(a.nombre);
    strAlumno.append("|");
    strAlumno.append(a.apellido);

    return strAlumno;
}

string to_upper(string s) {
    for (int i = 0; i < s.length(); i++)
        s[i] = toupper(s[i]);
    return s;
}
