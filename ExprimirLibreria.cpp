#include "Arbol/ArbolBinarioAVL.h"
#include <iostream>
#include <thread>  // Para usar sleep_for
#include <chrono>  // Para manejar tiempos

using namespace std;

int main(){
    ArbolBinarioAVL<int> arbol;
    int numero=0;
    cout << "Ingrese hasta que numero desea mostrar el arbol" << endl;
    cin >> numero;
    for(int i=0; i<numero; i++){
        system("cls");
        arbol.put(i);
        arbol.print();
        cout << "balance: " << arbol.getBalance() << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
}