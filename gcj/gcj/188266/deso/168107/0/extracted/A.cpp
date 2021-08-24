#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

//ifstream fin ("A-small.in");
ifstream fin ("A-small-attempt0.in");
ofstream fout ("A-small.out");
//ifstream fin ("A-large.in");
//ofstream fout ("A-large.out");

int N, N2 = 1;
char line[512];
bool was[1000000];

int main()
{
	fin >> N;
	fin.getline( line, 512);
	while(N2<=N)
	{
		fin.getline( line, 512);
		string stline = line;
		istringstream get(stline);
		int n = 0;
		int v[10];
		while( get >> v[n] ) n++;
		int hn = 2;
		bool go = true;
		while(go)
		{
			//cout << hn << endl;
			bool ok = true;
			for(int i=0; i<n && ok; i++)
			{
				//cout << v[i] << endl;
				int nn = hn;
				memset(was, 0, sizeof(was));
				was[nn] = 1;
				while( nn!=1 )
				{
					//cout << nn << " ";
					int aux = nn;
					nn = 0;
					while(aux)
					{
						nn += (aux%v[i])*(aux%v[i]);
						aux /= v[i];
					}
					if( was[nn] ) break;
					was[nn] = 1;
					//cout << nn << endl;
				}
				//system("pause");
				if( nn!=1 ) ok = false;
			}
			if( ok ) go = false;
			else hn++;
		}
		

		fout << "Case #" << N2 << ": " << hn << endl;
		N2++;
	}
return 0;
}


