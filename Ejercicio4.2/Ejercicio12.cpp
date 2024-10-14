
/*@ <authors>
 *
 * Muxu Rubia Luque MARP35
 * 
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "Grafo.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

class MaxCompConexa {
private:
    vector<bool> visit;
    int maxim; //tamaño max componente conexa hasta el momento

    int dfs(Grafo const& g, int v) {
        visit[v] = true;
        int tam = 1;
        for (int w : g.ady(v)) {
            if (!visit[w])
                tam += dfs(g, w);
        }

        return tam;
    }

public:
    MaxCompConexa(Grafo const& g) : visit(g.V(), false), maxim(0) {
        for (int i = 0; i < g.V(); ++i) {
            if (!visit[i]) {
                int tam = dfs(g, i);
                maxim = max(maxim, tam);
            }
        }
    }

    int maximo() const {
        return maxim;
    }
};

void resuelveCaso() { //O(N + M)

    // leer los datos de la entrada
    int N, M; //num personas, num conexiones
    cin >> N >> M; 
    Grafo amigos(N);

    int v, w;
    for (int i = 0; i < M; ++i) {
        cin >> v >> w;
        amigos.ponArista(v-1, w-1);
    }

    MaxCompConexa mcc(amigos);

    // escribir la solución

    cout << mcc.maximo() << "\n";
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);;
#endif
    return 0;
}
