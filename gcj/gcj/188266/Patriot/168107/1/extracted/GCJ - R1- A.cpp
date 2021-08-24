
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include <algorithm> 
#include <vector> 
#include <string> 
#include <stack> 
#include <queue> 
#include <map> 
#include <set> 
#include <iterator> 
#include <iostream> 
#include <functional> 
#include <sstream> 
#include <numeric>

using namespace std;

#define CLR( x , y ) ( memset( (x) , (y) , sizeof( (x) ) ) ) 
#define EPS 1e-9

FILE *in=fopen("A.in","r");
FILE *out=fopen("A.out","w");

int memo[1000][11];

int doit(int x,int base)
{
	int nx=0;
	while(x){
		int R=x%base;
		nx+=R*R;
		x/=base;
	}
	return nx;
}

int happy(int x,int base)
{
	if(x==1)return 1;
	int &ret=memo[x][base];
	if(ret!=-1)return ret;
	ret=0;
	return ret=happy(doit(x,base),base);
}
vector<string> tokenize(string s, string ch)
{
	int p,p2;
	vector<string> ret;
	for( p = 0; p < s.size(); p = p2+1 )
	{
		p2 = s.find_first_of(ch, p);
		if( p2 == -1 ) p2 = s.size();
		if( p2-p > 0 ) ret.push_back( s.substr(p, p2-p) );
	}
	return ret;
}

vector<int> tokint(string s, string ch)
{
	int i;
	vector<int> ret;
	vector<string> p = tokenize(s, ch);
	for( i = 0; i < p.size(); i++ )
		ret.push_back( atoi(p[i].c_str()) );
	return ret;
}
int visread=0;
string readline()
{
	string qwe;
	char junk;
	for(;;){
		if(fscanf(in,"%c",&junk)==EOF){visread=1;break;}
		if(junk=='\n')break;
		qwe+=junk;
	}
	return qwe;
}
int main()
{
	int i,j,k,T,ret;
	fscanf(in,"%d\n",&T);
	CLR(memo,-1);
	for(int test=1;test<=T;test++){
		string Q;
		Q=readline();
		vector < int > ar=tokint(Q," ");
		for(i=2;;i++){
			for(j=0;j<ar.size();j++){
				if(!happy(doit(i,ar[j]),ar[j]))break;
			}
			if(j==ar.size())break;
		}
		fprintf(out,"Case #%d: %d\n",test,i);
	}
	return 0;
}
