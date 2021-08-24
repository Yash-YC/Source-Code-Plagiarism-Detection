#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <math.h>
#include <sstream>
#include <fstream>
using namespace std;

long long int next(long long int input){
	long long int sum=0;
	while (input!=0){
		sum+=(input%10)*(input%10);
		input/=10;
	}
	return sum;
}

long long int convertBase(long long int input,int base){
	long long int sum=0;
	int count=0;
	while (input!=0){
		sum+=pow(10.0,count)*(input%base);
		count++;
		input/=base;
	}
	return sum;
}

bool checkH(long long int input,int base){
	if (base==2 || base==4)//done by hand. all numbers are happy in these bases
		return true;
	if (base==3){
		while (true){
			input=convertBase(input,3);
			if (input==2 ||input==11 ||input==12 ||input==22)
				return false;
			if (input==1)
				return true;
			input=next(input);
		}
		return false;
	}
	if (base==5){
		while (true){
			input=convertBase(input,5);
			if (input==4 ||input==31 ||input==20 ||input==23 || input==33)
				return false;
			if (input==1)
				return true;
			input=next(input);
		}
		return false;
	}
	if (base==7){
		while (true){
			input=convertBase(input,7);
			if (input==2 ||input==11 ||input==4 ||input==22||input==34 ||input==13 ||input==23 ||input==16 ||input==52 ||input==41 ||input==63 ||input==44)
				return false;
			if (input==1)
				return true;
			input=next(input);
		}
		return false;
	}
	if (base==6){
		while (true){
			input=convertBase(input,6);
			if (input==32 ||input==21 ||input==5 ||input==41||input==25 ||input==45 ||input==105 ||input==42 )
				return false;
			if (input==1)
				return true;
			input=next(input);
		}
		return false;
	}
	if (base==8){
		while (true){
			input=convertBase(input,8);
			if (input==4 ||input==20 ||input==12 ||input==5||input==31 ||input==32 ||input==15 ||input==24 ||input==64)
				return false;
			if (input==1)
				return true;
			input=next(input);
		}
		return false;
	}
	if (base==9){
		while (true){
			input=convertBase(input,9);
			if (input==72 ||input==55 ||input==58 ||input==108||input==45 ||input==75 ||input==82)
				return false;
			if (input==1)
				return true;
			input=next(input);
		}
		return false;
	}
	if (base==10){
		while (true){
			if (input==4 ||input==16 ||input==37 ||input==58||input==89 ||input==145 ||input==42||input==20)
				return false;
			if (input==1)
				return true;
			input=next(input);
		}
		return false;
	}
	return false;
}

int main(){
	ifstream inputf;
	fstream outputf;	
	string inputFile;
	cin >> inputFile;
	inputf.open(inputFile.c_str(),fstream::in);
	if (!inputf){
		cout<<"No file!";
		return -1;
	}
	string outFile=inputFile;
	outFile.append("out");
	outputf.open(outFile.c_str(),fstream::out);
	int N;
	inputf >> N;
	inputf.ignore(1,'\n');
	for (int cntN=0;cntN<N;cntN++){
		string line2;
		getline(inputf,line2);
		stringstream line(line2);
		vector<int> bases;
		int vl=0;
		while (line>>vl){
			if (vl!=2 && vl!=4)
				bases.push_back(vl);
		}
		int cur=2;
		while(true){
			bool flag=true;
			for (vector<int>::iterator it=bases.begin();it!=bases.end();it++){
				if (!checkH(cur,*it)){
					flag=false;
					break;
				}
			}
			if (flag){
				outputf<<"Case #"<<cntN+1<<": "<<cur<<endl;
				break;
			}
			cur++;
		}
	}
	inputf.close();
	outputf.close();
	return 0;
}
	
