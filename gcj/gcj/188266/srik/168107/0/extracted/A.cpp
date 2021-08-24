#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;
#define RVAL int

int a[11][1001];
bool ah[11];
char line[1000];


int convadd(int n,int b){
	int ret=0,pw=1;
	//cout<<b<<endl;
	while(n){
		//cout<<n%b<<" "<<pw<<endl;
		pw=(n%b);
		pw*=pw;
		ret+=pw;
		n/=b;
	}
	return ret;
}
bool chk(int n,int b){
	int val=convadd(n,b);
	if(val==1){
		//cout<<" "<<n<<endl;
		if(n<1001)a[b][n]=true;
		return true;}
	if(n>1000){
		return chk(val,b);
	}
	if(a[b][n]!=-1)return a[b][n];
	a[b][n]=0;
	a[b][n]=chk(val,b);
	return a[b][n];
}

void dobase(int b){
	//cout<<"Begin "<<b<<endl;
	for(int i=1;i<1001;i++){
		//cout<<"Chk "<<i<<endl;
		chk(i,b);
		//if(b==7 && a[b][i]==1)cout<<" "<<i<<endl;
	}
	
}
bool allhappy(int n){
	for(int i=10;i>1;i--)
	if(ah[i]){
		if(!chk(n,i)){return false;}
	}
	return true;
}

vector <RVAL> dlimit(string str,char* dlim){
  char cstr[1001]; //***check whether the size is okay***
  vector <RVAL> ret;
  strcpy(cstr,str.c_str());
  char *res = strtok(cstr,dlim);
  while(res!=NULL){
    ret.push_back(atoi(res));  //***this line needs modification based on return type***
    res=strtok(NULL,dlim);
  }
  return ret;
 
}


void doit(){
	memset(ah,0,sizeof(ah));
	vector <RVAL> ret;
	cin.getline(line,1000);
	ret = dlimit(line," ");
	int rs=ret.size();
	for(int i=0;i<rs;i++)ah[ret[i]]=true;
	for(int i=2;i<11814486;i++){
		if(allhappy(i)){cout<<i<<endl;return;}
	}
}
int main(){
	int tc;
	memset(a,-1,sizeof(a));
	for(int i=2;i<11;i++)
		dobase(i);
	cin.getline(line,1000);
	tc=atoi(line);
	for(int i=1;i<=tc;i++){
		cout<<"Case #"<<i<<": ";
		doit();
	}
	return 0;
}
