

#include <iostream>
#include "Cola.h"
#include "Nodo.h"
int main()
{
    Cola* primera = new Cola();
    primera->meter(12);
    primera->meter(343);
    primera->meter(456);
    primera->mostrar();
    std::cout << "Hello World!\n";
}
