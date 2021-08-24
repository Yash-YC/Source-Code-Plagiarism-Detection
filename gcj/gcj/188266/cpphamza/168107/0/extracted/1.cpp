#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<deque>
#include<string>
#include<cctype>
#include<cmath>
#include<sstream>
#include<numeric>
#include<complex>
#include<queue>
#include<ext/hash_map>
using namespace std;
using namespace __gnu_cxx;

#define Big long long

struct hashItem{
	int operator()(const long long& n)const{
		return n%2000000037;
	}
};
struct eqItem{
	bool operator()(const  long long& it1, const  long long& it2)const{
		return it1 == it2;
	}
};

string get(int b1, int b2, string n){
	Big d = 0;
	for(int i = n.size()-1 ; i >= 0 ; i--){
		int g = (n[i] >= '0' && n[i] <= '9') ? n[i]-'0' : n[i]-'A'+10;
		d += g*(::pow(b1, n.size()-i-1)+1e-9);

		if(g >= b1)
			return "INVALID";
	}

	if(d == 0)
		return "0";

	string str = "";
	while(d > 0){
		int r = d%b2;
		if(r < 10)
			str += '0'+r;
		else
			str += 'A'+(r-10);
		d /= b2;
	}

	reverse(str.begin(), str.end());
	return str;
}

#define NUM_TYPE long long
struct Num{NUM_TYPE nVal;string sVal;Num(string str){sVal = str;istringstream stream(sVal);stream >> nVal;}Num(NUM_TYPE n){nVal = n;ostringstream stream(sVal);stream << fixed << n;sVal = stream.str();}};

int tob(int x, int b){
	Num n(x);
	string s = get(10, b, n.sVal);
	Num nn(s);
	return nn.nVal;
}

vector<int> v;

hash_map<Big, bool, hashItem, eqItem> table[100];

bool check(int x, int b){

	if(x == 1)
		return true;

	if(table[b].find(x) != table[b].end())
		return table[b][x];

	table[b][x] = 0;

	int y = x, xx = 0;
	while(y){
		int d = y%10;
		y /= 10;
		xx += d*d;
	}
	int a = tob(xx, b);

	return table[b][x] = check(a, b);
}

int main(){

	//freopen("1.in", "rt", stdin);
	//freopen("1.out", "wt", stdout);
	freopen("A-small-attempt0.in", "rt", stdin);
	freopen("A-small-attempt0.out", "wt", stdout);
	//freopen("A-large.in", "rt", stdin);
	//freopen("A-large.out", "wt", stdout);

	int tt; scanf("%d ", &tt);
	for(int t = 0 ; t < tt ; t++){

		v.clear();
		string line; getline(cin, line);
		stringstream st(line);
		while(true){
			int x; if(!(st>>x))break;
			v.push_back(x);
		}

		cout << "Case #" << t+1 << ": ";
		for(int x = 2 ; ; x++){

			bool ok = true;
			for(int i = 0 ; i < v.size() ; i++){
				int xx = tob(x, v[i]);
				if(!check(xx, v[i])){
					ok = false;
					break;
				}
			}
			if(ok){
				cout << x << endl;
				break;
			}
		}
	}

	return 0;
}
