#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;

int small_happy[512];

int main(){
	string str;
	int cs;

	ifstream is("a.mem");

	for(int i = 1; i < 512; ++i)
		is >> small_happy[i];


	cin >> cs;
	getline(cin, str);

	for(int tc = 1; tc <= cs && getline(cin, str); ++tc){
		istringstream in(str);	
		int v;
		int k = 0;

		while(in >> v){
			k |= 1 << (v-2);
		}

		cout << "Case #" << tc << ": "<< small_happy[k] << endl;
	}

	return 0;
}
