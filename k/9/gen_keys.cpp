#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
 
using namespace std;

const double MIN = -1e6;
const double MAX = 1e6;

double random(double min = MIN, double max = MAX, int precision = 6) {
    double value;
    value = rand() % (int)pow(10, precision);
    value = min + (value / pow(10, precision)) * (max - min);

    return value;
}

struct Elem {
    double key;
    string value;

    Elem(double _key, string _value) : key(_key), value(_value) {}
};

int main() {
    srand(time(NULL));

    ifstream in("ascii");

    vector<Elem> data;
    string s;
    int n = 0;
    while (getline(in, s)) {
        data.push_back(Elem(0, s));
        n++;
    }

    double step = (MAX - MIN) / n;

    for (int i = 0; i < n; ++i) {
        double key = random(MIN + step * i, MIN + step * (i + 1));
        data[i].key = key;
    }

    cout.precision(6);
    cout << fixed;
    for (int i = 0; i < n; ++i) {
        cout << setw(14) << setfill(' ') << data[i].key;
        cout << ": " << data[i].value << endl;
    }

    random_shuffle(all(data));

    ofstream out("test");
    out.precision(6);
    out << fixed;
    for (int i = 0; i < n; ++i)
        out << data[i].key << " " << data[i].value << "\n";
}