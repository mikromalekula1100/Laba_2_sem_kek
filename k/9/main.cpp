// Метод сортировки
// ((16 - 1) % 11) + 1 = 5
// - Метод простой вставки
// Структура таблицы
// ((16 + 6) % 9) + 1 = 5
// - Вещественный тип ключа, хранение данных и ключа вместе, число элементов таблицы 8-12

#include <bits/stdc++.h>
 
using namespace std;

struct Elem {
    double key;
    string value;

    Elem(double _key, string _value) : key(_key), value(_value) {}
};

void insertionSort(vector<Elem> & data) {
    for (int i = 1; i < data.size(); i++) {
        int item = i - 1;
        while(item >= 0 && data[item].key > data[item + 1].key) {
            swap(data[item], data[item + 1]);
            item--;
        }
    }
}

void print(vector<Elem> & data) {
    cout.precision(6);
    cout << fixed;
    for (int i = 0; i < data.size(); ++i) {
        cout << setw(14) << setfill(' ') << data[i].key;
        cout << ": " << data[i].value << endl;
    }
}

int main() {
    srand(time(NULL));

    ifstream in("test");

    vector<Elem> data;
    string s;
    while (getline(in, s)) {
        string key = "";
        int i = 0;
        for (; s[i] != ' '; ++i)
            key += s[i];
        string value = s.substr(i + 1, s.size() - i);
        data.push_back(Elem(stod(key), value));
    }
    int n = data.size();

    print(data);

    cout << "\n" << "Отсортировать? ";
    if (cin >> s)
        insertionSort(data);
    
    cout << endl;
    print(data);
    cout << endl;

    while (true) {
        cout << "Введите значение:" << endl;
        double key;
        cin >> key;

        int l = 0,
        r = n - 1;
        while (true) {
            int m = l + (r - l) / 2;
            if (key == data[m].key) {
                cout << "Значение найдено!" << endl;
                cout << data[m].value << endl;
                break;
            } else if (l == r) {
                cout << "Значений не найдено!" << endl;
                cout << "Ближайшее значение: " << data[l].key << endl;
                break;
            } else if (key < data[m].key)
                r = m;
            else
                l = m + 1;
            
        }
        cout << endl;
    }
}