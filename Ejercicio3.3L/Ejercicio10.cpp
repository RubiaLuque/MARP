
/*@ <authors>
 *
 * Muxu Rubia Luque MARP35
 * Jorge Zurdo Izquierdo MARP46
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

#include "IndexPQ.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>



 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

//bool operator>(pair<int, int> a, pair<int, int> b) {
//    return b.second > a.second || (a.second == b.second && b.second > a.second);
//}

bool resuelveCaso() {

    // leer los datos de la entrada
    int numMins, numCanales, numAcc;
    cin >> numMins >> numCanales >> numAcc;

    if (!std::cin)  // fin de la entrada
        return false;

    //Cola de pares (num canal, audiencia)
    IndexPQ<int, greater<int>> cola(numCanales);
    //num canal y num mins
    vector<pair<int, int>> vector(numCanales);

    //Para el minuto 0 se hace push porque no existen los elementos
    for (int i = 0; i < numCanales; ++i) {
        int audiencia; cin >> audiencia;
        cola.push(i, audiencia );
        vector[i] = { i, 0 };
    }

    int anteriorMinuto =0;

    //Aqui se hace update de los canales que ya existen
    for (int i = 0; i < numAcc; ++i) {
        int min;
        cin >> min;
        int max = cola.top().elem;
        int minuto = vector[max].second;
        vector[max].second += (min-anteriorMinuto);
        anteriorMinuto = min;

        int canal, audiencia;


        cin >> canal;
        while (canal != -1) {
            cin >> audiencia;
            cola.update(canal -1, audiencia); 
            cin >> canal;
        }

    }

    vector[cola.top().elem].second += (numMins - anteriorMinuto);
   
    // escribir la solución
    std::sort(vector.begin(), vector.end(), [](auto& left, auto& right)
    {
            return left.second > right.second || (left.second == right.second && left.first < right.first);
    });

    for (int i = 0; i < vector.size(); ++i) {
        if (vector[i].second != 0) {
            cout << vector[i].first +1 << " " << vector[i].second << "\n";
        }
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
