
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la soluci�n.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "PriorityQueue.h"  // propios o los de las estructuras de datos de clase

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
    int gravedad;
    int tiempoEspera;
};

bool operator<(paciente const& a, paciente const& b) {
    return a.gravedad < b.gravedad || 
        (a.gravedad == b.gravedad && a.tiempoEspera > b.tiempoEspera);
}

bool operator>(paciente const& a, paciente const& b) {
    return b < a;
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int numEvents;
    std::cin >> numEvents;

    if (numEvents == 0)
        return false;

    PriorityQueue<paciente, greater<paciente>> colaPacientes;

    for (int i = 0; i < numEvents; ++i) {
        char evt;
        std::cin >> evt;
        if (evt == 'I') {
            string nombre; std::cin >> nombre;
            int gravedad; std::cin >> gravedad;
            colaPacientes.push({nombre, gravedad, i}); //i indica el momento en el que llega. Cuanto mas peque�o, mas tiempo lleva esperando
        }
        else if (evt == 'A') {
            paciente atendido = colaPacientes.top();
            colaPacientes.pop();
            std::cout << atendido.nombre + '\n';
        }
    }
    std::cout << "---\n";
    

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
