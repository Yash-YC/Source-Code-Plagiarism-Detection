//2 ¡Â all possible input bases ¡Â 10
//
//Small dataset
//
//1 ¡Â T ¡Â 42
//
//2 ¡Â number of bases on each test case ¡Â 3
//
//Large dataset
//
//1 ¡Â T ¡Â 500
//
//2 ¡Â number of bases on each test case ¡Â 9
//
//Sample

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <set>

using namespace std;

int n;
int	base[10];
char line[1000];

int chk(int N, int B)
{
	int now = N;
	set<int> dup;

	for(;;)
	{
		if(dup.count(now)) return 0;
		dup.insert(now);

		int tmp = 0;
		while(now)
		{
			tmp += (now % B) * (now % B);
			now /= B;
		}

		if( tmp == 1 ) break;
		now = tmp;
	}

	return 1;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int r;
	scanf("%d", &r);
	gets(line);
	for( int testc = 1; testc <= r; ++testc )
	{
        gets(line);
		n = 0;
		char *p = strtok(line, " ");
		while(p)
		{
			base[n++] = atoi(p);
			p = strtok(NULL, " ");
		}
        
		for(int sol = 2; ; ++sol)
		{
			for( int i = 0; i < n; ++i )
				if( !chk(sol, base[i]) )
					break;

			if(i == n)
			{
				printf("Case #%d: %d\n", testc, sol);
				break;
			}
		}
	}

	return 0;
}