#pragma once
#include "Nodo.h"
using namespace std;
class Pila
{private:
	Nodo* topePtr;
	bool EstaVacia();
public:
	Pila();
	~Pila();
	void mete(int valor);
	int saca();
	int nodoInicio();
	void mueve(Pila &p1);
	void muestra();
	int cantidadElementos();
	int NodoMAyor();
	void eliminarNodo(int ref);
	void concatenar(Pila &p1);
};

