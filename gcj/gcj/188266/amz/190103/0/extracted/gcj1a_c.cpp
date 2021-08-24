#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <vector>
#include <map>
#include <list>
#include <cmath>

using namespace std;

void processCase(int lineN, istream& in, ostream& out)
{
	int C, N;
	in >> C >> N;

	double sum = 0;
	for (int i=1;i<=50;i++) {
		sum += double(N)/(pow(double(C),i)) * (i+1);
	}

	// Print result
	out << "Case #" << lineN << ": ";
	out << sum;
	out << endl;
}

int main()
{
	ifstream in("C-small-attempt0.in");
	//ostream& out = cout;
	ofstream out("C-small-attempt0.out", std::ios_base::out | std::ios_base::binary);

	int nCases;
	in >> nCases;
	for (int i=0; i<nCases; i++) {
		processCase(i+1, in, out);
	}

	out.flush();
}
