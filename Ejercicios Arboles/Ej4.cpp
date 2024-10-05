/*
Problema: Un restaurante tiene un sistema de reservas donde cada mesa tiene un número
específico. A medida que los clientes reservan o cancelan mesas, el sistema debe
mantenerse actualizado
Tarea: Agrega las reservas de las siguientes mesas: 15, 10, 20, 5, 12, 18, 25.
● Desafío: Dos clientes cancelaron sus reservas en las mesas 10 y 20, así que
elimínalas del sistema. Luego, un nuevo cliente reserva la mesa 13. Verifica si la
mesa 12 aún está reservada e imprime la lista actualizada de mesas reservadas.
*/

#include <iostream>
#include "Arbol/ArbolBinario.h"
using namespace std;

void cargarDatos(ArbolBinario<int> &mesas){
    mesas.put(15);
    mesas.put(10);
    mesas.put(20);
    mesas.put(5);
    mesas.put(12);
    mesas.put(18);
    mesas.put(25);
}

void cancelarReserva(ArbolBinario<int> &mesas){
    cout << "Presione enter para cancelar mesas 10 y 20" << endl;
    cin.get();
    mesas.remove(10);
    mesas.remove(20);
}

int main(){
    ArbolBinario<int> mesas;
    cargarDatos(mesas);
    mesas.print();
    cout << " " << endl;
    cancelarReserva(mesas);
    mesas.print();
    cout << "" << endl;
    cout << "Presione enter para reservar mesa 13" << endl;
    cin.get();
    mesas.put(13);
    cout << "" << endl;
    try{
        mesas.search(12);
        cout << "La mesa 12 está reservada" << endl;
    }catch(int e){
        if(e==404){
            cout << "La mesa 12 no se encuentra reservada" << endl;
        }
    }
    cout << "" << endl;
    mesas.print();
    return 0;
}