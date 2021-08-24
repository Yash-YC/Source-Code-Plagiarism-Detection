#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
#define FOR(i,n) for(i=0;i<n;i++)
#define VI vector<int>
#define FORR(i,a,b) for(i=a;i<b;i++)
#define pb(a) push_back(a)
ifstream fin("A.in.txt");
ofstream fout("A.txt");

int next(int l, int k) {
	int p = 0;
	while (l) {
		p += (l%k)*(l%k);
		l/=k;
	}
	return p;
}

#define MAX 100000
int a[MAX][10];

int main() {
	char s[100];
	int i,j,k,l,n,m,p,r,t;
	memset(a,0,sizeof(a));
	FORR(j, 2, 11) a[1][j] = 1;
	FORR(j, 2, 11)
		FORR(i, 2, MAX) if (!a[i][j]) {
			k = i;
			while (!a[k][j]) {
				a[k][j] = 3;
				k = next(k, j);
			}
			l = a[k][j]==1?1:2;
			k = i;
			while (a[k][j] == 3) {
				a[k][j] = l;
				k = next(k, j);
			}
	}
	VI b;
	fin >> r;fin.getline(s,100);
	FORR(t, 1, r+1) {
		fin.getline(s,100);
		istringstream sin(s);
		b.clear();
		while (sin >> k) {
			//fout << k << " ";
			b.pb(k);
		}
		FORR(i, 2, MAX) {
			bool f = true;
		  FOR(j, b.size()) {
			  if (a[i][b[j]] == 2)  { f = false; break; }
		  }
		  if (f) { fout << "Case #"<< t << ": " << i << endl;break;}
		}
		//fout << endl;
	}
}