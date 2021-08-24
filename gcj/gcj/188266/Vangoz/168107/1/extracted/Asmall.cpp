#include <iostream>
#include <sstream>
using namespace std;

int T;
long K;

int tabel[9][50000000];

int happy(int num, int base){	
	if (tabel[base-2][num] == 1) return 1;
	if (tabel[base-2][num] == -1) return 0;
	if (tabel[base-2][num] == 2) { tabel[base-2][num] == -1; return 0; }
	int y = 0;
	int x = num;
	while (x > 0){
		int mod = x%base;
		y += mod*mod;
		x /= base;
	}
	//cerr << tabel[base][num] << " " << base << " " << num << " " << y << endl;
	if (num == y){ tabel[base-2][num] = -1; return false; }
	else { 
		tabel[base-2][num] = 2; 
		int h=happy(y, base); 
		tabel[base-2][num] = tabel[base-2][y];
		return h;
	}
}

int main(){
	cin >> T;
	
	string s;
	for (int i=2; i<=10; i++) tabel[i-2][1] = 1;
	int basis[10];
		getline(cin, s);
	for (int i=1;i<=T; i++){
		stringstream ss (stringstream::in | stringstream::out);
		getline(cin, s);
		ss << s;
		int numbase = 0;
		while (ss >> basis[numbase]){ numbase++; }		
		int K = 2;
		cerr << i << endl;
		do {
			bool stop = true;
			for (int j=0; j<numbase; j++){
				if (!happy(K,basis[j])){
					stop = false;					
				}
			}
			//if (K>13) break;
			if (stop) break;
			K++;
		} while (true);
		cout << "Case #" << i << ": " << K << endl;
	}
}