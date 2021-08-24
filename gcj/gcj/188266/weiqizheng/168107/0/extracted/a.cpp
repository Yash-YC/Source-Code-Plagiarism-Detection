#include <iostream>
#include <map>
#include <sstream>
#include <string>
using namespace std;


map<int,int> happy[3];
int bases[3];
int baseCount;

int square(int x){
	return x*x;
}

bool isHappy(int number,int base){
	int index;
	for(index=0;index<baseCount;index++)
		if(bases[index]==base)
			break;
	if(happy[index].find(number)!=happy[index].end()){
		if(happy[index][number]==-1)
			return true;
		else
			return false;
	}
	happy[index][number]=number;
	int next = 0;
	for(int tmp=number;tmp!=0;tmp/=base)
		next += square(tmp%base);
	if(next==1){
		happy[index][number]=-1;
		return true;
	}
	bool ret = isHappy(next,base);
	if(ret)
		happy[index][number]=-1;
	return ret;
}


int main(){
	int T;
	char line[20];

	cin>>T;
	cin.getline(line,20);
	for(int i=1;i<=T;i++){
		cin.getline(line,20);
		stringstream baseLine(line);
		int base = 0;
		baseCount=0;
		while(baseLine>>base){
			bases[baseCount++]=base;
		}
		for(int j=0;j<3;j++){
			happy[j].clear();
		}
		
		int j = 0;
		for( j=2; true ;j++){
			bool ret = true;
			for(int k=0;k<baseCount;k++){
				ret = isHappy(j,bases[k]);
				if(!ret)
					break;
			}
			if(ret)
				break;
		}
		cout<<"Case #"<<i<<": "<<j<<endl;
	}
}