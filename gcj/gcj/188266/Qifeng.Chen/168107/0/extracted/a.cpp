#include<iostream>
#include<sstream>
#define fr(i,a,b) for(i=a;i<=b;++i)
using namespace std;
const int maxn=10000002;
int u[maxn],ti,ca,i,n,tt,tmp,x[1000],j;
string s;
bool ok(int r,int base){
	tt++;
	do{
		u[r]=tt;
		int sum=0;
		while(r!=0){
			sum+=(r%base)*(r%base);
			r/=base;
		}
		r=sum;
		if(r==1)
			return true;
	}while(u[r]!=tt);
	return false;
}
int main(){
	freopen("a1.in","r",stdin);
	freopen("a1.out","w",stdout);
	cin>>ca;
	getline(cin,s);
	tt=0;
	fr(ti,1,ca){
		getline(cin,s);
		stringstream in(s);
		n=0;
		while(in>>tmp)
			x[++n]=tmp;
		cout<<"Case #"<<ti<<": ";
		fr(i,2,maxn-1){
			bool pd=true;
			fr(j,1,n)
				if(!ok(i,x[j])){
					pd=false;
					break;
				}
			if(pd){
				cout<<i<<endl;
				break;
			}					
		}
	}
}