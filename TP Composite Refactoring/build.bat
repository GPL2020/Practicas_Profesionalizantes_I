:: Compilo el Binario
cd src
g++ -Wall -std=c++11 -c CompositeRefactoring.cpp

g++ CompositeRefactoring.o -o cr.exe

echo "Programa compilado"
pause

:: Limpio los códigos objeto
DEL .\*.o