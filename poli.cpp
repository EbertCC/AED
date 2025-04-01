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

    long tamanio=200000;
    long M[tamanio];

    llenar(M,tamanio);
    ordenar(M,M+tamanio-1,&as);
    //mostrar(M,M+tamanio-1);

    auto inicio = high_resolution_clock::now();
    ordenar(M,M+tamanio-1,&de);
    auto fin = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(fin-inicio);

    mostrar(M,M+tamanio-1);
    cout << "Tiempo de ejecucion (peor caso): " << duration.count() << " microsegundos" << endl;

    return 0;
    //100 35
    //1000 3521
    //10000 358106
    //100000 43707564
    //200000 145194775
}