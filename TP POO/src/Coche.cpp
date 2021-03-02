#include "Coche.h"

Coche::Coche(string color, string marca, int motor) {
    //cosas que deban nacer con un coche
    m_color = color;
    m_marca = marca;
    m_motor = motor;
}

Coche::~Coche() {
    //cosas que deban morir con un coche
}

void Coche::arrancar() {
    //algo para arrancar, cout << "estoy en marcha" << endl;
}

void Coche::parar() {
    //algo para arrancar, cout << "estoy detenide" << endl;
}

void Coche::repostar() {
    //algo para arrancar, cout << "me detuve a repostar combustible" << endl;
}
