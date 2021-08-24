#include <stdio.h>

int save[11][101000];
int num[21];
int temp[21];

void init()
{
	int i, j, k, t;
	int sum;
	int calc;

	int L = 10;

	for(i = 2; i <= 10; i ++)
	{
		for(j = 0; j < 20; j ++)
			num[j] = 0;
		
		num[0] = 1;

		for(t = 0; t < 99900; t ++)
		{
			num[0] ++;
			for(j = 0; j <= L; j ++)
			{
				if(num[j] >= i)
				{
					num[j+1] ++;
					num[j] %= i;
				}
			}

			for(j = 0; j <= L; j ++)
				temp[j] = num[j];

			for(k = 0; k < 100; k ++)
			{
				sum = 0;
				for(j = 0; j < L; j ++)
				{
					calc = num[j] * num[j];
					sum += ((calc / i) * 10);
					sum += (calc % i);
				}

				if(sum == 1) break;

				for(j = 0; j < L; j ++)
				{
					num[j] = sum % 10;
					sum /= 10;
				}

				for(j = 0; j < L ; j++)
				{
					if(num[j] >= i)
					{
						num[j+1] += (num[j] / i);
						num[j] %= i;
					}
				}
			}

			if(k != 100)
			{
				calc = 1;
				sum = 0;
				for(j = 0; j < L; j ++)
				{
					sum += (temp[j] * calc);
					calc *= i;
				}
				save[i][sum] = 1;
			}

			for(j = 0; j < L; j ++)
				num[j] = temp[j];
		}
	}
}

int n, m;
int data[10];

int main()
{
	init();

	int i, j, k;
	int temp;
	int flag;

	char tt;

	FILE *in = fopen("input.txt","r");
	FILE *out = fopen("output.txt","w");

	fscanf(in, "%d\n" ,&n);

	for(i = 0; i < n; i ++)
	{
		m = 0;
		while(1)
		{
			fscanf(in, "%c", &tt);
			if(tt == '\n')
				break;
			if(tt == ' ')
				continue;
			else
			{
				if(tt == '1')
				{
					fscanf(in,"%c", &tt);
					
					tt = 10 + '0';
				}
				data[m] = tt - '0';
				m ++;
			}
		}

		flag = 0;
		for(j = 2; j <= 10000; j ++)
		{
			for(k = 0; k < m; k ++)
			{
				if(!save[data[k]][j])
					break;
			}
			if(k == m)
			{
				flag = j;
				break;
			}
		}

		fprintf(out,"Case #%d: %d\n", i+1, flag);
	}

	fclose(in);
	fclose(out);
}