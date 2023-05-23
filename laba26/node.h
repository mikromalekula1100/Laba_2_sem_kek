#pragma once
#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    Node(int value);
    
    void print();
    Node* get_next();
    int get_value();
    void change_next(Node* i);
private:
    int value;
    Node* next;
};

