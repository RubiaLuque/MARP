
/*@ <authors>
 *
 * Muxu Rubia Luque MARP35
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include "PriorityQueue.h"
using namespace std;

#include "vector"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

struct tarea {
    int ini;
    int fin;
    int period;
};

bool operator<(tarea const& a, tarea const& b) {
    return (a.ini < b.ini);
}

bool operator>(tarea const& a, tarea const& b) {
    return b < a;
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int N, M, T;
    cin >> N >> M >> T;

    if (!std::cin)  // fin de la entrada
        return false;

    PriorityQueue<tarea, less<tarea>> timeline;

    //Se incluyen las tareas unitarias
    int ini, fin;
    for (int i = 0; i < N; ++i) {
        cin >> ini >> fin;
        if(ini < T) timeline.push({ ini, fin, 0 });
    }

    //Se incluyen las tareas repetitivas
    int period;
    for (int i = 0; i < M; ++i) {
        cin >> ini >> fin >> period;
        timeline.push({ini, fin, period});
    }
    
    bool solapamiento = false;
    while(timeline.size()>1) {
        tarea task = timeline.top();
        timeline.pop();
        if (task.fin > timeline.top().ini) {
            solapamiento = true;
            break;
        }
        if (task.period > 0 && task.ini+task.period < T) {
            
            timeline.push({ task.ini + task.period, task.fin + task.period, task.period });
        }
    }

    string out = solapamiento ? "SI" : "NO";
    cout << out; cout << '\n';

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
