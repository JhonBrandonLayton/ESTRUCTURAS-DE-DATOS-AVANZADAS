#include <iostream>
#include <conio.h>
using namespace std;

int busquedaBinaria(const int arreglo[], int inicioArreglo, int finalArreglo, int objetivo) {
    while (inicioArreglo <= finalArreglo)
    {
        int mitad = (inicioArreglo + finalArreglo) /2;

        if (arreglo[mitad] == objetivo)
        {
            return mitad; //Elemento encontrado en la mitad
        }
        if (arreglo[mitad] > objetivo)
        {
            finalArreglo = mitad -1; //Busqueda en la mitad izquierda
        }else 
        {
            inicioArreglo = mitad + 1; //Busqueda en la mitad derecha
        }
    }
    return -1; //Elemento no encontrado
}

int main()
{
    /*3 arreglos 15 datos*/
    int arreglo1[15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int arreglo2[15] = {16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
    int arreglo3[15] = {31,32,33,34,35,36,37,38,39,40,41,42,43,44,45};

    int objetivo;
    cout<<"Ingrese el dato a buscar: ";
    cin>>objetivo;

    int posicionArreglo1 = busquedaBinaria(arreglo1, 0, sizeof(arreglo1) / sizeof(arreglo1[0]) -1, objetivo);
    int posicionArreglo2 = busquedaBinaria(arreglo2, 0, sizeof(arreglo2) / sizeof(arreglo2[0]) -1, objetivo);
    int posicionArreglo3 = busquedaBinaria(arreglo3, 0, sizeof(arreglo3) / sizeof(arreglo3[0]) -1, objetivo);
    
    if (posicionArreglo1 != -1)
    {
        cout<<"El numero "<<objetivo<<" fue encontrado en el arreglo 1 en la posicion "<<posicionArreglo1<<" con direccion de memoria "<<&objetivo<<endl;
    }
    if (posicionArreglo2 != -1)
    {
        cout<<"El numero "<<objetivo<<" fue encontrado en el arreglo 2 en la posicion "<<posicionArreglo2<<" con direccion de memoria "<<&objetivo<<endl;
    }
    if (posicionArreglo3 != -1)
    {
        cout<<"El numero "<<objetivo<<" fue encontrado en el arreglo 3 en la posicion "<<posicionArreglo3<<" con direccion de memoria "<<&objetivo<<endl;
    }
    if (posicionArreglo1 == -1 && posicionArreglo2 == -1 && posicionArreglo3 == -1)
    {
        cout<<"El elemento no fue encontrado en ninguno de los arreglos"<<endl;
    } 
    getch();
    system("pause");
    return 0;
}
