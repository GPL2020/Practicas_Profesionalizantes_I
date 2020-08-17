#include <iostream>

using namespace std;

struct MP3 {
    string artista;
    string titulo;
    int duracion;
    float KB;
};

int main()
{
    /* Programa que pide ingresar datos en una estructura
       y luego los muestra por pantalla
    */
    MP3 cancion;

    cout << "Ingrese el artista: ";
    getline(cin, cancion.artista);
    cout << "Ingrese el titulo de la cancion: ";
    getline(cin, cancion.titulo);
    cout << "Ingrese la duracion (seg): ";
    cin >> cancion.duracion;
    cout << "Ingrese el tamanio del archivo (KB): ";
    cin >> cancion.KB;

    cout << "\nEl contenido de la estructura es:" << endl;
    cout << "Artista: " << cancion.artista << endl
         << "Titulo: " << cancion.titulo << endl
         << "Duracion: " << cancion.duracion << " seg" << endl
         << "Tamanio: " << cancion.KB << " KB" << endl;

    cout << "\nPresione ENTER para finalizar... ";
    cin.sync();
    cin.get();
    return 0;
}
