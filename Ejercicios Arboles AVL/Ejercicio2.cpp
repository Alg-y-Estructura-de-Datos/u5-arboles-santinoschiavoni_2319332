/*
Imagina que trabajas en una tienda que vende una variedad de productos. Cada producto 
tiene un código único que lo identifica y necesitas gestionar el inventario utilizando un 
árbol AVL para asegurarte de que el sistema esté optimizado y balanceado. Los productos 
se identifican únicamente por su código, y no hay productos duplicados en el inventario. 
Opciones del menú: 
1. Agregar producto: Inserta un nuevo código de producto en el sistema. 
2. Eliminar producto: Elimina un código de producto del sistema. 
3. Buscar producto: Verifica si un código de producto existe en el inventario. 
4. Mostrar inventario: Imprime el árbol AVL de productos para mostrar su estructura 
balanceada. 
5. Salir: Finaliza el programa. 
*/

#include<iostream>
#include "Arbol/ArbolBinarioAVL.h"
using namespace std;

void menu(){
    cout << "1. Agregar producto" << endl;
    cout << "2. Eliminar producto" << endl;
    cout << "3. Buscar producto" << endl;
    cout << "4. Mostrar inventario" << endl;
    cout << "5. Salir" << endl;
}

void agregarProducto(ArbolBinarioAVL<int> &arbol){
    int codigo;
    cout << "Ingrese el codigo del producto: ";
    cin >> codigo;
    try{
        arbol.put(codigo);
        cout << "" << endl;
    } catch(int e){
            cout << "El producto con ID " << codigo << " ya se encuentra en el inventario" << endl;
    }
}

void eliminarProducto(ArbolBinarioAVL<int> &arbol){
    int codigo;
    cout << "Ingrese el codigo del producto a eliminar: ";
    cin >> codigo;
    try{
        cout << "" << endl;
        arbol.remove(codigo);
        cout << "El producto con ID " << codigo << " ha sido eliminado" << endl;
    } catch(int e){
            cout << "El producto con ID " << codigo << " no se encuentra" << endl;
    }
}

void buscarProducto(ArbolBinarioAVL<int> &arbol){
    int codigo;
    cout << "Ingrese el codigo del producto a buscar: ";
    cin >> codigo;
    try{
        cout << "" << endl;
        arbol.search(codigo);
        cout << "El producto con ID " << codigo << " se encuentra en el inventario" << endl;
    } catch(int e){
        if(e==404){
            cout << "El producto con ID " << codigo << " no se encuentra" << endl;
        }
    }
}

int main(){
    ArbolBinarioAVL<int> arbol;
    int opcion=0;
    do{
        menu();
        cout << "Ingrese la opcion deseada: ";
        cin >> opcion;
        switch(opcion){
            case 1:
                agregarProducto(arbol);
                break;
            case 2:
                eliminarProducto(arbol);
                break;
            case 3:
                buscarProducto(arbol);
                break;
            case 4:
                cout << "" << endl;
                cout << "Inventario: " << endl;
                arbol.print();
                cout << "" << endl;
                //Cuando apreto enter q se limpia la pantalla
                cout << "Presione enter para continuar...";
                cin.ignore();
                cin.get();
                system("cls");
                break;
            case 5:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion no valida" << endl;
                break;
        }
    } while(opcion!=5);
    return 0;
}