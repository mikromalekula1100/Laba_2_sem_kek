#pragma once
#include <bits/stdc++.h>
#include "node.h"
using namespace std;
//description of functions for creating a deq

class deq {
private:
    int Size;
    Node* head;
    Node* tail;
public:
    deq();
    ~deq();
    deq(const deq &other);

    int size();

    // for back
    void push_back(int i);

    int back();

    void pop_back();

    // for front
    void push_front(int i);

    int front();

    void pop_front();

    int operator [] (int i) const;
    
    friend deq operator * (const deq &lol1,const deq &lol2);//for fun

    friend deq operator + ( const deq &lol1,  const deq &lol2);
    
    // friend deq operator + (  deq &lol1,   deq &lol2);

    deq sort();

    
};

deq operator * (const deq &lol1,const deq &lol2);
deq operator + (const deq &lol1, const deq &lol2);
// deq operator + ( deq &lol1,  deq &lol2);56565