#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <list>
using namespace std;
typedef long long LL;
#define F(i,n) for (int i = 0; i < (int)(n); i++)
main(){

	FILE *fin = freopen("A-large.in", "r", stdin);
	assert (fin != NULL);
	//cout << "A open ";
	FILE *fout = freopen("A-large.out", "w", stdout);
	//cout << "A created";
	string s;
	list<char> v;
	int n, T;
	
	cin >> T;
	//cout << "Test cases: " << T;
	for(int t = 1; t <= T; t++){
		cin >> s;
		n = s.length();
		v.clear();
		//v.push_back(s.at(0));
		F(i,n){
			if (i==0)
				v.push_front(s.at(i));
			else{

				if (s.at(i) >= v.front()){
					v.push_front(s.at(i));
				}
				else
					v.push_back(s.at(i));
			}	
		}
		
		cout << "Case #" << t << ": ";
		//F(i,n)
		//for (std::list<int>::iterator it=v.begin(); it != v.end(); ++it)
		//	cout << *it;
		
		//	cout << v[i]; 
		F(i,n){
			cout << v.front();
			v.pop_front();
		}
		cout << endl;
			


	}
	exit(0);
}
