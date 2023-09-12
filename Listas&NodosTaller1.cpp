#include <iostream>
#include <conio.h>
using namespace std;

// ESTRUCTURA DE NODO
struct Nodo
{
    int dato;
    Nodo *siguiente; 
};

//FUNCION IMPRIMIR ELEMENTOS DE NODO
void imprimirLista(Nodo *actual){
    if (actual == nullptr)
    {
        cout<<endl;
        return;
    }
    cout<<endl<<actual->dato<<" "<<endl;
    imprimirLista(actual->siguiente);
}

int main(){
    //CEACION DE NODOS
    Nodo* inicio = new Nodo;
    Nodo* segundo = new Nodo;
    Nodo* tercero = new Nodo;
    Nodo* cuarto = new Nodo;
    Nodo* quinto = new Nodo;

    //ASIGNACION DE VALORES Y ENLACES DE NODOS
    inicio->dato = 5;
    inicio->siguiente = segundo;

    segundo->dato = 10;
    segundo->siguiente = tercero;

    tercero->dato = 15;
    tercero->siguiente = cuarto;

    cuarto->dato = 20;
    cuarto->siguiente = quinto;

    quinto->dato = 25;
    quinto->siguiente = nullptr;

    //MOSTRAR LISTA
    cout<<"Lista enlazada: ";
    imprimirLista(inicio);

    //ELIMINAR NODOS
    delete inicio;
    delete segundo;
    delete tercero;
    delete cuarto;
    delete quinto;

    getch();
    return 0;
    system("pause");
}
