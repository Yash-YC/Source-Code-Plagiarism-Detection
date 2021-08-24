// Round1A.cpp : Defines the entry point for the console application.
//

#include <vector>
#include <string>
#include <set>
#include <stdio.h>

using namespace std;

#define maxhappy 1000000LL
typedef long long int64;

set<int64> happy[11];//base 2 and 4 all are happy

int64 fix(int64 n,int64 b)
{
	int count[10];
	memset(count,0,sizeof(count));
	while (n>0)
	{
		count[n%b]++;
		n/=b;
	}
	int64 pot=1;
	int64 res=0;
	for (int64 i=b-1;i>0;i--)
	{
		while(count[i]>0)
		{
			res+=pot*i;
			pot*=b;
			count[i]--;
		}
	}
	return res;
}

int64 convert(int64 n,int64 b)
{
	int64 res=0;
	while (n>0)
	{
		int64 digit=n%b;
		n/=b;
		res+=digit*digit;
	}
	return fix(res,b);
}

void searchhappy(void)
{
	for (int64 b=3;b<11;b++)
	{
		if (b==2)
		{
			continue;
		}
		if (b==4)
		{
			continue;
		}
		happy[b].insert(1);
		for (int64 i=2;i<maxhappy;i++)
		{
			int64 x=fix(i,b);
			if (x<i)
			{
				//lower then, not a basic
				continue;
			}
			if (x==i)
			{
				//is a basic number, follow the process
				set<int64> visited;
				visited.insert(x);
				while (true)
				{
					int64 y=convert(x,b);
					if (y<i)
					{
						if (happy[b].count(y)>0)
						{
							happy[b].insert(i);
						}
						break;
					}
					else if (visited.count(y)>0)
					{
						break;
					}
					visited.insert(y);
					x=y;
				}
			}
			else
			{
				printf("Error");
			}
		}
	}
}


int main(int argc, char* argv[])
{
	FILE *entrada = fopen("input.txt","rt");
	FILE *salida = fopen("salida.txt","wt");
	int T;
	char c;
	fscanf(entrada,"%d%c",&T,&c);
	searchhappy();
	for (int t=1;t<=T;t++)
	{
		vector<int> bases;
		int n=0;
		while (true)
		{
			if (fscanf(entrada,"%c",&c)!=1)
			{
				c='\n';
			}
			if (c=='\n')
			{
				if ((n!=2)&&(n!=4))
				{
					bases.push_back(n);
				}
				break;
			}
			if (c==' ')
			{
				if ((n!=2)&&(n!=4))
				{
					bases.push_back(n);
				}
				n=0;
			}
			else
			{
				n*=10;
				n+=c-'0';
			}
		}
		for (n=2;n<maxhappy;n++)
		{
			bool bueno=true;
			for (int i=0;i<bases.size();i++)
			{
				if (happy[bases[i]].count(fix(int64(n),int64(bases[i])))==0)
				{
					bueno=false;
					break;
				}
			}
			if (bueno)
			{
				break;
			}
		}
		fprintf(salida,"Case #%d: %d\n",t,n);
	}

	fclose(entrada);
	fclose(salida);
	return 0;
}

