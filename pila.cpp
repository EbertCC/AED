#include <iostream>

using namespace std;

template<typename T>
class pila{
    protected:
    T AR[10];
    T *top;
    public:
    pila(){
        top = nullptr;
    }
    void push(T val){
        int tamanio;
        if(top == nullptr){
            tamanio = 0;
        }else{
            tamanio = top - AR +1 ;
        }
        if(tamanio >= 10){
            cout<<"pila llena"<<endl;
            return;
        }
        if(top == nullptr){
            top = AR;
            *top = val;
        }else{
            top++;
            *top = val;
        }
    }
    void pop(){
        if(top==nullptr){
            cout<<"pila vacia"<<endl;
            return;
        }
        if(top == AR){
            top = nullptr;
        }else{
            top--;
        }

    }
    void mostrar(){
        if(top == nullptr){
            cout<<"pila vacia"<<endl;
        }
        for(T *p = AR ; p <= top ; p++){
            cout<<*p<<" ";
        }
        cout<<endl;
    }

};


int main(){

    pila<int> pil;

    for(int i=0;i<=10;i++){
        pil.push(i);
    }
    pil.mostrar();
    pil.pop();
    pil.mostrar();
    pil.pop();
    pil.pop();
    pil.pop();
    pil.pop();
    pil.pop();
    pil.pop();
    pil.pop();
    pil.pop();
    pil.mostrar();
    pil.pop();
    pil.pop();
/*
    pil.push(1);
    pil.push(2);
    pil.push(3);
    pil.push(4);
    pil.push(5);
    pil.push(6);
    pil.push(7);
    pil.push(8);
    pil.push(9);
    pil.push(10);
*/

    return 0;
}