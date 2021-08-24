#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <set>

using namespace std;
set <int> tested;

bool isHappy(int num, int bbase) {
	int tttt = num;
	if (tested.count(num) > 0) 
		return false;
	
	int tsum = 0;
	while (num > 0) {
		int tt = num % bbase;
		tsum += (tt * tt);
		num /= bbase;
	}
	if (tsum == 1) {
		tested.erase(tttt);
		return true;
	}
	else {
		tested.insert(tttt);
		return isHappy(tsum, bbase);
	}
}

int main() {
	ifstream cin ("test.in");
	ofstream cout ("test.out");
	
	int t;
	char buff[256];
	cin >> t;
	cin.getline(buff, 256);
	vector <int> data;

	for (int i = 0; i < t; ++i) {
		cin.getline(buff, 256);
		data.clear();
		
		stringstream ss(buff);
		int tt;
		while (ss >> tt) {
			data.push_back(tt);
		}
/*
		sort(data.begin(), data.end());
		int mulhap = 1;
		for (int j = 0; j < data.size(); ++j)
			mulhap *= data[j];
		
		for (int j = 2; ; ++j) {
			tested.clear();
			if (isHappy (j, mulhap)) {
				cout << "Case #" << i+1 << ": " << j << endl; 
				break;
			}
		}
		*/
		bool flag = true;
		for (int k = 2; ; ++k) {
			flag = true;
			for (int j = 0; j < data.size(); ++j) {
				tested.clear();
				if (!isHappy (k, data[j])) {
					flag = false;
					break;
				}
				
			}
			if (flag) {
				cout << "Case #" << i+1 << ": " << k << endl; 
				break;
			}
		}
			
	}

	return 0;
}
