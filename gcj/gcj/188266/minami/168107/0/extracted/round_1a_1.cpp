//============================================================================
// Name        : round_1a_1.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;

#include "Input.h"

bool
in_history(const list<long>& history, long number)
{
	for(list<long>::const_reverse_iterator rit = history.rbegin(); rit != history.rend(); ++rit)
	{
		if (number == *rit)
			return true;
	}
	return false;
}

bool
check_is_happy(long check, long base)
{
	list<long> history;
	// if not happy, cycle comes out.
	long number = check;
	long nextnumber;
	while(number != 1 && !in_history(history, number))
	{
		history.push_back(number);

		nextnumber = 0;
		while(number != 0)
		{
			long digit = number % base;
			number /= base;

			nextnumber += digit * digit;
		}

		number = nextnumber;
	}

	return number == 1;
}

long
check_smallest(TestInput* testcase)
{
	long check;
	for(check = 2; ; ++check)
	{
		list<long>::iterator it;
		for (it = testcase->bases.begin(); it != testcase->bases.end(); ++it)
		{
			if (!check_is_happy(check, *it))
			{
				break;
			}
		}
		if (it == testcase->bases.end())
		{
			return check;
		}
	}

	return 0L;
}

int main() {
	Inputs* input = new Inputs();
	input->read("A-small-attempt0.in");

	ofstream out("out-small.txt", ios::out);

	long counter = 1;
	for (list<TestInput*>::iterator it = input->tests.begin();
			it != input->tests.end(); ++it)
	{
		long num = check_smallest(*it);

		// output
		out << "Case #" << counter++ << ": " << num << endl;
	}

	delete input;
}
