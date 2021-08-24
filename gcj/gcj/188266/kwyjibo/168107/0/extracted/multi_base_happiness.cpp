// multi_base_happiness.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <fstream>
#include <vector>
#include <list>
#include <set>
#include <string>


typedef std::list<long long> bases_list_t;
typedef std::list<bases_list_t> bases_list_list_t;



void load_data(std::istream &in, bases_list_list_t &bll)
{
	std::string sT;
	int T;

	std::getline(in, sT);
	T = strtoul(sT.c_str(), NULL, 10);

	for (int k = 0U; k < T; k++) {
		//
		bases_list_t bl;

		//
		std::string l;

		std::getline(in, l);

		//
		std::string::size_type i = l.find_first_not_of(" ");

		while (i != std::string::npos) {
			std::string::size_type j = l.find_first_of(" ", i);

			if (j != std::string::npos)
				bl.push_back(strtol((l.substr(i, j - i)).c_str(), NULL, 10));
			else {
				bl.push_back(strtol((l.substr(i)).c_str(), NULL, 10));
				break;
			}

			i = j + 1;
		}

		bll.push_back(bl);
	}
}

bool is_happy(long long v, long long b)
{
	std::set<long long> steps;

	while (v > 1) {
		steps.insert(v);

		long long aux = 0;

		do {
			aux += (v % b) * (v % b);
			v /= b;
		} while (v > 0);

		if (steps.find(aux) != steps.end())
			break;

		v = aux;
	}

	return (v == 1) ? true : false;
}

long long compute(const bases_list_t &bl)
{
	long long n;

	for (n = 2; ; n++) {
		bool is;

		for (bases_list_t::const_iterator i = bl.begin(); i != bl.end(); i++) {
			is = is_happy(n, *i);
			
			if (is == false)
				break;
		}

		if (is == true)
			break;
	}

	return n;
}

void process_data(std::ostream &out, bases_list_list_t &bll)
{
	for (int i = 0; bll.empty() == false; i++) {
		out << "Case #" << (i + 1) << ": " << compute(bll.front()) << std::endl;

		bll.pop_front();
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
// 	std::ifstream in("sample.in");
//	std::ofstream out("sample.out");
	std::ifstream in("A-small-attempt3.in");
	std::ofstream out("A-small-attempt3.out");

	bases_list_list_t bll;

	load_data(in, bll);
	process_data(out, bll);

	return 0;
}

