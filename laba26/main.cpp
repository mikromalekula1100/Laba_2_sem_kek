#include <bits/stdc++.h>
using namespace std;
#include "node.h"
#include "deq.h"



int main(){  
    deq lol1,lol2;
    lol2.push_back(1111);
    lol2.push_back(22);
    
    

    deq t = (lol1+lol2);
    
    t = t.sort();
    for(int i=0;i<t.size();++i){cout<<t[i]<<" ";}
    cout<<endl;
    // cout<<t.size()<<endl;
}   