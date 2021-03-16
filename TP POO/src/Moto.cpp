#include "../include/Moto.h"

Moto::Moto(string color, string marca, int cilindrada) {
    //cosas que deban nacer con un coche
    m_color = color;
    m_marca = marca;
    m_cilindrada = cilindrada;
}

Moto::~Moto() {
    //cosas que deban morir con un coche
}

void Moto::getColor() {
    cout << m_color;
}

void Moto::getMarca() {
    cout << m_marca;
}

void Moto::arrancar() {
    cout << "Estoy en marcha" << endl;
}

void Moto::parar() {
    cout << "Estoy detenida" << endl;
}

void Moto::repostar() {
    //algo para arrancar, cout << "me detuve a repostar combustible" << endl;
    cout << "Me detuve a repostar combustible" << endl;
}
