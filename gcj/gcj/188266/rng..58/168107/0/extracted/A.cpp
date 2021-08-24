#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define split(str) {vs.clear();istringstream ss(str);while(ss>>(str))vs.push_back(atoi(str.c_str()));}
template <class T> inline string itos(T n) {return (n)<0?"-"+itos(-(n)):(n)<10?(string)("")+(char)('0'+(n)):itos((n)/10)+itos((n)%10);}
#define gcj_print(ans) {cout << "Case #" << ((test)+1) << ": " << (ans) << endl;}

#define N 1000000
bool happy[12][N+10];

char _ch[100];

int func(int n, int b){
	int ans = 0;
	while(n > 0){
		ans += (n%b) * (n%b);
		n /= b;
	}
	return ans;
}

int main(void){
	int b,i,j,ans,T,test;
	
	for(b=2;b<=10;b++) REP(i,N){
		if(i >= 1000){
			happy[b][i] = happy[b][func(i,b)];
		} else {
			int tmp = i;
			REP(j,1010) tmp = func(tmp,b);
			happy[b][i] = (tmp == 1);
		}
	}
	
	cin >> T;
	cin.getline(_ch,sizeof(_ch));
	REP(test,T){
		cin.getline(_ch,sizeof(_ch));
		string str = _ch;
		vector <int> vs; split(str);
		for(ans=2;ans<N;ans++){
			REP(i,vs.size()) if(!happy[vs[i]][ans]) break;
			if(i == vs.size()) break;
		}
		gcj_print(ans);
	}
	
	return 0;
}
