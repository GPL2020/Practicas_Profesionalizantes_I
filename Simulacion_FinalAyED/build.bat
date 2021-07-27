:: Compilo el Binario
cd src
g++ -Wall -std=c++11 -c Taller.cpp
g++ -Wall -std=c++11 -c Vehiculo.cpp 
g++ -Wall -std=c++11 -c Coche.cpp 
g++ -Wall -std=c++11 -c Moto.cpp
g++ -Wall -std=c++11 -c main.cpp 

g++ Taller.o Vehiculo.o Coche.o Moto.o main.o -o taller.exe

echo "Programa compilado"
pause

:: Limpio los códigos objeto
DEL .\*.o