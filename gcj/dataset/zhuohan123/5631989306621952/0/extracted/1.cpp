#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int T;cin>>T;
	for(int ti=1;ti<=T;ti++)
	{
		cout<<"Case #"<<ti<<": ";
		string str;cin>>str;
		string tstr;tstr+=str[0];
		for(int i=1;i<str.length();i++)
		{
			if(str[i]>=tstr[0])tstr=str[i]+tstr;
			else tstr+=str[i];
		}
		cout<<tstr<<endl;
	}
	return 0;
}
