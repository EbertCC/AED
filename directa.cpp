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
        *p = rand() % tamanio; 
    }

}
void ordenar(long *ini,long *fin){
    for(long *p=ini ;p<fin+1;p++){
        for(long *q=ini ; q < fin-(p-ini);q++){
            if(*q>*(q+1)){
                swap(*q,*(q+1));
            }
        }
    }
}


int main(){

    long tamanio=400000;
    long M[tamanio];
    llenar(M,tamanio);
    auto inicio = high_resolution_clock::now();
    ordenar(M,M+tamanio-1);
    auto fin = high_resolution_clock::now();
    auto duracion = duration_cast<microseconds>(fin-inicio);

    mostrar(M,M+tamanio-1);
    cout<<"tiempo de ejecucion: "<<duracion.count()<<" microsegundos"<<endl;

    return 0;
    //100 24
    //1000 2077
    //10000 247969
    //100000 28573222
    //200000 116995753
    //400000 505425584
}


