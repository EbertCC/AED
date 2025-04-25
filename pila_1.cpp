#include <iostream>

using namespace std;

template<typename T>
class pila{
    private:
    T AR[10];
    T *top;
    public:
    pila(){
        top=nullptr;
    }
    void push(T valor){
        T tamanio = 10;
        if(top == nullptr){
            top = AR;
            *top = valor;
        }else if(top<AR+tamanio-1){
            top++;
            *top = valor;
        }else{
            cout<<"pila llena"<<endl;
        }
    }
    void pop(){
        if(top==nullptr){
            cout<<"pila vacia"<<endl;
        }else if(top==AR){
            top = nullptr;
        }else{
            top--;
        }
    }
    void mostrar(){
        if(top == nullptr){
            cout<<"pila esta vacia"<<endl;
            return;
        }
        for(T *p=AR ; p<=top; p++){
            cout<<*p<<" ";
        }
        cout<<endl;
    }
};


int main(){

    pila<int> pil_1;

    for(int i=1;i<=11;i++){
        pil_1.push(i);
    }
    pil_1.mostrar();
    pil_1.pop();
    pil_1.pop();
    pil_1.pop();
    pil_1.pop();
    pil_1.pop();
    pil_1.pop();
    pil_1.pop();
    pil_1.pop();
    pil_1.pop();

    pil_1.mostrar();
    pil_1.push(11);
    pil_1.mostrar();

    pil_1.pop();
    pil_1.pop();
    pil_1.pop();

    
    return 0;
}