#include <iostream>
#include<fstream>
#include<cstring>
using namespace std;
int main()
{
	
	freopen("A-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int test;
	
	cin >> test;
	for(int z=0;z<test;z++)
		{
		string s;
		cin >> s;
		char c=s[0];
		string last="";
		last+=c;
		for(int x=1;x<s.length();x++)
		{
			c=last[0];
		if(s[x]<c)
		last+=s[x];
		else
		last=s[x]+last;
	}
	cout<<"Case #"<<(z+1)<<": "<<last<<endl ;
	}
    return 0;
}
