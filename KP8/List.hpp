#include "node.hpp"

class List{
    int length;
    node * head = nullptr;
    node * tail = nullptr;
public:
    List();
    ~List();
    int len();
    void add(bool value);
    void print();
    void operator [] (int i);
    void exchange(int a, int b);
    
};