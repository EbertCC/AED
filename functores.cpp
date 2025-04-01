#include <iostream>
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
struct asc{
    bool operator()(long a,long b){
        return a>b;
    }
};
struct desc{
    bool operator()(long a,long b){
        return a<b;
    }
};

template<typename T>
void ordenar(long *ini,long *fin,T comp){
    for(long *p=ini ;p<fin+1;p++){
        //for(long *q=ini ; q<fin-cont;q++){
        for(long *q=ini ; q < fin-(p-ini);q++){
            //if(*q<*(q+1)){
            if(comp(*q,*(q+1))){
            //if(a->cmd(*q,*(q+1))){
                swap(*q,*(q+1));
            }
        }
    }
}


int main(){
    
   long tamanio=400000;
   long M[tamanio];
   llenar(M,tamanio);
   ordenar(M,M+tamanio-1,asc());
   //mostrar(M,M+tamanio-1);


   auto inicio = high_resolution_clock::now();
   ordenar(M,M+tamanio-1,desc());
   auto fin = high_resolution_clock::now();
   auto duracion = duration_cast<microseconds>(fin-inicio);

   mostrar(M,M+tamanio-1);
   cout<<"tiempo de ejecucion: "<<duracion.count()<<" microsegundos"<<endl;

   //100 33
   //1000 3181
   //10000 318929
   //100000 31973741
   //200000 130237138
   //400000 513416754

 


   return 0;
}