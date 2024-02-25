#pragma once
#include "Nodo.h"
class Cola
{
    Nodo* incio;
    Nodo* final;

    bool vacio();
public:
    int nodoInicio();
    int nodoFinal();
    void meter(int valor);
    void Sacar();

    void mostrar();
    ~Cola();
    Cola();
    void mueve(Cola c);
    int cantidad();
    int mayor();
    void elemininar(int referencia);
    void mezcla(Cola c1, Cola c2);

};

