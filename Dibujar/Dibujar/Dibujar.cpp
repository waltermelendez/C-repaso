
#include <iostream>
using namespace std;
#include <string>
int tablesize = 10;
//metodo de division
int hashi(char* a, int stringsize) {
	int hashval, j;
	hashval = (int)a[0];
	for (j = 1; j < stringsize; j++)
	{
		hashval += (int)a[j];

	}
	return(hashval % tablesize);
}
struct Alumno
{
	char nombre[50];
	int nota;
	int estado = 0;
	int clave;

};
int insertar(Alumno* A, Alumno* B, int i, int n) {
	int j = (A[i].nota + 1) % n;
	do
	{
		if (A[j].estado == 0) {
			B[j] = A[j];
			A[j].estado = 1;
		}
		else
		{
			j++;
		}
	} while (j>n);
	return j;
}

int buscarHash(Alumno* A, int n, int clave) {
	int j = 0;
	while (j<n)
	{
		if (A[j].clave == clave) {
			return j;

		}
		else
		{
			j++;
		}
		return -1;
	}
}
int main()
{
	char a[4] = { 'j','o','s','e' };

	cout << "Hash posicion:" << hashi(a, 4) << endl;
	cout << "---------------------------------------------\n";
	int op = 0, n, clave, x;
	do {
		cout << "ingrese la cantidad de alumnos: \n ";
		cin >> n;
	} while (n <= 0);
	Alumno* A = new Alumno[n];
	Alumno* B = new Alumno[n];
	system("cls");
	do {
		cout << "\t ---------------------\n";
		cout << "\tMETODO DE BUSQUEDA DE HASH\n";
		cout << "1.Insertar, / 2.Buscar\n";
		cout << "\t 3.Salir \n";
		cout << "\t ingrese la opcion\n";
		cin >> op;
		system("cls");
		switch (op)
		{
		case 1:
			for (int i = 0; i < n; i++)
			{
				cout << "DATOS DEL ALUMNO "<<1+i<<endl;
				fflush(stdin);
				cout << "Nombre\n";
				cin.ignore();
				cin.getline(A[i].nombre, 50);
				do {
					cout << "notas\n";
					cin >> A[i].nota;
				} while (A[i].nota<0||A[i].nota>20);
				A[i].clave = insertar(A, B, i, n);
				cout << "clave: ";
				cout << A[i].clave << endl;
			}
			break;
		case 2:
			cout << "Diga el codigo a buscar\n";
			fflush(stdin);
			cin >> clave;
			x = buscarHash(A, n, clave);
			if (x == -1) {
				cout << "numero no encontrado\n";

			}
			else {
				cout << "Numero encontrado" << endl;
				cout << "Nombre: " << B[x].nombre << endl;
				cout << "nota: " << B[x].nota << endl;
			}
			break;
		case 3:
			cout << "OK\n";
			break;
		default:
			cout << "Opcion no disponible\n";
			system("pause");
			break;
		}

	} while (op!=3);
	return 0;
}
