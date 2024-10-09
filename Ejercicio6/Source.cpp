
/*@ <authors>
 *
 * Muxu Rubia Luque MARP35
 * 
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <queue>
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

struct paciente {
    string nombre;
    int priority;
    int turno;
};

bool operator>(paciente a, paciente b) {
    return b.priority > a.priority || (a.priority == b.priority && b.turno > a.turno);
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int N; 
    cin >> N; //Numero eventos
    if (N == 0)
        return false;

    std::priority_queue<paciente, greater<int>> cola;

    // resolver el caso posiblemente llamando a otras funciones
    for (int i = 0; i < N; ++i) {
        int evento;
        cin >> evento;
        if (evento == 'I') {
            string nombre; int priority;
            cola.push({ nombre, priority, 0 });
        }
        else if (evento=='A') {

        }
    }

    // escribir la solución

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
