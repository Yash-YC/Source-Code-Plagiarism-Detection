#include<cstdio>
#include<climits>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<sstream>
#include<cassert>
#include<complex>

#define FOR(a , b , c) for(int a = (int)b; a<=(int)c; a++)
#define FORD(a , b , c) for(int a = (int)b; a>=(int)c; a--)
#define pb push_back
#define mk make_pair
#define sz(v) ((int)(v).size())
#define all(v) v.begin() , v.end()
#define set(x, with) memset(x , with , sizeof(x))
#define same(a,b) (fabs((a)-(b))<0.000000001)
#define even(a) ((a) % 2 == 0)
#define odd(a) ((a) % 2 == 1)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int , int> ii;

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

const int MaxQ = 100000;
const int MaxNum = 100000;
int Queue[MaxQ + 1];
int happyset[11][MaxNum + 1];

bool ishappy(int num, int base){
	int cnt = 0 , l = 1;
	if(num <= MaxNum && happyset[base][num]){
		return happyset[base][num] == 1;
	}
//	cerr << num << endl;
	Queue[l] = num;
//	cerr << Queue[1] << endl;
	bool happy = true;
	if(num <= MaxNum) happyset[base][num] = -1;
	vi tmp;
//	cerr << Queue[1] << endl;
	while(cnt != l){
		cnt++;
		if(cnt > MaxQ) cnt = 1;
		int num = Queue[cnt];
		if(num <= MaxNum){
			tmp.pb(num);
		}
		if(num == 1) break;
//		cerr << base << ' ' << num << ' ';
		int nextnum = 0;
		while(num > 0){
			int t = num % base;
			num /= base;
			nextnum += t * t;
		}
//		cerr << nextnum << endl;
		if(nextnum <= MaxNum && happyset[base][nextnum]){
			if(happyset[base][nextnum] != 1){
				happy = false;
			}
			break;
		} else{
			l++;
			if(l > MaxQ) l = 1;
			Queue[l] = nextnum;
			if(nextnum <= MaxNum){
				happyset[base][nextnum] = -1;
			}
		}
	}
	int val;
	if(happy){
		val = 1;
	} else{
		val = -1;
	}
//	cerr << base << ' ' << num << ' ' << val << endl;
	FOR(i, 0, tmp.size() - 1){
		happyset[base][tmp[i]] = val;
	}
	return (val == 1);
}

int main(void){
	int C;
	cin >> C;
	FOR(k, 1, C){
		string str;
		getline(cin, str);
		while(str.size() == 0){
			getline(cin, str);
		}
		vi bases;
		{
			stringstream ss;
			ss << str;
			while(!ss.eof()){
				int b;
				ss >> b;
				bases.pb(b);
			}
			sort(all(bases));
			reverse(all(bases));
		}
		int i;
		for(i=2; i>0; i++){
			int j;
			for(j=0; j<bases.size(); j++){
				if(!ishappy(i, bases[j])) break;
			}
			if(j == bases.size()) break;
		}
		cout << "Case #" << k << ": " << i << endl;
	}
	return 0;
}
