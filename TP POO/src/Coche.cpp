#include "../include/Coche.h"

Coche::Coche(string color, string marca, int motor) {
    //cosas que deban nacer con un coche
    m_color = color;
    m_marca = marca;
    m_motor = motor;
}

Coche::~Coche() {
    //cosas que deban morir con un coche
}

void Coche::getColor() {
    cout << m_color;
}

void Coche::getMarca() {
    cout << m_marca;
}

void Coche::arrancar() {
    cout << "Estoy en marcha" << endl;
}

void Coche::parar() {
    cout << "Estoy detenido" << endl;
}

void Coche::repostar() {
    cout << "Me detuve a repostar combustible" << endl;
}
