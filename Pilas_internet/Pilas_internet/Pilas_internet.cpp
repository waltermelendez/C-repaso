
#include <iostream>
using namespace std;
#include "Nodo.h"
#include "Pila.h"
int main()
{//ESTA PILA TAMBIEN ES DE TIPO UVG
    Pila* nuevaPila = new Pila();
    nuevaPila->mete(45);
    nuevaPila->mete(60);
    nuevaPila->mete(1);
    nuevaPila->cantidadElementos();
    nuevaPila->muestra();
    nuevaPila->eliminarNodo(45);
    nuevaPila->muestra();
    
}

