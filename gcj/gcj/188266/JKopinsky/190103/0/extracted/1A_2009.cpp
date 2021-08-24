#include <iostream>
#include <fstream>
#include <cmath>
#include <list>
#include <string>

#define MAXNA 1

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
	ifstream in("A-large.in");
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

int binom[41][41];
void computeBinoms()
{
	binom[0][0] = 1;
	for (int i = 1; i <= 40;i++)
	{
		binom[i][0] = binom[i][i] = 1;
		for (int j = 1;j < i;j++)
		{
			binom[i][j] = binom[i-1][j-1] + binom[i-1][j];
			//cout << i << " " << j << " " << binom[i][j] << endl;
		}
	}
}

double E(int i, int j, int C)
//i = numFound, j = numLeft, (N = i+j)
{

	if (j == 0) return 0;

	double result = 0;
	for (int k = 0;k < C;k++)
	{
		if (C-k > j) continue;
		if (k > i) break;

		result += (double)binom[i][k]*binom[j][C-k]/binom[i+j][C]*E(i+(C-k),j-(C-k),C);
	}

	result++;

	cout << i << ' ' << j << ' ' << C << endl;
	cout << binom[i][C] << " " << binom[i+j][C] << endl;
	if (i >= C)
		result /= 1-(double)binom[i][C]/binom[i+j][C];
	cout << result << endl;

	return result;
}

void C()
{
	ifstream in("C-small-attempt1.in");
	ofstream out("C-small-attempt1.out");

	computeBinoms();

	int T;
	in >> T;

	int N,C;

	for (int Case = 1;Case <= T;Case++)
	{
		in >> N >> C;
		out << "Case #" << Case << ": " << E(0,N,C) << endl;
	}
}

int main()
{
	//A();
	//B();
	C();
	return 0;
}