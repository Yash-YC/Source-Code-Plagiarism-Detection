#include <iostream>
#include<fstream>
#include <string>
#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include<math.h>
#include<sstream>
#include <algorithm>
using namespace std;
//ofstream fo("G:\\ASmallAns.txt",ios_base::out);
int a[11][1000] ={0};
void find(int x,int y)
{
	int z,i;
	while(a[x][y] == 0)
	{
		//cout<<y<<" ";
		a[x][y] =3;
		z=0;
		while(y!=0)
		{
			z=z+(y%x)*(y%x);
			y=y/x;
		}
		y=z;
	}
	if (a[x][y] == 3)
		a[x][y]=2;
	for (i=2;i<1000;i++)
		if (a[x][i]==3)
			a[x][i]=a[x][y];
	return;
}
int check(int x,int y)
{
	int z;
	z=0;
	while(y!=0)
	{
		z=z+(y%x)*(y%x);
		y=y/x;
	}
	return a[x][z]-1;
}
int main()
{
	int i,j,len,ans,t,n,m,ok;
	int num[15];
	char str[100];
	//ofstream fo("G:\\AaAns.txt",ios_base::out);
	memset(a,0,sizeof(a));
	for (i=2;i<=10;i++)
	{
		//cout<<i<<"::";
		a[i][0]=2;
		a[i][1]=1;
		for (j=2;j<1000;j++)
		{
			if (a[i][j] == 0)
				find(i,j);
		}
		//cout<<endl;
	}
	scanf("%d",&t);
	cin.getline(str,100-1);	
	for (n=1;n<=t;n++)
	{
		cin.getline(str,1000-1);
		//cout<<str<<endl;
		len =strlen(str);
		m=0;
		memset(num,0,sizeof(num));
		for (i=0;i<len;i++)
		{
			if (str[i]>='0'&&str[i]<='9')
				num[m]=num[m]*10+int(str[i]-'0');
			else
				m++;
		}
		m++;

		/*cout<<m<<endl;
		
		for (i=0;i<m;i++)
			cout<<num[i]<<" ";
		cout<<endl;*/
		

		ans=2;
		while(1)
		{
			ok=0;
			for (i=0;i<m;i++)
			{
				ok = check(num[i],ans);
				if (ok == 1)
					break;
			}
			if (ok==0)
				break;
			ans++;
		}

		//fo<<"Case #"<<n<<": "<<ans<<endl;
		printf("Case #%d: %d\n",n,ans);

	}	
	return 0;
}