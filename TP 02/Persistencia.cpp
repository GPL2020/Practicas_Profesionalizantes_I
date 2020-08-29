#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define MAX_FILES 1000

struct FileData {
    string name;
    long size;
};

int menu();
void persistirDatos(string nombreArchivo, FileData f[MAX_FILES], int n);
int levantarDatos(string nombreArchivo, FileData f[MAX_FILES]);


/* Programa que guarda en un archivo el contenido
   de cada posición de un arreglo
*/
int main()
{
    int numberOfFiles = 0; // Número de archivos que ya tenemos
    int i; // Indice para el bucle
    int option; // Opción para elección en menú

    string tempText; // Para pedir datos al usuario
    int tempNumber;
    FileData files[MAX_FILES];

    do {
        option = menu();
        switch (option) {
            case 0: // Guardar el contenido del arreglo en un archivo
                persistirDatos("datos.bin", files, numberOfFiles);
                cout << "\nDatos guardados en el archivo (datos.bin)... " << endl;
                break;
            case 1: // Pasar datos del archivo a un arreglo
                numberOfFiles = levantarDatos("datos.bin", files);
                if (numberOfFiles > 0)
                    cout << "\nDatos transferidos a la memoria.... " << endl;
                break;
            case 2: // Añadir un dato nuevo
                if (numberOfFiles < MAX_FILES) {
                    cout << "\nIntroduce el nombre del archivo: ";
                    cin.ignore();
                    getline(cin, files[numberOfFiles].name);
                    cout << "Introduce el tamanio en KB: ";
                    cin >> files[numberOfFiles].size;
                    numberOfFiles++;
                }
                else
                    cout << "\nMáximo de archivos alcanzado (1000)!" << endl;
                break;
            case 3: // Mostrar todos
                cout << endl;
                for (i = 0; i < numberOfFiles; i++)
                    cout << "Nombre: " << files[i].name
                         << "; Tamaño: " << files[i].size
                         << "Kb\n" << endl;
                break;
            case 4: // Mostrar según el tamaño
                cout << "\n¿A partir de que tamaño quieres que te muestre? ";
                cin >> tempNumber;
                for (i = 0; i < numberOfFiles; i++)
                    if (files[i].size >= tempNumber)
                        cout << "Nombre: " << files[i].name
                             << "; Tamaño: " << files[i].size
                             << "Kb\n" << endl;
                break;
            case 5: // Ver todos los datos (pocos) de un archivo
                cout << "\n¿De que archivo quieres ver todos los datos? ";
                cin.ignore();
                getline(cin, tempText);
                for (i = 0; i < numberOfFiles; i++)
                    if (files[i].name == tempText)
                        cout << "Nombre: " << files[i].name
                             << "; Tamaño: " << files[i].size
                             << "Kb\n" << endl;
                break;
            case 6: // Salir: avisamos que salimos
                cout << "\nFin del programa" << endl;
                break;
            default: // Otra opción: no válida
                cout << "\n¡Opcion desconocida!" << endl;
                break;
        }
    } while (option != 6); // Si la opción es 5, terminamos

    cout << "\nPresione ENTER para finalizar... ";
    cin.sync();
    cin.get();

    return 0;
}

int menu() {
    int op;
    cout << endl;
    cout << "0.- Persistir datos" << endl;
    cout << "1.- Levantar datos del archivo" << endl;
    cout << "2.- Añadir datos de un nuevo archivo" << endl;
    cout << "3.- Mostrar los nombres de todos los archivos" << endl;
    cout << "4.- Mostrar archivos que sean de mas de un cierto tamaño" << endl;
    cout << "5.- Ver datos de un archivo" << endl;
    cout << "6.- Salir" << endl;
    cout << "Escoja una opcion: ";
    cin >> op;

    return op;
}

// Persiste los datos del arreglo en un arhivo binario
void persistirDatos(string nombreArchivo, FileData f[MAX_FILES], int n) {
    ofstream arch(nombreArchivo, ios::binary);

    if (arch.is_open()) {
        if (n > 0)
            for (int i = 0; i < n; i++)
                arch.write((char *) &f[i], sizeof(FileData));
        else
            cout << "\nNo hay datos para persisitir... " << endl;
        arch.close();
    }
    else
        cout << "Error al crear el archivo (" << nombreArchivo << ")" << endl;
}

// Pasa los datos de un archivo binario a un arreglo
int levantarDatos(string nombreArchivo, FileData f[MAX_FILES]) {
    ifstream arch(nombreArchivo, ios::app);
    int i = 0;

    if (arch.is_open()) {
        while (!arch.eof() && (i < MAX_FILES)) {
            arch.read((char *) &f[i], sizeof(FileData));
            i++;
        }
        i--;
        arch.close();
    }
    else
        cout << "Archivo (" << nombreArchivo << ") inexistente... " << endl;
    return i;
}
