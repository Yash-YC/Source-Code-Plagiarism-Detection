#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>


#define debug(x) cout << '>' << #x << ':' << x << '\n';
#define rep(X,Y,Z) for (int X = Y;X < Z;X++)
#define forn(X,Y) for (int X = 0;X < Y;X++)
#define sz(Z) Z.size()
#define all(W) W.begin(), W.end()
#define inf 2123123123LL
#define eps 0.0000001
#define vint vector<int>
#define forit(X,Y) for(typeof((Y).begin()) X = (Y).begin();X!=(Y).end();X++)
#define mp make_pair
#define I(M) (typeof((M).begin()))
#define pb push_back

typedef long long ll;
typedef long double ld;

using namespace std;

vector<string> split(string susu,char dudu) {
	susu += dudu;
	vector<string> raigeki;
	string water;
	forit(i,susu) {
		if ((*i) == dudu) {
			if (water != "") raigeki.push_back(water);
			water = "";
			continue;
			}
		water += (*i);
		}
	
	return raigeki;
	}
	

vector<int> vstrtovint (vector<string> abcdef) {
	vector<int> retvalue;
	for (int i = 0;i < abcdef.size();i++) {
		int temp;
		sscanf(abcdef[i].c_str(),"%d",&temp);
		retvalue.push_back(temp);
		}
	return retvalue;
	}
		
vector<int> strtovint (string susu,char dudu) {
	return vstrtovint(split(susu,dudu));
	}

int happy[10000001][12];
int touched[10000001][12];

int ishappy2(int abc,int def);

int ishappy(int abc,int xxx) {
	if (happy[abc][xxx] == 1) return 1;
	if (happy[abc][xxx] == 0) return 0;
	if (touched[abc][xxx]) {
		happy[abc][xxx] = 0;
		return 0;
		}
	touched[abc][xxx] = 1;
	int newa = 0;
	int def = abc;
	int ghi;
	while (def > 0) {
		ghi = def % xxx;
		def /= xxx;
		newa += (ghi * ghi);
		}
	happy[abc][xxx] = ishappy(newa,xxx);
	return happy[abc][xxx];
	}

int ishappy2(int abc,int def) {
	int angka = 0;
	while (abc > 0) {
		int ghi = abc % def;
		abc /= def;
		angka += (ghi * ghi);
		}
	
	return ishappy(angka,def);
	}

map< vector<int>,int >m;

int main() {
	memset(happy,-1,sizeof(happy));
	forn(i,11) happy[1][i] = 1;
	//debug(ishappy(7));
	//debug(ishappy2(3,2));
	//sdebug(ishappy2(3,3));
	int T;
	scanf("%d\n",&T);
	forn(z,T) {
		printf("Case #%d: ",z + 1);
		char hehe[100];
		scanf("%[^\n]\n",hehe);
		string la = hehe;
		vector<int> ang = strtovint(hehe,' ');
		if (m.find(ang) != m.end()) {
			printf("%d\n",m[ang]);
			continue;
			}
		for (int i = 2;;i++) {
			//if (!ishappy(i)) continue;
			int valid = 1;
			forn(j,sz(ang)) if (!ishappy2(i,ang[j])) {
				valid = 0;
				break;
				}
			if (valid) {
				m[ang] = i;
				printf("%d\n",i);
				break;
				}
			}
		}
	
	
	return 0;
	}

