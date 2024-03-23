#pragma once
#include "Nodo.h"
class Lista
{
private:
	Nodo* primeroPtr;
	bool Estvacia();
public:
	Lista();
	~Lista();
	void InsertaralInicio(int v);
	void RecorrerIterativo();
	//funciones extras
	void insertaralFinal(int c);
	void llamadoRecorridoRecursivo();
	void RecorrerREcursivo(Nodo * actualPTR);
	void insertarAntes(int refe,int v);
	void eliminarprimero();
	void EliminarNodos(int refe);
	//otras operaciones
	void insertarDespues(int refe,int v);
	void eliminarUltimo();
};

