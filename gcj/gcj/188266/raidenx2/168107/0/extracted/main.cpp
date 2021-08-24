#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <fstream>

using namespace std;


vector<string> readFile(string fileName)
{
	ifstream file(fileName.c_str(), ios::in);

	vector<string> contenu;
	string line="";

	while( getline(file,line) )
		contenu.push_back(line);
	
	file.close();
	return contenu;
}

string convert(int num, int b)
{
	string temp = "";

	while(num)
	{
		int r = num % b;
		num = num / b;
		temp += r + '0';
	}

	reverse(temp.begin(), temp.end());
	return temp;
}

bool ishappy(string str, int base)
{

	int tab[100000];

	memset(tab, 0, sizeof(tab));


	while(str != "1")
	{
		int res = 0;
		for(int i=0; i < str.size(); ++i)
		{
			res += (str[i]-'0')*(str[i]-'0');
		}

		if( res == 1 )
			return true;
		
		if( tab[res] )
			return false;

		tab[res] = 1;

		str = convert(res, base);
	
	}
	
	return 1;
}

int main()
{
	ofstream file("out.txt");
	vector<string> contenu = readFile("in.txt");
	
	for(int i=1; i < contenu.size(); ++i)
	{
		vector<int> base;

		stringstream out;
		out << contenu[i];
		int temp;
		while( out >> temp )
		{
			base.push_back(temp);
		}
		
	
		for(int j=2; j < 1000000000; ++j)
		{
			bool happy = true;
		
			for(int k=0; k < base.size(); ++k)
			{
				string str = convert(j, base[k]);
				

				if( !ishappy(str, base[k]) )
				{
					happy = false;
					break;
				}
			}

			if( happy )
			{
				file << "Case #" << i << ": " << j << endl;
				break;
			}
		}
	}

	file.close();
	return 0;
}