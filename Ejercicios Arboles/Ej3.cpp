/*
Problema: Estás diseñando un sistema de inscripción para un gimnasio, donde cada socio
tiene un número de socio único. El sistema debe permitir la inscripción de nuevos socios, la
eliminación de socios que se dan de baja, y la búsqueda de socios activos.
● Tarea: Inscribe a los socios con los siguientes números de socio: 500, 250, 750, 100,
300, 600, 800.
● Desafío: Un socio con el número 250 se da de baja, así que elimínalo. Luego,
verifica si los socios con los números 300 y 750 aún están activos. Imprime la lista
de socios actualizada.
*/

#include <iostream>
#include "Arbol/ArbolBinario.h"
using namespace std;

void cargarDatos(ArbolBinario<int> &socios){
    socios.put(500);
    socios.put(250);
    socios.put(750);
    socios.put(100);
    socios.put(300);
    socios.put(600);
    socios.put(800);
}

int main() {
    ArbolBinario<int> socios;

    cargarDatos(socios);
    // Mostrar arbol despues de cargar datos
    socios.print();
    // Socio 250 se da de baja
    cout << "" << endl;
    cout << "Presione enter para confirmar la baja del socio 250" << endl;
    cin.get();
    socios.remove(250);
    // Mostrar arbol despues de dar de baja al socio 250
    cout << "" << endl;
    socios.print();
    cout << "" << endl;
    cout << "Presione enter para buscar al socio 300" << endl;
    cin.get();
    try{
        socios.search(300);
        cout << "El socio 300 se encuentra activo" << endl;
    }catch(int e){
        if(e == 404){
        cout << "El socio 300 no se encuentra activo" << endl;
        }
    }
    cout << "" << endl;
    cout << "Presione enter para buscar al socio 750" << endl;
    cin.get();
    try{
        socios.search(750);
        cout << "El socio 750 se encuentra activo" << endl;
    }catch(int e){
        if(e == 404){
        cout << "El socio 750 no se encuentra activo" << endl;
        }
    }
    cout << "" << endl;
    socios.print();
    return 0;
}
