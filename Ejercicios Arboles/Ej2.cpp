/*
Problema: En una tienda de electrónica, cada producto tiene un código único y quieres
gestionar el inventario. A medida que entran y salen productos, es necesario mantener el
sistema actualizado.
● Tarea: Inserta los productos con los siguientes códigos: 4001, 2002, 6003, 1500,
3500, 5000, 7000.
● Desafío: Un cliente compró los productos con códigos 2002 y 6003, así que
elimínalos del sistema. Luego, un nuevo producto con el código 2500 llega al
inventario. Imprime el inventario actualizado y verifica si el código 4001 todavía está
en el sistema
 */

#include <iostream>
#include "Arbol/ArbolBinario.h"
using namespace std;

int main() {
    ArbolBinario<int> inventario;

    inventario.put(4001);
    inventario.put(2002);
    inventario.put(6003);
    inventario.put(1500);
    inventario.put(3500);
    inventario.put(5000);
    inventario.put(7000);

    inventario.print();
    cout << "----------------------------------" << endl;
    cout << "->Cliente compra productos 2002 y 6003" << endl;
    inventario.remove(2002);
    inventario.remove(6003);
    cout << "----------------------------------" << endl;
    inventario.print();
    cout << "----------------------------------" << endl;
    cout << "->Producto codigo 2500 ingresa" << endl;
    inventario.put(2500);
    inventario.print();
    cout << "----------------------------------" << endl;
    try{
        int producto = inventario.search(4001);
        cout << "El producto con ID 4001 se encuentra en el inventario" << endl;
    } catch(int e){
        if(e==404){
            cout << "El producto con ID 4001 no se enncuentra" << endl;
        }
    }
    cout << "----------------------------------" << endl;
    inventario.print();
    cout << "----------------------------------" << endl;

    return 0;
}
