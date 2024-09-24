
/*@ <answer>
 *
 * Nombre y Apellidos: Muxu Rubia Luque
 *
 *@ </answer> */

 // Se trata de construir un arbol binario a partir de la entrada y despues
 // compruea con una duncions recursiva (que ademas calcula la altura del arbol, 
 // y si es un ABB no vacio, su menor y mayor claves) si es AVL

#include <iostream>
#include <fstream>


using namespace std;

#include "bintree.h" // propios o los de las estructuras de datos de clase


/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
template <typename T>
struct sol {
    bool avl;
    int alt;
    T min, max;
};

//EL COSTE DE LA FUNCION ES LINEAL EN EL NUMERO DE NODOS (N) DEL ARBOL => O(N)
template <typename T>
sol<T> es_avl_rec(bintree<T> const& arbol) {
    if (arbol.empty()) return{ true, 0, {}/*notacion para llamar a constructora por defecto*/,
        T() /*lo mismo que lo anterior*/ };
    else {
        //el orden abajo importa
        auto [avl_iz, alt_iz, min_iz, max_iz] = es_avl_rec(arbol.left());
        auto [avl_dr, alt_dr, min_dr, max_dr] = es_avl_rec(arbol.right());

        int alt = 1 + max(alt_iz, alt_dr);
        //si el hijo derecho es vacio, el max es la raiz, si no, es el max de la derecha
        T max = arbol.right().empty() ? arbol.root() : max_dr;
        //idem para el menor
        T min = arbol.left().empty() ? arbol.root() : min_iz;

        bool avl = avl_iz && avl_dr && abs(alt_iz - alt_dr) <= 1 &&
            (arbol.left().empty() || arbol.root() > max_iz) &&
            (arbol.right().empty() || arbol.root() < min_dr);

        return { avl, alt,  min, max };
    }
}

template <typename T>
bool es_avl(bintree<T> const& arbol) {
    return es_avl_rec(arbol).avl; //solo nos interesa el campo avl
}

//@</answer>

void resuelveCaso() {

    // leer los datos de la entrada
    auto t = leerArbol<int>(-1);

    // resolver el caso posiblemente llamando a otras funciones
    if (es_avl(t)) cout << "SI\n"; // escribir la solución
    else cout << "NO\n";

}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}



