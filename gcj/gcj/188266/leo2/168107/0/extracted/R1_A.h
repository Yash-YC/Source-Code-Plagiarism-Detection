#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

class mbase{
public:
	map<int,int> mlst;

	int isHappy(int iNum, int iBase){
		bool bhappy = false;
		int iCnt = 0;
		mlst.clear();
		mlst.insert(pair<int,int>(iNum,0));
		while(true){
			iCnt++;
			int iNumNext = 0;
			while(iNum){
				int id = iNum % iBase;
				iNumNext += id*id;
				iNum = iNum/iBase;
			}
			if(iNumNext==1){
				bhappy = true;
				break;
			}
			if(!iNumNext || mlst.find(iNumNext) != mlst.end()){
				break;
			}
			iNum = iNumNext;
			mlst.insert(pair<int,int>(iNum,0));
		}
		if(bhappy)
			return iCnt;
		else
			return -1;
	}


};
