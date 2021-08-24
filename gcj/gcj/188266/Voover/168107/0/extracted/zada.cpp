#include <cstdio>
#include <vector>
#include <list>

using namespace std;
const int maxres=100000;
int proccess(int k, int base){
  int result=0;
  while(k>0){
    int t=k%base;
    result+=t*t;
    k/=base;
  }
  return result;
}

int main(){
  int tab[maxres][11];
  for(int i=0; i<maxres; i++)
    for(int j=0; j<11; j++)
	tab[i][j]=0;
  for(int j=0; j<11; j++)
    tab[1][j]=1;
  for(int j=2;j<=10; j++)
  for(int i=2;i<maxres; i++){
    if(tab[i][j])continue;
    int p=i;
    list<int> mod;
    while(!tab[p][j]){
	tab[p][j]=-1;
	mod.push_back(p);
	p=proccess(p,j);
    }
    if(tab[p][j]==1)
	for(list<int>::iterator it=mod.begin(); it!=mod.end(); it++)
	   tab[*it][j]=1;
  }
  int T;
  scanf("%d\n",&T);
  for(int caseid=1; caseid<=T; caseid++){
    list<int> bases;
    while(true){
      int n;
      char c;
      scanf("%d",&n);
      bases.push_back(n);
      scanf("%c",&c);
      if(c=='\r' || c=='\n')
	break;
    }
    int i=2;
    for(;i<maxres;i++){
      bool flaga=true;
      for(list<int>::iterator it=bases.begin(); it!=bases.end(); it++)
	if(tab[i][*it]!=1) flaga=false;
      if(flaga)break;
    }	
    printf("Case #%d: %d\n",caseid,i);
  }
}
