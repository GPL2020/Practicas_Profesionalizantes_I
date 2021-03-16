#include "../include/ListaVehiculos.h"

ListaVehiculos::ListaVehiculos() {
    //ctor
    cont = 0;
}

void ListaVehiculos::mostrarVehiculo(int pos) {
    lista[pos]->getColor();
    cout << " ";
    lista[pos]->getMarca();
    cout << " ---> ";
    lista[pos]->arrancar();


}

void ListaVehiculos::add(Vehiculo *v) {
    lista[cont] = v;
    cont++;
}

int ListaVehiculos::cantVehiculos() {
    return cont;
}

ListaVehiculos::~ListaVehiculos() {
    //dtor
}
