#include "Moto.h"

Moto::Moto(string color, string marca, int cilindrada) {
    //cosas que deban nacer con un coche
    m_color = color;
    m_marca = marca;
    m_cilindrada = cilindrada;
}

Moto::~Moto() {
    //cosas que deban morir con un coche
}

void Moto::arrancar() {
    //algo para arrancar, cout << "estoy en marcha" << endl;
}

void Moto::parar() {
    //algo para arrancar, cout << "estoy detenide" << endl;
}

void Moto::repostar() {
    //algo para arrancar, cout << "me detuve a repostar combustible" << endl;
}
