#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <cstdlib>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <iterator>
#define MAX 100000
using namespace std;

string dec2base (int d, int b){
	string r;
	char n[]="0123456789";
	while (d!=0) {
		r= n[d%b] +r;
		d/=b;
	}
	return r.length()==0?"0":r;
}

bool isHappy( long int n, int b) {
	string nums=dec2base(n,b);
	set<string> m;
	int d;
	long int s;
	while(m.find(nums) == m.end() ){
		s=0;
		m.insert(nums);
		for (int i=0; i<nums.length(); i++) {
			d=nums[i]-'0';
			s+=d*d;
		}
		nums=dec2base(s,b);
		
		if (s==1) return true;
				
	}
	
	return false;
}

int main(){
	
	int k,b;
	long int n;
	set <long int> s[11];
	string linea;
	for (b=2; b<11; b++) {
		for ( n=2; n<MAX; n++) {
			if (isHappy( n, b))
				s[b].insert(n);
		}
	}

	

	scanf("%d\n", &k);
	for (int i=1; i<=k; i++) {
		vector <int> bases;
		getline(cin,linea);
		istringstream in (linea);
		while(in>>b) {
			bases.push_back(b);
		}
		int total=bases.size();
		set <long int> aux =s[bases[0]]; 
		for (int j=1; j<total; j++) {
			
			set <long int> tmp; 
			set_intersection(s[bases[j]].begin(), s[bases[j]].end(), aux.begin(), aux.end(),inserter(tmp, tmp.begin()));
			aux=tmp;
			
		}
		printf("Case #%d: %ld\n",i,*aux.begin());
		 
	}
	

	return 0;
}

