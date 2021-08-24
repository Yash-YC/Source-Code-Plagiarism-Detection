#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <set>
#include <map>

using namespace std;

#define TASK "file"
int S[20];
int test;
int f[1000000];
int mark;
map<int,int> Set;
int c[1000];

int check(int num,int base){
	c[0]=0;
	f[num]=mark;
	while (true){
		//cout<<num<<" ";
		c[0]=0;
		while (num>0){
			c[++c[0]]=num%base;
			num/=base;
		}
		num=0;
		for (int i=1;i<=c[0];i++){
			num+=c[i]*c[i];
		}
		
		if (num==1) return true;
		if (f[num]==mark) return false;
		f[num]=mark;
		//cout<<"- ";
	}
}

int fucking(void){
	int num=1;
	while (true){
		num++;
		
		int f=1;
		for (int i=1;i<=S[0];i++){
			//Set.clear();
			mark++;
			if (!check(num,S[i])){
				f=0;
				break;
			}
			//cout<<endl;
		}
		if (f) return num;
	}
}

int main(void){
	freopen(TASK".in","r",stdin);
	freopen(TASK".out","w",stdout);
	scanf("%i\n",&test);
	mark=0;
	for (int z=0;z<test;z++){
		string s;
		getline(cin,s);
		stringstream ss(s);
		S[0]=0;
		int dum;
		while (ss>>dum){
			S[++S[0]]=dum;
		}
		printf("Case #%i: ",z+1);
		int ans=0;
		ans=fucking();
		printf("%i\n",ans);		
	}

	return 0;
}