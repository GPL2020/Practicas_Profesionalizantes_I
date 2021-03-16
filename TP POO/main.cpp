#include <iostream>
#include "./include/Taller.h"
#include "./include/Vehiculo.h"
#include "./include/Coche.h"
#include "./include/Moto.h"

using namespace std;

int main()
{
    Taller* taller1 = new Taller(0);
    Vehiculo* coche1 = new Coche("rojo", "honda", 4);
    Vehiculo* coche2 = new Coche("negro", "chevrolet", 5);
    Vehiculo* moto1 = new Moto("roja", "honda", 3);
    Vehiculo* moto2 = new Moto("negra", "zanella", 6);

    taller1->meter(coche1);
    taller1->meter(coche2);
    taller1->meter(moto1);
    taller1->meter(moto2);

    cout << endl;

    taller1->arreglarVehiculos();

    delete coche1;
    delete coche2;
    delete moto1;
    delete moto2;

    cout << "\nPresione ENTER para finalizar... ";
    cin.sync();
    cin.get();

    return 0;
}
