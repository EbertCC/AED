#include <iostream>

using namespace std;

template<typename T>
class cola{
    private:
    T *head;
    T *tail;
    T AR[10];
    public:
    cola(){
        head=nullptr;
        tail=nullptr;
    }

    bool full(){
        int tamanio = 10;
        if(head == nullptr){
            return false;
        }
        T *p;
        if(AR+tamanio-1 == tail){
            p = AR;
        }else{
            p = tail+1;
        }
        return head==p;
    }
    void push(T valor){
        int tamanio = 10;
        if(head==nullptr){
            head = AR;
            tail = AR;
            *head = valor;
            return;
        }
        if(full()){
            cout<<"cola esta llena"<<endl;
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
        int tamanio = 10;
        if(head == nullptr){
            cout<<"cola esta vacia"<<endl;
        }
        if(head == tail){
            head = nullptr;
            tail = nullptr;
            return;
        }else if(AR+tamanio-1==head){
            head = AR;
        }else{
            head++;
        }
    }

    void mostrar(){
        int tamanio = 10;
        if(head == nullptr){
            cout<<"cola esta vacia"<<endl;
            return;
        }
        T *p = head;
        cout<<"cola : ";
        while(true){
            cout<<*p<<" ";
            if(p==tail){
                break;
            }
            if(p==AR+tamanio-1){
                p=AR;
            }else{
                p++;
            }
        }
        cout<<endl;
    }
    void mostrar_2(){
        int tamanio = 10;
        for(T *p = AR; p <= AR+tamanio-1;p++){
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
            col1.mostrar();
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