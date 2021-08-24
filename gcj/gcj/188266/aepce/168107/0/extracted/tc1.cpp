#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define MAXNUM 10000
int rec[MAXNUM][11];

vector<int> repre(int num, int base)
{
	vector<int> v;
	v.clear();
	while(num > 0)
	{
		v.push_back(num % base);
		num /= base;
	}
	return v;
}

int next(int num, int base)
{
	vector<int> v = repre(num, base);
	int sum = 0;
	for(int i = 0; i < v.size(); ++i)
	{
		sum += v[i] * v[i];
	}
	return sum;
}

bool dfs(int num, int base)
{
	if(rec[num][base] == 0 || rec[num][base] == 1)
		return rec[num][base];
	if(num == 1)
	{
		rec[num][base] = 1;
		return 1;
	}

	if(rec[num][base] == -2)
	{
		rec[num][base] = 0;
		return 0;
	}
	rec[num][base] = -2;

	vector<int> v = repre(num, base);
	
	int sum = 0;
	for(int i = 0; i < v.size(); ++i)
		sum += v[i] * v[i];
	rec[num][base] = dfs(sum, base);

	return rec[num][base];
}

void init()
{
	memset(rec, -1, sizeof(rec));
	for(int i = 2; i < MAXNUM; ++i)
	{
		for(int k = 2; k <= 10; ++k)
			dfs(i, k);
	}
}

int main()
{
	ifstream ifs("A-small-attempt0.in");
	ofstream ofs("A-small-attempt0.out");

	int T;
	char buf[50];
	int bases[10];

	init();

	ifs >> T;
	ifs.getline(buf, 50);
	istringstream iss;
	for(int caseNo = 1; caseNo <= T; ++caseNo)
	{
		ifs.getline(buf, 50);
		iss.clear();
		iss.str(buf);
		int i, k, baseNum = 0;
		while(iss >> bases[baseNum])
			++baseNum;
		for(i = 2; ; ++i)
		{
			bool flag = true;
			for(k = 0; k < baseNum; ++k)
			{
				int tmp = next(i, bases[k]);
				if(!rec[tmp][bases[k]])
				{
					flag = false;
					break;
				}
			}
			if(flag)
			{
				ofs << "Case #" << caseNo<< ": " << i << endl;
				break;
			}
		}
	}

	ifs.close();
	ofs.close();
	
	return 0;
}