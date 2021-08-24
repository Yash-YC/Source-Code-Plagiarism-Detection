#include <iostream>
#include <fstream>
using namespace std;


bool happy(int n, int base);
int onbase(int n, int base);
int main()
{
	ifstream fin("in.txt");
	ofstream fout("out.txt");

	int t;
	int b;
	int z;
	int base[10];
	int n;
	int num;
	int found;
	bool ok;
	int sum;
	int used;
	fin >> t;
	z = 0;
	while (t > 0)
	{ 
		z++;
		n = 0;
		do 
		{
			fin >> base[n++];
		}while (fin.get() != '\n');
		num = 1;
		found = false;
		for (num=2; num <100000; num++)
		{
			found = 0;
			for (int i=0; i<n; i++)
			{
				used  = num;
				ok = false;
				for (int j=0; j<10000; j++)
				{
					sum = 0;
					while (used > 0)
					{
						b = used % base[i];
						sum += b * b;
						used /= base[i];
					}
					if (sum == 1)
					{
						ok= true;
						break;
					}
					used = sum;
				}
				if (ok)
					found ++;
			}
			if (found == n)
				break;
		}
		fout << "Case #" << z << ": " << num << endl;
		t--;
	}

	fin.close();
	fout.close();
	return 0;
}
bool happy(int n, int base)
{
	if (n == 1)
		return true;

	int sum = 0;
	int t;
	while (n > 0)
	{
		t = n % base;
		sum += t * t;
		n /= base;
	}
	
	return happy(sum, base);
}