#include <sstream>
#include <set>
#include <vector>
#include <iostream>
using namespace std;

int numeroAbase(int n, int base){
    int nuevo = 0;
    while(n){
        nuevo *= 10;
        nuevo += (n % base);
        n /= base;
    }
    return nuevo;
}

int funcion(int n){
    int respuesta = 0;
    while(n){
        respuesta += (n%10)*(n%10);
        n /= 10;
    }
    return respuesta;
}

bool esHappy(int n, int base){
    n = numeroAbase(n, base);
    set<int> loops;
    cerr << "Testeando si el numero " << n << " es happy en base " << base <<
endl;
    while(!loops.count(n)){
        cerr << n << ' ';
        loops.insert(n);
        n = numeroAbase(funcion(n), base);
        if (n == 1) return true;
    }
    cerr << endl;
    return false;
}

int main(){
    int casos;
    cin >> casos;
    string S;
    getline(cin, S);
    for(int c = 1 ; c <= casos; c++){
        vector<int> base;
        getline(cin, S);
        istringstream ISS (S);
        int a;
        while(ISS>>a) base.push_back(a);
        int j = 2;
        bool sol = false;
        while(!sol){
            sol = true;
            for(int i = 0; i < base.size();i++)
                if (!esHappy(j, base[i])){
                    sol = false;
                    break;
                }
            ++j;
        }
        cout << "Case #" << c << ": " << j-1 << endl;
    }
    return 0;
}