
/*@ <authors>
 *
 * Muxu Rubia Luque MARP35
 * 
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

#include "Grafo.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Hay que comprobar si existe camino a todos los vértices realizando un recorrido en profundidad. 
 Si esto se cumple se sabe que es conexo y no dirigido.
 Para saber si es acíclico, sabiendo lo anterior, debe cumplirse también que el número de aristas es el de vértices 
 menos 1.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

class CaminoDFS {
private:
    vector<bool> visit;
    vector<int> ant;
    int s; //vertice origen

public:
    void dfs(Grafo const& g, int v) {
        visit[v] = true;
        for (int w : g.ady(v)) {
            if (!visit[w]) {
                ant[w] = v;
                dfs(g, w);
            }
        }
    }

    CaminoDFS(Grafo const& g, int s) : visit(g.V(), false), ant(g.V()), s(s) {
        dfs(g, s);
    }

    bool hayCamino(int v) const {
        return visit[v];
    }

    using Camino = deque<int>;

    Camino camino(int v) const {
        if (!hayCamino(v))
            throw domain_error("No existe camino.");
        
        Camino cam; 
        for (int i = v; i != s; i = ant[i]) {
            cam.push_front(i);
        }
        cam.push_front(s);
        return cam;
    }
};

bool resuelve(Grafo const& g) {
    if (g.V() == 0) return false; //Grafo vacio

    CaminoDFS cam = CaminoDFS(g, 0); //O(log(V) * V)

    for (int i = 0; i < g.V(); ++i) { //O(V*(V+A))
        if (!cam.hayCamino(i)) return false; //O(V+A)
    }

    //Dado lo anterior tambien tiene que cumplirse esto para que sea acíclico
    if (g.A() != g.V() - 1) return false;

    return true;

}

bool resuelveCaso() {

    // leer los datos de la entrada
    Grafo g(cin, 0);

    if (!std::cin)  // fin de la entrada
        return false;

    // resolver el caso posiblemente llamando a otras funciones
    bool sol = resuelve(g);

    // escribir la solución
    (sol) ? cout << "SI\n" : cout << "NO\n";

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
