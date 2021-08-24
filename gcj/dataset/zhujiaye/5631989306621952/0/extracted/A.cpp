#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

string s;
int Q;
int main(){
	freopen("i.txt","r",stdin);
	cin>>Q;
	for (int testcase=1;Q--;testcase++){
		cout<<"Case #"<<testcase<<": ";
		cin>>s;
		string ans="";
		for (int i=0;i<s.size();i++){
			string t1,t2;
			t1=ans+s[i];
			t2=s[i]+ans;
			if (t1>t2)
				ans=t1;
			else
				ans=t2;
		}
		cout<<ans<<endl;
	}
	return 0;
}
