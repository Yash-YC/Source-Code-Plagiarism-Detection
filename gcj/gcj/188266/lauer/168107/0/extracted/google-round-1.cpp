#include<iostream>
#include<map>
#include<fstream>
using namespace std;

int cvrt[1000000];
int place;
map<long long int,long long int > rec;
void convert(long long int n,int base)
{
	place = 0;
	while( n > 0 )
	{
		cvrt[ place++ ] = n%base;
		n/=base;
	}
}

bool check(long long int n ,int base)
{
	rec.clear();
	//cout << n << ' ' << base << endl;
	//system("pause");
	while(true)
	{
		convert( n,base );
		long long int total = 0;
		for(int i=0;i<place;i++)
			total += cvrt[i]*cvrt[i];
		//cout << total << endl;
		if(total == 1)
			return true;
		if( rec[ total ]>0 )
		{
			return false;
		}
		rec[ total ] = 1;
		n = total;
	}

}

int main()
{
	ofstream fout("out");
	int test;
	char tmp[100];
	int Base[10],size;
	cin >> test;
	cin.getline(tmp,100);
	int Case = 1;

	while( test > 0 )
	{
		test--;
		cin.getline(tmp,100);
		char *p = tmp;
		for(int i=0,j=0;;i++)
		{
			if(tmp[i]=='\0')
			{
				Base[j++] = atoi(p);
				size = j;
				break;
			}
			if( tmp[i]==' ')
			{
				Base[j++] = atoi(p);
				p += i;
			}
		}
		bool happy = true;
		for(long long int i=2;i>0;i++)
		{
			happy = true;
			for(int j=0;j<size;j++)
			{
				if( !check( i,Base[j] ) )
				{
					happy = false;
					break;
				}
			}
			if( happy )
			{
				fout << "Case #" << Case++ << ": ";
				fout << i << endl;
				break;
			}
		}
	}
}