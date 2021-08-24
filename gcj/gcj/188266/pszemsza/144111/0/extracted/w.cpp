#include <vector>
#include <queue>
#include <string>
#include <stdio.h>

using namespace std;


int w, h;


int main()
{
	int i,l,k,j,te;
	int a,b,c;
	int C;
	string s;

	int inf = 9999999;
	int S[50][50], W[50][50], T[50][50];
	int dp[50][50];


	int th, tw, tmp;

	scanf("%d", &C);
	for (te=0; te<C; te++)
	{
		scanf("%d %d", &h, &w);

		th = 2*h;
		tw = 2*w;
		for (i=0; i<h; i++)
		{
			for (l=0; l<w; l++)
			{
				scanf("%d %d %d", &a, &b, &c);
				S[h-i-1][l] = a;
				W[h-i-1][l] = b;
				tmp = a+b;
				while (c > 0) c-= tmp;
				T[h-i-1][l] = c;
			}
		}

		for (i=0; i<h; i++)	for (l=0; l<w; l++) dp[i][l] = inf;
		dp[0][0] = 0;

		int diff, cyk;
		int ni, nl;
		for (i=0; i<2*h; i++)
		{
			for (l=0; l<2*w; l++) if (i+l>0)
			{
				//printf("\njestem na polu (%d %d)", i, l);
				int dol = inf, lewo = inf;
				if (l>0) // idziemy z dolu
				{
					if (l%2==0)
					{
						dol = dp[i][l-1] + 2;
					}
					else
					{
						ni = i / 2;
						nl = (l-1) / 2;
						// obliczamy kiedy najszybciej byly swiatla NS
						int ctime = dp[i][l-1];
						int ltime = T[ni][nl]; // zaczyna sie cykl
						cyk = S[ni][nl] + W[ni][nl];
						diff = ctime - ltime;
						diff %= cyk;

						if (diff < S[ni][nl]) 
						{
							dol = dp[i][l-1] + 1 + S[ni][nl] - diff; // czekam na WE
						}
						else dol = dp[i][l-1] + 1;
						//else dol = dp[i][l-1] + cyk - diff + 1; // nie zdazylem, czekam do konca cyklu + 1 za przejscie

						//if (diff < S[i][l-1]) dol = dp[i][l-1] + 1; // ok, zdazylem
						//else dol = dp[i][l-1] + cyk - diff + 1; // nie zdazylem, czekam do konca cyklu + 1 za przejscie
					}
				} // l>0


				if (i>0) // idziemy z lewej
				{
					if (i%2==0)
					{
						lewo = dp[i-1][l] + 2;
					}
					else
					{
						ni = (i-1) / 2;
						nl = l / 2;

						// obliczamy kiedy najszybciej byly swiatla NS
						int ctime = dp[i-1][l];
						int ltime = T[ni][nl]; // zaczyna sie cykl
						cyk = S[ni][nl] + W[ni][nl];
						diff = ctime - ltime;
						diff %= cyk;
						if (diff < S[ni][nl]) lewo = dp[i-1][l] + 1; // ok, zdazylem
						else lewo = dp[i-1][l] + cyk - diff + 1; // nie zdazylem, czekam do konca cyklu + 1 za przejscie
					}
				} // i>0

				//printf("\n   lewo: %d, dol: %d", lewo, dol);
				if (lewo < dol) dol = lewo;
				dp[i][l] = dol;
			}
		}

		printf("Case #%d: %d\n", te+1, dp[2*h-1][2*w-1]);
	}

	char ch;
	//scanf("%c", &ch);
	//scanf("%c", &ch);
	//scanf("%c", &ch);
	//scanf("%c", &ch);
	return 0;
}
