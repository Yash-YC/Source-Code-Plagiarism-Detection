#include <iostream>
using namespace std;

bool hash[11][100001];
bool flag[10001];

int  zhao(int x, int b) 
{
	int sum = 0, i, haha;
	char str[10000];
	itoa(x, str, b);
	for (i = 0; str[i]; i++) {
		haha = str[i] - '0';
		sum +=haha * haha;
	}
	return sum;
}

void finnd()
{
	int haha, i, j;
	memset(hash, false, sizeof(hash));
	for (i = 2; i <= 10; i++) {
		for (j = 2; j <= 100000; j++) {
			memset(flag, true , sizeof(flag));
			haha = zhao(j, i);
			while (true) {
				if (flag[haha]) {
					flag[haha] = false;
					if (haha == 1) {
						hash[i][j] = true;
						//printf("%d %d      ", i, j);
						break;
					} else {
						haha = zhao(haha, i);
					}
				} else {
					break;
				}
			}
		}
	}
}

int main()
{
	int tt=0;
	finnd();
	int t;
	int a[10];
	char s[1000];
	int i,j;
	int n;
	freopen("A-small-attempt1.in","r",stdin);
	freopen("out2.out","w",stdout);
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		tt++;
		gets(s);
		n=0;
		for(i=0;s[i]!='\0';i++)
		{
			if(s[i]=='1')
			{
				if(s[i+1]=='0')
				{
					a[n]=10;
					n++;
					i++;
				}
				else
				{
					a[n]=1;
					n++;
				}
			}
			else if(s[i]>'1' && s[i]<='9')
			{
				a[n]=s[i]-'0';
				n++;
			}
		}

	//	for(i=0;i<n;i++)
	//		printf("%d ",a[i]);

		int ans=-1;
		for(i=2;i<100001;i++)
		{
			for(j=0;j<n;j++)
			{
				
				if(hash[a[j]][i]==false)
					break;
			}
			if(j==n)
			{
				ans=i;
				break;
			}
		}
		printf("Case #%d: %d\n",tt,ans);
	}
	return 0;
}
