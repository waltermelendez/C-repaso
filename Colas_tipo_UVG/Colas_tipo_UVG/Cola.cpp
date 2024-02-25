#include "Cola.h"
#include <cstddef>
#include<string>
#include<iostream>
using namespace std;
bool Cola::vacio() {
	if (incio == NULL && final == NULL) {
		return 1;

	}
	else {
		return 0;
	}
}
Cola::Cola() {
	incio = NULL;
	final = NULL;


}
Cola ::~Cola() {
	while (!vacio()) {
		Sacar();
	}
}
void Cola::Sacar() {
	if (vacio()) {
		cout << "la cola esta vacia\n";
		exit(1);
		return;
	}
	Nodo* temporal = incio;
	incio = incio->sguiente;
	if (incio == NULL) {
		final = NULL;
	}
	delete temporal;
}
void Cola::meter(int valor) {
	Nodo* nuevo = new Nodo();
	nuevo->datos = valor;
	nuevo->sguiente = NULL;
	if (final != NULL) {
		final->sguiente = nuevo;
	}
	final = nuevo;
	if (incio == NULL) {
		incio = nuevo;
	}
}
int Cola::nodoInicio() {
	if (incio == NULL) {
		cout << "La cola esta vacia.\n";
	}
	return incio->datos;
}
int Cola::nodoFinal() {
	if (final == NULL) {
		cout << "La cola esta vacia.\n";
	}
	return final->datos;
}

void Cola::mostrar() {
	if (vacio()) {
		cout << "La cola esta vacia.\n";
		system("pause");
		return;
	}
	Cola aux;//crea unauxiliar
	int x;
	cout << "Los elemtos son: ";
	while (!vacio()) {
		x = nodoInicio();
		cout << x << " -> "; //meutsra el dato
		Sacar();//saca el dato mostrado
		aux.meter(x);//guarda el dato

	}
	while (!aux.vacio()) {//regresa los datos  desde aux
		x = aux.nodoInicio();
		aux.Sacar();
		meter(x);//regra el dato a la cola


	}
	cout << "\n \n";
	system("pause");


}


void Cola::mueve(Cola c) {
	int x;//variable temporal
	while (!c.vacio()) {
		x = c.nodoInicio();
		c.Sacar();
		meter(x);
	}
}
void Cola::elemininar(int referencia) {
	if (vacio()) {
		cout << "La cola esta vacia.\n";
		return;
	}
	Cola aux;//cola auxiliar para no perder datos
	int x;//vareiable temporal
	bool encontrado = false;//si se encuetra el valor;
	while (!vacio()) {
		x = nodoInicio();
		Sacar();
		if (referencia == x) {
			cout << "Nodo eliminado \n";
			encontrado = true;
		}
		else {
			aux.meter(x);//guarda el dato en la cola	
		}
		//regresa eldato desde aux
		mueve(aux);

	}
	if (!encontrado) {
		cout << "No esta en la cola\n";
	}

}