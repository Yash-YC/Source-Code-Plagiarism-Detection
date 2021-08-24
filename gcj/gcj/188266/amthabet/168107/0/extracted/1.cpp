#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<sstream>
#include<map>
#include<algorithm>
using namespace std;

const int MAX = 3000001;
int vis[MAX];
int happy[MAX];

//map<pair<string,int>, bool> m;
//typedef map<pair<string,int>, bool>::iterator iter;

/*bool f(int num, int base)	{
	if(num>MAX) return 0;
	if(num==1) return 1;
	if(num==0) return 0;
	//if((vis[num]>>base)&1) return (happy[num]>>base)&1;
	string s="";
	int next=0, temp;
	for(int x=num;x;x/=base) {
		temp=x%base;
		s.push_back('0'+temp);
		next+=temp*temp;
	}
	reverse(s.begin(), s.end());
	sort(s.begin(), s.end());
	pair<string,int> p = make_pair(s,base);
	iter it = m.find(p);
	if(it!=m.end()) 
		return it->second;
	
	m[p];

	return m[p] = f(next,base);

}*/

bool f(int num, int base)	{
	if(num>MAX) return 0;
	if(num==1) return 1;
	if(num==0) return 0;
	if(vis[num] & (1<<base)) 
		return happy[num]& (1<<base);
	vis[num] = vis[num] | (1<<base);
	int next=0, temp;
	if(num==9 && base==7) {
		int z=0;
	}
	for(int x=num;x;x/=base) {
		temp=x%base;
		next+=temp*temp;
	}
	
	int ans = f(next,base);
	happy[num] = happy[num] | ( ans << base );
	return (happy[num]>>base)&1;
}

int main()	{

	freopen("a_small.in","rt",stdin);
	freopen("1_small.out","wt",stdout);

	memset(happy, 0, sizeof(happy));
	memset(vis, 0, sizeof(vis));

	for(int i=2;i<MAX;i++)
		for(int j=2;j<=10;j++)
			f(i,j);

	int t;
	cin>>t;
	string s;

	getline(cin,s);

	for(int tt=1;tt<=t;tt++)	{
	
		getline(cin,s);
		stringstream ss(s);
		int val;
		int base = 0;
		while(1)	{
			ss>>val;
			if(ss.fail()) break;
			base=base|(1<<val);
		}
		
		int ans=-1;
		for(int i=2;i<MAX;i++) if((happy[i]&base) == base)	{
			ans=i;
			break;
		}

		cout<<"Case #"<<tt<<": "<<ans<<endl;
	}

	return 0;
}
