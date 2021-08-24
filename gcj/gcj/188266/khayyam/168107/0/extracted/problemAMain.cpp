#include <iostream>
#include <sstream>
using namespace std;

void parseNextInput(int bases[], int &numBases){
	char buffer[1000];
	cin.getline(buffer, 1000);
	istringstream is(buffer);
	numBases=0;
	while(is>>bases[numBases]){
		++numBases;
	}
}

inline int next(int x, int base){
	int sol=0;
	while(x){
		int d=x%base;
		sol+=d*d;
		x/=base;
	}
	return sol;
}

inline bool isHappy(int x0, int base){
	if(x0==1){
		return true;
	}
	int x1=next(next(x0, base),base);
	x0=next(x0,base);
	while(x0!=x1 && (x1!=1) && (x0!=1)){
		x0=next(x0,base);
		x1=next(next(x1,base),base);
	}
	if((x1==1) || (x0==1))
		return true;
	return false;
}


int main(){
	int bases[10];
	int numBases;
	int T;
	cin>>T;
	parseNextInput(bases,numBases);
	for(int caseNum=1;caseNum<=T;++caseNum){
		parseNextInput(bases,numBases);
		int x=2;
		bool ok=false;
		while(!ok){
			ok=true;
			for(int i=0;i<numBases;++i)
				if(!isHappy(x,bases[i])){
					ok=false;
					break;
				}
			if(ok){
				cout<<"Case #"<<caseNum<<": "<<x<<endl;
				break;
			}
			++x;
		}
	}
	return 0;
}
