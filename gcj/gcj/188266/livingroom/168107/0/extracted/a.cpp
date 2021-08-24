#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int cs,n,bs[15],cn = 1;
bool hs[100000];
char to[1000];

int change(int x,int bs,char s[])
{
	int sn = 0;
	while(x)
	{
		s[sn++] = x%bs+'0';
		x /= bs;
	}
	s[sn] = '\0';
	return sn;
}

int check(char s[],int bs,int l)
{
	int i,j;
	while(1)
	{
		int go = 0;
		for(i=0;i<l;i++){
			go += (s[i]-'0')*(s[i]-'0');
		}
		if(go == 1) return 1;
		if(hs[go]) return 0;
		hs[go] = 1;
		l = change(go,bs,s);
	}
	return 0;
}

int main()
{
	int i,j;
	char ch;
	freopen("A-small-attempt0.in","r",stdin);
	freopen("a-out.txt","w",stdout);
	scanf("%d\n",&cs);
	while(cs--)
	{
		int num = 0,n = 0;
		while((ch=getchar()) != '\n')
		{
			if(ch>='0' && ch<='9')
			{
				num = num*10+(ch-'0');
			}
			else if(ch == ' ')
			{
				bs[n] = num;
				num = 0;
				n++;
			}
		}
		if(num != 0) bs[n++] = num;
		for(i=2;;i++)
		{
			for(j=0;j<n;j++)
			{
				memset(hs,0,sizeof(hs));
				hs[i] = 1;
				int len = change(i,bs[j],to);
				if(!check(to,bs[j],len)) break;
			}
			if(j == n)
			{
				printf("Case #%d: %d\n",cn++,i);
				break;
			}
		}
	}
	return 0;
}

