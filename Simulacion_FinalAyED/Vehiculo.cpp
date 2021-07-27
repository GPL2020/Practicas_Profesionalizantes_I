#include "Vehiculo.hpp"

Vehiculo::Vehiculo(string marca, string color) {
    _marca = marca;
    _color = color;
}

string Vehiculo::getMarca() {
    return _marca;
}

string Vehiculo::getColor() {
    return _color;
}

Vehiculo::~Vehiculo() {
}