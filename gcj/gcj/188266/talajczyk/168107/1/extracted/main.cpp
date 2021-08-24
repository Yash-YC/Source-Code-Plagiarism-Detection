#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

int T;

vector<int> bases;

const int max_check = 12000000;

vector<int> numbers;


bool is_happy(int b, int n) {
	int s=n; 
	int k=20;
	do {
		n=s;
		s=0;
		while(n > 0) {
			int c= n%b;
			s+=c*c;
			n=n/b;
		}
		k--;
	} while ((s!=1) && (k>0));
	return (s==1);
}

int find_min_happy() {
	int x=2;
	while(true) {
		bool ok=true;
		for(int i=0; i<bases.size(); i++)
			if (!is_happy(bases[i], x)) {
				ok=false;
				break;
			}
		if (ok)	
			return x;
		x++;
	}
	return -1;
}

void check_all_numbers() {
	numbers.resize(max_check);
	for(int x=2; x<numbers.size(); x++) {
		int v = 0;
		for(int i=2; i<=10; i++)
			if (is_happy(i, x)) {
				v = v | (1 << i);
			}
		
		numbers[x]=v;
	}	
}

int find_min_happy2() {
	int v = 0;
	for(int i=0; i<bases.size(); i++) {
		v = v | (1 << bases[i]);
	}
	
	for(int x=2; x<numbers.size(); x++) 
		if ((numbers[x] & v) == v) 
			return x;

	return -1;
}


int main() {	
	check_all_numbers();
		
	cin >> T;
	string line;
	getline (cin,line);			
	for(int i=0; i<T; i++) {
		int tmp;
		getline (cin,line);
		istringstream iss(line);
		bases.clear();
		
		while(true)
		{
			int sub;
			iss >> sub;
			if (!iss)
				break;
			bases.push_back(sub);			
		}
							
		cout << "Case #" << (i+1) << ": " << find_min_happy2() << endl;
	}
	return 0;
}
