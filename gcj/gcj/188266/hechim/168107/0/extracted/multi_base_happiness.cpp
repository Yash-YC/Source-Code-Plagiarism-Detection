#include <iostream>
#include <fstream>
using namespace std;

const int SIZE=1000*1000;
int happy[SIZE][11];
bool visited[SIZE];

int check(int x, int base)
{
	if(happy[x][base]==-1) {
		int b;		

		if(!visited[x]) {
			visited[x]=true;
			int digits[100]; int n=0;
			int q=x;
			while(q>0) {
				digits[n++]=q%base;
				q /= base;
			}

			int s=0;
			for(int i=0; i<n; i++)
				s += digits[i]*digits[i];

			if(s==1) b=1;
			else b=check(s,base);
		}
		else
			b=0;
		happy[x][base]=b;
	}
	visited[x]=false;
	return happy[x][base];
}


int main()
{
	for(int i=0; i<SIZE; i++) for(int j=0; j<11; j++) happy[i][j]=-1;

	ifstream fin("multi_base_happiness.in");
	ofstream fout("multi_base_happiness.out");

	int T; fin>>T;
	char ch; fin.get(ch);
	for(int t=1; t<=T; t++) {
		int bases[10]; int num=0;
		fin.get(ch);
		while(ch!='\n') {
			fin.putback(ch);
			fin>>bases[num++];
			fin.get(ch);
		}

		int x=1; bool found=false;
		while(!found) {
			x++;
			found=true;
			for(int i=0; i<num; i++) {
				if(check(x,bases[i])==0) {
					found=false;
					break;
				}
			}
		}
		fout<<"Case #"<<t<<": "<<x<<endl;
	}

	return 0;
}