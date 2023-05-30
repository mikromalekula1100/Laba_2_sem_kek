#include "binary_search.hpp"

int main(){
    wf();
    string e;
    while (1)
    {
        cin>>e;
        if(e == "exit")break;
        int t = binary_search(stoi(e));
        if(t==-1){cout<<"element not found";}
        else cout<<picture[t].data<<endl;
    }
}