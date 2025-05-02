#include <iostream>

using namespace std;

//template<typename T>
struct Nodo
{
    int valor[5];
    Nodo *next;
    Nodo()
    {
        next = nullptr;
    }
};


class Pila
{
    private:
    Nodo *head;
    int indice;

    public:
    Pila();
    ~Pila();
    void push_back(int val);
    void pop_back();
    void mostrar();

};
Pila::Pila()
{
    head = nullptr;
    indice = 0;
}
void Pila::push_back(int val)
{
    if(head == nullptr || indice == 5)
    {
        Nodo *newnodo = new Nodo();
        newnodo ->next = head;
        head = newnodo;
        indice = 0;
    }
    head->valor[indice] = val;
    indice = indice + 1 ;
}
void Pila::pop_back()
{
    if(head == nullptr)
    {
        cout<<"pila esta vacia"<<endl;
        return;
    }
    indice = indice - 1 ;
    if(indice == 0){
        Nodo *temp = head;
        head = head ->next;
        delete temp;
        if(head != nullptr)
        {
            indice = 5 ;
        }else
        {
            indice = 0;

        }
    }
}

void Pila::mostrar()
{
    if(head == nullptr)
    {
        cout<<"pila vacia"<<endl;
        return;
    }
    
    Nodo *aux = head;
    while(aux != nullptr)
    {
        int num_indices;
        if(aux == head)
        {
            num_indices = indice;
        }else
        {
            num_indices = 5;
        }
        for(int i = 0; i<num_indices;i++)
        {
            cout<<aux->valor[i]<<" ";
        }
        cout<<endl;
        aux = aux ->next;
    }
    

}
Pila::~Pila(){
    while(head != nullptr)
    {
        Nodo *temp = head;
        head = head->next;
        delete temp;
    }
}



int main(){
    Pila pil_1;
    pil_1.mostrar();
    pil_1.pop_back();
    pil_1.push_back(1);
    pil_1.push_back(2);
    pil_1.push_back(3);
    pil_1.push_back(4);
    pil_1.push_back(5);
    //pil_1.mostrar();
    pil_1.push_back(6);
    pil_1.push_back(7);
    pil_1.mostrar();
    pil_1.pop_back();
    pil_1.pop_back();
    pil_1.pop_back();
    cout<<endl;
    pil_1.mostrar();



    return 0;
}