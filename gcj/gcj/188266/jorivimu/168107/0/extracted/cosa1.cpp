#include <cstdio>
#include <iostream>
#include <cmath>
#include <sstream>
#include <string>
#include <set>
#include <algorithm>
#include <map>
#include <iterator>
#include <cstdlib>
using namespace std;


int calcula(int base,int num){
	string s="";
	int aux=0,temp=num;
	
	int suma=0;
	set <int > sss;
	do{
		
		suma=0;
		if(find(sss.begin(),sss.end(),num)==sss.end()) sss.insert(num);
		else{ return 0;}
		while(num>=base){
			aux=(num%base);
			suma+=aux*aux;
			num/=base;
		}
		suma+=num*num;
		num=suma;
	
	}while(suma!=1);
	if(suma==1){ 

	return 1;}
	else 0;
	
}

int main(){
	int n,temp,temp2;
	string cad;
	scanf("%d\n",&n);
	set <int> se[12];
	for(int i=2;i<=10;i++){
		for(int num=2;num<=100000;num++){
			if(calcula(i,num)==1){
				se[i].insert(num);
			}
			
		}
	}
	int caso=1;
	while(n--){
		getline(cin, cad);
		set <int> cosa;
   		istringstream in(cad);
   		while(in >> temp){
   			 cosa.insert(temp);
		}
		set <int>::iterator it = cosa.begin();
		set <int> ss=se[*it];
		for(it++;it!=cosa.end();it++){
			set <int> ss1=se[*it];
			set <int> auxi;
			set_intersection(ss.begin(),ss.end(),ss1.begin(),ss1.end(), inserter(auxi,auxi.begin()));  
			ss=auxi;
		}
		it = ss.begin();
		cout<<"Case #"<<caso++<<": "<<*it<<endl;
	}
	return 0;
}

