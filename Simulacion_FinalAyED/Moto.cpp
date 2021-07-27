#include "Moto.hpp"

Moto::Moto(int cil, string marca, string color) : Vehiculo(marca, color) {
    _cilindrada = cil;
}
        
void Moto::arrancar() {
    cout << "Moto: " << getMarca() << ", " << getColor() << " esta en marcha" << endl;
}
    
void Moto::parar() {
    cout << "Moto: " << getMarca() << ", " << getColor() << " esta detenida" << endl;
}

void Moto::repostar() {
    cout << "Moto: " << getMarca() << ", " << getColor() << " cargando combustible" << endl;
}

Moto::~Moto() {
}