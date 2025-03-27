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
    /*
    long M[] = {53,63,432,3,6,34,0,356};
    int tamanio = sizeof(M)/sizeof(M[0]);
    mostrar(M,M+tamanio-1);
    ordenar(M,M+tamanio-1,asc());
    mostrar(M,M+tamanio-1);
    ordenar(M,M+tamanio-1,desc());
    mostrar(M,M+tamanio-1);
    */
   long tamanio=100000;
   long M[tamanio];
   llenar(M,tamanio);
   //ordenar(M,M+tamanio-1,asc());
   //mostrar(M,M+tamanio-1);

   // Medir tiempo de orden ascendente
   auto start_asc = high_resolution_clock::now();
   ordenar(M, M + tamanio - 1, asc());
   auto end_asc = high_resolution_clock::now();
   auto duration_asc = duration_cast<microseconds>(end_asc - start_asc);
   cout << "Orden Ascendente: ";
   //mostrar(M, M + tamanio - 1);
   cout << "Tiempo de orden ascendente: " << duration_asc.count() << " microsegundos\n";


   // Medir tiempo de orden descendente
   auto start_desc = high_resolution_clock::now();
   ordenar(M, M + tamanio - 1, desc());
   auto end_desc = high_resolution_clock::now();
   auto duration_desc = duration_cast<microseconds>(end_desc - start_desc);
   cout << "Orden Descendente: ";
   //mostrar(M, M + tamanio - 1);
   cout << "Tiempo de orden descendente: " << duration_desc.count() << " microsegundos\n"; 
   
   /*100
   Tiempo de orden ascendente: 31 microsegundos
   Tiempo de orden descendente: 33 microsegundos
   */
   /*1000
   Tiempo de orden ascendente: 3049 microsegundos
   Tiempo de orden descendente: 3204 microsegundos
   */
   /*
   Tiempo de orden ascendente: 347645 microsegundos
   Tiempo de orden descendente: 320046 microsegundos
   */
   /*
   Orden Ascendente: Tiempo de orden ascendente: 36241810 microsegundos
   Orden Descendente: Tiempo de orden descendente: 32139957 microsegundos
   */



   return 0;
}