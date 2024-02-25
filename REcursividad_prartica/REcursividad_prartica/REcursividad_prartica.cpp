// REcursividad_prartica.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;
#include<conio.h>
int factorial(int);
int factorial(int n) {
    if (n == 0) {
        n = 1;
    }
    else {
        n = n * factorial(n-1);
    }
    return n;
}
int sumar(int);
int sumar(int n) {
    int suma = 0;
    if (n == 1) {
        suma = 1;
    }
    else {
        suma = n + sumar(n - 1);
    }
    return suma;
}
int fibo(int);
int fibo(int n) {
    int s;
    if (n == 0) {
        s = 0;
    }
    else {
        s = n + fibo(n - 1);
    }
    return s;
}

int main()
{
    int ele;
    do {
        cout << "de un numero\n";
        cin >> ele;
    } while (ele<= 0);
    cout << "la suma es "<<sumar(ele) << endl;
    cout << "factorial "<<factorial(5) << endl;
    cout << " fibo " << fibo(1)<<endl;
    std::cout << "Hello World!\n";
}

