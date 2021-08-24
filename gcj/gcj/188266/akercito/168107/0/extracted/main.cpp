#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <queue>
#include <map>
#include <stack>
#include <algorithm>

using namespace std;

long long convertToDecimal (long long number, int base) {
	
	long long ans = 0, prod = 1;    
	while(number > 0) {
		  ans += number % 10 * prod;
		  prod *= base;
		  number /= 10;
	}
	return ans;
}

long long FromDecimal (long long number, int base) {

   long long ans = 0, prod = 1;
   while(number > 0 ){
	  ans += number % base * prod;
	  prod *= 10;
	  number /= base;
   }
   return ans;
}

bool isHappy (long long number, int base) {
	map<long long, bool> used;
	while (number != 1LL) {
		if (used[number] == true) {
			return false;
		}
		used[number] = true;
		ostringstream os;
		os << number;
		string n = os.str();
		long long sum = 0;
		for (int i = 0; i < n.size(); ++i) {
			int converted = convertToDecimal(n[i] - '0', base);
			sum += converted * converted;
		}
		if (sum == 1) return true;
		number = FromDecimal(sum, base);
	}
	return false;
}


int main () {

	freopen("a.txt", "r", stdin);
	freopen("a.out", "w", stdout);

	string buffer;
	getline(cin, buffer, '\n');
	int cases = atoi(buffer.c_str());

	for (int c = 0; c < cases; ++c) {
		
		getline(cin, buffer, '\n');
		istringstream input(buffer);
		vector<int> bases;
		int b;
		while (input >> b) {
			bases.push_back(b);
		}
		long long n = 2;
		while (true) {
			//cout << "en el while"<< endl;
			bool ok = true;
			for (int i = 0; i < bases.size(); ++i) {
				//long long converted = convertToDecimal(n, bases[i]);
				if (!isHappy(FromDecimal(n, bases[i]), bases[i])) {
					ok = false;
					break;
				}
				
			}
			if (ok) break;
			++n;
			//cout << n << endl;
		}
		cout << "Case #" << (c + 1) << ": " << n << endl;
	}
	//system("pause");
	return 0;

}