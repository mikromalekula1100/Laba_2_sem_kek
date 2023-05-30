
#include "List.hpp"

 List::List()
{
    this -> length = 0;
}

void List::add(bool a)
{
    node * new_node = new node;
    new_node->value = a;
    length++;
    if(head == nullptr && tail == nullptr){
        head = new_node;
        tail  = head;
        head -> next = head;
        return;
    }
    node * ptail = tail;
    tail = new_node;
    ptail->next = tail;
    tail->next = head;
       
}

void List::print()
{
    node * phead = head;
    if(length == 1){
        cout<<head->value;
        return;
    } 
    while(phead->next!=head){
        cout<<phead->value<<endl;
        phead = phead->next;
    }
    cout<<phead->value<<endl;
}

void List::exchange(int a, int b)
{
    if(a>=length || a<0 || b>=length || b<0 ||a == b){std::cerr << std::runtime_error("Out of range").what() << std::endl;
    exit(EXIT_FAILURE);}
    int k = 0;
    int c;
    if(a>b){
        c = b;
        b = a;
        a = c;
    }
    node * phead = head;
    while(k!=a){
        k++;
        phead = phead->next;
    }
    k = 0;
    node * pphead = head;
    while(k!=b){
        k++;
        pphead = pphead->next;
    }
    bool t = phead->value;
    phead->value = pphead->value;
    pphead->value = t;
    
}

void List::operator[](int i) 
{
    if(i>=length || i<0){std::cerr << std::runtime_error("Out of range").what() << std::endl;
    exit(EXIT_FAILURE);}
    
    int k = 0;
    node * phead = head;
    node * pphead = tail;
    while(k!=i){
        k++;
        pphead = phead;
        phead = phead->next;
    }
    pphead -> next = phead ->next;
    head = tail->next;
    length--;
    delete phead;
    
}

int List::len()
{
    return length;
}

List::~List()
{
    node * phead;
    if(length == 1){
        delete head;
        return;
    }
    while(head!=tail){
        phead = head->next;
        delete head;
        head = phead;
    }
    delete head;
}
