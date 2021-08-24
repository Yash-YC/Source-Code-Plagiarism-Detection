

#include <fstream>
#include <sstream>
#include "Input.h"

using namespace std;

Inputs::Inputs()
{
}

Inputs::~Inputs()
{
	for (list<TestInput*>::iterator it = tests.begin(); it != tests.end(); ++it)
	{
		delete *it;
	}
	tests.clear();
}

bool
Inputs::read(const string& file_path)
{
	ifstream in(file_path.c_str());

	if (!in.is_open())
	{
		return false;
	}

	string line;
	getline(in, line);
	stringstream linestream(line);

	linestream >> this->num_cases;

	while(getline(in, line))
	{
		stringstream teststream(line);

		TestInput* test = new TestInput();

		string num;
		while(getline(teststream, num, ' '))
		{
			test->bases.push_back(atoi(num.c_str()));
		}

		this->tests.push_back(test);
	}

	return true;
}
