
#include <bits/stdc++.h>

using namespace std;

struct elem_tree{
    int value;
    elem_tree * right;
    elem_tree * left;
};

elem_tree* new_top(int value){
    elem_tree * kek = new elem_tree;
    kek->value = value;
    kek->right = NULL;
    kek->left = NULL;
    return kek;
}
void add(elem_tree* elem,  elem_tree * & head){
    if(head == NULL) head = elem;
    else{
        if(head->value > elem->value){
            if(head->left==NULL)head->left = elem;
            else add(elem,head->left);
        }
        else if(head->value == elem->value) { cout<<"такой узел уже существует"<<endl;}
        else{
            if(head->right==NULL) head->right = elem;
            else add(elem,head->right);
        }
    }
}
void printTree(elem_tree* root, int indent = 0) {
    if (root != NULL) {
        // Выводим правое поддерево
        printTree(root->right, indent + 4);

        // Выводим текущий узел
        cout << string(indent, ' ') << root->value << endl;

        // Выводим левое поддерево
        printTree(root->left, indent + 4);
    }
}
void delete_top(elem_tree * & phead, int value){
    elem_tree * head = phead;
    elem_tree * lol = phead->right;
    elem_tree * headr = phead->right;
    elem_tree * headl = phead->left;
    
        if(head->value < value){
            if(((head->right)->value) == value){
                if((head->right)->left == NULL and (head->right)->right == NULL){
                delete((head->right));
                head->right = NULL;
            }
            else if(((head->right)->left == NULL and (head->right)->right != NULL) or ((head->right)->left != NULL and (head->right)->right == NULL)){
                if(((head->right)->left == NULL and (head->right)->right != NULL)) head->right = (head->right)->right;
                
                else head->right = (head->right)->left;
                delete(headr);
            }
            
            else{
                elem_tree * kek = head->right;
                head->right = (head->right)->right;
                (head->right)->left = kek->left;
                delete(kek);
            }
            }
            else delete_top(head->right,value);
        }
        else if(head->value > value){
            if(((head->left)->value) == value){
                if((head->left)->left == NULL and (head->left)->right == NULL){
                    delete((head->left));
                    head->left = NULL;
            }
            else if(((head->left)->left == NULL and (head->left)->right != NULL) or ((head->left)->left != NULL and (head->left)->right == NULL)){
                if(((head->left)->left == NULL and (head->left)->right != NULL)) head->left = (head->left)->right;
                
                else head->left = (head->left)->left;
                delete(headl);
            }
            
            else{
                elem_tree * kek = head->left;
                head->left = (head->left)->right;
                (head->left)->left = kek->left;
                delete(kek);
                }   
            }
            else delete_top(head->left,value);
        }
        else if(phead -> value == value){
            if(phead->right ==NULL){
                elem_tree * keke = phead->left;
                delete(phead);
                phead = keke;
                delete(keke);
            }
            else if(phead->left ==NULL){
                elem_tree * keke = phead->right;
                delete(phead);
                phead = keke;
                delete(keke);
            }
            else{
               while((lol->left) != NULL) lol = (lol->left);
               lol->left = phead->left;
               phead = phead->right; 
            }
               
        }
        else cout<<"Введены некорректные данные"<<endl;
}

bool is_linear_list_of_vertices(elem_tree * phead){
    if(phead->left != NULL and phead->right == NULL){
        is_linear_list_of_vertices( phead->left);
    }
    else if(phead->left == NULL and phead->right != NULL){
        is_linear_list_of_vertices( phead->right);
    }
    else if(phead->left == NULL and phead->right == NULL)return 1;
    else return 0;
}

int main()
{   
    elem_tree * head = NULL;
    while(1){
        cout<<"Ведите команду:"<<endl;
        cout<<"Add - добавление нового узла."<<endl;
        cout<<"View - визуализация дерева."<<endl;
        cout<<"Del - удаление узла."<<endl;
        cout<<"Break - завершить работу программы."<<endl;
        cout<<"Check - проверка, является ли дерево линейным списком вершин."<<endl;
        string k;
        cin>>k;
        if(k == "Add"){
            cout<<"Введите значние узла."<<endl;
            int k;
            
            int s;
            cin>>s;
            if(head == NULL) cout<<"Корень дерева создан!"<<endl;
            add(new_top(s),head);
            
        }
        if(k == "View"){
            printTree(head);
        }
        if(k == "Break"){
            break;
        }
        if(k == "Del"){
            cout<<"Введите значение удаляемого узла.";
            int s;
            cin>>s;
            delete_top(head,s);
        }
        if(k == "Check"){
            if(is_linear_list_of_vertices(head)) cout<<"Дерево ЯВЛЯЕТСЯ линейным списком вершин."<<endl;
            else cout<<"Дерево НЕ ЯВЛЯЕТСЯ линейным списком вершин."<<endl;
        }
    }
}