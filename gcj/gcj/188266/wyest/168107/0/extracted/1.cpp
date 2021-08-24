#include<set>
#include<cmath>
#include<cstdio>
#include<sstream>
using namespace std;
int main()
{
	freopen("1.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	getchar();
	char l[16];
	int b[10];
	double bb[10];
	for (int k = 1; k <= T; ++k)
	{
		gets(l);
		istringstream is(l);
		int r = 0;
		while (is >> b[r])
		{
			bb[r] = sqrt((double)b[r]);
			++r;
		}
		for (int i = 2; ; ++i)
		{
			bool flag = true;
			for (int j = 0; j < r; ++j)
			{
				set<int> ed;
				int t = i;
				int s = 0;
				while (t >= bb[j] && ed.find(t) == ed.end())
				{
					s = 0;
					ed.insert(t);
					while (t)
					{
						s += (t%b[j])*(t%b[j]);
						t /= b[j];
					}
					t = s;
				}
				if (t != 1) flag = false;
	//			printf("%d %d\n", i, b);
			}
			if (flag)
			{
				printf("Case #%d: %d\n", k, i);
				break;
			}
		}
	}
	return 0;
}