#include "Pila.h"
#include <cstddef>
using namespace std;
#include <string>
#include <iostream>
Pila::Pila() {//constructor
	topePtr = NULL;
}
Pila::~Pila() {//destructor
	while (!EstaVacia()) {
		saca();
	}
}
//verifica si la fila esta vacia
bool Pila::EstaVacia() {
	return topePtr == NULL;
}
void Pila::mete(int valor) {//mete un dato en la fila
	Nodo* nuevoPtr = new Nodo();
	nuevoPtr->dato = valor;
	nuevoPtr->siguientePtr = topePtr;
	topePtr = nuevoPtr;//apunta al nuevo dato ingresado
}
int Pila::saca() {//saca un elemento de la pila, simepre inicio
	if (EstaVacia()) {//si esta vacia
		cout << "\nError en saca(). La pila eat vacia\n";
	}
	int x = topePtr->dato;//guarda el dato en el tope
	Nodo* tempPtr = topePtr;//guarda el nodo a sacar 
	topePtr = topePtr->siguientePtr;
	delete tempPtr;//libera
	return x;//regresa el dato sacado
}
int Pila::nodoInicio() {
	if (topePtr == NULL) {
		cout << "\nError de incicio().La pila esta vacia";
		exit(1);
	}
	return topePtr->dato;
}
void Pila::mueve(Pila& p1) {//mueve los elemntos de una
	int x;//variable temp
	//regresa Los datos desd
	while (!p1.EstaVacia()) {
		x = p1.saca();
		mete(x);//mete
	}
}
void Pila::muestra() {//muestra los datos
	if (EstaVacia()) {//La pila eat vacia
		cout << "\nLa pila eata vacia\n";
		system("pause");
		return;
	}
	Pila aux;//pila aux
	int x;//variable temporal
	cout << "Los elemtos son:\n";
	//muetsra los datos
	while (!EstaVacia()) {
		x = saca();
		cout << x<<" x-> ";//muestra el dato
		aux.mete(x);//guarda el dato en la parte 
	}
	mueve(aux);
	cout << "NULL\n";
	system("pause");
}
int Pila::cantidadElementos() {
	if (EstaVacia()) {
		return 0;
	}
	Pila aux;//pila auxiliar
	int x; //variable auxiliar
	int contador = 0;
	//muetra los datos y los guarda
	while (!EstaVacia()) {
		x = saca();// saca el dato
		aux.mete(x);//guarda el dato
		contador++;
	}
	//regresa los datos de la pila auxiliar
	mueve(aux);
	return contador;
}
int Pila::NodoMAyor() {
	if (EstaVacia()) {
		cout << "Pila vacia\n";
		return	0;

	}

		
	Pila aux;//variable axuiliar para no pderdre datos
	int x, mayor;//variable temporal para el dato mayor y variable temporal

	mayor = saca();//si solo hay un dato o nodo se pasa a guarda en la nueva pila
	aux.mete(mayor);
	while (!EstaVacia())
	{
		x = saca();

	}
}
void Pila::eliminarNodo(int refe){
	if (EstaVacia()) {
		cout << "No esta en la pila\n";
		return;
	}
	Pila aux;
	int x;
	bool enctrado = false;// esta o no en la pila
	while (!EstaVacia())
	{
		x = saca();//saca el dato
		if (refe == x) {
			cout << "Nodo eliminado" << x <<endl;
			enctrado = true;
		}
		else {
			aux.mete(x);
		}

	}
	mueve(aux);
	if (!enctrado) {
		cout << "No se encuentra en la fila\n";
	}
}
void Pila::concatenar(Pila &p1){
	Pila ux;
	int x;
	ux.mueve(p1);
	mueve(ux);
}
