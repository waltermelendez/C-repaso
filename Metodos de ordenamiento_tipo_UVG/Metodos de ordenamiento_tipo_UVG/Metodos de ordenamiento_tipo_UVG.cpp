using namespace std;
#include <iostream>

void metodo_burbuja(int A[], int lon) {

	int temp;
	for (int i = 0;i < lon;i++) {
		for (int j = i + 1;j < lon;j++) {
			if (A[j] < A[i]) {
				temp = A[i];
				A[i] = A[j];
				A[j] = temp;
			}
		}
	}
	cout << "\tArrglo ordenado del metodo burbuja\n";
	for (int i = 0;i < lon;i++) {
		cout << A[i] << " , ";
	}
	cout << endl;
}

void metodo_seleccion(int A[], int lon) {
	int min;

	int p, temp;
	for (int i = 0; i < lon;i++) {
		min = A[i];
		p = i;
		for (int j = i + 1; j < lon; j++)
		{
			if (min > A[j]) {
				min = A[j];
				p = j;
			}
		}
		temp = A[i];
		A[i] = A[p];
		A[p] = temp;

	}
	cout << "\tArreglo ordenado del metodo seleccion\n";
	for (int i = 0;i < lon;i++) {
		cout << A[i] << " , ";
	}
	cout << endl;
}

int main()
{

	cout << "\tarreglo de metodo burbuja no ordenado\n ";
	int A[8] = { 15,67,8,16,44,27,12,35 };
	int lon = 8;
	for (int i = 0;i < 8;i++) {
		cout << A[i] << " , ";
	}
	cout << endl;
	metodo_burbuja(A, lon);
	cout << "\tmetodo burbuja ^\n";

	cout << "------------------------------------\n";
	int B[8] = { 12,3,45,66,100,78,95,9 };

	cout << "\tarreglo no ordenado del metodo de insercion\n";

	for (int i = 0; i < 8; i++)
	{
		cout << B[i] << " , ";
	}

	cout << endl;
	cout << endl;
	metodo_insercion(B, 8);
	cout << "\t metodo insercion ^\n";

	cout << "---------------------------------------------------\n";
	cout << "\tMetodo de seleccion, arreglo no ordenado\n";
	int C[8] = { 41,2,0,46,88,99,100,44 };
	for (int i = 0; i < lon; i++)
	{
		cout << C[i] << " ,";
	}
	cout << endl;
	cout << endl;
	metodo_seleccion(C, 8);
	cout << "\t metodo seleccion ^\n";

	cout << "---------------------------------------------------\n";
	cout << "\tMetodo Quick, arreglo no ordenado\n";
	int D[8] = { 10,56,88,44,13,2,99,67 };
	for (int i = 0;i < 8;i++) {
		cout << D[i] << " , ";
	}
	cout << endl;
	cout << endl;
	cout << "------------------------------\n";
	cout << "metodo merge, arreglo no ordenado\n";
	int E[8] = { 34,67,0,89,10,11,101,8 };
	for (int i = 0; i < 8; i++)
	{
		cout << E[i] << " , ";
	}
	cout << endl;
	cout << endl;
	pivote_merge(E, 0, 8);
	return 0;
}
