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

class pt{
    public:
    virtual bool cmd(long a , long b) = 0;
};

class asc:public pt{
    public:
    bool cmd(long a,long b){
        return a>b;
    }
};

class des:public pt{
    public:
    bool cmd(long a,long b){
        return a<b;
    }
};

void ordenar(long *ini,long *fin,pt *a){
    for(long *p=ini ;p<fin+1;p++){
        //for(long *q=ini ; q<fin-cont;q++){
        for(long *q=ini ; q < fin-(p-ini);q++){
            //if(q<(q+1)){
            if(a->cmd(*q,*(q+1))){
                swap(*q,*(q+1));
            }
        }
        //cont++;
    }


}

int main(){
    asc as;
    des de;

    /*
    long M[] = {1,3,4,5,13,0};
    int tamanio = sizeof(M)/sizeof(M[0]);
    mostrar(M,M+tamanio-1);
    ordenar(M,M+tamanio-1,&as);
    mostrar(M,M+tamanio-1);
    ordenar(M,M+tamanio-1,&de);
    mostrar(M,M+tamanio-1);
    */
    
    long tamanio=100000;
    long M[tamanio];

    llenar(M,tamanio);
    //ordenar(M,M+tamanio-1,&as);
    //mostrar(M,M+tamanio-1);

    // Medir tiempo de orden ascendente
    auto start_asc = high_resolution_clock::now();
    ordenar(M, M + tamanio - 1, &as);
    auto end_asc = high_resolution_clock::now();
    auto duration_asc = duration_cast<microseconds>(end_asc - start_asc);
    cout << "Orden Ascendente: ";
    //mostrar(M, M + tamanio - 1);
    cout << "Tiempo de orden ascendente: " << duration_asc.count() << " microsegundos\n";

    // Medir tiempo de orden descendente
    auto start_desc = high_resolution_clock::now();
    ordenar(M, M + tamanio - 1, &de);
    auto end_desc = high_resolution_clock::now();
    auto duration_desc = duration_cast<microseconds>(end_desc - start_desc);
    cout << "Orden Descendente: ";
    //mostrar(M, M + tamanio - 1);
    cout << "Tiempo de orden descendente: " << duration_desc.count() << " microsegundos\n";


    /* 100
    Tiempo de orden descendente: 35 microsegundos
    Tiempo de orden ascendente: 32 microsegundos
    */

    /*1000
    Tiempo de orden ascendente: 3067 microsegundos
    Tiempo de orden descendente: 3508 microsegundos
    */
    
    /*10000
    Tiempo de orden descendente: 348533 microsegundos
    Tiempo de orden ascendente: 352665 microsegundos
    */
    /*
    Orden Ascendente: Tiempo de orden ascendente: 37182626 microsegundos
    Orden Descendente: Tiempo de orden descendente: 35213377 microsegundos
    */

  


    return 0;
}