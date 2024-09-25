
/*@ <authors>
 *
 * Muxu Rubia Luque MARP35
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

struct caja {
    int idCaja;
    int tiempo;
};

//Como la cola es de maximos, se usa el operador < y es mas prioritario el que menor tiempo tenga
bool operator<(caja t1, caja t2) {
    return t2.tiempo < t1.tiempo || (t2.tiempo == t1.tiempo && t2.idCaja < t1.idCaja);
}

bool resuelveCaso() { //Coste O(N*logN + C*logN)

    // leer los datos de la entrada
    int N; //Cajas abiertas
    int C; //Num clientes esperando
    cin >> N >> C;
    if (N==0 && C==0)
        return false;

    priority_queue<caja> colaCajas;

    for (int i = 0; i < N; ++i) {
        colaCajas.push({ i+1, 0}); //Se añaden a la cola los ids de las diferentes cajas
        //En un principio todas las cajas tardan 0 minutos en atender al principio
    }
    
    for (int i = 0; i < C; ++i) {
        int tiempo; cin >> tiempo;
        auto c = colaCajas.top(); colaCajas.pop();
        c.tiempo += tiempo;
        colaCajas.push(c); //Se reinserta la caja con el nuevo tiempo que tardara en atender
    }

    // escribir la solución
    std::cout << colaCajas.top().idCaja << "\n";

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
