
#ifndef _INPUT_H
#define _INPUT_H

#include <list>
using namespace std;

class TestInput;

class Inputs {
public:

	Inputs();
	~Inputs();

	bool read(const string& file_path);

	int num_cases;
	list<TestInput*> tests;
};


class TestInput {
public:
	list<long> bases;
};

#endif
