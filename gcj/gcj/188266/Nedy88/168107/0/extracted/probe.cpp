#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <sstream>
using namespace std;

ifstream fin("a.in");
ofstream fout("a.out");

bool used[1000000];

int A[10][10];

int base;
int step[10];

int solve(int x) {
    if(x==1)return 1;
    used[x] = 1;
    int n = x;
    int tmp = 0;
    while(n>0) {
	tmp += step[n%base];
	n/=base;
    }
    if(tmp>=1000000)cout<<"Failed"<<endl;
    if(used[tmp])return 0;
    else return solve(tmp);
}

int main() {
    int i,j,k;
    for(i=0;i<10;++i)step[i] = i*i;
    int T,t;
    string line;
    getline(fin,line);
    stringstream sin;
    sin<<line;
    sin>>T;
    vector<int> vec;
    for(t=1;t<=T;++t) {
	vec.clear();
	getline(fin,line);
	sin.clear();
	sin<<line;
	int tmp;
	while(sin>>tmp) {
	    vec.push_back(tmp);
	}
	int ret = 1;
	for(i=2;;++i) {
	    bool ok = true;
	    for(j=0;j<vec.size();++j) {
		for(k=0;k<1000000;++k)used[k]=0;
		base = vec[j];
		if(!solve(i)){ok=false;break;}
	    }
	    if(ok){ret=i;break;}
	}
	fout<<"Case #"<<t<<": "<<ret<<endl;
    }
    return 0;
}
