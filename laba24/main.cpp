#include <bits/stdc++.h>
#include <Windows.h>
using namespace std;

// structure for creating tree nodes
struct elem_tree{ 
    string value;
    elem_tree * right;
    elem_tree * left;
};

queue<string> infz;  //queue for infix entry
queue<string> postfz;  //queue for postfix recording
stack<string> st;   //auxiliary stack for postfix record formation
stack<elem_tree*> pst; // stack for tree formation
map<string,int>q = {{"(", 0}, {")", 1}, {"^", 2}, {"*", 3}, {"/", 3}, {"+", 4}, {"-", 4}}; //dictionary for setting the operation priority
queue<string> pz;  //a queue for a postfix entry but already for a simplified expression


// a function that creates a new tree node
elem_tree* new_node(string value){
    elem_tree * node = new elem_tree;
    node->value = value;
    node->right = NULL;
    node->left = NULL;
    return node;
}
// // draw our tree
void printTree(elem_tree* root, int indent = 0) {
    if (root != NULL) {
        printTree(root->right, indent + 4);
        cout << string(indent, ' ') << root->value << endl;
        printTree(root->left, indent + 4);
    }
}
// a function that determines whether a string is a numberчиѝлом
bool is_digit(string a){
    if(a == "-") return 0;
    else{
        if(a[0]=='-') a = a.substr(1,a.size()-1);
    for(char i:a) if(!isdigit(i))return 0;
    }
    
    return 1;
}

//  a function that converts an infix form to a postfix form, it is stored in a postfix queue
void create_que(string s){  
    string t = "";
    for(char i:s){
        if(i==' ') continue;
        else{
            if(isdigit(i))t+=string(1,i);
            else{
                if(i=='-' and t.size()==0){
                    if((!infz.empty()) and (is_digit(infz.back()) or infz.back() ==")")){
                        infz.push(string(1,i));
                    }else t = string(1,i);
                }
                else if(i=='-' and t.size()!=0){
                    infz.push(t);
                    infz.push(string(1,i));
                    t = "";
                }
                else{
                    if(t.size()!=0){
                        infz.push(t);
                        infz.push(string(1,i));
                        t = "";
                    }
                    else infz.push(string(1,i));
                }
                    
                }
        }
        }
        if(t.size()!=0)infz.push(t);
        cout<<"The read expression has the form:"<<endl;
        int x = infz.size();
        for(int i = 0;i<x;++i){
            cout<<infz.front()<<" ";
            infz.push(infz.front());
            infz.pop();
        }
        for(int i = 0;i<3;++i)cout<<endl;
        
}
// a function that translates an infix form into a postfix form, it is stored in a postfix queue
void pstrec(){
    while(!infz.empty()){
        string s = infz.front();
        infz.pop();
        if(is_digit(s)) postfz.push(s);
        else{
            if(s=="(") st.push(s);
            else if(s==")"){
                while(st.top()!="("){
                    postfz.push(st.top());
                    st.pop();
                }
                st.pop();
            }
            else{
                if(st.empty()) {
                   st.push(s);
                }
                
                else{
                    while((!st.empty()) and ((q[st.top()] <= q[s]) and q[st.top()] != 0)){
                        postfz.push(st.top());
                        st.pop();
                    }
                    st.push(s);
                }
                
            }
        }
    }
    if(!st.empty()){
        
        while(!st.empty()){
            postfz.push(st.top());
            st.pop();
        }
    }
    cout<<"The read expression has the form in POSTFIX NOTATION:"<<endl;
    int x = postfz.size();
        for(int i = 0;i<x;++i){
            cout<<postfz.front()<<" ";
            postfz.push(postfz.front());
            postfz.pop();
        }
        for(int i = 0;i<3;++i)cout<<endl;
}
 // a function that forms a tree from a postfix entry, that is, from the infz queue
elem_tree* create_free(){
    while(!postfz.empty()){
        string t = postfz.front();
        postfz.pop();
        if(is_digit(t)){
           pst.push(new_node(t)); 
        }
        else{
            elem_tree* keke = new_node(t);
            keke->right = pst.top();
            pst.pop();
            keke->left = pst.top();
            pst.pop();
            pst.push(keke);
        }
    }
    return pst.top();
}

// this function recursively traverses the tree in width and replaces integer expressions that include multiplication by zero element by zero

int simplify(elem_tree* &head, int a = 0){
    if(head ->left == NULL and head ->right == NULL) return stoi(head->value);
    if(a == 1){
        if(head->value == "+") return simplify(head->left,1)+simplify(head->right,1);
        else if(head->value == "-") return simplify(head->left,1)-simplify(head->right,1);
        else if(head->value == "^") return simplify(head->left,1)^simplify(head->right,1);
        else if(head->value == "/") return simplify(head->left,1)/simplify(head->right,1);
   }     
   if(head -> value == "*"){
        if(simplify(head->left,1)==0 or simplify(head->right,1)==0){
            if(head->left != NULL) delete head->left;             
            if(head->right != NULL) delete head->right;           
            head->value = "0";
            head->right = NULL;
            head->left = NULL;
            return 0;
        }
        else {
            return 1;
        }
   }
   else{
        simplify(head->left,0);
        simplify(head->right,0);
        return 0;
   }
}

//a function that builds a postfix entry on a tree
void expr_from_tree(elem_tree* root) {
    if (root == nullptr) {
        return;
    }
     pz.push(root->value); 
    expr_from_tree(root->right); 
    expr_from_tree(root->left); 
    }

int main(){    
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8); 

    string a;
    getline(cin,a); //reading an expression into a string

    create_que(a); //I put the expression in the lol queue and immediately output it
    pstrec(); //I create a queue with a postfix entry and immediately output it

    elem_tree* head = create_free(); // creating a tree

    cout<<"Expression tree before simplification:"<<endl;
    printTree(head); // bringing out a tree

    for(int i = 0;i<3;++i)cout<<endl;

    simplify(head); //simplifying the expression through a tree

    cout<<"Expression tree after simplification:"<<endl;
    printTree(head); // output the tree of the modified expression

   for(int i = 0;i<3;++i)cout<<endl;

    
    expr_from_tree(head); 
    string s = "";
    int x = pz.size();
        for(int i = 0;i<x;++i){
            s = " "+pz.front()+s; 
                // output a postfix entry of a simplified expression
            pz.push(pz.front());
            pz.pop();
        }
    cout<<"SIMPLIFIED postfix entry:"<<endl;
    cout<<s<<endl;

    for(int i = 0;i<3;++i)cout<<endl;

    stack<string> z1;
    stack<string> z2;
    while(!pz.empty()){
        z1.push(pz.front());
        pz.pop();
    }
    while(!z1.empty()){
        string h = z1.top();
        z1.pop();
        if(is_digit(h)){
            z2.push(h);
        }
        else{
            string s1,s2;
            s1 = z2.top();
            z2.pop();
            s2 = z2.top();
            z2.pop();
            z2.push("("+s2+h+s1+")");
        }
    }
    cout<<"A normalized (infix) entry of A SIMPLIFIED FORM:"<<endl;
    cout<<z2.top();
}