#include <iostream>
#include <fstream>
#include <cmath>
#include <list>
#include <string>

#define MAXNA 100000

using namespace std;

int happy[11][MAXNA];

int isHappy(int b,int n,int ctr)
{
	if (ctr > b*b*b)
		return 0;
	else if (happy[b][n] != -1)
		return happy[b][n];

	int newN,t;
	while (n > 0)
	{
		t = n % b;
		t *= t;
		newN += t;
		n /= b;
	}

	happy[b][n] = isHappy(b,newN,ctr+1);
	return happy[b][n];
}

void A()
{
	ifstream in("A-small-attempt1.in");
	ofstream out("A-small.out");

	int T, bases[10];
	in >> T;
	cout << T << endl;

	char c = in.get();
	int ctr,base;

	for (int i = 2;i <= 10;i++)
	{
		happy[i][1] = 1;
		for (int j = 2;j < MAXNA;j++)
			happy[i][j] = -1;
	}

	for (int i = 2;i <= 10;i++)
	{
		for (int j = 2;j < MAXNA;j++)
		{
			happy[i][j] = isHappy(i,j,0);
		}
	}
	for (int i = 0;i < T;i++)
	{
		cout << i << ' ';
		ctr = 0;
		while((c = in.get()) != '\n' && !in.eof())
		{
			base = c-'0';
			if (base >= 2 && base <= 10)
			{
				bases[ctr++] = base;
			}
			else if (base == 1)
			{
				c = in.get();
				bases[ctr++] = 10;
			}
			cout << base << " ";
		}
		bases[ctr] = -1;

		for (int j = 2;;j++)
		{
			if (j == MAXNA)
			{
				cout << "out of bounds" << endl;
				break;
			}
			int isHappy = 1;
			for (int k = 0;k < ctr;k++)
			{
				isHappy &= happy[bases[k]][j];
			}
			if (isHappy)
			{
				out << "Case #" << i+1 << ": " << j << endl;
				break;
			}
		}

		cout << endl;
	}

}
int main()
{
	A();
	return 0;
}