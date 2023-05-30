#include<bits/stdc++.h>

using namespace std;



int main(int argc, char * argv[]){
    ifstream in1("students_name");
    ifstream in2("students_group");
    ifstream in3("students_exams");
    ifstream in4("students_sex");
    string name, m1, m2, m3, sex, surname;
    int count_students, key1, key2,key3, group;
    if(argc > 1){
        string t = argv[1];
        in1>>count_students;
        if(t == "-f"){
            cout<<"|_____Name_____|___Sex___|___group___|__M1__|__M2__|__M3__|"<<endl;
            for(int i = 0; i < count_students; ++i){
                in1>>key1>>name>>surname;
                cout<<"   "<<name<<" "<<surname<<"        ";
                for(int j = 0; j < count_students; ++j){
                    in4>>key2>>sex;
                    if(key1 == key2) cout<<sex<<"         ";
                    break;
                }
                for(int r = 0; r < count_students; ++r){
                     in2>>key2>>group;
                    if(key1 == key2) cout<<group<<"         ";
                    break;
                }
                for(int f = 0; f < count_students; ++f){
                     in3>>key2>>m1>>m2>>m3;
                    if(key1 == key2) cout<<m1<<"       "<<m2<<"      "<<m3<<endl;
                    break;
                }
                   

            }
        }
        else if(t == "-p"){
            int k = 0, p;
            cin>>p;
            for(int j = 0; j < count_students; ++j){
                in4>>key1>>sex;
                if(sex == "F"){
                    for(int j = 0;j<count_students;j++){
                        in2>>key2>>group;
                        if(key1==key2 && group ==p){
                            for(int g = 0; g<count_students;g++){
                                in3>>key3>>m1>>m2>>m3;
                                if((key1 == key3) && ((m1 == "5" && m2 != "5" && m3 != "5")||(m1 != "5" && m2=="5" && m3 !="5")||(m1 != "5" && m2 != "5" && m3 == "5")) ){
                                    k++;
                                    break;
                                }
                            }
                            break;
                        }
                    }
                    }
            }
            cout<<k;
        }
        
    }
}