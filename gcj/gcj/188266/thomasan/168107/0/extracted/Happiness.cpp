#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

void print_base(vector<int> v) {
	for (int i = 0; v[i] != 0; i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

void cal_digit(unsigned int n, unsigned int base, vector<int> &digit) {
	if (n == 0)
		return;
	digit.push_back(n % base);
	cal_digit(n / base, base, digit);
}

bool is_in(unsigned int r, const vector<int> &d) {
	for (int i = 0; i < d.size(); i++) {
		if (r == d[i])
			return true;
	}
	return false;
}

vector<int> d;
bool is_happy(unsigned int n, unsigned int base) {
	if (n == 1)
		return true;
	vector<int> digit;
	d.push_back(n);
	cal_digit(n, base, digit);

	unsigned int r = 0;
	for (int i = 0; i < digit.size(); i++) {
		r += digit[i] * digit[i];
	}
	if (is_in(r, d))
		return false;
	else
		d.push_back(r);
	return is_happy(r, base);

}

int main() {
	string filename;
	cin >> filename;
	string infile = filename + ".in", outfile = filename + ".out";
	ifstream inf(infile.c_str());
	ofstream outf(outfile.c_str());

	int tc;
	string line;
	getline(inf, line);
	istringstream iss(line);
	iss >> tc;

	for (int t = 1; t <= tc; t++) {
		vector<int> base(9, 0);
		getline(inf, line);
		iss.clear();
		iss.str(line);
		int i = 0;
		while (iss) {
			iss >> base[i++];
		}
		//print_base(base);
		int result = 2;
		while (true) {
			bool flag = false;
			for (int i = 0; base[i] != 0; i++) {
				d.clear();
				if (!is_happy(result, base[i])) {
					flag = true;
					break;
				}
			}
			if (flag)
				result++;
			else
				break;
		}
		outf << "Case #" << t << ": " << result << endl;
		cout << "Case #" << t << ": " << result << endl;
	}

	return 0;
}
