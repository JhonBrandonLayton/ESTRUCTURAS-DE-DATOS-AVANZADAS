#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

struct Nodo
{
    int dato;
    Nodo *izquierda;
    Nodo *derecha;
};

Nodo *arbol = NULL;

/*CREACION DE NODO*/
Nodo *crearNodo(int numero){
    Nodo *nuevoNodo = new Nodo();

    nuevoNodo->dato = numero;
    nuevoNodo->izquierda = NULL;
    nuevoNodo->derecha = NULL;

    return nuevoNodo;
}

//INSERTAR DATOS
void insertarNodo(Nodo *&arbol, int numero){

    if (arbol == NULL)
    {
        Nodo *nuevoNodo = crearNodo(numero);
        arbol = nuevoNodo;
    }else{
        int valorRaiz = arbol->dato;
        if (numero < valorRaiz) //Insercion lado izquierdo
        {
            insertarNodo(arbol->izquierda, numero);
        }else if(numero > valorRaiz){ //Insercion lado derecho
            insertarNodo(arbol->derecha, numero);
        }else{
            cout<<"El valor ya existe, digite otro numero: ";
            cin>>numero;
            insertarNodo(arbol, numero);
        }
    }
    
}

void menu(){
    int opcion, numero;

    do
    {
        cout<<"\t MENU ARBOLES BINARIOS: \n";
        cout<<"Escoja una opcion: \n";
        cout<<"1. INSERTAR NODOS \n";
        cout<<"2. SALIR \n";
        cin>>opcion;

        switch (opcion)
        {
        case 1:
            cout<<"Digite un numero: ";
            cin>>numero;
            insertarNodo(arbol, numero);
            cout<<"\n";
            system("pause");
            break;

        default:
            break;
        }
        system("cls");
    } while (opcion != 2);
    
}

int main(){
    menu();

    getch();
    return 0;
}