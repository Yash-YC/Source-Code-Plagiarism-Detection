// pro1.cpp : main project file.

#include"vector"
#include"set"
#include"math.h"
#include"stdio.h"
#include"iostream"
#include"algorithm"
#include"list"
#include"string"
#include"map"

using namespace std;
//char arr[100];
long basen(long base10,int n)
{
	char arr[256];
	int k=0;
	for(long i=base10;i>0;)
	{
		arr[k]=(char)(i%n)+48;
		k++;
		i=i/n;
	}
	arr[k]=0;
	reverse(arr,arr+k);	
	long num=atoi(arr);
	return num;
}
long basetodec(long base,int n)
{
	long var=0,j=0;
	for(long i=base;i>0;)
	{
		var+=(i%10)*(long)pow((double)n,(int)j);
		j++;
		i=i/10;
	}
	return var;
}
long nextbasen(long num,int n)
{
	long num1=basetodec(num,n)+1;
	return basen(num1+1,n);
}
long check(long i,int n)
{
	set<int> arr;
	int num=0;
	arr.insert(i);
	i=basen(i,n);
	
	while(1)
	{
		num=0;
		for(long ii=i;ii>0;)
		{
			num+=(ii%10)*(ii%10);
			ii=ii/10;
		}
		if(arr.find(num)!=arr.end())
			return 0;
		if(num!=1)
			arr.insert(num);
		
		if(num==1)return 1;
		num=basen(num,n);
		i=num;
	}
}
int main()
{
    //cout<<basen(5,2);
	int n,m;
	cin>>n;
	n++;
	m=n;
	while(n--)
	{
		int arr[100],i1=0;
		int num=0;
		fflush(stdin);
		while(1)
		{


			char ch;
			ch=getc(stdin);
			if(ch=='\n')
				break;
			else
			{   ungetc(ch,stdin);
				scanf("%d",&arr[num++]);
			}
				
		}

			
		for(int i=2;;i++)
		{
			int k=0;
			for(k=0;k<num;k++)
			{
				if(check(i,arr[k])!=1)
					break;
			}
			if(k==num)
			{	
				if(n!=m-1)
					cout<<"Case #"<<m-n-1<<": "<<i<<endl;
				break;
			}
		}
	}
	return 0;
}
