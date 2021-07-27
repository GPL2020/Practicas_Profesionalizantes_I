#include "Coche.hpp"

Coche::Coche(int motor, std::string marca, std::string color) : Vehiculo(marca, color) {
    _motor = motor;
}

void Coche::arrancar() {
    cout << "Coche: " << getMarca() << ", " << getColor() << " esta en marcha" << endl;
}
 
void Coche::parar() {
    cout << "Coche: " << getMarca() << ", " << getColor() << " esta detenido" << endl;
}

void Coche::repostar() {
    cout << "Coche: " << getMarca() << ", " << getColor() << " cargando combustible" << endl;
}

Coche::~Coche() {
}