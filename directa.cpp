#include <iostream>
#include <cstdlib>

#include <chrono>
using namespace std::chrono;

using namespace std;

void mostrar(long *ini,long*fin){
    for ( long *p=ini;p<fin+1;p++){
        cout<<*p<<" ";
    } 
    cout<<endl;
}

void llenar(long AR[],long tamanio){
    for(long *p = AR ; p < AR+tamanio ; p++){
        *p = rand() % 1000; 
    }

}
void ordenar(long *ini,long *fin){
    //int cont=0;
    for(long *p=ini ;p<fin+1;p++){
        //for(long *q=ini ; q<fin-cont;q++){
        for(long *q=ini ; q < fin-(p-ini);q++){
            if(*q>*(q+1)){
                swap(*q,*(q+1));
            }
        }
        //cont++;
    }
}


int main(){
/*
    long AR[] = {1,2,3,0,5,45,23,65,87,7};
    int tamanio = sizeof(AR)/sizeof(AR[0]);
    mostrar(AR,AR+tamanio-1);
    ordenar(AR,AR+tamanio-1);
    mostrar(AR,AR+tamanio-1);
*/
    auto start_total = high_resolution_clock::now();
    long tamanio=100000;
    long AR[tamanio];

    //llenar(M,tan);
    //ordenar(M,M+tan-1);
    //mostrar(M,M+tan-1);

    // Medir tiempo de llenado
    auto start = high_resolution_clock::now();
    llenar(AR, tamanio);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "Tiempo de llenado: " << duration.count() << " microsegundos" << endl;

    // Medir tiempo de ordenamiento
    start = high_resolution_clock::now();
    ordenar(AR, AR + tamanio - 1);
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);
    cout << "Tiempo de ordenamiento: " << duration.count() << " milisegundos" << endl;

    // Medir tiempo de mostrar (opcional)
    start = high_resolution_clock::now();
    mostrar(AR, AR + tamanio - 1);
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);
    cout << "Tiempo de mostrar: " << duration.count() << " milisegundos" << endl;

    auto end_total = high_resolution_clock::now(); // Fin del tiempo total
    auto duration_total = duration_cast<milliseconds>(end_total - start_total);
    cout << "Tiempo total del programa: " << duration_total.count() << " milisegundos" << endl;

    //100  Tiempo total del programa: 4 milisegundos
    //1000 Tiempo total del programa: 40 milisegundos
    //10000 Tiempo total del programa: 630 milisegundos
    //100000 Tiempo total del programa: 32485 milisegundos

    
    return 0;
}


