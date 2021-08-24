/*
 * fmain.cpp
 *
 *  Created on: 2009-9-12
 *      Author: sunguoyang07
 *	    E-mail: matrixworker@gmail.com
 *        Note: Solution for small data set, Round 1A, GCJ 2009
 */
#include <iostream>
#include <fstream>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <string.h>

using namespace std;

bool is_happy(int data, int base)
{
	set<int> all_gen;

	all_gen.insert(data);

	bool finish = false;
	while(!finish)
	{
		int temp=0;
		while(data)
		{
			int it=data%base;
			data/=base;
			temp+=it*it;
		}
		if(temp == 1)
			return true;
		else if(all_gen.find(temp)!=all_gen.end())
			return false;
		else
		{
			data=temp;
			all_gen.insert(temp);
		}
	}
}
int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	assert(fin);
	assert(fout);

	int T, cas=1;
	string line;

	getline(fin, line, '\n');
	T = atoi(line.c_str());

	set<int> baseset;
	char* d=" ";
	while(T--)
	{
		baseset.clear();
		getline(fin, line, '\n');
		char* cstr = new char [line.size()+1];
		strcpy (cstr, line.c_str());

		char* p=strtok(cstr, d);
		while(p)
		{
		  int base = atoi(p);
		  cout<<base<<" ";
		  baseset.insert(base);
		  p=strtok(NULL, d);
		}
		cout<<endl;

		//main process
		int result = 2;
		bool finished = false;
		while (!finished)
		{
			bool matched = true;
			set<int>::iterator iter=baseset.begin();
			while (iter != baseset.end())
			{
				if(!is_happy(result, *iter))
				{
					matched = false;
					break;
				}
				iter++;
			}
			if(matched)
			{
				finished=true;
			}
			else
			{
				result++;
			}
		}
		fout<<"Case #"<<cas++<<": "<<result<<endl;
	}

	fin.close();
	fout.close();

	return 0;
}
