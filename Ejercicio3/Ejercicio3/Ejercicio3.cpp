
/*@ <authors>
 *
 * Muxu Rubia Luque MARP35
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

//#include "..."  // propios o los de las estructuras de datos de clase

/*@ <answer>
* 
* 

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

int64_t resuelve(priority_queue<int64_t, vector<int64_t>, greater<int64_t>>& sumaMin, int64_t N) {
    int64_t sumaCoste = 0;
    int64_t sumaNums = sumaMin.top();

    for (int i = 0; i < N-1; ++i) {
        sumaMin.pop();
        sumaNums += sumaMin.top();
        sumaCoste += sumaNums;
    }

    return sumaCoste;
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int64_t N=-1;
    cin >> N;
    if (N==0)
        return false;

    //Cola de prioridad ordenada de menor a mayor
    priority_queue<int64_t, vector<int64_t>, greater<int64_t>> sumaMin;
    for (int i = 0; i < N; ++i) {
        int num; 
        cin >> num;
        sumaMin.push(num);
    }
    // resolver el caso posiblemente llamando a otras funciones
    int64_t sol = resuelve(sumaMin, N);
    // escribir la solución
    cout << sol << "\n";

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
