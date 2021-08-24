#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <vector>
#include <map>
#include <list>
#include <cmath>
#include <sstream>

using namespace std;
char buffer[1024*1024];
map<int, map<int, bool>> baseMap;

int getNext(int n, int baseN)
{
	int accum = 0;
	while (n > 0) {
		int digit = n % baseN;
		accum += digit * digit;
		n /= baseN;
	}
	return accum;
}

bool isHappy(int n, int baseN)
{
	if (n == 1)
		return true;
	map<int, bool>& base = baseMap[baseN];
	map<int,bool>::iterator res = base.find(n);
	if (res != base.end()) {
		return res->second;
	} else {
		base[n] = false;
		bool result = isHappy(getNext(n, baseN), baseN);
		base[n] = result;
		return result;
	}
}

void processCase(int lineN, istream& in, ostream& out)
{
	in.getline(buffer, 1024*1024);
	stringstream line(buffer);

	vector<int> bases;
	while (!line.eof()) {
		int n;
		line >> n;
		bases.push_back(n);
	}

	int result = 0;
	for (int i=2; true; i++) {
		bool happy = true;
		for (size_t base=0; base<bases.size(); base++) {
			if (!isHappy(i, bases[base])) {
				happy = false;
				break;
			}
		}
		if (happy) {
			result = i;
			break;
		}
	}

	if (result == 0) {
		throw exception();
	}

	// Print result
	//string result = line;
	out << "Case #" << lineN << ": ";
	out << result;
	out << endl;
}

int main()
{
	ifstream in("A-large.in");
	//ostream& out = cout;
	ofstream out("A-large.out", std::ios_base::out | std::ios_base::binary);

	int nCases;
	in >> nCases;
	char tmp[2];
	in.getline(tmp, 2);
	for (int i=0; i<nCases; i++) {
		processCase(i+1, in, out);
	}

	out.flush();
}
