#include<bits/stdc++.h>

using namespace std;

struct a{
    int number_column;
    float value;
    int index_next;    
};
vector<int> M;
vector<a> A;
int m,n;
ifstream in("matrix.txt");
struct pr
    {
        int x;
        int column = -1;
    };

void foo(){
    float integer_number;
    for(int i = 0;i<m;++i){
        bool flag = 1;
        vector<a>lol;
        for(int j = 0;j<n;++j){
            in >> integer_number;
            if(integer_number != 0){
                flag = 0;
                if(lol.size()!=0){
                    lol[lol.size()-1].index_next = j+1;
                }
                a kek;
                kek.number_column = j+1;
                kek.value = integer_number;
                lol.push_back(kek);  
            }
        }
        if(flag == 1) M.push_back(0);
        else{
            M.push_back(i+1);
            lol[lol.size()-1].index_next = 0;
            for(a i : lol){
                A.push_back(i);
            }
        }  
    }
}

void print_A(){
    cout<<endl;
    cout<<"Array A: [ ";
    for(a i :A){
        cout<<"{"<<i.number_column<<", "<<i.value<<", "<<i.index_next<<"}"<<" ";
    }
    cout<<"]"<<endl;
}

void print_M(){
    cout<<endl;
    cout<<"Array M: [ ";
    for(int i : M) cout<<i<<" ";
    cout<<"]"<<endl;
}

void print_matrix(){
    int k = 0;
    for(int i = 0; i < m; ++i){
        if(M[i] == 0){
            for(int j = 0; j < n; ++j){
                cout<<0<<" ";
            }
            cout<<endl;
        }
        else{
            if(A[k].index_next == 0){
                int ll = 0;
                int iter = A[k].number_column-ll-1;
                    for(int i = 0;i<iter;++i){
                        cout<<0<<" ";
                        ll++;
                    }
                cout<<A[k].value<<" ";
                ll++;
                for(int i = 0; i< (n-ll);++i){
                    cout<<0<<" ";
                }
                k++;
                cout<<endl;
            }
            else{
                int l = 0;
                while(A[k].index_next != 0){
                    int iter = A[k].number_column-l-1;
                    for(int i = 0;i<iter;++i){
                        cout<<0<<" ";
                        l++;
                    }
                    cout<<A[k].value<<" ";
                    l++;
                    k++;
                }
                int iter = A[k].number_column-l-1;
                for(int i = 0;i<iter;++i){
                        cout<<0<<" ";
                        l++;
                    }
                cout<<A[k].value<<" ";
                    l++;
                    k++;
                for(int i = 0; i< (n-l);++i){
                    cout<<0<<" ";
                }
                cout<<endl;
            }
                     
        }
    }
}

void max_modul(){
    
    pr x1,x2;
    x1.x = -100000;
    x2.x = -200000;
    for(a i:A){
        if(i.value >= x2.x){
            if(x1.x == i.value){
                if(i.number_column<x1.column){
                    x2.column = x1.column;
                    x2.x = x1.x;
                    x1.column = i.number_column;
                    continue;
                }
                
            }
            x1.x = x2.x;
            x2.x = i.value;
            x1.column = x2.column;
            x2.column = i.number_column;
        }

    }
    
    if(x1.x == x2.x){
        cout<<x1.column<<" "<<x1.x<<" "<<x2.column<<" "<<x2.x<<endl;
        for(int i = 0;i<A.size();++i){
            if(A[i].number_column == x1.column){
                A[i].value = A[i].value/(x1.x);
            }
        }
        return;
    }
    for(int i = 0;i<A.size();++i){
            if(A[i].number_column == x2.column){
                A[i].value = (A[i].value)/(x2.x);
            }
        }
        
    
}

int main(){   
   
    in>>m>>n;
    foo();
 
    print_A();
    print_M();
    print_matrix();
    cout<<endl;
    max_modul();
    cout<<endl;
    print_matrix();

    
}