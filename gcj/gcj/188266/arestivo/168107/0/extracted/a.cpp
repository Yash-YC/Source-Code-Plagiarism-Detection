#include <iostream>
#include <map>
#include <sstream>
#include <vector>

using namespace std;

long long pow(long long b, int e) {
  long long t = 1;
  for (; e; b *= b, e >>= 1) if (e & 1) t *= b;
  return t;
}


long long strtoint(string & s, int base) {
	int exp = 0;
	long long total = 0; 
	for (int i = s.length() - 1; i >= 0; i--) {
		total += (s[i] - '0') * pow(base, exp++);
	}
	return total;
}

string inttostr(long long number, int base) {
	int exp = 0;
	string str = "";
	long long n = number;
	while (pow(base, exp) < n) exp++;
	while (exp >= 0) {
		long long e = pow(base, exp--);
		if (n >= e) {str += '0' + (n / e); n -= (n / e) * e; }else if (str != "") str += "0";
	}
	if (str == "") str = "0";
	return str;
}

long long nexthappy(long long num, int base) {
	string s = inttostr(num, base);
	long long total = 0;
	for (int i = 0; i < s.length(); i++) {
		int d = s[i] - '0';
		total += d * d;
	}

	return total;
}

bool ishappy(long long num, int base) {
	map<long long, bool> m;

	while (num != 1) {
		if (m.find(num) != m.end()) return false;		
		m[num] = true;
		num = nexthappy(num, base);
	}
	return true;
}

long long findlarger() {
	string s; getline(cin, s);
	istringstream is; is.str(s);
	vector<int> bases;

	int b;
	while (is >> b) {
		bases.push_back(b);
	}	

	int l = 2;
	while (true) {
		bool found = true;
		for (int b = 0; b < bases.size(); b++) {
			if (!ishappy(l, bases[b])) {found = false; l++; break;}
		}
		if (found) return l;
	}

	return 0;
}

int main() {
	int t; cin >> t;
	string dummy; getline(cin, dummy);
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": " << findlarger() << endl;	
	}
}
