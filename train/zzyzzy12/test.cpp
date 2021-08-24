#include <iostream>
#include <cstdio>
using namespace std;
string s,ans;
int main(){
	int T;
	freopen("A-large.in.txt","r",stdin);
	freopen("A-large.in.out","w",stdout);
	cin>>T;
	for (int cases=1;cases<=T;cases++){
		cin>>s;
		ans=s[0];
		for (int i=1;i<s.length();i++){
			char a=ans[0],c=s[i];
			if (c>=a) ans=c+ans;
			     else ans=ans+c;
		}
		cout<<"Case #"<<cases<<": "<<ans<<endl;
	}
	return 0;
}