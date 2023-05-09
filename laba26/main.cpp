#include <bits/stdc++.h>
using namespace std;
#include "node.h"
#include "deq.h"


// void foo(deq l){

//     cout<<l.size()<<endl;
// }

int main(){  
    deq lol1,lol2,lol3;
    lol2.push_back(2);
    lol2.push_back(1);

    deq t = (lol3+lol1+lol2);
    // foo(lol1);
    t = t.sort();
    for(int i=0;i<t.size();++i){cout<<t[i]<<" ";}
    cout<<endl;
    // cout<<t.size()<<endl;
}   