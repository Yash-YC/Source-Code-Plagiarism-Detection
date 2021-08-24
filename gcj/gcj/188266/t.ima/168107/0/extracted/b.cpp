#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

const int N = 200000;
const int NIL = 0;
const int TRUE = 1;
const int FALSE = -1;

int T;

vector<vector<int> > tab;

template<typename T>
inline void resize(vector<vector<T> > &v, int X, int Y){
    v.resize(X); for(int x = 0; x < X; ++x) v[x].resize(Y);
}


int nxt(int k, int b){
    int n = 0;
    while(k > 0){
	int i = k % b;
	n += i * i;
	k /= b;
    }
    return n;
}

void gen(int b){
    for(int i = 2; i < N; ++i){
	vector<bool> a(N, false);
    	vector<int> z;
	int k = i;
	while(!a[k]){
	    if(tab[b][k] != NIL){
		a[1] = (tab[b][k] == TRUE ? true:false);
		break;
	    }
	    a[k] = true;
	    z.push_back(k);
	    k = nxt(k, b);
	}
	for(size_t i = 0; i < z.size(); ++i){
	    if(a[z[i]]){
		tab[b][z[i]] = a[1] ? TRUE:FALSE;
	    }
	}
    }
}

int main(void){
    cin >> T;
    resize(tab, 11, N);
    for(int i = 2; i <= 10; ++i) gen(i);
    string tmp;
    getline(cin, tmp);
    for(int i = 0; i < T; ++i){
	string buf;
	getline(cin, buf);
	istringstream is(buf);
	vector<int> base;
	int b;
	while(is >> b) base.push_back(b);
#if 0
	for(size_t k = 0; k < base.size(); ++k){
	    int b = base[k];
	    cout << b << " ";
	    cout << endl;
	}
#endif
	for(int j = 2; j < N; ++j){
	    bool found = true;
	    for(size_t k = 0; k < base.size(); ++k){
		int b = base[k];
		if(tab[b][j] != TRUE){
		    found = false;
		    break;
		}
	    }
	    if(found){
		cout << "Case #" << (i + 1) << ": " << j << endl;
		break;
	    }
	}
    }

    return 0;
}
