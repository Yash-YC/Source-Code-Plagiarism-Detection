#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
using namespace std;

const int MAXN = 100000;

int footmark[MAXN][10+1];
int bases[10+1];
int nb;

inline int sqr(int a)
{
	return a*a;
}

int next(int n, int b)
{
	int res = 0;
	while (n > 0){
		res += sqr(n%b);
		n /= b;
	}
	return res;
}

bool check(int n, int b)
{
	if (footmark[n][b] == 0)
		return false;
	if (n == 1)
		return true;
	if (footmark[n][b] == -1)
	{
		footmark[n][b] = 0;
		footmark[n][b] = check(next(n, b), b);
	}
	return footmark[n][b] == 1;
}

int main(int argc, char* args[]){
	if (argc < 3){
		cout << "lack of args" << endl;
		return 0;
	}
	freopen(args[1], "r", stdin);
	freopen(args[2], "w", stdout);
	memset(footmark, -1, sizeof(footmark));/*
	int maxCnt = 0, maxNum;
	for(int i=2; i<=MAXN; i++){
		int cnt = 0;
		for(int j=2; j<=10; j++){
			cout << i << ' ' << j << ':' << (int)check(i, j) << endl;
			if (check(i, j))
				cnt++;
		}
		if (cnt >= 9)
		{
			cout << i << endl;
			return 0;
		}
		if (cnt > maxCnt)
		{
			maxCnt = cnt;
			maxNum = i;
		}
	}
	cout << maxNum << ':' << maxCnt << endl;*/
	int T;
	cin >> T;
	string line;
	getline(cin, line);
	for(int ic=0; ic<T; ic++)
	{
		getline(cin, line);
		stringstream input(line);
		nb = 0;
		int temp;
		while (input >> temp)
			bases[nb++] = temp;
		int i;
		for(i=2; i<MAXN; i++)
		{
			int cnt = 0;
			for(int j=0; j<nb; j++)
				cnt += check(i, bases[j]);
			if (cnt == nb)
			{
				printf("Case #%d: %d\n", ic+1, i);
				break;
			}
		}
		if (i == MAXN){
			cout << "Failed:" << ic+1 << endl;
			return 0;
		}
	}
}

