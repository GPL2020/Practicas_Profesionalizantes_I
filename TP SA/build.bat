:: Compilo el Binario
g++ -Wall -std=c++11 -c lista.cpp 
g++ -Wall -std=c++11 -c bd.cpp 
g++ -Wall -std=c++11 -c main.cpp 
g++ lista.o bd.o main.o  -o asistencia.exe

:: Limpio los códigos objeto
DEL .\*.o