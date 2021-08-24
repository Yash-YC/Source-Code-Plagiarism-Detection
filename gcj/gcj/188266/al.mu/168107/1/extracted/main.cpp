#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <strstream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <climits>
using namespace std;

const int NMAX = 100000000;
char save_happy[11][NMAX];

const char HAPPY = 2;
const char UNHAPPY = 1;

typedef int INT;

inline INT sqr(INT a)
{
	return a*a;
}

char happy(int base, INT num)
{
	INT num2 = num;
	if( num<NMAX )
	{
		if( save_happy[base][num] )
			return save_happy[base][num];
		save_happy[base][num] = UNHAPPY;
	}

	if( num<base )
	{
		if( 1==num )
			return save_happy[base][num] = HAPPY;

		INT qnum = sqr(num);
		if( qnum<base )
		{
			return save_happy[base][num] = UNHAPPY;
		}
		else
		{
			return save_happy[base][num] = happy(base,qnum);
		}
	}
	
	//if( num<base )
	//{
	//	return save_happy[base][num] = 1+(num==1);
	//}


	INT sum = 0;
	while(num)
	{
		sum += sqr(num % base);
		num /= base;		
	}

	char result = 0;
	
	
	//if( sum>=base )
		result = happy(base,sum);
	//else
	//	result = 1+(sum==1);

	if( num2<NMAX )
	{
		save_happy[base][num2] = result;
	}

	///cout << "( " << base << " " << num2 << " ) = " << int(result) << endl;

	return result;
}


const int LMAX = 1000000;
char line[LMAX];

int main()
{
	//////cout << (int)happy(9,91) << endl;
	//////return 0;

	freopen("input.txt", "rt", stdin);
	freopen("output1.txt", "wt", stdout);

	int numTests = 0;
	scanf("%d\n", &numTests);


	for(int it=0; it<numTests; ++it)
	{
		vector<int> bases;
		{
			gets(line);
			std::istrstream stre(line);
			
			for(;;)
			{
				int a = -1;
				stre >> a;
				if( a==-1 )	break;

				bases.push_back(a);
			}
		}
		
		//cout << "bases = (";
		//for(int i=0; i<bases.size(); i++)
		//{
		//	cout << bases[i] << " ";
		//}
		//cout << ")"<<endl;


		for(INT num=2;num>0;num++)
		{
			bool is_happy = true;
			for(int i=0; i<bases.size(); i++)
			{
				if( HAPPY!=happy(bases[i],num) )
				{
					is_happy=false;
					break;
				}
			}
			if( is_happy )
			{
				cout << "Case #" << it+1 << ": " << num << endl;
				break;
			}
		}
		//cout << "here";
	}
	return 0;
}

