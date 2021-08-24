#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

bool valid(int num, int Base)
{
	int tmp = num, check, ok = 1;
	while( tmp ) 
	{
		check = tmp%10;
		if( check >= Base ) ok = 0;
		tmp /= 10;
	}

	if( ok == 0 ) return false;
	else return true;
}

bool happynumber(int num, int Base)
{
	map<int, int> repeat;
	int tmp = num, check;
	// int cnt = 0;
	

	while(1)
	{
		vector<int> b_num;
		while(tmp)
		{
			check = tmp%Base;
			b_num.push_back(check);
			tmp /= Base;
		}

		check = 0;
		for(int a = 0; a < b_num.size(); a++ )
		{
			check += b_num[a] * b_num[a];
		}
		if( check == 1 ) return true; 
		if( repeat[check] == 1 ) return false; 
		repeat[check] = 1;
		tmp = check; 
		
//		cnt++;
	}

}

int main()
{
	ifstream in;
	ofstream out;
	in.open("A-small-attempt0.in");
	out.open("A.out");

	char buf[1024];
	int T, tmp;
	in.getline(buf, 1024, '\n');
	T = atoi(buf);

	for(int i = 1; i <= T; i++)
	{
		tmp = 0;

		vector<int> dat;
		in.getline(buf, 1024, '\n');
		int first = 1;

		for( int a  = 0; a < strlen(buf); a++ )
		{
			if( buf[a] >= '0' && buf[a] <= '9' ) 
			{
				if( first )  
				{
					first = 0;
					tmp += buf[a] - '0';
				}
				else 
				{
					tmp *= 10;
					tmp += buf[a] - '0';
				}
			}
			else
			{
				first = 1;
				if(tmp )
				dat.push_back(tmp);
				tmp = 0;
			}
		}

		if( tmp ) dat.push_back(tmp);

		// check all base... 
			for(int b = 2; b < 1000000; b++ )
			{
				int ok = 1;
				// b 가 dat[a] 진법이 아니면 스킵 
				for(int a = 0; a < dat.size(); a++ )	// base 	
				{
					if( happynumber( b, dat[a] ) == false )
					{
						ok = 0; break; 
					}
				}

				if( ok ) 
				{
					out << "Case #" << i << ": " << b << endl;
					cout << "Case #" << i << ": " << b << endl;
					break;
				}
			}
	}

	return 0;
}
