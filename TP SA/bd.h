#ifndef BD_H_INCLUDED
#define BD_H_INCLUDED

#include <iostream>
#include <fstream>
#include "lista.h"

void levantarFechas(string archivo, string f[MAX_FECHAS], bool &ok);
void levantarDatosArchivos(string archivo1, string archivo2, tLista &l, bool &ok);
void persistirDatosArchivos(string archivo1, string archivo2, string archivo3, tLista l, string f[MAX_FECHAS]);
string armarRegistro(tAlumno a);
string to_upper(string s);

#endif // BD_H_INCLUDED
