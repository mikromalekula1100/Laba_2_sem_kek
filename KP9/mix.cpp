#include<bits/stdc++.h>

using namespace std;

ifstream in("text3.txt");
int c = 29;
struct elem
{
    int key;
    string data;
};
vector<elem> picture;

int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 29);

    std::set<int> unique_numbers;
    vector<int> a;
    while(a.size() < 29)
    {
        int i = dist(gen);
        int s = unique_numbers.size();
        unique_numbers.insert(i);
        if(s!=unique_numbers.size()){
            a.push_back(i);
        }
    }

   for(int i = 0; i < c; ++i){
        elem kek;
        in >> kek.key;
        in >> kek.data;
        picture.push_back(kek);
    }

    
    ofstream file1("text1.txt");
    for(int i:a){
        file1<<picture[i-1].key<<picture[i-1].data<<endl;
    }

    file1.close();

    ofstream file2("text2.txt");
    for(int i = 29;i>0;--i){
        file2<<picture[i-1].key<<picture[i-1].data<<endl;
    }
    file2.close();

}