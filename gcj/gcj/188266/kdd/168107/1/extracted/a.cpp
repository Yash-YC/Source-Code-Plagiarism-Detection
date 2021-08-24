#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
char line[10000];
int req[20];
int reqlen;

typedef set<int> MYSET;
MYSET s;

              
signed char f[100000000][12];

bool check(int now, int base) {
	//cout<<"*** "<<now<<' '<<base<<endl;
	
	if (f[now][base]!=-1) {
		if (f[now][base]==1) return true;
		else return false;
	}
	
	s.insert(now);
	int a=now,b,sum=0;
	while (a) {
		b=a%base;
		a=a/base;
		sum+=b*b;
	}
	bool res;
	//cout<<sum<<endl;
	
	if (sum==1) res=true;
	else if (s.find(sum)!=s.end()) res=false;
	else res=check(sum,base);
	if (res) {
		f[now][base]=1;
		s.erase(now);
		return true;
	}
	else {
		f[now][base]=0;
		s.erase(now);
		return false;
	}
	
	
}	
		
	


int main() {
	s.clear();
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	memset(f,0xff,sizeof(f));
	
	
	//for (int i=2;i<=10000;++i) if (check(i,4)) cout<<i<<endl;
	//return 0;
	int tn;
	//int a;
	scanf("%d ",&tn);
	for (int ti=1;ti<=tn;++ti) {
		reqlen=0;
		gets(line);
		char *pch=strtok(line," \n");
		while (pch) {
			int tmp;
			sscanf(pch,"%d",&tmp);
			++reqlen;
			req[reqlen]=tmp;

			//cout<<a<<endl;
			pch=strtok(0," \n");
		}
		//cout<<"hi"<<endl;
		int now=2;
		//cout<<req[1]<<endl;
		//cout<<req[2]<<endl;
		//cout<<reqlen<<endl;
		//break;
		
		while (1) {
			bool ok=true;
			s.clear();
			for (int i=1;i<=reqlen;++i) if (!check(now,req[i])) {
				ok=false;
				break;
			}
			if (ok) break;
			++now;
		}
		cout<<"Case #"<<ti<<": "<<now<<endl;
		
	}
	//cout<<check(3,2)<<endl;
	//cout<<"hi"<<endl;
	return 0;
}
