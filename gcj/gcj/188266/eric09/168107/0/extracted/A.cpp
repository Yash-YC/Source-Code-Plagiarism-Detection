/*
 * A.cpp
 */

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

map<string, bool> dict; // num@@base -> true/false

// convert a decimal number to base #base
string convertTo(int num, int base) {
	string ret("");
	while(num) {
		ret.append(1, char(num%base+'0'));
		num/=base;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

// make a key
string makeKey(string num, int base) {
	string baseStr="";
	while(base) {
		baseStr.append(1, char(base%10+'0'));
		base/=10;
	}
	reverse(baseStr.begin(), baseStr.end());
	
	return num+string("@@")+baseStr;
}

bool isHappyNumber(int num, int base) {
	string curNum=convertTo(num, base); bool res;
	set<string> seen; seen.clear();
	while(true) {

		if(curNum.length()==1 && curNum[0]=='1') {
			res=true; break;
		}

		if(seen.find(curNum)!=seen.end()) {
			res=false; break;
		}

		string key=makeKey(curNum, base);
		if(dict.find(key)!=dict.end()) {
			res = dict[key];
			break;
		}
		
		// go further
		int sum=0;
		for(int i=0; i<curNum.length(); i++)
			sum+=int(curNum[i]-'0')*int(curNum[i]-'0');
		seen.insert(curNum);
		curNum=convertTo(sum, base);
	}
	
	for(set<string>::iterator it=seen.begin(); it!=seen.end(); it++) {
		dict[makeKey(*it, base)]=res;
	}
	
	return res;
}

void proc(int caseNum) {
	stringstream ins; string input;  
	getline(std::cin, input); 
	ins.str(input);
	vector<int> bases; int num;
	while(ins>>num) bases.push_back(num);
	
	num=2;
	while(true) {
		bool flag=true;
		for(int i=0; i<bases.size();i++) {
			if(!isHappyNumber(num, bases[i])) {
				flag=false;
				break;
			}
		}
		if(flag) {
			printf("Case #%d: %d\n", caseNum, num);
			break;
		}
		num++;
	}
}


int main( int argc, char* argv[] ) {
	int no; std::cin>>no;string input;  
	getline(std::cin, input); 
	for(int i=1; i<=no; i++)
		proc(i);
	return 0;
}

