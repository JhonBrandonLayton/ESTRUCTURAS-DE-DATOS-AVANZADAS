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

Nodo *crearNodo(int numero){
    Nodo *nuevoNodo = new Nodo();

    nuevoNodo->dato = numero;
    nuevoNodo->izquierda = NULL;
    nuevoNodo->derecha = NULL;

    return nuevoNodo;
}

void insertarNodo(Nodo *&arbol, int numero){

    if (arbol == NULL)
    {
        Nodo *nuevoNodo = crearNodo(numero);
        arbol = nuevoNodo;
    }else{
        int valorRaiz = arbol->dato;
        if (numero < valorRaiz){
            insertarNodo(arbol->izquierda, numero);
        }else if(numero > valorRaiz){
            insertarNodo(arbol->derecha, numero);
        }else{
            cout<<"El valor ya existe, digite otro numero: ";
            cin>>numero;
            insertarNodo(arbol, numero);
        }
    }
    
}
    
void PreOrden(Nodo *arbol, int numero){
    if(arbol != NULL){
        cout << arbol->dato << " ";
        PreOrden(arbol->izquierda, numero);
        PreOrden(arbol->derecha, numero);
    }
}

void InOrden(Nodo *arbol, int numero){
    if(arbol != NULL){
        InOrden(arbol->izquierda, numero);
        cout << arbol->dato << " ";
        InOrden(arbol->derecha, numero);
    }
}

void PostOrden(Nodo *arbol, int numero){
    if(arbol != NULL){
        PostOrden(arbol->izquierda, numero);
        PostOrden(arbol->derecha, numero);
        cout << arbol->dato << " ";
    }
}

bool buscar(Nodo *arbol, int numero, int nivel) {
    if (arbol == NULL) {
        cout << "Numero no encontrado en el árbol.\n";
        return false;
    }

    if (arbol->dato == numero) {
        cout << "Numero " << numero << " encontrado en el nivel " << nivel << ".\n";
        return true;
    } else if (numero < arbol->dato) {
        cout << "Descendiendo a la izquierda en el nivel " << nivel << ".\n";
        return buscar(arbol->izquierda, numero, nivel + 1);
    } else {
        cout << "Descendiendo a la derecha en el nivel " << nivel << ".\n";
        return buscar(arbol->derecha, numero, nivel + 1);
    }
}

Nodo* encontrarMinimo(Nodo* arbol) {
    while (arbol->izquierda != NULL) {
        arbol = arbol->izquierda;
    }
    return arbol;
}

void eliminarNodoSinHijos(Nodo *&arbol, int numero) {
    if (arbol == NULL) {
        return; 
    }

    if (numero < arbol->dato) {
        eliminarNodoSinHijos(arbol->izquierda, numero);
    } else if (numero > arbol->dato) {
        eliminarNodoSinHijos(arbol->derecha, numero);
    } else {
        
        cout << "Nodo eliminado exitosamente.\n";
        delete arbol;
        arbol = NULL; 
    }
    
}


void eliminarNodoConUnHijo(Nodo *&arbol, int numero) {
    if (arbol == NULL) {
        return; 
    }

    if (numero < arbol->dato) {
        eliminarNodoConUnHijo(arbol->izquierda, numero);
    } else if (numero > arbol->dato) {
        eliminarNodoConUnHijo(arbol->derecha, numero);
    } else {
        
        if (arbol->izquierda == NULL) {
            Nodo* temp = arbol;
            arbol = arbol->derecha;
            delete temp;
        } else if (arbol->derecha == NULL) {
            Nodo* temp = arbol;
            arbol = arbol->izquierda;
            delete temp;
        }
    }
    cout << "Nodo eliminado exitosamente.\n";
}

void eliminarNodoConDosHijos(Nodo *&arbol, int numero) {
    if (arbol == NULL) {
        return;
    }
    if (numero < arbol->dato) {
        eliminarNodoConDosHijos(arbol->izquierda, numero);
    } else if (numero > arbol->dato) {
        eliminarNodoConDosHijos(arbol->derecha, numero);
    } else {
        Nodo* sucesor = encontrarMinimo(arbol->derecha); 
        arbol->dato = sucesor->dato;
        eliminarNodoConUnHijo(arbol->derecha, sucesor->dato);
        cout << "Nodo eliminado exitosamente.\n";
    }
    
}



void menu(){
    int opcion, numero;

    do
    {
        cout<<"\t MENU ARBOLES BINARIOS: \n";
        cout<<"Escoja una opcion: \n";
        cout<<"1. INSERTAR NODOS \n";
        cout<<"2. MOSTRAR METODOS DE ORDEN \n";
        cout<<"3. BUSCAR METODO DE ORDEN \n";
        cout<<"4. ELIMINAR NODO \n";
        cout<<"5. SALIR \n";
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
        case 2:
            cout<<"Metodo PreOrden : ";
            PreOrden(arbol, numero);
            cout<<"\n";
            cout<<"\n";
            cout<<"Metodo InOrden : ";
            InOrden(arbol, numero);
            cout<<"\n";
            cout<<"\n";
            cout<<"Metodo PostOrden : ";
            PostOrden(arbol, numero);
            cout<<"\n";
            system("pause");
        break;
        case 3:
            cout << "Digite un numero a buscar: ";
            cin >> numero;
            buscar(arbol, numero, 0);
            cout << "\n";
            system("pause");
        break;
        case 4:
            cout << "Digite un numero a eliminar: ";
            cin >> numero;
            if (arbol != NULL) {
                if (buscar(arbol, numero, 0)) {
                    if (arbol->izquierda == NULL && arbol->derecha == NULL) {
                        eliminarNodoSinHijos(arbol, numero);
                    } else if ((arbol->izquierda == NULL) || (arbol->derecha == NULL)) {
                        eliminarNodoConUnHijo(arbol, numero);
                    } else {
                        eliminarNodoConDosHijos(arbol, numero);
                    }
                }
            } 
            cout << "\n";
            system("pause");
        break;
        default:
            break;
        }
        system("cls");
    } while (opcion != 5);
    
}

int main(){
    menu();

    getch();
    return 0;
}