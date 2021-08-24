#include <stdio.h>
#include <string.h>

#include <iostream>
#include <vector>
#include <set>
using namespace std;

#define		DEBUG		0

int		T;
int		CAS = 0;

int		base[10], b_cnt;

typedef struct big
{
	int		dig[100];
	int		len;
}BIG;


void	read()
{
	int		i, j, k;

	b_cnt = 0;
	char	line[200];
	gets(line);

	int		len = strlen(line);
	int		temp = 0;
	for (i=0; i<len; i++)
	{
		if (line[i] == ' ')
		{
			base[b_cnt++] = temp;
			temp = 0;
		}
		else
		{
			temp = 10 * temp + line[i] - '0';
		}
	}
	base[b_cnt++] = temp;
}


void		add(BIG&  a, BIG& b, int B)
{
	int		len = a.len > b.len ? a.len : b.len;
	int		i;
	for (i=0; i<len; i++)
	{
		a.dig[i]	+= b.dig[i];
		if (a.dig[i] >= B)
		{
			a.dig[i+1] += a.dig[i] / B;
			a.dig[i] %= B;
		}
	}
	a.len = len;
	if (a.dig[len] != 0)	a.len++;
}


int		getNext(int B, int N)
{
	BIG	stack[100];
	int		top = 0, i;

	memset(stack, 0, sizeof(stack));
	while (N)
	{
		int		temp = N % B;
		//if (temp == 0)	continue;

		stack[top].len = 1;
		stack[top].dig[0] = temp;

		stack[top].dig[0] *= stack[top].dig[0];

		if (stack[top].dig[0] >= B)
		{
			stack[top].dig[1] = stack[top].dig[0] / B;
			stack[top].dig[0] = stack[top].dig[0] % B;
			stack[top].len = 2;
		}
		
		N /= B;
		top++;
	}
	
	BIG	sum;
	memset(&sum, 0, sizeof(sum));

	sum.len = 1;
	sum.dig[0] = 0;

	for (i=0; i<top; i++)
		add(sum, stack[i], B);

	int		s = 0, m = 1;
	for (i=0; i<sum.len; i++)
	{
		s += sum.dig[i] * m;
		m *= B;
	}

	return s;
}

bool	check(int B, int N)
{
	set<int>	caled;
	
	do
	{
		if (N == 1)	return true;

		if (caled.find(N) != caled.end())		break;
		caled.insert(N);
		//printf("cas %d\n", N);
		N = getNext(B, N);
	} while (1);
	return false;
}

int		run()
{
	int		rnt = 0, i;

	for (rnt=2;   ;rnt++)
	{
		int		cnt = 0;
		for ( i=0; i<b_cnt; i++)
		{
			if (check(base[i], rnt) == false)		break;
		}
		if (i >= b_cnt)		return rnt;
	}
}

int main()
{
	int		i, j, k;

	FILE *in = (DEBUG) ? stdin : fopen("D:/round1/1.in", "rt");	
	FILE *out = (DEBUG) ? stdout : fopen("D:/round1/1.out", "wt");


	fscanf(in, "%d", &T);
	char	cc[10];
	gets(cc);


	for (; T; T--)
	{
		read();
//		for (i=0; i<b_cnt; i++)		printf("%d ", base[i]);
		int		ans = run();
		fprintf(out, "Case #%d: %d\n", ++CAS, ans);
	}


	return 0;
}