#include<iostream>
#include <fstream>
#include <sstream>
#include <istream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


vector<int*> cycle(11);

long long int get_in_base(long long int nbr, int base)
{
	long long int res = 0;
	long long int accu = 1;
	while (nbr != 0)
	{
		
		res += accu  * (nbr % base);
		accu *= 10;
		nbr /= base;
	}
	return res;
}

int is_cycle(long long int nbr, int base)
{
	int i = 0;
	while (cycle[base][i] != 0)
	{
		if (cycle[base][i] == nbr)
			return 1;
		i++;
	}
	return 0;
}


int is_happy(long long int nbr, int base)
{
	if (is_cycle(get_in_base(nbr, base), base))
		return 0;
	while (nbr != 1)
	{
		//std::cout << nbr << " "<< get_in_base(nbr, base)<< " " << base << endl;
		nbr = get_in_base(nbr, base);
		if (is_cycle(nbr, base))
			return 0;
		long long int newNbr = 0;
		while (nbr)
		{
			newNbr += (nbr % 10) * (nbr % 10);
			nbr /= 10;
		}
		nbr = newNbr;
	}
	return 1;
}


int main(int argc, char** argv)
{
	int tab3[ 100 ] = {2, 11, 12, 22, 0} ;
	int tab5[ 100 ] = {4, 31, 20, 23, 33, 0} ;
	int tab6[ 100 ] = {32, 21, 5, 41, 25, 45, 105, 42, 32, 0} ;
	int tab7[ 100 ] = {2, 4, 22, 11, 34, 13, 23, 16, 52, 41, 63, 44, 0};
	int tab8 [100 ] = {4, 20, 5, 31, 12, 32, 15, 24, 64,0};
	int tab9 [100 ] = {55, 58, 108, 72, 45, 75, 82, 0};
	int tab10 [100 ] = {4, 16, 37, 58, 89, 145, 42, 20, 0};
	
	cycle[3] = tab3;
	cycle[5] = tab5;
	cycle[6] = tab6;
	cycle[7] = tab7;
	cycle[8] = tab8;
	cycle[9] = tab9;
	cycle[10] = tab10;


	std::ifstream file (argv[1]);
	int NbrCase;
	char str[2000];
	file >> NbrCase;
	file.getline(str, 2000);
	for (int k = 1; k <= NbrCase; ++k)
	{
		
		long long int total = 2;
		file.getline(str, 2000);
		stringstream line(stringstream::in | stringstream::out);
		line << str;
		vector<int> bases;
		
		while (!line.eof())
		{
			int base;
			line >> base;
			if (base != 2 && base != 4)
				bases.push_back(base);
		}
	
		if (0 != bases.size())
		{
			for (long long int i = 2; ; ++i)
			{
				bool is_good = true;
				for (int j = 0; is_good && j < bases.size(); ++j)
					is_good = is_happy(i, bases[j]);	
				total = i;
				if (is_good)
					break;
			}
		}


		std::cout << "Case #" << k << ": " << total << endl;
	}
	return 0;
}
