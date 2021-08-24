#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

int n;
int base[20];
int num[100000000];
int mark=1;

int solve(int b, int x) {
	mark++;
	while (1) {
		if (num[x]==mark) { return 0; }
		num[x]=mark;
		if (x==1) return 1;
		if (x==0) return 0;
		int s=0;
		while (x>0) {
			int d=x%b;
			x/=b;
			s+=d*d;
		}
		x=s;
	}
}

int main() {
	int t;
	ifstream fin("A-small-attempt0.in");
	FILE *fout=fopen("A-small-attempt0.out","w");
	fin >> t;
	string s;
	getline(fin,s);
	for (int test=1;test<=t;test++) {
		getline(fin,s);
		stringstream ss(s);
		int n=0;
		while (ss>>base[n]) { n++; }

		int x=2;
		while (1) {
			int ok=1;
			for (int b=0;b<n;b++) {
				if (solve(base[b],x)==0) { ok=0; break; }
			}
			if (ok) break;
			x++;
		}
		fprintf(fout,"Case #%d: %d\n",test,x);
	}
    return 0;
}
