#include<iostream>
#include<fstream>
using namespace std;

short base[9][1000000];
short mark[1000000];

short Search(int i, int j)
{
	if (j >= 1000000) printf("out of limit\n");
	if (mark[j]) return base[i - 2][j];
	mark[j] = 1;
	int p = j;
	int t = 0;
	while (j)
	{
		t += (j % i) * (j % i);
		j /= i;
	}
	base[i - 2][p] = Search(i, t);
	return base[i - 2][p];
}

fstream inf, ouf;
int main()
{
	inf.open("f:\\A-small-attempt0.in",ios::in);
	ouf.open("f:\\yy.txt", ios::out);

	int i, j;
	for (i = 2; i <= 10; ++i)
		for (j = 1; j < 1000000; ++j)
			base[i - 2][j] = -1;
	for (i = 2; i <= 10; ++i)
	{
		
		for (j = 1; j < 1000000; ++j)
			mark[j] = 0;
		mark[1] = 1;
		base[i - 2][1] = 1;
		for (j = 2; j < 1000000; ++j)
		Search(i, j);
	}

	int list[10], p;
	int tt;
	char tmp;
	inf>>tt;
	for (int ti = 1; ti <= tt; ++ti)
	{
		p = 0;
		do
		{
			inf>>list[p++];
			tmp = inf.get();
		} while (tmp != '\n');
		for (j = 2; j < 1000000; ++j)
		{
			bool yy;
			yy =true;
			for (i = p; i >= 1; --i)
				if (base[list[i - 1] - 2][j] != 1) 
				{
					yy =false;
					break;
				}
			if (yy)
			{
				ouf<<"Case #"<<ti<<": "<<j<<endl;
				break;
			}
		}
	}

	inf.close();
	ouf.close();
	return 0;
}