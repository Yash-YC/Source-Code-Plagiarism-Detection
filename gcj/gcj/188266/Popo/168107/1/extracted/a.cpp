#include<iostream>
#include<sstream>
#include<cstring>
#define UP 12000000

using namespace std;

int small_happy[1024];
int happy_boss[11][UP];

int find_boss(int base, int val){
	if(happy_boss[base][val] != val) happy_boss[base][val] = find_boss(base, happy_boss[base][val]);

	return happy_boss[base][val];
}

int uni_boss(int base, int val1, int val2){
	happy_boss[base][find_boss(base, val1)] = find_boss(base, val2);
}

int show(int val, int base){
	int k = 0;
	int i = 1;

	while(val != 0){
		k += (val % base) * i;
		val /= base;
		i *= 10;
	}

	return k;
}

bool happy(int val, int base){
	//if(val == 1) return true;
	//if(used[val]) return false;
	//used[val] = true;

	int k = 0;
	int tmp = val;
	
	while(val != 0){
		register int tmp = val % base;
		k += tmp * tmp;
		val /= base;
	}

	uni_boss(base, k, tmp);
}

bool all_happy(int key, int val){
	for(int i = 2; key != 0; key >>= 1, ++i) if(key & 1){
		if(find_boss(i, val) != find_boss(i, 1)) return false;
	}

	return true;
}

int main(){
	//for(int i = 2; memset(used, 0, 65535), i <= 10; ++i) happy(1024, i, used);

	//return 0;

	for(int i = 2; i <= 10; ++i)
		for(int j = 0; j < UP; ++j)
			happy_boss[i][j] = j;

	for(int i = 2; i <= 10; ++i)
		for(int j = 0; j < UP; ++j)
			happy(j, i);
	

	for(int i = 1; i < 512; ++i){
		int j;
		for(j = 2; j < UP; ++j){
			if(all_happy(i,j)) break;
		}
		small_happy[i] = j;
	}

	int cs;
	string str;

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
	
	//for(int i = 1; i < 512; ++i){
	//	cout << small_happy[i] << endl;
	//}


	return 0;
}
