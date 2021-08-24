#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define FOR(i,n) for((i)=0;(i)<(n);(i)++)
#define FORN(i,n) for((i)=(n)-1;(i)>=0;(i)--)
#define _FORIT(it, b, e) for (__typeof(b) it = (b); it != (e); it++)
#define FORIT(x...) _FORIT(x)
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define SI(a) ((a).size())
#define PB push_back
#define MP make_pair
#define CLR(a,v) memset((a),(v),sizeof(a)) 
#define TLE while(1);
#define RTE printf("%d", 1/0);

using namespace std;
typedef vector<int> VI; typedef vector<double> VD; typedef vector<string> VS;
typedef vector<vector<int> > VVI; typedef vector<vector<string> > VVS;
typedef set<int> SI; typedef set<double> SD; typedef set<string> SS;
typedef pair<int,int> PII;
typedef signed long long i64; typedef unsigned long long u64;

#define EPS 1E-14
#define INF 0x3F3F3F3F
#define DINF 1E16
#define NULO -1

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}


VI bases;

VI itob(int n, int b = 10) {
    int j;
    VI num;
    int i = 0;
    do { j = n%b; num.PB(j); } while ((n/=b) != 0);
    return num;
}

void print_base(VI &num) {
    int i; FOR(i, SI(num)) printf("%d ", num[i]); putchar('\n');
}

/*******************************************************************************
 * Separa uma string s em tokens definidos pelos caracteres em ch. */
vector<string> tokenize(string s, string ch) {
  vector<string> ret;
  for(int p = 0, p2; p < SI(s); p = p2+1) {
    p2 = s.find_first_of(ch, p);
    if(p2 == -1) p2 = SI(s);
    if(p2-p > 0) ret.PB( s.substr(p, p2-p));
  }
  return ret;
}

/*******************************************************************************
 * Separa em tokens e retorna um vetor de inteiros. */
VI tokint(string s, string ch) {
  VI ret;
  VS t = tokenize(s, ch);
  for(int i = 0; i < t.size(); i++) ret.PB(atoi(t[i].c_str()));
  return ret;
}


int happy(int num) {
    int i, j; VI val;
    int found[100000];
    int s;
    FOR(i, SI(bases)) {
        val = itob(num, bases[i]); CLR(found, 0); found[num] = 1;
        while (1) {
            s = 0; FOR(j, SI(val)) s += val[j]*val[j];
            if (s==0 || found[s]) return 0;
            if (s==1) break; found[s] = 1;
            val = itob(s, bases[i]);
        } 
    }
    return 1;
}



int main() {

    char str[100];
    int i, c, t;
    scanf("%d ", &t);
    for (c = 1; c <= t; c++) {
        printf("Case #%d: ", c);
        gets(str);
        bases = tokint(str, " ");
        for (i = 2; ; i++) if (happy(i)) { printf("%d\n", i); break; }
    }
    
    return 0;
}
