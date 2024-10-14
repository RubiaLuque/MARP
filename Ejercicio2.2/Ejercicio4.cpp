
/*@ <authors>
 *

 * Muxu Rubia Luque
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

/*@ <answer>


 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

struct user {
    int id; //id de cada uno por si hay empate
    int period; //tiempo entre envios
    int turno; //cuando le toca
};

bool operator<(user const& a, user const& b) {
    return b.turno < a.turno || (a.turno == b.turno && b.id < a.id);
}


bool resuelveCaso() {

    // leer los datos de la entrada
    int N = 0; //Num usuarios
    cin >> N;
    if (N == 0)
        return false;
    
    priority_queue<user> cola;

    for (int i = 0; i < N; ++i) {
        int id, pr;
        cin >> id >> pr;
        cola.push({ id, pr, pr }); //Ya se ordena segun el operador definido con anterioridad
    }

    int envios; cin >> envios;

    while (envios != 0) {
        auto top = cola.top(); 
        cola.pop();
        cout << top.id << "\n";
        top.turno += top.period; //Se le añade tiempo hasta que le toque de nuevo
        cola.push(top);

        envios--;
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
