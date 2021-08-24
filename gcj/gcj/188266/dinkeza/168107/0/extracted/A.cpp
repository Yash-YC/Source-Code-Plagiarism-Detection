#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <queue>

using namespace std;
int T;
vector<int> bases;
char s[64];
set<int> used;
char digits[64];
void parse()
{
	bases.clear();
	
	for(int i=0;s[i]!=0;i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			if(s[i+1]>='0' && s[i+1]<='9')
			{
				bases.push_back(  (s[i]-'0')*10 + (s[i+1]-'0') );
				i++;
			}
			else bases.push_back( s[i]-'0');
		}	
	}
	
//	for(int i=0;i<bases.size();i++) cout<<bases[i]<<" ";cout<<endl;
}

bool isHappy(int num,int base)
{
	used.clear();
	
	while(used.find(num)==used.end())
	{
		if(num==1) return true;
		used.insert(num);
		memset(digits,0,sizeof(digits));
			itoa(num,digits,base);
		
		num=0;
		for(int i=0;digits[i]!=0;i++)
			num+=(digits[i]-'0')*(digits[i]-'0');
		
	}
	return false;
}
int main(int argc,char* argv[])
{
	freopen(argv[1],"r",stdin);
	freopen("G:\\Documents and Settings\\ivan\\Desktop\\A.out","w",stdout);
	scanf("%d",&T);	
	gets(s);
	for(int i=1;i<=T;i++)
	{
			memset(s,0,sizeof(s));
			gets(s);
			parse();
			for(int j=2;;j++)
			{
				bool flag = true;
				for(int k=0;k<bases.size();k++)	
					flag = (flag && isHappy(j,bases[k]));
				if(flag)
				{
					cout<<"Case #"<<i<<": "<<j<<endl;
					break; 	
				}
			}
	}
	
	
}
