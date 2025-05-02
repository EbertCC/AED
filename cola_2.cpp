#include <iostream>

using namespace std;

struct Node
{
    int Valores[5];
    Node *next;
    Node ()
    {
        next = nullptr;
    }
};

class Cola
{
    private:
    Node *head;
    Node *tail;
    int indi_head;
    int indi_tail;
    public:
    Cola();
    ~Cola();
    void push_back(int val);
    void pop_front();
    void mostar();
};
Cola::Cola()
{
    head = nullptr;
    tail = nullptr;
    indi_head = 0;
    indi_tail = 0;

}
Cola::~Cola()
{
    while(head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}
void Cola::push_back(int val)
{
    if(tail == nullptr || indi_tail==5)
    {
        Node *newnodo = new Node();
        if(tail != nullptr)
        {
            tail->next = newnodo;
        }
        tail = newnodo;
        if(head == nullptr){
            head = newnodo;
        }
        indi_tail = 0;
        
    }
    tail->Valores[indi_tail] = val;
    indi_tail = indi_tail + 1;

}
void Cola::pop_front()
{
    if(head == nullptr)
    {
        cout<<"pila vacia"<<endl;
        return;
    }
    indi_head = indi_head + 1;
    if(indi_head == 5)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        indi_head = 0;
        if(head == nullptr)
        {
            tail = nullptr;
        }
    }
}
void Cola::mostar()
{
    if(head == nullptr)
    {
        cout<<"pila vacia"<<endl;
        return;
    }
    Node *aux = head;
    while(aux != nullptr)
    {
        if(aux == head && aux == tail)
        {
            for(int i =indi_head;i<indi_tail;i++){
                cout<<aux->Valores[i]<<" ";
            }
        }
        else if(aux == head)
        {
            for(int i=indi_head;i<5;i++){
                cout<<aux->Valores[i]<<" ";
            }
        }
        else if(aux == tail)
        {
            for(int i =0;i<indi_tail;i++){
                cout<<aux->Valores[i]<<" ";
            }
        }
        else{
            for(int i = 0;i<5;++i){
                cout<<aux->Valores[i]<<" ";
            }
        }
        cout<<endl;
        aux = aux -> next;
    }
}

int main(){

    Cola cola_1;
    cola_1.push_back(1);
    cola_1.push_back(2);
    cola_1.push_back(3);
    cola_1.push_back(4);
    cola_1.push_back(5);
    cola_1.push_back(6);
    //cola_1.mostar();
    cola_1.pop_front();
    cola_1.pop_front();
    cola_1.mostar();
    return 0;
}