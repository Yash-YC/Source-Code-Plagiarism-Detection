#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <istream>
#include <fstream>
#include <cmath>
#include <map>
using namespace std;

#define  MAXVALUE 4294967295

int n, m;
unsigned int s[20][20], w[20][20], t[20][20];
bool visited[40][40];
unsigned int dis[40][40];

unsigned int getTime(unsigned int now, unsigned int s, unsigned int w, unsigned int t, bool label)
{ 
	t %= s + w;
	if(label)
	{
		unsigned int temp = (now-t+s+w)%(s+w);
		if ( temp < s )
		{
			return 1;
		}
		return 1 + s + w - temp;
	}
	else
	{
		unsigned int temp = (now-t+s+w)%(s+w);
		if( temp < s )
		{
			return 1 + s - temp;
		}
		return 1;
	}
}

void moveRight(int row, int col, unsigned int now)
{
	if( col == 2 * m - 1 )return;
	if(col%2)
	{		
		if(dis[row][col+1] > now+2 )
			dis[row][col+1] = now + 2;
	}
	else
	{
		unsigned int temp = getTime(now, s[row/2][col/2], w[row/2][col/2], t[row/2][col/2], false);
		if(dis[row][col+1] > now+temp )
			dis[row][col+1] = now + temp;
	}
}

void moveLeft(int row, int col, unsigned int now)
{
	if( col == 0 )return;
	if(col%2 == 0)
	{
		if(dis[row][col-1] > now+2 )
			dis[row][col-1] = now + 2;
	}
	else
	{
		unsigned int temp = getTime(now, s[row/2][col/2], w[row/2][col/2], t[row/2][col/2], false);
		if(dis[row][col-1] > now+temp )
			dis[row][col-1] = now + temp;
	}
}

void moveUp(int row, int col, unsigned int now)
{
	if( row == 0 )return;
	if(row%2 == 0)
	{
		if(dis[row-1][col] > now+2 )
			dis[row-1][col] = now + 2;
	}
	else
	{
		unsigned int temp = getTime(now, s[row/2][col/2], w[row/2][col/2], t[row/2][col/2], true);
		if(dis[row-1][col] > now+temp )
			dis[row-1][col] = now + temp;
	}
}

void moveDown(int row, int col, unsigned int now)
{
	if( row == 2*n-1 )return;
	if(row%2)
	{
		if(dis[row+1][col] > now+2 )
			dis[row+1][col] = now + 2;
	}
	else
	{
		unsigned int temp = getTime(now, s[row/2][col/2], w[row/2][col/2], t[row/2][col/2], true);
		if(dis[row+1][col] > now+temp )
			dis[row+1][col] = now + temp;
	}
}

void moveNext(int row, int col, unsigned int now)
{
	moveLeft(row, col, now);
	moveRight(row, col, now);
	moveUp(row, col, now);
	moveDown(row, col, now);
}

pair<int, int> findMin()
{
	unsigned int d = MAXVALUE;
	pair<int, int> res;
	for ( int i  = 0; i < n*2; i++ )
	{
		for ( int j = 0; j < m*2; j++ )
		{
			if(visited[i][j])continue;
			if (dis[i][j] < d)
			{
				d = dis[i][j];
				res = make_pair(i, j);
			}
		}
	}
	return res;
}

void getResult()
{
	while(true)
	{
		pair<int, int> res = findMin();
		visited[res.first][res.second] = true;
		if (res.first == 0 && res.second == m*2-1)
		{
			break;
		}
		moveNext(res.first, res.second, dis[res.first][res.second]);
	}
}

int main()
{
	ifstream fin("B-large.in");  
	ofstream fout("results.txt");
	int caseNum;
	fin >> caseNum;
	for ( int num = 1; num <= caseNum; num++ )
	{
		fin >> n >> m;
		for ( int i = 0; i < n; i++ )
		{
			for ( int j = 0; j < m; j++ )
			{
				fin >> s[i][j] >> w[i][j] >> t[i][j];
			}
		}
		memset( dis, -1, sizeof(dis) );
		memset( visited, false, sizeof(visited) );
		dis[2*n-1][0] = 0;
		getResult();
		fout << "Case #" << num << ": " << dis[0][2*m-1] << endl;
	}
	
	fin.close();
	fout.close();
	return 0;
}