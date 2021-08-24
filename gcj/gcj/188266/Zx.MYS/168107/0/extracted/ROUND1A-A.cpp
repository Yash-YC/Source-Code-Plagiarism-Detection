#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cassert>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<list>
#include<sstream>
using namespace std;
#define LOOP(x,y,z) for((x)=(y);(x)<=(z);(x)++)
#define LOOPB(x,y,z) for((x)=(y);(x)<(z);(x)++)
#define RLOOP(x,y,z) for((x)=(y);(x)>=(z);(x)--)
#define RLOOPB(x,y,z) for((x)=(y);(x)>(z);(x)--)
#define ABS(x) ((x)<0?-(x):(x))
#define PI 3.1415926535898
int i,j,k,a,m,n,s,t,l,tt,cas;
const int oo=1<<29;
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
istringstream inss;
vector<int> bases;
string strtmp;
set<int> cir;


inline bool lucky(int num,int base){
    if(num==1)return true;
    cir.clear();
    int now=num,k,tmp,i,j,l;
    cir.insert(now);
    while(1){
        k=int(log(now)/log(base)+1e-8);
        tmp=0;
        j=(int)pow((float)base,k);
        while(now&&j){
            l=now/j;
            tmp+=l*l;
            now%=j;
            j/=base;
        }
        now=tmp;
        if(now==1)return true;
        if(cir.find(now)!=cir.end())return false;
        cir.insert(now);
    }
}

inline bool test(int num){
    int i;
    LOOPB(i,0,bases.size())
        if(!lucky(num,bases[i]))return false;
    return true;
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d\n",&cas);
tt=0;
while(cas--){
    printf("Case #%d: ",++tt);
    bases.clear();
    getline(cin,strtmp);
    inss.clear();
    inss.str(strtmp);
    while(inss>>a){
        bases.push_back(a);
    }
    j=2;
    while(!test(j)){
        j++;
    }
    printf("%d\n",j);
}
}
