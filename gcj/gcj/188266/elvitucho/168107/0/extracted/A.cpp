#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<cmath>
#include<string>
#include<cstring>
#include<cctype>
#include<algorithm>
#include<vector>
#include<bitset>
#include<queue>
#include<stack>
#include<utility>
#include<list>
#include<set>
#include<map>
 
using namespace std;

#define eps 1e-9
#define INF INT_MAX
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).end(),(v).begin()
#define mp make_pair
#define pb push_back

#define SZ(v) ((int)(v).size())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)
#define REPE(i,n) FORE(i,0,n)
#define REPSZ(i,v) REP(i,SZ(v))
#define CLEAR(t) memset((t),0,sizeof(t))

typedef pair < int, int > pii;
typedef long long LL;
int memo[100000][11];
int visited[100000];
int sumq(int num, int base){
	int suma = 0;
	while(num>0){
		int d=num%base;
		suma+=(d*d);
		num = num/base;
	}
	return suma;
}
bool prueba(int num, int base){
	
	if(num==1) return true;
	//if(num<base) return false;
	if(memo[num][base]>-1) return memo[num][base];
	if(visited[num]) return false;
	visited[num]=1;
	memo[num][base]= prueba(sumq(num,base),base);
	return memo[num][base];
}
vector<int> getbases(string s){
	int num=0;
	vector<int> sol;
	REP(i,SZ(s)){
		if(s[i]==' '){
			if(num>0) sol.push_back(num);
			num=0;
		}else num = num*10+(s[i]-'0');
	}
	if(num>0) sol.push_back(num);
	return sol;
}
void run1(int caso){
	string s;
	getline(cin,s);	
	
	vector<int> bases = getbases(s);

	memset(memo,-1,sizeof(memo));
	
	int num = 2;
	while(true){
		bool cumple = true;
		
		for(int i=0;i<SZ(bases) && cumple;i++){
			memset(visited,0,sizeof(visited));
			cumple = cumple && prueba(num,bases[i]);
		}
		if(cumple) break;
		num++;

	}

	cout << "Case #"<<caso<<": "<< num<<endl;
}
int main()
{
	int T; scanf("%d",&T);
	string s;
	getline(cin,s);	
	FORE(i,1,T) run1(i);
	return 0;
}