#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>
#include <cmath>
#include <string>
using namespace std;

int T,cases=0;

int main()
{
	freopen("A-large.in","r",stdin);
	freopen("Aout.txt","w",stdout);
	scanf("%d",&T);
	while(T--){
		string s,ans;
		cin>>s;
		int len=s.size();
		for(int i=0;i<len;i++){
			if(i==0) ans=ans+s[0];
			else if(s[i]>=ans[0]) ans=s[i]+ans;
			else ans=ans+s[i];
		}
		cout<<"Case #"<<++cases<<": ";
		cout<<ans<<endl;
	}

	return 0;
}
