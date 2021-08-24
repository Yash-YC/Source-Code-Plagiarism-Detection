#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream fin("in.txt");
	ofstream fout("out.txt");
	int t;
	double n;
	double c;
	fin >> t;
	for (int z=1; z<=t; z++)
	{
		while (fin >> c >> n)
		{
			if (n>=c)
				fout << "Case #" << z << ": " << 1 <<endl;
			else 
				fout << "Case #" << z << ": " << (n+c)/n <<endl;
		}
		
	}
	fin.close();
	fout.close();
	return 0;
}