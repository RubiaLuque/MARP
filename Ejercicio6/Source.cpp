
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

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
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

    // escribir la soluci�n

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

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
