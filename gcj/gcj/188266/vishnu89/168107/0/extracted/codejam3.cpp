#include<iostream>
#include<map>
#include<vector>
using namespace std;
string fn(int n,int base)
{
	string s;
	while(n!=0){
		s=(char)(n%base+48)+s;
		n=n/base;
	}
	return s;
}		
int main()
{
	
	map<long long int,long long int> m;
	long long int c,g,d,p,i,j,k,n,sum,t;
	vector<long long int> v;
	string s;
	cin>>t;
	getline(cin,s);
	for(c=0;c<t;c++){
		getline(cin,s);
		for(i=0;i<s.size();i+=2){
			if(s[i]=='1'){
				g=10;
				v.push_back(g);
				i++;
			}
			else	
				v.push_back((int)(s[i]-48));
		}		
		i=2;
		while(1<2){
			p=0;
			for(j=0;j<v.size();j++){
				s=fn(i,v[j]);
				d=atoll(s.c_str());
				n=d;
				m[n]=1;
				k=0;
				while(n!=1){
					sum=0;
					while(n!=0){
						sum+=(n%10)*(n%10);
						n=n/10;
					}
					s=fn(sum,v[j]);
					d=atoll(s.c_str());
					if(m[d]==1){
						k=1;
						break;
					}	
					n=d;
					m[n]=1;
				}
				m.clear();
				if(k==1){
					p=1;
					break;
				}
			}
			if(p==0){
				cout<<"Case #"<<c+1<<": "<<i<<endl;
				break;
			}
			i++;
		}
		v.clear();
	}					
	return 0;
}			


		


