#include<bits/stdc++.h>


using namespace std;

ifstream in("text1.txt");
int c = 29;

struct elem
{
    int key;
    string data;
};

vector<elem> picture;

void wf(){
    for(int i = 0; i < c; ++i){
        elem kek;
        in >> kek.key;
        in >> kek.data;
        picture.push_back(kek);
    }
    
    for(elem i : picture){
        if(i.key<10){
            cout<<i.key<<"  "<<i.data<<endl;
        }
        else cout<<i.key<<" "<<i.data<<endl;
    }

    cout<<endl;
    cout<<endl;
    cout<<endl;


    int k = 0;
    while(1){
        k = k%2;
        int ch = 2*((picture.size()-k)/2);
        int y = 0;
        for(int i = k;i<ch;i=i+2){
            if(picture[i].key > picture[i+1].key){
                elem t = picture[i];
                picture[i] = picture[i+1];
                picture[i+1] = t;
                y = 1;
            }
        }
        if(y==0) break;
        k++;
    }


    for(elem i : picture){
        if(i.key<10){
            cout<<i.key<<"  "<<i.data<<endl;
        }
        else cout<<i.key<<" "<<i.data<<endl;
    }
    in.close();
    cout<<endl;
    cout<<endl;
}