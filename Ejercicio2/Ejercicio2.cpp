/*
 * MUY IMPORTANTE: Solo se corregirán los comentarios y el código
 * contenidos entre las etiquetas <answer> y </answer>.
 * Toda modificación fuera de esas etiquetas no será corregida.
 */

 /*@ <answer>
  *
  * Indicad el nombre completo y usuario del juez de quienes habéis hecho esta solución:
  * Estudiante 1: Jorge Zurdo Izquierdo
  * Estudiante 2: Muxu Rubia Luque
  *
  *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

#include "TreeSet_AVL_tami.h"

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema.

 @ </answer> */

 // ================================================================
 // Escribe el código completo de tu solución aquí debajo (después de la marca)
 //@ <answer>

bool resuelveCaso() {
    int N;
    cin >> N;
    if (N == 0)
        return false;

    // los valores de la entrada se insertan en el conjunto
    Set<int> cjto;
    int valor;
    for (int i = 0; i < N; ++i) {
        cin >> valor;
        cjto.insert(valor);
    }

    // COMPLETAR
    int M = 0; //Cantidad de numeros a consultar
    cin >> M;
    for (int i = 0; i < M; ++i) {
        int num;
        cin >> num;
        int elem = cjto.k_esimo(num);
        cout << elem << endl;
    }


    cout << "---\n";

    return true;
}


//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
