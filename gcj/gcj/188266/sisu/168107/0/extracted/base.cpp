#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <vector>
#include <cstdio>

using namespace std;

const int M=1<<20;

int arr[16][M];

vector<int> tmp;

bool happy(int n, int b)
{
asd:
//	printf("h: %d %d %d\n", n, b, arr[b][n]);
	if (arr[b][n]>=0) return arr[b][n];
	if (arr[b][n]==-2) return 0;
	int x=0;
	arr[b][n]=-2;
	tmp.push_back(n);
	while(n) {
		int k=n%b;
		x += k*k;
		n/=b;
	}
	n=x;
	goto asd;
}
bool happyx(int n, int b)
{
//	printf("jee\n");
	tmp.clear();
	int r=happy(n,b);
	for(unsigned i=0; i<tmp.size(); ++i)
		arr[b][tmp[i]] = r;
	return r;
}

int main(int argc, char* argv[])
{
	memset(arr, -1, sizeof(arr));
	for(int i=0; i<=10; ++i) arr[i][0]=0, arr[i][1]=1;
//	happy(10,10);return 0;
	int t;cin>>t; cin.ignore();
	string s;
	for(int a=0; a<t; ++a) {
		getline(cin, s);
		istringstream iss(s);
		int b;
		vector<int> vec;
		while(iss>>b) {
			vec.push_back(b);
		}
		for(int i=2; ; ++i) {
			bool ok=1;
			for(unsigned j=0; j<vec.size(); ++j) {
				if (!happyx(i, vec[j])) {
					ok=0;
					break;
				}
			}
			if (ok) {
				cout<<"Case #"<<a+1<<": "<<i<<'\n';
				break;
			}
		}
	}
}
