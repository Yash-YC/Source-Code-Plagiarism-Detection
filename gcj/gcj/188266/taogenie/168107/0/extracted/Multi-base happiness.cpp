#include <fstream>
#include <iostream>
using namespace std;

int t;
int base[10];
int basenum;

bool ishappy(int num,int base)
{
	int i,n;
	int stack[10000];
	int index=0;
	int next;
	stack[index++]=num;
	while(1)
	{
		next=0;
		do
		{
			n=num%base;
			next+=n*n;
		}
		while((num/=base)!=0);
		if(next==1)
		{
			return true;
		}
		for(i=0;i<index;i++)
		{
			if(stack[i]==next)
			{
				return false;
			}
		}
		stack[index++]=next;
		num=next;
	}
}

int findhappy()
{
	int i;
	int num=1;
	bool isok;
	while(1)
	{
		num++;
		isok=true;
		for(i=0;i<basenum;i++)
		{
			if(!ishappy(num,base[i]))
			{
				isok=false;
				break;
			}
		}
		if(!isok)
		{
			continue;
		}
		return num;
	}
}

int main()
{
	ifstream fin("A-small-attempt0.in",ios::in);
	ofstream fout("output.txt",ios::out);
	int i,j,k;
	char tempstr[30];
	fin>>t;
	fin.get();
	for(i=0;i<t;i++)
	{
		fout<<"Case #"<<i+1<<": ";
		//in
		fin.getline(tempstr,30);
		for(j=0;j<10;j++)
		{
			base[j]=0;
		}
		k=0;
		for(j=0;j<strlen(tempstr);j++)
		{
			if(tempstr[j]<'0'||tempstr[j]>'9')
			{
				k++;
				continue;
			}
			base[k]*=10;
			base[k]+=tempstr[j]-'0';
			/*if(tempstr[j]>='0'&&tempstr[j]<='9')
			{
				base[k++]=tempstr[j]-'0';
			}*/
		}
		basenum=k+1;
		//out
		fout<<findhappy()<<endl;
	}
	system("pause");
	return 0;
}