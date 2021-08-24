#include <iostream>
#include<fstream>
#include<cstring>
using namespace std;
int main()
{
	
	freopen("bb.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int test;
	
	cin >> test;
	for(int z=0;z<test;z++)
		{
		int n,i;
		cin >> n;
		int a[2501]={0};
		int s[n];
		int c=0;
		for(int x=0;x<n*(2*n-1);x++)
		{
			cin >> i;
			a[i]++;
		}
		cout<<"Case #"<<(z+1)<<": ";
		for(int x=1;x<2500;x++)
		{
		if(a[x]%2==1)
		{
			cout<<x<<" ";
		}
	
		}
		cout<<endl;
}
}
