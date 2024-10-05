/*
Un almacén necesita gestionar su inventario de productos. Cada producto tiene un número 
único  de  identificación  (ID),  y  el  sistema  debe  mantener  el  inventario  organizado  para 
realizar búsquedas rápidas de productos y permitir actualizaciones del stock. 
Utilizar  un  árbol  AVL  para  almacenar  los  IDs  de  los  productos.  El  árbol  debe  mantenerse 
balanceado para garantizar búsquedas rápidas. 
Crear un sistema con un menú que permita gestionar las siguientes opciones: 
1. Insertar un codigo de producto. 
2. Eliminar un codigo de producto. 
3. Buscar un producto por codigo. 
4. Imprimir el árbol (mostrando su estructura balanceada). 
5. Salir del programa.
*/

#include <iostream>
#include "Arbol/ArbolBinarioAVL.h"
using namespace std;

void menu(){
    cout << "1. Insertar un codigo de producto." << endl;
    cout << "2. Eliminar un codigo de producto." << endl;
    cout << "3. Buscar un producto por codigo." << endl;
    cout << "4. Imprimir el arbol (mostrando su estructura balanceada)." << endl;
    cout << "5. Salir del programa." << endl;
}

int main(){
    ArbolBinarioAVL<int> arbol;
    int opcion=0, codigo=0;
    do{
        menu();
        cout << "Ingrese la opcion deseada: ";
        cin >> opcion;
        switch(opcion){
            case 1:
                cout << "Ingrese el codigo del producto: ";
                cin >> codigo;
                arbol.put(codigo);
                cout << "" << endl;
                break;
            case 2:
                cout << "Ingrese el codigo del producto a eliminar: ";
                cin >> codigo;
                cout << "" << endl;
                try{
                    arbol.remove(codigo);
                    cout << "El producto con ID " << codigo << " ha sido eliminado" << endl;
                } catch(int e){
                    if(e==200){
                        cout << "El producto con ID " << codigo << " no se encuentra" << endl;
                    }
                }
                cout << "" << endl;
                break;
            case 3:
                cout << "Ingrese el codigo del producto a buscar: ";
                cin >> codigo;
                cout << "" << endl;
                try{
                    arbol.search(codigo);
                    cout << "El producto con ID " << codigo << " se encuentra en el inventario" << endl;
                } catch(int e){
                    if(e==404){
                        cout << "El producto con ID " << codigo << " no se enncuentra" << endl;
                    }
                }
                cout << "" << endl;
                break;
            case 4:
                arbol.print();
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
                cout << "Opción inválida." << endl;
                break;
        }
    }while(opcion!=5);
}