#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>
#include<map>
using namespace std;
map<int,bool> mp;
int conv(int n,int b)
{
	int ret=0;
	int d;
	while(n>0)
	{
		d=n%b;
		ret=ret*10+d;
		n=n/b;
	}
	return ret;
}
int sos(int num)
{
	int ans=0;
	int d;
	while(num>0)
	{
		d=num%10;
		ans+=(d*d);
		num=num/10;
	}
	return ans;
}	
bool isHappy(int n,int b)
{
	if(sos(conv(n,b)) == 1)
		return true;
	if(mp[n]==true)return false;
	mp[n]=true;
	return isHappy(sos( conv(n,b) ),b);
}	
int main()
{
	ofstream fout("A.out");
	int T;		
	//ifstream fin("A.in");
	cin>>T;
	int i,j,k,b;
	bool flag;
	vector<int> v;
	string str;
	getline(cin,str);
	for(i=0;i<T;++i)
	{
		getline(cin,str);
		istringstream sin(str);
		v.clear();
	//	cout<<"I= "<<i<<endl;
		while(sin>>b)
		{
			v.push_back(b);
	//		cout<<b<<endl;
		}
		for(j=2;;++j)
		{
	//		cout<<j<<endl;
			flag=true;
			for(k=0;k<v.size();++k)
			{
				mp.clear();
				if(!isHappy(j,v[k]))
				{
					flag=false;
					break;
				}
			}
			if(flag)
			{
				fout<<"Case #"<<(i+1)<<": "<<j<<endl;
				break;
			}
		}
	}

	return 0;
}
