
/*@ <authors>
 *
 * Muxu Rubia Luque MARP35
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <queue>
#include <climits>
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
using Camino = deque<int>;
const int INF = INT_MAX;

class CaminoMasCorto {
public:
    CaminoMasCorto(Grafo const& g, int s) : visit(g.V(), false), ant(g.V()), dist(g.V(), INF), s(s) {
        bfs(g);
    }

    // ¿hay camino del origen a v ?
    bool hayCamino(int v) const {
        return visit[v];
    }

    // número de aristas entre s y v
    int distancia(int v) const {
        return dist[v];
    }

    // devuelve el camino más corto desde el origen a v (si existe)
    Camino camino(int v) const {
        if (!hayCamino(v)) throw std::domain_error("No existe camino");
        Camino cam;
        for (int x = v; x != s; x = ant[x])
            cam.push_front(x);
        cam.push_front(s);
        return cam;
    }


private:
    std::vector<bool> visit; // visit[v] = ¿hay camino de s a v?
    std::vector<int> ant; // ant[v] = último vértice antes de llegar a v
    std::vector<int> dist; // dist[v] = aristas en el camino s-v más corto
    int s;

    //Recorrido en anchura
    void bfs(Grafo const& g) {
        std::queue<int> q;
        dist[s] = 0; visit[s] = true;
        q.push(s);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (int w : g.ady(v)) {
                if (!visit[w]) {
                    ant[w] = v; dist[w] = dist[v] + 1; visit[w] = true;
                    q.push(w);
                }
            }
        }
    }
};

bool resuelveCaso() {

    // leer los datos de la entrada
    int P; //Num peliculas
    cin >> P;

    if (!std::cin)  // fin de la entrada
        return false;

    map<string, int> numActores; //nombre actor, numero asignado
    vector<vector<int>> peliculas(P); //peliculas con el numero asignaado a cada actor que participan en ellas

    for (auto& actores:peliculas) { //Cada vector de int es la lista con el numero asignado a los actores para una pelicula
        string titulo; cin >> titulo;
        int nActores; cin >> nActores;
        for (int i = 0; i < nActores; ++i) {
            string actor; cin >> actor;
            numActores.insert({ actor, numActores.size() +P });
            actores.push_back(numActores[actor]); //Se añade el valor del map correspondiente a actor al vector actores de cada pelicula
        }
    }

    //Añadimos a Bacon en caso de que no esté
    numActores.insert({ "KevinBacon", numActores.size() + P});

    Grafo g(numActores.size() + P);
    for (int i = 0; i < P; ++i) {
        for (int j = 0; j < peliculas[i].size(); ++j) {
            g.ponArista(i, peliculas[i][j]); //Nodo i corresponde a peliculas, j es la posicion del actor dentro de la pelicula i
        }
    }

    CaminoMasCorto cam(g, numActores["KevinBacon"]);

    int actoresAComprobar; cin >> actoresAComprobar;
    for (int i = 0; i < actoresAComprobar; ++i) {
        string actor; cin >> actor;
        int numBacon = INF;
        if (numActores.count(actor)) numBacon = cam.distancia(numActores[actor]);
        if (numBacon == INF) cout << actor << " INF\n";
        else cout << actor << " " << numBacon / 2 << '\n';
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

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
