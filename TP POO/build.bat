:: Compilo el Binario
cd src
g++ -Wall -std=c++11 -c Taller.cpp
g++ -Wall -std=c++11 -c Vehiculo.cpp 
g++ -Wall -std=c++11 -c Coche.cpp 
g++ -Wall -std=c++11 -c Moto.cpp
g++ -Wall -std=c++11 -c ListaVehiculos.cpp
cd ..
g++ -Wall -std=c++11 -c main.cpp 
g++ ./src/Taller.o ./src/Vehiculo.o ./src/Coche.o ./src/Moto.o ./src/ListaVehiculos.o main.o -o Taller.exe

echo "Programa compilado"
pause

:: Limpio los códigos objeto
DEL .\*.o