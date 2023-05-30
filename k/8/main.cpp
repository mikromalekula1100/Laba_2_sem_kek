// Вид списка
// (16 / 2) % 6 + 1 = 3
// - Линейный однонаправленный
// Действие
// 16 % 15 + 1 = 2
// - Очистить список, если в нем есть элемент, равный заданному значению

#include <bits/stdc++.h>
 
using namespace std;

template <typename T>
struct Node {
    T data;
    Node* next;
    int id = 0;
    
    Node(T _data, Node* _next = nullptr) : data(_data), next(_next) {}

    void print() {
        cout << "id: " << id << " data: " << data << endl;
    }
};

template <typename T>
struct List {
    using ptr = Node<T>*;

    ptr phead = nullptr;
    int size = 0;

    class Iterator {
        ptr elem = nullptr;
        
    public:
        Iterator(ptr _elem) : elem(_elem) {}

        // ptr shift(int n) {
        //     ptr pnode = phead;
        //     for (int i = 0; i < n; ++i)
        //         if (pnode->next != nullptr)
        //             pnode = pnode->next;
        //         else
        //             return nullptr;
        //     return pnode;
        // }

        ptr operator++ () {
            elem = elem->next;
            return elem;
        }
        ptr operator+ (int n) {
            ptr pnode = elem;
            for (int i = 0; i < n; ++i)
                if (pnode->next != nullptr)
                    pnode = pnode->next;
                else
                    return nullptr;
            return pnode;
        }

        bool operator== (const Iterator &it) {
            return (elem == it.elem);
        }
        bool operator!= (const Iterator &it) {
            return (elem != it.elem);
        }

        // ptr operator-- (int n) {
        //     return shift(elem->id - 1);
        // }
        // ptr operator- (int n) {
        //     if (elem->id - n >= 0)
        //         return shift(elem->id - n);
        //     else
        //         return nullptr;
        // }

        Node<T>& operator* () {
            return *elem;
        }
    };

    Iterator begin() {
        return phead;
    }
    Iterator end() {
        return nullptr;
    }
    
    Node<T>* add_Node(T data, Node<T>* next = nullptr) {
        if (phead == nullptr) {
            phead = new Node<T>(data, next);
            size++;
            return phead;
        }

        Node<T>* pnode = phead;
        while (pnode->next != nullptr)
            pnode = pnode->next;
    
        pnode->next = new Node<T>(data, next);
        
        pnode = pnode->next;
        pnode->id = size;
        
        size++;
        
        return pnode;
    }

    bool rem_Node(T data) {
        Iterator it(begin());

        if (phead->data == data) {
            ptr pnode = phead->next;
            delete phead;
            phead = pnode;
            size--;
            return true;
        }

        for (; it != end(); ++it) {
            if ((*it).next != nullptr && (*it).next->data == data) {
                ptr pnode = (*it).next;
                (*it).next = pnode->next;
                delete pnode;
                size--;
                return true;
            }
        }

        return false;
    }

    void print() {
        Node<T>* pnode = phead;
        while (pnode != nullptr) {
            pnode->print();
            pnode = pnode->next;
        }
    }

    bool clear(T data) {
        if (rem_Node(data)) {
            ptr pnode = phead;
            while (pnode != nullptr) {
                phead = pnode->next;
                delete pnode;
                pnode = phead;
            }

            size = 0;

            return true;
        } else
            return false;
    }
};

template <typename T>
ostream& operator<< (ostream &out, Node<T> &x) {
    x.print();
    return out;
}

int main() {
    List<int> a;
    a.add_Node(10);
    a.add_Node(20);
    a.add_Node(17);
    a.add_Node(45);

    cout << *(a.phead) << endl;

    List<int>::Iterator it(a.begin());
    cout << *it << endl;
    cout << *(++it) << endl;
    cout << *(++it) << endl;

    a.rem_Node(20);
    a.print();

    a.rem_Node(23);
    a.print();

    cout << a.clear(20) << endl;
    cout << a.clear(17) << endl;

    cout << *(it) << endl;
}