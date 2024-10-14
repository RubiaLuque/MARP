
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

//Matriz de chars
using Mapa = vector<string>;

class Manchas {
private:
    int F, C;
    vector<vector<bool>> visit; //se ha visitado el pixel <i,j> ?
    int num; //numero de manchas
    int maxim; //tamaño de la mayor mancha

    //Comprobar que no se salga de los limmites
    bool correcta(int i, int j) {
        return 0 <= i && i < F && 0 <= j && j < C;
    }

    //Vector de direcciones
    const vector<pair<int, int>> dirs = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

    int dfs(Mapa const& M, int i, int j) { //O(F*C)
        visit[i][j] = true;
        int tam = 1; //tamaño de esta mancha

        for (auto d : dirs) { //Como no hay grafo, se debe hacer de esta manera. Se trabaja con una matriz
            int ni = i + d.first; 
            int nj = j + d.second;

            //Si la nueva pos es correcta, es un # y no se ha visitado antes, se suma 1 al tamaño
            if (correcta(ni, nj) && M[ni][nj] == '#' && !visit[ni][nj]) {
                tam += dfs(M, ni, nj);
            }
        }

        return tam;
    }

public:
    Manchas(Mapa const& M) : F(M.size()), C(M[0].size()), visit(F, vector<bool>(C, false)), num(0), maxim(0) {
        for (int i = 0; i < F; ++i) {
            for (int j = 0; j < C; ++j) {
                if (!visit[i][j] && M[i][j] == '#') { //Nueva mancha
                    ++num;
                    int nuevoTam = dfs(M, i, j); //Se recorre dicha mancha por dentro
                    maxim = max(maxim, nuevoTam);
                }
            }
        }
    }

    int numero() const { return num; }
    int maximo() const { return maxim; }
};

bool resuelveCaso() { //O(F*C)

    // leer los datos de la entrada
    int F, C; cin >> F >> C;

    if (!std::cin)  // fin de la entrada
        return false;

    Mapa m(F);

    //Se lee el mapa de bits
    for (string& linea : m) {
        cin >> linea;
    }
    
    Manchas mancha(m); //Logica del problema
    cout << mancha.numero() << ' ' << mancha.maximo() << '\n';

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
