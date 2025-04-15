
/*@ <authors>
 *
 * Muxu Rubia Luque MARP35
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <queue>
#include "PriorityQueue.h"  // propios o los de las estructuras de datos de clase

using namespace std;


/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

bool resuelveCaso() {

    // leer los datos de la entrada
    int N, P;
    cin >> P >> N;
    //P = num partituras
    //N = num de instrumentos distintos
    if (!std::cin)  // fin de la entrada
        return false;
    PriorityQueue<int, greater<int>> colaPartituras;

    for (int i = 0; i < N; i++) {
        int numMusicos; cin >> numMusicos;
        colaPartituras.push(numMusicos);
    }

    if (P > N) {
        int dif = P - N; //Partituras extras
        for (int i = 0; i < dif; ++i) {
            int grupo = colaPartituras.top();
            colaPartituras.pop(); //El grupo mayoritario se divide en dos
            int grupo1 = grupo / 2;
            int grupo2 = grupo - grupo1; //No tienen por que ser grupos pares
            colaPartituras.push(grupo1);
            colaPartituras.push(grupo2);
        }
    }

    cout << colaPartituras.top(); cout << '\n';
    

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

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
