#pragma region MyTemplate
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> ivec;
typedef vector<string> svec;
typedef vector<double> dvec;
typedef pair<int,int> ipair;

#define For(i,a,b) for (ll i(a),_b(b); i <= _b; ++i)
#define Ford(i,a,b) for (lli(a),_b(b); i >= _b; --i)
#define Rep(i,n) for (ll i(0),_n(n); i < _n; ++i)
#define Repd(i,n) for (ll i((n)-1); i >= 0; --i)
#define Fill(a,c) memset(&a, c, sizeof(a))
#define MP(x, y) make_pair((x), (y))
#define All(v) (v).begin(), (v).end()
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

#define MAXCHILD 10
class TREE{
public:
	TREE():p(NULL),childno(0){
		chi = new TREE*[MAXCHILD];
	}
	int childno;
	TREE *p;
	TREE **chi;
	//other data member:
};
#pragma endregion

#define Max 100000
int T, baseno;
ivec base;
vector<ll> series;
int status[11][Max];
ifstream fin;
ofstream fout;

ll sqrsum(int j, ll i){
	int b = j;
	ll sum=0;
	while(i){
		sum += (i%b)*(i%b);
		i /= b;
	}
	return sum;
}


void process(int j, ll i){
	if(status[j][i]==-3){
		ll squaresum = sqrsum(j,i);
		if(squaresum == 1){
			status[j][i] = -1;
			Rep(k,series.size()){
				status[j][series[k]] = -1;
			}
			series.clear();
		}else{
			status[j][i] = -2;
			series.push_back(i);
			process(j,squaresum);
		}
	}
	if(status[j][i] == -2){
		series.clear();
		return;
	}
	if(status[j][i] == -1){
		Rep(k,series.size()){
			status[j][series[k]] = -1;
		}
		series.clear();
		return;
	}
}

ll findmin(){
	For(k,2,Max){
		bool flag = true;
		Rep(i,baseno){
			if(status[base[i]][k] != -1){
				flag=false;
				break;
			}
		}
		if(flag){
			return k;
		}
	}
	return Max;
}


int main(){
	fin.open("A-small-attempt1.in");
//	fin.open("test.txt");
	fout.open("small-result.txt");
//	fout.open("large-result.txt");

	Rep(i,11){
		Rep(j,Max){
			status[i][j]=-3;
		}
	}
	For(i,2,10){
		For(j,2,Max){
			process(i, j);
		}
	}

	string s;
	getline(fin,s);
	stringstream ss(s);
	ss>>T;
	For(caseid,1,T){
		base.clear();
		series.clear();

		//Read Input Data:		

		getline(fin,s);
		stringstream ss(s);
		int i;
		while(ss>>i){
			base.push_back(i);
		}
		baseno=base.size();

		//Compute:
		ll min = findmin();

		//Output:
		fout<<"Case #"<<caseid<<": "<<min<<endl;
	}
	fin.close();
	fout.close();
//	cin>>T;
}
