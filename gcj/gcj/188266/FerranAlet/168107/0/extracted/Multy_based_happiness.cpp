//Done by Grey Matter
//Fet per Ferran Alet

#include<iostream>
#include<cmath>
#include<iomanip>
#include<vector>
#include<map>
#include<queue>
#include<fstream>
#include<algorithm>
#include<string>
#include<stack>
#include<numeric>
#include<set>
#include<sstream>

#define INF 2147483647
#define LINF 1000000000000000000LL
#define EPS 1e-9
#define debug(x) cerr << #x << " = " << x << endl
#define FORN(x,y) for(int x=0;x<y;x++)
#define FORU(x,y) for(int x=1;x<=y;x++)
using namespace std;


typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<char> VB;
typedef vector<VB> VVB;
typedef vector<string> VS;
typedef map<int,int> MII;
typedef MII::iterator iMII;
typedef long long ll;

map<pair<long long,int>, char> M;

ifstream fin("A.in");
ofstream fout("A.out");

bool happy(long long n, int base,VB &v){
//	cout<<n<<' '<<base<<endl;
	if(n==1) return true;
	if(v[n]) return false;
	if(M.find(make_pair(n,base))!=M.end()) return M[make_pair(n,base)];
	int cont=0;
	v[n]=true;
	while(n>0){
		cont+=((n%base)*(n%base));
		n/=base;
	}
	return M[make_pair(n,base)]=happy(cont,base,v);
}

int main() {
	int T,nnn;
	fin>>T;
	string linia;
	getline(fin,linia);
	for(int cas=1;cas<=T;cas++){
		getline(fin,linia);
		VI v;
		stringstream ss;
		ss<<linia;
		while(ss>>nnn) v.push_back(nnn);
		int n=v.size();
		for(long long i=2;1;i++){
			bool superhappy=true;
			for(int j=n-1;j>=0;j--){
				VB vb(100000);
				if(!happy(i,v[j],vb)){superhappy=false; break;}
			}
			if(superhappy){
				fout<<"Case #"<<cas<<": "<<i<<endl;
				break;
			}
		}
	}
}
