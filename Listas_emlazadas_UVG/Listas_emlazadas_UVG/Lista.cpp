#include "Lista.h"
#include <cstddef>
using namespace std;
#include <iostream>
bool Lista::Estvacia() {
	return primeroPtr == NULL;
}
Lista::Lista() {
	primeroPtr = NULL;
}
Lista::~Lista() {
	if (!Estvacia()) {
		cout << "Destruyendo nodos\n";
		Nodo* actualPtr = primeroPtr;
		Nodo* tempPtr;
		//eliminar nodos restantes
		while (actualPtr != NULL)
		{
			tempPtr = actualPtr;
			cout << "tempPtr->datos" << " ' ' ";
			actualPtr = actualPtr->siguientePtr;
			delete tempPtr;
		}
	}
	cout << "Se destruyeron todos los nodos\n";
}
void Lista::InsertaralInicio(int v) {
	Nodo* nuevoPtr = new Nodo();
	nuevoPtr->dato = v;
	if (Estvacia()) {//La lista esta vacia
		nuevoPtr->siguientePtr = NULL;

	}
	else {//La lista no esta vacia
		nuevoPtr->siguientePtr = primeroPtr;
	}
	primeroPtr = nuevoPtr;//Apunta al primer nodo de la lista hacia el nuevo nodo

}
void Lista::RecorrerIterativo() {
	if (Estvacia()) {
		cout << "La lista esta vacia" << endl;
		system("pause");
		return;
	}
	Nodo* actual = primeroPtr;
	cout << "	Los elementos de la lista son: \n";
	while (actual != NULL)
	{
		cout << actual->dato << " ->";
		actual = actual->siguientePtr;
	}
	cout << "NULL\n";
	system("pause");

}
void Lista::insertaralFinal(int c) {
	Nodo* nuevo = new Nodo();
	nuevo->dato = c;
	nuevo->siguientePtr = NULL;
	if (Estvacia()) {// si eat vacia
		primeroPtr = nuevo;
	}
	else
	{//si no esta vacia
		Nodo* actual = primeroPtr;
		while (actual->siguientePtr != NULL)
		{
			actual = actual->siguientePtr;
		}
		actual->siguientePtr = nuevo;//el ultimo nodo
	}
}
void Lista::llamadoRecorridoRecursivo() {
	if (Estvacia()) {
		cout << "La lista esta vacia\n";
		system("pause");
		return;
	}
	cout << "Los elementos de la lista de forma recursiva son: ";
	RecorrerREcursivo(primeroPtr);
}
void Lista::RecorrerREcursivo(Nodo* actualPTR) {
	if (actualPTR != NULL) {
		cout << actualPTR->dato << " -> ";
		RecorrerREcursivo(actualPTR->siguientePtr);
	}
}
void Lista::insertarAntes(int ref, int v) {
	if (Estvacia()) {
		cout << "El nodo dado como refencia no esta en la lista\n";//si esta  vacia la lista
	}
	Nodo* nuevoPtr = new Nodo();
	nuevoPtr->dato = v;
	nuevoPtr->siguientePtr = NULL;
	//Se crea un nuevo nodo a insertar↑

	Nodo* actualPTR = primeroPtr;// obtiene el primer  nodo de la lista 
	Nodo* previoPTR= new Nodo();//guarda el dato anterior de la lsitaa actual
	int Band = 1;//variable si se encuentra el valor

	while (actualPTR->dato != ref && Band == 1)
	{
		if (actualPTR->siguientePtr == NULL) {
			previoPTR = actualPTR;//guarda el nodo actual antes de saltar
			actualPTR = previoPTR->siguientePtr;

		}
		else {
			Band = 0;
		}
	}
	if (Band == 1) {
		if (primeroPtr == actualPTR) {
			nuevoPtr->siguientePtr = primeroPtr;
			primeroPtr = nuevoPtr;
		}
		else
		{
			previoPTR->siguientePtr = nuevoPtr;
			nuevoPtr->siguientePtr = actualPTR;
		}
	}
	else
	{
		cout << " El nodo de refencia no esta en la  lista\n";
	}
}
void Lista::eliminarprimero() {
	if (Estvacia()) {
		cout << "La lista esta vacia\n";
	}
	cout << "Destruyendo el nodo: " << primeroPtr->dato << "\n";
	Nodo* tempPTr = primeroPtr;
	primeroPtr = primeroPtr->siguientePtr;
	delete tempPTr;
}
void Lista::EliminarNodos(int refe) {
	if (Estvacia()) {
		cout << "La lista esta vacia\n";
		return;
	}
	Nodo* actualPtr = primeroPtr;
	Nodo* previoPtr=new Nodo();
	while (actualPtr->dato != refe && actualPtr->siguientePtr != NULL)
	{
		previoPtr = actualPtr;//guarda el nodo actual y pasa al siguiente
		actualPtr = actualPtr->siguientePtr;
	}
	if (actualPtr->dato == refe) {//si encontro la referencia
		Nodo* tempPtr = actualPtr;//guardar en nodo eliminar
		if (primeroPtr == actualPtr) {// si el nodo de refencia es igual al primero
			primeroPtr = primeroPtr->siguientePtr;//el repvio apunta al siguiente
		}
		else
		{
			previoPtr->siguientePtr = actualPtr->siguientePtr;//nodo previo
		}
		cout << "Destruyendo nodos: " << tempPtr->siguientePtr << endl;
		delete tempPtr;//librerar memoria
	}
	else
	{
		cout << "el nodo dado como refencia no se encuentra en la lista\n";
	}

}
void Lista::insertarDespues(int refe, int valor) {
	if (Estvacia()) {
		cout << "el nodo de refencia no se encuentra en la lista\n";
		system("pause");
		return;
	}
	Nodo* nuevoPtr = new Nodo();
	nuevoPtr->dato = valor;
	nuevoPtr->siguientePtr = NULL;
	Nodo* actual = primeroPtr;
	//recorre hasta encontrar el valor o llegar al ultimo nodo
	while (actual->dato != refe && actual->siguientePtr != NULL)
	{
		actual = actual->siguientePtr;
	}if (actual->dato == refe) {
		nuevoPtr->siguientePtr = actual->siguientePtr;
		actual->siguientePtr = nuevoPtr;
	}
	else
	{
		cout << "El nodo de refencia no esta en la lista\n";
	}
}
void Lista::eliminarUltimo() {
	if (Estvacia()) {
		return;
	}
	Nodo* actual = primeroPtr;//primer valor
	Nodo* pre = new Nodo();//variable que guarda	el nodo
	while (actual->siguientePtr != NULL)//recorrer hasta este vacio
	{
		pre = actual;//guarda el nodo antes de pasar
		actual = actual->siguientePtr;

	}
	Nodo* tempPtr = actual;//guarda el nodo antes de eliminar
	if (primeroPtr == actual) {//si solo hay un nodo
		primeroPtr = NULL;//se vacia la lista
	}
	else
	{
		pre->siguientePtr = NULL;//el nodo previo se vuelve null
	}
	cout << "DEstruyendo el nodo" << tempPtr->dato << endl;
	delete tempPtr;
}

