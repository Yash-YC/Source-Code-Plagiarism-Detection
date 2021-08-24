#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include <algorithm>
#include <math.h>
#include <map>
#include <sstream>
#include <stdio.h>
#include <math.h>
#include <set>

std::set<int> string;


std::string itos(int a)
{
	char buf[10];
	itoa(a, buf, 10);
	return std::string(buf);
}

std::string ftos(float f)
{
	std::ostringstream oss;
	oss << f;
	return oss.str();
}
int					stoi(std::string s)
{
	return atoi(s.c_str());
}

inline bool space(char c)
{
	return c == ' ' || c == '\t' || c == '\n';
}

inline bool notspace(char c)
{
	return !space(c);
}

//break a sentence into words
std::vector<std::string> split(const std::string& s)
{
	std::vector<std::string> ret;
	std::string::const_iterator i = s.begin();
	while(i != s.end())
	{
		i = std::find_if(i, s.end(), notspace); // find the beginning of a word
		std::string::const_iterator j = std::find_if(i, s.end(), space); // find the end of the same word
		if(i != s.end())
		{
			ret.push_back(std::string(i, j)); //insert the word into std::vector
			i = j; // repeat 1,2,3 on the rest of the line.
		}
	}
	return ret;
} 


int convertDecToAnyBase(int decimal, int idx_base)
{

	int res_base = 0;


	int rank = 0;
	//decimal -> base
	while (decimal != 0)
	{
		int cur_digit = decimal % idx_base;
		res_base = cur_digit * ((int)powf(10, rank)) + res_base;
		rank++;
		decimal = decimal / idx_base;

	} 
	return res_base;
}

unsigned long long int computeHappyNumber(int res, int idx_base)
{
	int decimal = 0;

	int rank = 0;

	int old_res = res;

	// base -> happy decimal
	while (res != 0) 
	{
		int digit = res % 10;
		decimal += digit * digit;
		res = res / 10;
	}

	rank = 0;
	int res_base = 0;
	int old_decimal = decimal;

	//decimal -> base
	while (decimal != 0)
	{
		int cur_digit = decimal % idx_base;
		res_base = cur_digit * ((int)powf(10, rank)) + res_base;
		rank++;
		decimal = decimal / idx_base;

	} 
//	std::cout << old_res << " " << old_decimal << " " << res_base << std::endl;
	return res_base;
}


bool checkBase(int res, int idx_base)
{
	if (res == 0)
		return false;
	if (res == 1)
		return true;
	if (idx_base == 2 || idx_base == 4)
		return true;
	if (idx_base == 3)
	{
		if (res == 2 || res == 12 || res == 22)
			return false;
	}
	if (idx_base == 5)
	{
		if (res == 4 || res == 23 || res == 33)
			return false;
	}
	if (idx_base == 6)
	{
		if (res == 32)
			return false;
	}
	if (idx_base == 7)
	{
		if (res == 2 || res == 34 || res == 13 || res == 23 || res == 63 || res == 44)
			return false;
	}
	if (idx_base == 8)
	{
		if (res == 4 || res == 5 || res == 32 || res == 24 || res == 64)
			return false;
	}
	if (idx_base == 9)
	{
		if (res == 55 || res == 58 || res == 45 || res == 75)
			return false;
	}
	if (idx_base == 10)
	{
		if (res == 4)
			return false;
	}

	int newValue = computeHappyNumber(res, idx_base);
//	std::cout << "new value: " << newValue << std::endl;
	return checkBase(newValue, idx_base);
}

int main(int argc, char *argv[])
{
	computeHappyNumber(32, 6);

	std::ifstream input(argv[1]);

	int nbCases;

	input >> nbCases;

	//FIXME
	char buf[1024];
	input.getline(buf, 1024);

	for (int iter_case = 0; iter_case < nbCases; iter_case++)
	{

		input.getline(buf, 1024);

		std::string line(buf);

		std::vector<std::string> words = split(line);

		int nbBase = words.size();
		int base[10];

		for (int i = 0; i < nbBase; i++)
			base[i] = stoi(words[i]);		
		int res = 2;
		for (int idx_base = 0; idx_base < nbBase; idx_base++)
		{
			int valueInBase = convertDecToAnyBase(res, base[idx_base]);
			if (checkBase(valueInBase, base[idx_base]))
				continue;
			else
			{
				res++;
				idx_base = -1;
			}
		}
		std::cout << "Case #" << iter_case + 1 << ": " << res << std::endl;		
	}
}
