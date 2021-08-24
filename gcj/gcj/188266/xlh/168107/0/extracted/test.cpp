#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <stack>
using namespace std;

#define size 1100111

int happy[11][size];

int getpro(int base, int num)
{
	int sum = 0;
//	printf("num %d base %d " , num, base);
	while(num)
	{
		sum += (num%base)*(num%base);
		num /= base;
	}
//	printf("res %d\n",sum);
//	if(base==3 )system("pause");
	return sum;	
}

int list[50000];
int listcnt;
bool  ishappy(int base, int num)
{
	int tmp;
	listcnt = 0;
	if(happy[base][num]==1) return true;
	
	while(true)
	{
	 list[listcnt++] = num;
	// printf("%d", num);
//	 system("pause");
	 tmp = getpro(base, num);
	 if(happy[base][tmp]==1)
	 {
			for(int i=0; i<listcnt; i++)
			happy[base][list[i]] = 1;
			return true;
	 }
	 if(happy[base][tmp]==0)
	 {
		    for(int i=0; i<listcnt; i++)
			happy[base][list[i]] = 0;
			return false;
	 }
	 
	 for(int i=0; i<listcnt; i++)
	 if(tmp==list[i]) {
			for(int j=0; j<listcnt; j++)
			happy[base][list[j]] = 0;
			
			happy[base][tmp] = 0;
			return false;
			}
	 
	 num = tmp;
	}
}
void cacu(int base)
{
	happy[base][1] = true;
	for(int i=2; i<size; i++)
	{
		ishappy(base, i);	
	}
} 
void work()
{
	memset(happy, 0xff, sizeof(happy));
	for(int i=2; i<=10; i++)
	cacu(i);
}
int main()
{
	int T, casenum = 0;
	char input[105];
	int bases[20];
	int cnt, i, j, len;
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout); 
	work();
	scanf("%d", &T);
	for(casenum = 1; casenum <= T; casenum++)
	{
	 scanf(" ");
	 fgets(input, 100, stdin);
	 memset(bases, 0, sizeof(bases));
	 cnt = 0;
	 len = strlen(input);
	 for(i=0; i<len; i++)
	 {
	  if(input[i]==' ')
	  {
		cnt++;
	  }
	  else
	  if(input[i]>='0'&&input[i]<='9')
	  {
		 bases[cnt] = bases[cnt]*10+input[i]-'0';
	   }
	 }
	 cnt++;
	 for(i=2; ; i++)
	 {
			for( j=0; j<cnt; j++)
	 		{
			 if(happy[bases[j]][i] == 0) break;
	  		}
	  		if(j>=cnt)
	  		{
			 printf("Case #%d: %d\n", casenum, i);
			 break;
			}
			
	  }
	}
	return 0;
}

