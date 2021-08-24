#include<iostream>
#include<fstream>
#include<sstream>
#include<cstring>
#include<stdio.h>
#define MAX
using namespace std;
ifstream in("data.in");
//FILE*read1;
ofstream out("data.out");
class contest
{
	int bas[100];	
	int top;
public:
	contest();
	void process();
	bool judge(long long , int);
};
contest::contest()
{
/*	char s[1000];
	int st = -1;
	char ch;
	while((s[++st] = fgetc(read1))!= '\n')
	{
	//	cout<<s[st];
		//	s[++st] = ch;
	}
	s[st] = '\0';
	string temp(s);
*/
//	cout<<"hello"<<endl;
	char ch;
	char temp[100];
//	in.get(ch);	
	in.getline(temp, 100);
	string a(temp);
	int b;
	istringstream sin(a);
	top = -1;
	while(sin>>b)
	{
		bas[++top] = b;
	}

}
bool contest::judge(long long i,int b)
{
	long long temp;
	int mark[10000];
	for(int j = 1;j < 10000;j++)
	{
		mark[j] = 0;
	}
	while(i != 1)
	{
		temp = 0;
		while(i > 0)
		{
			temp += (i % b) * (i % b);
			i /= b;
			
		}
		i = temp;
		if(i < 10000)
		{
			if(mark[i] == 1)return false;
			mark[i] = 1;
		}
	}
	return true;
} 
void contest::process()
{
	long long i = 2;
	while(true)
	{
		int find = 0;
		for(int j = 0;j <= top;j++)
		{
			if(!judge(i, bas[j]))
			{	
				find = 1;
				break;
			}
			
		}
		if(find == 0)
		{
			cout<<i<<endl;
			out<<i<<endl;
			return ;
		}
		i++;
	}
}
void solve()
{
	class contest myobj;
	myobj.process();
}
int main()
{
//	read1= fopen("data.in", "r");
	int t;
	char c;
	char temp[100];
	in.getline(temp, 100);
	//in.get(c);
	istringstream sin(temp);
	sin>>t;
	int i = 1;
	while(i <= t)
	{
		out<<"Case #"<<i<<": ";
		cout<<"Case #"<<i<<": ";
		solve();
		i++;
	}
	return 0;
}
