#include <iostream>

using namespace std;

template<typename T>
class cola{
    private:
    T AR[10];
    T *head;
    T *tail;
    public:
    cola(){
        head = nullptr;
        tail = nullptr;
    }
    bool full(){
        T tamanio = 10;
        if(head == nullptr){
            return false;
        }
        T *p;
        if(AR+tamanio-1 == tail){
            p = AR;
        }else{
            p = tail+1;
        }
        return p==head;
    }
    void push(T valor){
        T tamanio = 10;
        if(head == nullptr){
            head = AR;
            tail = AR;
            *head = valor;
            return;
        }
        if(full()){
            cout<<"pila esta llena"<<endl;
            return; 
        }
        if(AR+tamanio-1 == tail){
            tail = AR;
            *tail = valor;
        }else{
            tail++;
            *tail = valor;
        }
    }
    void pop(){
        T tamanio = 10;
        if(head == nullptr){
            cout<<"pila esta vacia"<<endl;
            return;
        }
        if(head==tail){
            head = nullptr;
            tail = nullptr;
        }else if(AR+tamanio-1 == head){  //else if(AR+tamanio+1 == head){
            head = AR;
        }else{
            head++;
        }
    }

    void mostrar_1(){
        T tamanaio = 10;
        if(head == nullptr){
            cout<<"pila esta vacia"<<endl;
            return;
        }
        T *p=head;
        while (true){
            cout<<*p<<" ";
            if(p==tail){
                break;
            }
            if(AR+tamanaio-1==p){
                p=AR;
            }else{
                p++;
            }
        }
        cout<<endl;
    }
    void mostrar_2(){
        T tamanio = 10;
        for(T *p=AR; p < AR+tamanio ; p++){
            cout<<*p<<" ";
        }
        cout<<endl;
    }

};



int main(){

    cola<int> col1;
    int val;
    int opc;

    do{
        cout<<"1. ingrese valor"<<endl;
        cout<<"2. eleminar "<<endl;
        cout<<"3. mostrar"<<endl;
        cout<<"4. salir"<<endl;
        cout<<"5. mostrar(2)"<<endl;
        cin>>opc;
        cout<<endl;
        switch(opc){
            case 1:
            cout<<"ingrese valor : ";
            cin>>val;
            col1.push(val);
            break;

            case 2:
            col1.pop();
            break;

            case 3:
            col1.mostrar_1();
            break;

            case 4:
            break;

            case 5:
            col1.mostrar_2();
            break;
        }
    }while (opc!=4);


    return 0;
}