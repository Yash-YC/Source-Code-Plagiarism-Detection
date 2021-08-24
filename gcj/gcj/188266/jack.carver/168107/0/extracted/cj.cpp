#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int convert(int num,int base)
{
	int i=0,j,ans=0,arr[100];
	
	while(num)
	{
		arr[i++]=num%base;
		num/=base;
	}
	for(j=0;j<i/2;j++) swap(arr[j],arr[i-j-1]);
	for(j=0;j<i;j++) ans=10*ans+arr[j];
	return ans;
}

bool ishappy(int num,int base)
{
	int it=100;
	bool ok=false;
	
	while(it--)
	{
		if(num==1) {ok=true;break;}
		int new_num=0;
//		printf("%d\n",num);
		while(num)
		{
			new_num+=(num%10)*(num%10);
			num/=10;
		}
		num=convert(new_num,base);
	}
	return ok;
}

void process(string S,int *base,int &sz)
{
	sz=0;
	string t;
   stringstream ss(S);
   while (ss >> t)
   	base[sz++]=atoi(t.c_str());
}

int main()
{
	int cases,base[100],sz;
	
	string str;
	scanf("%d",&cases);

	getline(cin,str);
	for(int k=1;k<=cases;k++)
	{
		getline(cin,str);
		process(str,base,sz);
		int ans;
		for(ans=2;;ans++)
		{
			bool ok=true;
			for(int i=0;i<sz;i++)
				if(ishappy(convert(ans,base[i]),base[i])==false) ok=false;
			if(ok) break;
		}
		printf("Case #%d: %d\n",k,ans);
	}
	return 0;
}
