#include<iostream>
#include<sstream>

using namespace std;

int used[100000];

bool isOk(int n, int k){
	memset(used, 0, sizeof(used));
	while (used[n] == 0){
		int m = n;
		used[m] = 1;
		int sum = 0;
		while (m > 0){
			int t = m % k;
			sum += t * t;
			m /= k;
		}
		n = sum;
	}
	if (n == 1)
		return true;
	return false;

}

int a[501];

int main(){
	int n = 0;
	cin >> n;
	string s;
	getline(cin, s);
	for (int t = 0; t < n; t++){
		stringstream ss;
		getline(cin, s);
		ss << s;
		int m = 0, k;
		while (ss >> k){
			a[m++] = k;		
		}
		bool ok = false;
		int p = 1;
		while (!ok){
			p++;
			ok = true;
			for (int i = 0; i < m; i++)
				if (!isOk(p, a[i])){
					ok = false;
					break;
				}
		}
		cout << "Case #" << t+1 << ": " << p << endl;
	}
	return 0;
}