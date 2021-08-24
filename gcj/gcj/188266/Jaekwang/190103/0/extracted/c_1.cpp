#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <cassert>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <iomanip>
#include <cmath>
#include <functional>
using namespace std;

//#define TEST
#define USE_FILE

#define pb(x) push_back(x)
#define FOR(i,a,b) for(int i = (a); i < (b); ++i) 
#define RFOR(i,a,b) for(int i = (a); i > (b); --i) 

#define printval(x) cout << #x << " = " << (x) << endl;
#define printarray(x) \
	cout << #x << ": "; \
	for(int idx=0; idx<((x).size()); idx++) { cout << ((x)[idx]) << " "; } cout << endl;
#define printmatrix(x) \
	cout << #x << ": " << endl; \
	for(int idx=0; idx<((x).size()); idx++) { \
		for(int idx2=0; idx2<((x)[0].size()); idx2++) { cout << ((x)[idx][idx2]) << " "; } cout << endl; \
	} 

//string szfile_input = "sample.txt";
//string szfile_output = "sample_output.txt";

string szfile_input = "C-small-attempt2.in";
string szfile_output = "C-small-attemp2.out.txt";

//string szfile_input = "C-large-practice.in.txt";
//string szfile_output = "C-large-practice.out.txt";

double P[1000001];

class C_1 {
protected:
	vector<double> D;
	vector<int> V;
	double P;

public:
	void Run() {
#ifdef USE_FILE
		ifstream cin(szfile_input.c_str());
		ofstream cout(szfile_output.c_str());

#endif
		int ncase;
		cin >> ncase;

		int C, N;
		double value;
		FOR(i, 0, ncase) {
			cin >> C >> N;
			value = getExpect(C, N);
			cout.precision(8);
			cout << "Case #" << i+1 << ": " << fixed << value << endl;
			printf("Case #%d: %0.8lf\n", i+1, value);

		}
	}

	double getExpect(int C, int N) {
		D.clear();
		V.clear();

		double ret = 0.0;


		D.assign(1<<C, -1.0);
		D[(1<<C)-1] = 0.0;

		
		FOR(i, 0, (1<<C)) {
			int cnt = 0;
			FOR(j, 0, C) {
				if((i & (1<<j)) != 0) cnt++; 
			}
			if(cnt == N) {
				V.push_back(i);
			}
		}
		printval(V.size());

		P = 1.0 / (double)V.size();
		//printarray(V);
		printval(P);

		ret = Trace(0, N, 0);

		return ret;	
	}

	double Trace(int state, int N, int level) {
		if(D[state] != -1.0) return D[state];

		if(level >= 120) return 0.0;

		double ret = 0.0;
		FOR(i, 0, V.size()) {
			int nstate = state | V[i];
			//printval(nstate);
			ret += P* (1.0 + Trace(state | V[i], N, level+1));
		}
		
		D[state] = ret;

		return ret;
	}

	double nCr(int n, int r) {
		double ret = 1.0;
		FOR(i, n-r+1, n+1) ret*=i;
		FOR(i, 2, r+1) ret /= i;
		return ret;
	}
};

class MillionaireTest : public C_1 {
public:
	void Test() {
		printval(getExpect(2, 1));
		printval(getExpect(10, 6));
		printval(getExpect(3, 2));
	}
};

int main()
{
#ifdef TEST
	MillionaireTest cnt;
	cnt.Test();
#else
	C_1 cn;
	cn.Run();
#endif
	return 0;
}
