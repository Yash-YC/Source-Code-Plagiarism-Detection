#include <iostream>
#include <stdio.h>
#include <set>
#include <map>
#include <list>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <vector>


using namespace std;

bool isHappy(int n, int base)
{
	int mod;
	int res = 0;
	int pres=n;

	set<int> foundvals;

	while(1)
	{

		while (n >= 1)
		{
			mod = n % base;

			res += mod * mod;

			n = n / base;
		}

		if ((foundvals.find(res) != foundvals.end()))
			break;

		{
			foundvals.insert(res);

			n = res;
			//pres = n;
			res=0;

		}

	};

	if (res == 1)
		return true;

	return false;
}

int getsmall(list<int> &lstn)
{

	bool bHappy=false;
	int i=2;
	for (; i; ++i)
	{
		bHappy = true;
		for (list<int>::iterator iter = lstn.begin(); iter!=lstn.end(); ++iter)
		{
			if (!isHappy(i , (*iter)))
			{
				bHappy = false;
				break;
			}
		}

		if (bHappy)
			return i;
	}

	return i;
}

int main()
{
	int nTestCases;
	int l, d, n;
	char bases[1024];

	FILE *in_file;
	FILE *out_file;

	isHappy(91, 9);

	if ((in_file = fopen("prob1_in.txt", "r")) == 0)
	{
		cout <<"in err\n";
	}

	if ((out_file = fopen("prob1_out.txt", "w+")) == 0)
	{
		cout <<"Out err\n";
	}

//#define in_file stdin
//#define out_file stdout

	fscanf(in_file, "%d\n", &nTestCases);

	char delim[] = " ";
	char *curp;

	list<int> lstnum;
	int		num;

	for (int i=1; i<=nTestCases; ++i)
	{
		fgets(bases, 1024, in_file);


		lstnum.clear();
		curp = strtok(bases, delim);
		while (curp != NULL)
		{
			sscanf(curp, "%d", &num);

			lstnum.push_back(num);

			curp = strtok(NULL, delim);
		}

		fprintf (out_file, "Case #%d: %d\n", i, getsmall(lstnum));
	}


	fclose(in_file);
	fclose(out_file);

	return 0;
}