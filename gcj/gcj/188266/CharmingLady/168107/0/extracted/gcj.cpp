#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<fstream>
#include<set>
using namespace std;

int nums[10];
int c;

ifstream fcin("in.in");
ofstream fcout("out.out");

void readdata()
{
	string str;

	getline(fcin,str);
	while(str.length()==0)  getline(fcin,str);
	int tmp = 0;
	int i=0;
	int count=0; 
	while(i<str.length())
	{
		tmp = tmp * 10 + str[i]-'0';

		i++;
		if(str[i]==' '||i==str.length())
		{
			nums[count]=tmp;
			tmp=0; i++;
			count++;
		}
	}
	c=count;
}

bool isHappy(int num)
{
	int n = num;
	int sum = 0;
	set<int> s;
	s.clear();
	int tmp;
	while(true)
	{
		while(n>0)
		{
			tmp = n%10;
			sum += tmp * tmp;
			n/=10;
		}
		if(sum==1)  return true;
		if(s.find(sum)!=s.end())
		{
			s.insert(sum);
			n=sum;
		}
		else return false;
	}
}

bool deal(int base,int happy)
{
	int n = happy;
	int res = 0;
	set<int> s;
	s.clear();
	int tmp;
	while(true)
	{
		while(n>0)
		{
			tmp = n%base;
			res += tmp*tmp;
			n=n/base;
		}
		if(res==1) return true;
		
		if(s.find(res)!=s.end()) return false;
		else 
		{
			s.insert(res);
			n=res;
			res = 0;
		}
	}
}


int main()
{
	int i,j,T;
	

	fcin>>T;
	for(int cases = 1; cases<=T; cases++)
	{
		readdata();

	//	for(i=0;i<c;i++)
	//		fcout<<nums[i]<<endl;

		int happy = 2;
		while(true)
		{
			for(i=0;i<c;i++)
			{
				if(deal(nums[i],happy)==true) continue;
				else { happy++; break; }
			}
			if(i==c)
			{
				fcout<<"Case #"<<cases<<": "<<happy<<endl;
				break;
			}
		}
	}

	return 0;
}