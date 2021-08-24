#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
using namespace std;
int repeat(int n)
{
	int sum = 0;
	int t = 0;
	while(n>0)
	{
		t = n%10;
		t *= t;
		sum += t;
		n /= 10;
	}
	return sum;
}
const int maxloop = 100;
int change(int num, int b)
{
	if(num == 0)
		return 0;

	int m = 1;
	while(num>=m)
	{
		m *= b;
	}
	m /= b;

	int res = 0;
	while(m > 0)
	{
		res += num / m;
		res *= 10;
		num %= m;
		m /= b;
	} 
	return res/10;
}
bool ishappy(int num, int b)
{
	int count = 0;
	while(count++ <maxloop)
	{
		
			if(num == 1)
				return true;
				
		num = repeat(num);
		num = change(num, b);
	}
	return false;
}
const int maxlen = 21;
const int maxnum = 100000;
bool happy[11][maxnum];
void init()
{
	memset(happy , 0, sizeof(bool)*11*maxnum);

	int num, i, j;
	for(i=2; i<maxnum; ++i)
	{
		happy[10][i] = ishappy(i, 10);
		for(j=2; j<10; j++)
		{
			int t = change(i, j);
			happy[j][i] = ishappy(t, j);
		}
	}
}
int main()
{
	init();

	int t, i, c=1, j;
	cin >> t;
	char str[maxlen];
	int bases[maxlen];

	ofstream out("result.txt");
	getchar();
	while(c <= t)
	{
		int count = 0;
		cin.getline(str, maxlen);
		istringstream ss(str);
		while(ss >> bases[count])
		{
			count++;
		}
	

		for(i=2; i<maxnum; i++)
		{
			bool mins = true;
			for(j=0; j<count; j++)
			{
				mins = mins && happy[bases[j]][i];
			}
			if(mins)
			{
				out << "Case #" << c <<": " << i << endl;
				break;
			}

		}
		c++;
	}

	out.close();
}