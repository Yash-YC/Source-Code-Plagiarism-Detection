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
int i=0,s=v.size();for(;i+1<s;i++)o<<v[i]<<", ";if(s)o<<v[i];o<<"}";return o;}
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
	string file("C");
	filename << file << "-small.";
	fnamein << filename.str() << "in"; fnameout << filename.str() << "out"; 
	ifstream fin(fnamein.str().c_str()); ofstream fout(fnameout.str().c_str());
	int count; fin >> count;
	for(int i=0;i<count;i++) { fout << "Case #" << (i+1) << ": ";
		calc(fin, fout); fout.flush(); }
	fin.close(); fout.close(); }

void calc(ifstream &fin, ofstream &fout)
	{
	int C, N;
	fin >> C >> N;
	int rd=0;
	vector<double> poss(C);
	vector<vector<double> > good(C+1, vector<double>(C+1));
	good[0][N]=1.0;

	for(int i=1;i<=C;i++)
		{
		vector<double> calc(C+1);
		calc[0]=1.0;
		for(int p=0;p<N;p++)
			{
			vector<double> ncalc(C+1);
			for(int g=0;g<=p;g++)
				{
				if(i-p+g>0)
					ncalc[g] += calc[g] * (0.0+i-p+g)/(0.0+C-p);
				if(C-i-g>0)
					ncalc[g+1] += calc[g] * (0.0+C-i-g)/(0.0+C-p);
				}
			calc=ncalc;
			}
		good[i] = calc;
		}
	cout << good << endl;

	poss[0]=1.0;
	double posssum=1;
	double out=0;
	while(posssum > 0.0000001)
		{
		cout << poss << endl;
		rd++;
		vector<double> poss2(C);
		for(int i=0;i<poss.size();i++)
			{
			for(int j=0;j<=N;j++)
				{
				if(i+j>=C)
					out+=rd*good[i][j]*poss[i];
				else
					poss2[i+j]+=good[i][j]*poss[i];
				}
			}

		poss=poss2;
		posssum=0.0;
		for(int i=0;i<C+1;i++)
			posssum+=poss[i];
		}
	fout << out << endl;

	return; 
	}
