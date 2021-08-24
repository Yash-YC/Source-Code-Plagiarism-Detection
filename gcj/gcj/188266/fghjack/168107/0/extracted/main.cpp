#include <stdio.h>
#include <iostream>

using namespace std;

int base[9], basecnt;
bool done[100000];

void Init()
{
	basecnt = 0;
	char temp;
	while(true)
	{
		scanf("%c", &temp);
		if(temp == '\n')
			break;
		else
		{
			cin.putback(temp);
			cin >> base[basecnt++];
		}
	}
}

bool Test(const int base, int num)
{
	memset(done, false, sizeof(done));
	done[num] = true;
	int temp, sum;
	while(num != 1)
	{
		temp = num;
		sum = 0;
		while(temp != 0)
		{
			sum += (temp % base) * (temp % base);
			temp /= base;
		}
		if(!done[sum])
		{
			done[sum] = true;
			num = sum;
		}
		else
			return false;
	}
	return true;
}

void Compute(int caseno)
{
	int k;
	for(int i=2; ; i++)
	{
//		printf("%d\n", i);
		for(k=0; k<basecnt; k++)
		{
			if(!Test(base[k], i))
				break;
		}
		if(k == basecnt)
		{
			printf("Case #%d: %d\n", caseno, i);
			return;
		}
	}
}

int main() 
{
//	freopen("data.txt", "r", stdin);
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("out.txt", "w", stdout);
    int cases;
	scanf("%d\n", &cases);
	int i;
	for(i=1; i<=cases; i++)
	{
		Init();
		Compute(i);
	}
	return 0;
}