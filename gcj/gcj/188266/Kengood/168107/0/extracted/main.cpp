
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


/*
set<int> appeared;
char isHappy(int n , int base)
{
	if(base == 2 ) return 1;
	if( n == 1 ) return 1;
	int newN = 0;
	int b = 1;
	//for(int i=len-1;i>=0;i--)
	while(n)
	{
		newN += (n%base) * (n%base);
		n /=base;
	}
	if( appeared.find(newN) != appeared.end() ) return 0;
	appeared.insert(newN);
	if( newN == 1 ) return 1;

	return isHappy(newN,base);
}

int tryA(int a , int b)
{
	for(int i = 3;i;i++)
	{
		appeared.clear();
		appeared.insert(i);
		if( isHappy(i,a) )
		{
			appeared.clear();appeared.insert(i);
			if( isHappy(i,b) )
				return i;
		}
	}
}


int tryB(int a , int b , int c)
{
	for(int i = 3;i;i++)
	{
		appeared.clear();
		appeared.insert(i);
		if( isHappy(i,a) )
		{
			appeared.clear();appeared.insert(i);
			if( isHappy(i,b) )
			{
				appeared.clear();appeared.insert(i);
				if( isHappy(i,c) )
					return i;
				
			}
		}
	}
}

int main()
{
	int i ,j;

	

	for(i=2;i<=10;i++)
	{
		for(j=i+1;j<=10;j++)
		{
			//printf("two[%d][%d] = %d;\n" ,i,j ,tryA(i,j) );
			for(int k=j+1;k<11;k++)
				printf("three[%d][%d][%d] =  %d;\n" ,i,j ,  k , tryB(i,j,k) );

		}
	}


	return 0;
}
*/



int two[11][11];
int three[11][11][11];
char buf[1024];


set<int> appeared;
char isHappy(int n , int base)
{
	if(n == 0 ) return 0;
	if(base == 2 ) return 1;
	if( n == 1 ) return 1;
	int newN = 0;

	while(n)
	{
		newN += (n%base) * (n%base);
		n /=base;
	}
	if( newN  == 0 ) return 0;
	if( appeared.find(newN) != appeared.end() ) return 0;
	appeared.insert(newN);
	if( newN == 1 ) return 1;

	return isHappy(newN,base);
}

int tryA(int a , int b)
{
	for(int i = 2;i;i++)
	{
		appeared.clear();
		appeared.insert(i);
		if( isHappy(i,a) )
		{
			appeared.clear();appeared.insert(i);
			if( isHappy(i,b) )
				return i;
		}
	}
}


int tryB(int a , int b , int c)
{
	for(int i = 2;i;i++)
	{
		appeared.clear();
		appeared.insert(i);
		if( isHappy(i,a) )
		{
			appeared.clear();appeared.insert(i);
			if( isHappy(i,b) )
			{
				appeared.clear();appeared.insert(i);
				if( isHappy(i,c) )
					return i;
				
			}
		}
	}
}

int main()
{

two[2][3] = 3;
two[2][4] = 3;
two[2][5] = 5;
two[2][6] = 6;
two[2][7] = 7;
two[2][8] = 8;
two[2][9] = 3;
two[2][10] = 7;
two[3][4] = 3;
two[3][5] = 23;
two[3][6] = 79;
two[3][7] = 143;
two[3][8] = 27;
two[3][9] = 3;
two[3][10] = 13;
two[4][5] = 5;
two[4][6] = 6;
two[4][7] = 7;
two[4][8] = 8;
two[4][9] = 3;
two[4][10] = 7;
two[5][6] = 49;
two[5][7] = 7;
two[5][8] = 27;
two[5][9] = 27;
two[5][10] = 7;
two[6][7] = 49;
two[6][8] = 216;
two[6][9] = 415;
two[6][10] = 44;
two[7][8] = 1001;
two[7][9] = 125;
two[7][10] = 7;
two[8][9] = 27;
two[8][10] = 97;
two[9][10] = 91;
three[2][3][4] =  3;
three[2][3][5] =  23;
three[2][3][6] =  79;
three[2][3][7] =  143;
three[2][3][8] =  27;
three[2][3][9] =  3;
three[2][3][10] =  13;
three[2][4][5] =  5;
three[2][4][6] =  6;
three[2][4][7] =  7;
three[2][4][8] =  8;
three[2][4][9] =  3;
three[2][4][10] =  7;
three[2][5][6] =  49;
three[2][5][7] =  7;
three[2][5][8] =  27;
three[2][5][9] =  27;
three[2][5][10] =  7;
three[2][6][7] =  49;
three[2][6][8] =  216;
three[2][6][9] =  415;
three[2][6][10] =  44;
three[2][7][8] =  1001;
three[2][7][9] =  125;
three[2][7][10] =  7;
three[2][8][9] =  27;
three[2][8][10] =  97;
three[2][9][10] =  91;
three[3][4][5] =  23;
three[3][4][6] =  79;
three[3][4][7] =  143;
three[3][4][8] =  27;
three[3][4][9] =  3;
three[3][4][10] =  13;
three[3][5][6] =  79;
three[3][5][7] =  143;
three[3][5][8] =  27;
three[3][5][9] =  27;
three[3][5][10] =  23;
three[3][6][7] =  2207;
three[3][6][8] =  3879;
three[3][6][9] =  707;
three[3][6][10] =  79;
three[3][7][8] =  5719;
three[3][7][9] =  143;
three[3][7][10] =  167;
three[3][8][9] =  27;
three[3][8][10] =  219;
three[3][9][10] =  91;
three[4][5][6] =  49;
three[4][5][7] =  7;
three[4][5][8] =  27;
three[4][5][9] =  27;
three[4][5][10] =  7;
three[4][6][7] =  49;
three[4][6][8] =  216;
three[4][6][9] =  415;
three[4][6][10] =  44;
three[4][7][8] =  1001;
three[4][7][9] =  125;
three[4][7][10] =  7;
three[4][8][9] =  27;
three[4][8][10] =  97;
three[4][9][10] =  91;
three[5][6][7] =  49;
three[5][6][8] =  1975;
three[5][6][9] =  415;
three[5][6][10] =  49;
three[5][7][8] =  1001;
three[5][7][9] =  125;
three[5][7][10] =  7;
three[5][8][9] =  27;
three[5][8][10] =  219;
three[5][9][10] =  91;
three[6][7][8] =  47089;
three[6][7][9] =  2753;
three[6][7][10] =  49;
three[6][8][9] =  4977;
three[6][8][10] =  608;
three[6][9][10] =  1033;
three[7][8][9] =  6393;
three[7][8][10] =  34527;
three[7][9][10] =  1337;
three[8][9][10] =  1177;

	int Case = 0;
	int cases;

	
	int a ,c ,b;
	int size;

	scanf("%d" , &cases);
	gets(buf);
	while( cases-- )
	{
		gets(buf);

		size = sscanf(buf,"%d%d%d" , &a,&b,&c);
		
		printf("Case #%d:" , ++Case);

		if( size == 2 )
		{
			/*if ( a > b )
			{
				a ^= b;
				b ^= a;
				a ^= b;
			}*/
			//printf(" %d\n" , two[a][b]);
			printf(" %d\n" , tryA(a,b) );
		}
		else
		{
			/*vector<int> dam; dam.push_back(a);dam.push_back(b);dam.push_back(c);
			sort( dam.begin() , dam.end() );

			printf(" %d\n" , three[dam[0]][dam[1]][dam[2]]);*/
			printf(" %d\n" ,  tryB(a,b,c));
		}

	}


	return 0;
}