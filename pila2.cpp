#include <iostream>

using namespace std;

template <typename T>
class pila{
    private:
    T A[10];
    T *top;
    public:
    pila():top(nullptr){}
    void push(T val){
        int tamanio_pila;
        if(top == nullptr){
            tamanio_pila = 0;
        }else{
            tamanio_pila = top-A+1;
        }

        if(tamanio_pila>=10){
            cout<<"piila esta llena"<<endl;
            return;
        }
        if(top == nullptr){
            top = A;
        }else{
            top++;
        }
        *top=val;
    }
    void pop(){
        if(top == nullptr){
            cout<<"la pila esta vacia"<<endl;
            return;
        }
        if(top == A){
            top = nullptr;
        }else{
            top--;
        }
    }
    void mostrar(){
        if(top == nullptr){
            cout<<"pila vacia"<<endl;
            return;
        }

        for(T *p = A ; p < top + 1 ; p++){
            cout<<*p <<" ";
        }
        cout<<endl;
    }
};




int main(){

    pila<int> pil1;
    pil1.push(10);
    pil1.mostrar();
    pil1.push(20);
    pil1.mostrar();
    pil1.pop();
    pil1.mostrar();
    pil1.pop();
    pil1.pop();
    return 0;
}