#include <cstdio>
#include <vector>
#include <list>

using namespace std;
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
  int maxres=10000;
  char tab[maxres][11];
  for(int i=0; i<maxres; i++)
    for(int j=2; j<=10; j++)
	tab[i][j]=0;
  for(int j=2; j<=10; j++)
    tab[1][j]=1;
  for(int j=2;j<=10; j++)
  for(int i=2;i<maxres; i++){
    if(tab[i][j])continue;
    int p=i;
    list<int> mod;
    while(!tab[p][j]){
	tab[p][j]=2;
	mod.push_back(p);
	p=proccess(p,j);
    }
    if(tab[p][j]==1)
	for(list<int>::iterator it=mod.begin(); it!=mod.end(); it++)
	   tab[*it][j]=1;
  }
  for(int caseid=1; caseid<=511; caseid++){
    int i=2;
    for(;;i++){
      bool flaga=true;
      for(int j=2; j<=10;j++)
	if((caseid&(1<<(j-2))) && tab[proccess(i,j)][j]!=1) flaga=false;
      if(flaga)break;
    }	
    printf("result[%d]=%d;\n",caseid,i);
  }
}
