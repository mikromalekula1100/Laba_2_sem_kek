#include "deq.h"

    deq::deq()
{
    Size = 0;
    head = nullptr;
    tail = nullptr;
    // cout<<"constructor"<<" "<<this<<" "<< endl;
}

deq::~deq() {
    Node* phead = head;
    while(phead!=tail){
        Node* plhead = phead;
        phead = phead->get_next();
        delete plhead;
        plhead = nullptr;
    }
    delete tail;
    phead = nullptr;
    head = nullptr;
    tail = nullptr;
    // cout<<"destructor"<<" "<<this<<" "<< endl;
}

    deq::deq(const deq &other)
    {   
        this->Size = other.Size;
        this->head = nullptr;
        this->tail = nullptr;
        for(int i=0;i<other.Size;i++){
                if(this->head==nullptr){this->head = this->tail = new Node(other[i]);}
                else{
                    this->tail->change_next(new Node(other[i]));
                    this->tail = this->tail->get_next();
                }
        }
            
        // cout<<"copy"<<" "<<this<<" "<<"from"<<&other<<endl;
        
    }

int deq::size(){return Size;}

void deq::push_back(int i)
{
    if(head == nullptr){
        head = new Node(i);
        tail = head;
        Size++;
    }
    else{
        tail->change_next(new Node(i));
        tail = tail->get_next();
        Size++;
    }
}

int deq::back()
{
    return tail->get_value();
}

void deq::pop_back()
{
    if(Size == 0) return;
    else if(Size == 1){
        delete head;
        head = nullptr;
        tail = nullptr;
        Size--;
    }
    else if(Size == 2){
        delete tail;
        tail = head;
        Size--;
    }
    else{
        Node * phead = head;
        while((phead->get_next()) != tail){
            phead = phead->get_next();
        }
        delete tail;
        tail = phead;
        phead = nullptr;
        Size--;
    }
}

void deq::push_front(int i)
{
    if(head == nullptr){
        head = new Node(i);
        tail = head;
        Size++;
    }
    else{
        Node* phead = head;
        head = new Node(i);
        head->change_next(phead);
        phead = nullptr;
        Size++;
    }
}

int deq::front()
{
    return head->get_value();
}

void deq::pop_front()
{
    if(Size == 0) return;
    else if(Size == 1){
        delete head;
        head = nullptr;
        tail = nullptr;
        Size--;
    }
    else if(Size == 2){
        delete head;
        head = tail;
        Size--;
    }
    else{
        Node * phead = head;
        head = head->get_next();
        delete phead;
        phead = nullptr;
        Size--;
    }
}

int deq::operator[](int i) const
{
    if(i>Size or i < 0) return -10000000;
    else{
        Node* phead = head;
        i--;
        while(i!=-1){
            phead = phead->get_next();
            i--;
        }
        return phead->get_value();
    }
}

deq operator*(const deq &lol1, const deq &lol2)
{
    int Size_lol1 = lol1.Size;
    int Size_lol2 = lol2.Size;
    deq keke;
    for(int i = 0;i<min(Size_lol1,Size_lol2);++i){
        keke.push_back(lol1[i] + lol2[i]);
    }
    return keke;
}

    deq operator+(const deq &lol1,const  deq &lol2)
    {
        deq keke;
        for(int i = 0; i<lol1.Size; ++i){
            keke.push_back(lol1[i]);
            }
        for(int i = 0; i<lol2.Size; ++i){
            keke.push_back(lol2[i]);
            } 
        return keke;
    }

    deq deq::sort()
    {   
        if(Size <= 1){
            deq keke;
            for(int i=0;i<Size;++i){keke.push_back((*this)[i]);
                
            }
            return keke;    
        }
        int s = Size;
        int k = (*this)[s/2];
        deq l1, l2, l3;
        for(int i=0;i<s;++i){
            if((*this)[i]>k) l3.push_back((*this)[i]);
            else if((*this)[i]<k) l1.push_back((*this)[i]);
            else l2.push_back((*this)[i]);
        }
        return l1.sort() + l2 + l3.sort();
    }

