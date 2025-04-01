#include <iostream>
#include <cstdlib>
#include <chrono>

using namespace std::chrono;

using namespace std;

void mostrar(long *ini, long *fin) {
    for (long *p = ini; p < fin + 1; p++) {
        cout << *p << " ";
    }
    cout << endl;
}

void llenar(long AR[], long tamanio) {
    for (long *p = AR; p < AR + tamanio; p++) {
        *p = rand() % tamanio;
    }
}

// Clase para orden ascendente
class Ascendente {
public:
    bool operator()(long a, long b) const {
        return a < b;
    }
};

// Clase para orden descendente
class Descendente {
public:
    bool operator()(long a, long b) const {
        return a > b;
    }
};

// Función de Bubble Sort que utiliza una clase functor para la comparación
template <typename Compare>
void ordenar(long *ini, long *fin, Compare cmp) {
    for (long *p = ini; p < fin + 1; p++) {
        for (long *q = ini; q < fin - (p - ini); q++) {
            if (!cmp(*q, *(q + 1))) {
                swap(*q, *(q + 1));
            }
        }
    }
}

int main() {
    long tamanio = 100000;
    long M[tamanio];

    llenar(M, tamanio);
    ordenar(M, M + tamanio - 1, Ascendente());

    auto inicio = high_resolution_clock::now();
    ordenar(M, M + tamanio - 1, Descendente());
    auto fin = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(fin-inicio);

    mostrar(M,M+tamanio-1);
    cout << "Tiempo de ejecucion (peor caso): " << duration.count() << " microsegundos" << endl;



    return 0;
}
