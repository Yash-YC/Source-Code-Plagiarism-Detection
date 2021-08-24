#include <iostream>
#include <fstream>
using namespace std;

#include "R1_A.h"

int main(int argc , char** argv){

	ifstream ifs;
	if(argc>1){
		ifs.open(argv[1]);
	}else{
		ifs.open("input.txt");
	}
	if(!ifs.good())
		return -1;

	int iSize=0;
	ifs >> iSize;

	mbase mbs;

	long iMax = 1;
	ofstream ofs("output.txt");
	for(int i=0;i<=iSize;i++){
		string str="";
		iMax = 1;
		vector<int> vbs;
		while(!ifs.eof()){
			char c;
			ifs.get(c);
			if(c=='\n'){
				if(str.empty())
					break;
				int ibs = atoi(str.c_str());
				vbs.push_back(ibs);
				str = "";
				break;
			}
			if(c==' '){
				if(str.empty())
					break;
				int ibs = atoi(str.c_str());
				vbs.push_back(ibs);
				str = "";
			}else{
				str += c;
			}
		}
		if(!vbs.size())
			continue;
		int iret = 0;
		for(int i=2;;i++){
			bool bcnt = true;
			for(int j=0;j<vbs.size();j++){
				if(mbs.isHappy(i,vbs.at(j)) < 0)
					break;
				if(j == vbs.size()-1)
					bcnt = false;
			}
			if(!bcnt){
				iret = i;
				break;
			}
		}
		cout << "Case #" << i << ": " << iret << endl;
		ofs << "Case #" << i << ": " << iret << endl;
	}

	ifs.close();
	ofs.close();

	return 0;
}
