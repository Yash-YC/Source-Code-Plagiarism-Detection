/* Brian's GCJ entries */
#include <vector>
#include <iterator>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;
int bitct(long long r) {return r == 0 ? 0 : (bitct(r>>1) + (r&1));}
long long gcd(long long x, long long y) {return x ? gcd(y%x,x) : y;}
template<typename T> ostream& operator << (ostream &o,vector<T> v){o<<"{";
int i=0,s=v.size();for(;i+1<s;i++)o<<v[i]<<", ";if(s)o<<v[i];o<<"}\n";return o;}
long long choose(long long n, long long q)
{ if(n==0 || q==0) return 1;
	if (q==1) return n; else return ( choose(n, q-1) * (n-q+1 ) /q); }
#define foreach(i,c) for(typeof((c).begin()) i=(c).begin();i!=(c).end();++i)
#define FOR(i,a,b) for(typeof(a) i=(a); i < (b); ++i)
//int dx[8] = {0,  1,  1,  1,  0, -1, -1, -1}
//int dy[8] = {1,  1,  0, -1, -1, -1,  0,  1}
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void calc(ifstream &, ofstream &);
main() {
	stringstream filename, fnamein, fnameout;
	string file("B");
	filename << file << "-small.";
	fnamein << filename.str() << "in"; fnameout << filename.str() << "out"; 
	ifstream fin(fnamein.str().c_str()); ofstream fout(fnameout.str().c_str());
	int count; fin >> count;
	for(int i=0;i<count;i++) { fout << "Case #" << (i+1) << ": ";
		calc(fin, fout); fout.flush(); }
	fin.close(); fout.close(); }

void calc(ifstream &fin, ofstream &fout)
	{
	int R, C;
	fin >> R >> C;
	vector<vector<int> > 
		S(R, vector<int>(C)),
		W(R, vector<int>(C)),
		T(R, vector<int>(C));

	for(int i=0;i<R;i++)
		for(int j=0;j<C;j++)
			{
			int s,w,t;
			fin >> s >> w >> t;
			S[R-1-i][j] = s;
			W[R-1-i][j] = w;
			T[R-1-i][j] = t%(s+w);
			}

	vector<vector<int> > board(R*2, vector<int>(C*2, -1));
	int round=0;
	board[0][0]=0;
		//cout << " " << board << endl;
	while(round<R*4+C*4+10)
		{
		round++;
		for(int i=0;i<R*2;i++)
			for(int j=0;j<C*2;j++)
				{
				if(-1 != board[i][j]) 
					{
					if(1==i%2 && i+1 < R*2 && 
							(-1 == board[i+1][j] || board[i][j]+2 < board[i+1][j]))
						{
						round=0;
						board[i+1][j]=board[i][j]+2;
						}
					if(1==j%2 && j+1 < C*2 && 
							(-1 == board[i][j+1] || board[i][j]+2 < board[i][j+1]))
						{
						round=0;
						board[i][j+1]=board[i][j]+2;
						}
					if(1==i%2 && i+1 < R*2 && board[i+1][j] != -1 &&
							(-1 == board[i][j] || board[i+1][j]+2 < board[i][j]))
						{
						round=0;
						board[i][j]=board[i+1][j]+2;
						}
					if(1==j%2 && j+1 < R*2 && board[i][j+1] != -1 &&
							(-1 == board[i][j] || board[i][j+1]+2 < board[i][j]))
						{
						round=0;
						board[i][j]=board[i][j+1]+2;
						}
					}
				}
		cout << " " << board << endl;
		for(int i=0;i<R*2;i++)
			for(int j=0;j<C*2;j++)
				if(-1 != board[i][j])
					{
					if(0==i%2)
						{
						int mytime = board[i][j] +(S[i/2][j/2]+W[i/2][j/2]) -T[i/2][j/2];
						mytime = (mytime)%(S[i/2][j/2]+W[i/2][j/2]);
						int delay=1;
						if(mytime<S[i/2][j/2])
							delay=1;
						else
							delay=1+((S[i/2][j/2]+W[i/2][j/2]) - mytime);
						if(-1 == board[i+1][j] || delay+board[i][j] < board[i+1][j])
							{
							board[i+1][j] = delay+board[i][j];
							round=0;
							}
						if(-1 != board[i+1][j] &&
								(-1 == board[i][j] || delay+board[i+1][j] < board[i][j]))
							{
							board[i][j] = delay+board[i+1][j];
							round=0;
							}
						}

					if(0==j%2)
						{
						int mytime = board[i][j] +(S[i/2][j/2]+W[i/2][j/2]) -T[i/2][j/2];
						mytime = (mytime)%(S[i/2][j/2]+W[i/2][j/2]);
						int delay=1;
						if(mytime>=S[i/2][j/2])
							delay=1;
						else
							delay=1+(S[i/2][j/2] - mytime);
						if(-1 == board[i][j+1] || delay+board[i][j] < board[i][j+1])
							{
							board[i][j+1] = delay+board[i][j];
							round=0;
							}
						if(-1 != board[i][j+1] &&
								(-1 == board[i][j] || delay+board[i][j+1] < board[i][j]))
							{
							board[i][j] = delay+board[i][j+1];
							round=0;
							}
						}

					}
				
		cout << board << endl;

		}

	fout << board[2*R-1][2*C-1] << endl;
	return; 
	}
