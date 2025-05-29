
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

struct grupo {
    int numMusicos;
    int numPartituras;
};

bool operator<(grupo const& a, grupo const& b) {
    return ((a.numMusicos / a.numPartituras) + (a.numMusicos % a.numPartituras) < 
        (b.numMusicos / b.numPartituras) + (b.numMusicos % b.numPartituras)); //Se suma el resto porque se redondea hacia abajo en caso de ser division impar
}

bool operator>(grupo const& a, grupo const& b) {
    return b < a;
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int N, P;
    cin >> P >> N;
    //P = num partituras
    //N = num de instrumentos distintos
    if (!std::cin)  // fin de la entrada
        return false;
    PriorityQueue<grupo, greater<grupo>> colaPartituras;

    for (int i = 0; i < N; i++) {
        int numMusicos; cin >> numMusicos;
        colaPartituras.push({numMusicos, 1}); //Como minimo cada grupo de musicos tiene 1 partitura
    }

    if (P > N) {
        int dif = P - N; //Partituras extras
        for (int i = 0; i < dif; ++i) {
            grupo grupo0 = colaPartituras.top();
            colaPartituras.pop(); //El grupo mayoritario se divide
            grupo0.numPartituras++;
            
            colaPartituras.push(grupo0);
        }
    }

    cout << (colaPartituras.top().numMusicos / colaPartituras.top().numPartituras) + 
        colaPartituras.top().numMusicos % colaPartituras.top().numPartituras; cout << '\n';
    

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
