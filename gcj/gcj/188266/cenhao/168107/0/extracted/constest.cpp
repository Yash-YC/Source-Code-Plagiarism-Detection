#include<iostream>
using namespace std;

bool been[100000];
int base[9];
int digit[1000];
int n;

void Init()
{
	n = 0;
	char c;
	while(cin.get(c))
	{
		if(c == '\n')return;
		if(c >= '1')
		{
			cin.putback(c);
			cin >> base[n++];
		}
	}
}

bool Ok(int num, int b)
{
	if(b == 2)return true;
	int tmp, len, i;
	memset(been, 0, sizeof(been));
	while(!been[num])
	{
		been[num] = true;
		len = 0;
		while(num != 0)
		{
			tmp = num / b;
			digit[len++] = num - tmp*b;
			num = tmp;
		}
		num = 0;
		for(i=0; i<len; ++i)
		{
			num += digit[i]*digit[i];
		}
		if(num == 1)return true;
	}
	return false;
}

void Solve(int no)
{
	int i, j;
	for(i=2; ; ++i)
	{
		for(j=0; j<n; ++j)
		{
			if(!Ok(i, base[j]))break;
		}
		if(j == n)
		{
			printf("Case #%d: %d\n", no, i);
			break;
		}
	}
}

int main()
{
	int t;
	cin >> t;
	cin.get();
	int i;
	for(i=0; i<t; ++i)
	{
		Init();
		Solve(i+1);
	}
	return 0;
}
