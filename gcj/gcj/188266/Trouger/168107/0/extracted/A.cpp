#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int table[512];
char s[1000];

int main()
{
	freopen("A-small.in", "r", stdin);
	freopen("A-small.txt", "w", stdout);

	FILE *fp = fopen("table1.txt", "r");
	for (int i = 0; i < 512; i++)
	{
		fscanf(fp, "%d", table + i);
	}
	fclose(fp);

	int T;
	scanf("%d", &T);
	gets(s);
	for (int c = 0; c < T; c++)
	{
		gets(s);
		istringstream is(s);
		bool b[11];
		memset(b, 0, sizeof(b));
		int t;
		int ind = 0;
		while(is>>t){
			b[t] = true;
		}
		for (int i = 2; i <= 10; i++)
			ind = (ind << 1) + (b[i]?1:0);

		int res = 100000000;
		for (int i = 0; i < 512; i++)
		{
			if ((i & ind) == ind)
				if (table[i] > 0 && table[i] < res)
					res = table[i];
		}
		printf("Case #%d: %d\n", c+1, res);
	}
}