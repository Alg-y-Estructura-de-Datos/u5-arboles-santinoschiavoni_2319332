/*
Problema: Trabajas en una empresa de logística y debes gestionar los paquetes que llegan
y se entregan a través de un sistema. Cada paquete tiene un número de seguimiento único.
Tu sistema debe permitir la entrada de nuevos paquetes, la entrega (eliminación) de
paquetes, y la verificación de los que siguen en tránsito.
● Tarea: Inserta los paquetes con los números de seguimiento: 1001, 5002, 3003,
2004, 4500, 7005, 8006.
● Desafío: Los paquetes con los números de seguimiento 2004 y 4500 fueron
entregados, así que elimínalos. Luego, un nuevo paquete con el número 3500 llega
al sistema. Verifica si el paquete con el número 1001 sigue en tránsito e imprime la
lista de paquetes restantes.
*/

#include <iostream>
#include "Arbol/ArbolBinario.h"
using namespace std;

void cargarDatos(ArbolBinario<int> &inventario){
    inventario.put(1001);
    inventario.put(5002);
    inventario.put(3003);
    inventario.put(2004);
    inventario.put(4500);
    inventario.put(7005);
    inventario.put(8006);
}


int main(){

    ArbolBinario<int> inventario;
    cargarDatos(inventario);

    inventario.print();
    cout << " " << endl;

    cout << "Los paquetes 2004 y 4500 fueron entregados, presione enter para eliminarlos del sistema" << endl;
    cin.get();
    inventario.remove(2004);
    inventario.remove(4500);
    cout << "" << endl;
    inventario.print();
    cout << "" << endl;
    cout << "Presione enter para agregar el producto 3500" << endl;
    cin.get();
    try{
        inventario.put(3500);
        cout << "Producto agregado correctamente" << endl;
    }catch(int e){
        if(e==200){
            cout << "El producto ya se encuentra en existencias" << endl;
        }
    }
    cout << "" << endl;
    inventario.print();
    cout << "" << endl;
    cout << "Presione enter para buscar el producto 1001" << endl;
    cin.get();
    try{
        inventario.search(1001);
        cout << "El producto 1001 sigue en transito" << endl;
    } catch(int e){
        if(e==404){
            cout << "El producto no se encuentra en transito" << endl;
        }
    }
    cout << "" << endl;
    inventario.print();

return 0;
}