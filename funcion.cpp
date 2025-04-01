#include <iostream>
#include <cstdlib>
#include <chrono>

using namespace std::chrono;
using namespace std;

bool ascendente(long a,long b){
    return a>b;
}
bool descendente(long a,long b){
    return a<b;
}


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
void ordenar(long *ini,long *fin,bool (*cmp)(long,long) ){
    for(long *p=ini ;p<fin+1;p++){
        for(long *q=ini ; q < fin-(p-ini);q++){
            if(cmp(*q,*(q+1))){
            //if(*q>*(q+1)){
                swap(*q,*(q+1));
            }
        }
    }
}


int main(){

    long tamanio=200000;
    long M[tamanio];
    llenar(M,tamanio);

    bool (*cmp)(long,long) = nullptr;

    cmp=ascendente;
    ordenar(M,M+tamanio-1,cmp);


    cmp=descendente;
    auto inicio = high_resolution_clock::now();
    ordenar(M,M+tamanio-1,cmp);
    auto fin = high_resolution_clock::now();
    auto duracion = duration_cast<microseconds>(fin-inicio);

    mostrar(M,M+tamanio-1);
    cout<<"tiempo de ejecucion: "<<duracion.count()<<" microsegundos"<<endl;

    return 0;
    //100 34
    //1000 3335
    //10000 330221
    //100000 33129618
    //200000 140064776
             
    
}

