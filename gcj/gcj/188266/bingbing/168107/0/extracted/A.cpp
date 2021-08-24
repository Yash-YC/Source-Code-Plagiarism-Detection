#include <iostream>

using namespace std;

bool happy(int n, int base)
{
	int i, flag = 0;
	bool exist[100000];
	memset(exist, false, sizeof(exist));
	exist[n] = true;
	int sum;
	for(i=1; i<=2000; i++)
	{
		sum  = 0;
		while(n)
		{
			sum += (n%base)*(n%base);
			n /= base;
		}
		if(sum==1)
		{
			flag = 1;
			break;
		}
		n = sum;
		if(exist[n])
			return false;
		exist[n] = true;
	}
	if(flag)
		return true;
	else
		return false;
}

int main()
{
	freopen("1.txt", "r", stdin);
	freopen("2.txt","w", stdout);
	//cout << happy(7, 3) << endl;
	//system("pause");
	char str[200];
	int base[10], basenum;
	int i, j, k, casenum, flag;
	scanf("%d", &casenum);
	getchar();
	for(i=1; i<=casenum; i++)
	{
		basenum = 0;
		memset(base, 0, sizeof(base));
		gets(str);
		for(j=0; str[j]; j++)
		{
			if(str[j]==' ')
			{
				basenum++;
				continue;
			}
			base[basenum] = base[basenum]*10+str[j]-'0';
		}
		for(j=2; ;j++)
		{
			flag = 0;
			for(k=0; k<basenum+1; k++)
			{
				if(!happy(j, base[k]))
				{
					flag = 1;
					break;
				}
			}
			if(!flag)
				break;
		}
		printf("Case #%d: %d\n", i, j);
	}
	return 0;
}