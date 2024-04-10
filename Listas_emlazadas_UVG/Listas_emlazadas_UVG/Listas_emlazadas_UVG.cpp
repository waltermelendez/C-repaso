

#include <iostream>
using namespace std;
#include "Lista.h"
#include "Nodo.h"
void menu() {
    system("cls");
    cout << "LISTA SIMPLEMENTE LIGADA\n";
    cout << "Walter Melendez Aguilar\n";
    cout << "Insertar elementos al inicio\n";
    cout << "Imprimir valores de la lista";
    cout << "Salir\n";
    cout << "Ingrese un valor\n";
    //\t Sangria

}
int main()
{
    //int opcion;//opcion menu
    //int valor;//valor de nodo
    //Lista    listaEnteros;//Objeto lista
    //system("color 1F");
    //do {
    //    menu();
    //    cin >> opcion;
    //    switch (opcion)
    //    {
    //    case 1:
    //        cout << "Ingrese un valor de entero\n";
    //        cin >> valor;
    //        listaEnteros.InsertaralInicio(valor);
    //        listaEnteros.RecorrerIterativo();

    //        break;
    //    case 2:
    //        listaEnteros.RecorrerIterativo();
    //        break;
    //    default:
    //        opcion = 3;
    //        break;
    //    }
    //} while (opcion!=3);
    //listaEnteros.eliminarprimero();
    //listaEnteros.llamadoRecorridoRecursivo();
    //listaEnteros.insertaralFinal(12);
    //listaEnteros.insertarAntes(4,3);
    //listaEnteros.insertarDespues(1, 6);
    Lista my_;
    my_.InsertaralInicio(12);
    my_.InsertaralInicio(122);
    my_.InsertaralInicio(900);
    my_.RecorrerIterativo();
    return 0;

}
