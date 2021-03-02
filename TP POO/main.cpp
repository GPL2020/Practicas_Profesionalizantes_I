#include <iostream>
#include ".\include\Taller.h"
#include ".\include\Vehiculo.h"
#include ".\include\Coche.h"
#include ".\include\Moto.h"

using namespace std;

int main()
{
    Taller* taller1 = new Taller(3, 256);
    Vehiculo* coche1 = new Coche("rojo", "honda", 4);
    Vehiculo* moto1 = new Moto("roja", "honda", 4);

    cout << "\nPresione ENTER para finalizar... ";
    cin.sync();
    cin.get();

    return 0;
}
