#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
int t;
char line[200];
vector<int> req_base;
#define MAXN 100000
int happy[11][MAXN + 1];
void init()
{
	for (int i = 0; i <= MAXN; ++i) {happy[2][i] = 1; happy[4][i] = 1;}
	for (int i = 2; i <= 10; ++i) {happy[i][1] = 1; happy[i][0] = 0; }
	happy[3][2] = happy[3][4] = happy[3][5] = happy[3][8] = 0;
	happy[5][4] = happy[5][16] = happy[5][10] = happy[5][13] = happy[5][18] = 0;
	happy[6][20] = happy[6][13] = happy[6][5] = happy[6][25] = happy[6][17] = happy[6][29] = happy[6][41] = happy[6][26] = 0;
	happy[7][2] = happy[7][4] = happy[7][16] = happy[7][8] = happy[7][25] = happy[7][10] = happy[7][17] = happy[7][13] = happy[7][37] = happy[7][29] = happy[7][45] = happy[7][32] = 0;
	happy[8][4] = happy[8][16] = happy[8][5] = happy[8][25] = happy[8][10] = happy[8][26] = happy[8][13] = happy[8][20] = happy[8][52] = 0;
	happy[9][50] = happy[9][53] = happy[9][89] = happy[9][65] = happy[9][41] = happy[9][68] = happy[9][74] = 0;

}

int iteration(int num, int base)
{
	string temp = "";
	int tnum,nnum;
	tnum = num;
	while (tnum != 0)
	{
		temp +=((tnum % base) + '0');
		tnum /= base;
	}
	nnum = 0;
	for (int i = 0; i < temp.length(); ++i) nnum = nnum + (temp[i] - '0') * (temp[i] - '0');

	if (happy[base][nnum] != -1) 
	{
		happy[base][num] = happy[base][nnum];
	}
	else 
	{
		happy[base][num] = 0;
		happy[base][num] = iteration(nnum, base);
	}
	return happy[base][num];
}

void buildtable()
{
	for (int i = 2; i <= 10; ++i)
	{
		if (i == 2 || i == 4) continue;
		//iteration(10000, i);
		for (int j = 2; j <= MAXN; ++j) 
			if (happy[i][j] == -1)	
				iteration(j, i);
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d\n",&t);
	//1:yes, 0:no
	memset(happy, -1, sizeof(happy));
	init();
	buildtable();
	for (int i = 1; i <= t; ++i)
	{
		req_base.clear();
		gets(line);
		int num = 0;
		for (int j = 0; j < strlen(line); ++j)		
		{
			if (line[j] >= '0' && line[j] <= '9') num = num * 10 + line[j] - '0';
			else 
			{
				req_base.push_back(num);
				num = 0;
			}
		}
		req_base.push_back(num);
		for (int ans = 2; ans <= MAXN; ++ ans)
		{
			bool ttt = true;
			for (int j = 0; j < req_base.size(); ++j)
				if (happy[req_base[j]][ans] == 0) 
				{
					ttt = false;
					break;
				}
			if (ttt == true) 
			{
				printf("Case #%d: %d\n", i, ans);
				break;
			}
		}
	}
	return 0;
}