
#include<algorithm>
#include<bitset>
#include<iostream>
#include<string>
#include<cstdio>
#include<sstream>
#include<vector>
#include<stack>
#include<deque>
#include<map>
#include<iterator>
#include<cmath>
#include<complex>
#include<queue>
#include<cassert>
#include<set>
#include<cstring>
#include<list>
#include<numeric>
#include<cassert>

#define FOREACH(it ,c ) for( typeof((c).begin()) it= (c).begin();it!=(c).end();++it) 
#define debug(x) cerr<< #x << " = " << x << "\n";
#define debugv(x) cerr<< #x << " = " ; FOREACH(it,(x)) cerr << *it << "," ; cerr<< "\n" ;
#define MP make_pair
#define PB push_back
#define siz(w) (int)w.size()
#define fup(i,st,ko) for(int i=st;i<=ko;i++)
#define fdo(i,st,ko) for(int i=st;i>=ko;i--)
#define REP(i,w) for(int i=0;i<siz(w);i++)
#define inf 100000000

using namespace std;

typedef long long ll;
#define maxn 12
int tab[maxn][maxn][maxn];

int main()
{
tab[2][3][3] = 3;
tab[2][3][4] = 3;
tab[2][3][5] = 23;
tab[2][3][6] = 79;
tab[2][3][7] = 143;
tab[2][3][8] = 27;
tab[2][3][9] = 3;
tab[2][3][10] = 13;
tab[2][4][4] = 2;
tab[2][4][5] = 5;
tab[2][4][6] = 6;
tab[2][4][7] = 7;
tab[2][4][8] = 8;
tab[2][4][9] = 3;
tab[2][4][10] = 7;
tab[2][5][5] = 5;
tab[2][5][6] = 49;
tab[2][5][7] = 7;
tab[2][5][8] = 27;
tab[2][5][9] = 27;
tab[2][5][10] = 7;
tab[2][6][6] = 6;
tab[2][6][7] = 49;
tab[2][6][8] = 216;
tab[2][6][9] = 415;
tab[2][6][10] = 44;
tab[2][7][7] = 7;
tab[2][7][8] = 1001;
tab[2][7][9] = 125;
tab[2][7][10] = 7;
tab[2][8][8] = 8;
tab[2][8][9] = 27;
tab[2][8][10] = 97;
tab[2][9][9] = 3;
tab[2][9][10] = 91;
tab[2][10][10] = 7;
tab[3][4][4] = 3;
tab[3][4][5] = 23;
tab[3][4][6] = 79;
tab[3][4][7] = 143;
tab[3][4][8] = 27;
tab[3][4][9] = 3;
tab[3][4][10] = 13;
tab[3][5][5] = 23;
tab[3][5][6] = 79;
tab[3][5][7] = 143;
tab[3][5][8] = 27;
tab[3][5][9] = 27;
tab[3][5][10] = 23;
tab[3][6][6] = 79;
tab[3][6][7] = 2207;
tab[3][6][8] = 3879;
tab[3][6][9] = 707;
tab[3][6][10] = 79;
tab[3][7][7] = 143;
tab[3][7][8] = 5719;
tab[3][7][9] = 143;
tab[3][7][10] = 167;
tab[3][8][8] = 27;
tab[3][8][9] = 27;
tab[3][8][10] = 219;
tab[3][9][9] = 3;
tab[3][9][10] = 91;
tab[3][10][10] = 13;
tab[4][5][5] = 5;
tab[4][5][6] = 49;
tab[4][5][7] = 7;
tab[4][5][8] = 27;
tab[4][5][9] = 27;
tab[4][5][10] = 7;
tab[4][6][6] = 6;
tab[4][6][7] = 49;
tab[4][6][8] = 216;
tab[4][6][9] = 415;
tab[4][6][10] = 44;
tab[4][7][7] = 7;
tab[4][7][8] = 1001;
tab[4][7][9] = 125;
tab[4][7][10] = 7;
tab[4][8][8] = 8;
tab[4][8][9] = 27;
tab[4][8][10] = 97;
tab[4][9][9] = 3;
tab[4][9][10] = 91;
tab[4][10][10] = 7;
tab[5][6][6] = 49;
tab[5][6][7] = 49;
tab[5][6][8] = 1975;
tab[5][6][9] = 415;
tab[5][6][10] = 49;
tab[5][7][7] = 7;
tab[5][7][8] = 1001;
tab[5][7][9] = 125;
tab[5][7][10] = 7;
tab[5][8][8] = 27;
tab[5][8][9] = 27;
tab[5][8][10] = 219;
tab[5][9][9] = 27;
tab[5][9][10] = 91;
tab[5][10][10] = 7;
tab[6][7][7] = 49;
tab[6][7][8] = 47089;
tab[6][7][9] = 2753;
tab[6][7][10] = 49;
tab[6][8][8] = 216;
tab[6][8][9] = 4977;
tab[6][8][10] = 608;
tab[6][9][9] = 415;
tab[6][9][10] = 1033;
tab[6][10][10] = 44;
tab[7][8][8] = 1001;
tab[7][8][9] = 6393;
tab[7][8][10] = 34527;
tab[7][9][9] = 125;
tab[7][9][10] = 1337;
tab[7][10][10] = 7;
tab[8][9][9] = 27;
tab[8][9][10] = 1177;
tab[8][10][10] = 97;
tab[9][10][10] = 91;

	int cas;
	cin >> cas;
	string s;
	getline(cin, s);
	fup(i, 1, cas)
	{
		string s;
		getline(cin, s);
		stringstream x;
		x << s;
		vector<int> vek;
		int number;
		while(x >> number)
		{
			vek.push_back(number);
		}
		cout <<"Case #" << i << ": ";
		if(siz(vek) == 2)
		{
			cout << tab[vek[0]][vek[1]][vek[1]] << endl;
		}
		else
		{
			cout << tab[vek[0]][vek[1]][vek[2]] << endl;
		}
	}

	return 0;
}



