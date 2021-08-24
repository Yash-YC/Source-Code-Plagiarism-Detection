#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
using namespace std;

#define MAX 10000
#define MAX2 2200

int f[MAX+1][MAX2+1],fc[MAX+1];
int happy[MAX+1];
int q[MAX+1],qh,qt;

void bfs(int l){
	int i,x;
	qh=qt=0;
	q[qh++]=1;
	while(qh>qt){
		x=q[qt++];
		happy[x]|=l;
		//cout<<x<<", ";
		for (i=0; i<fc[x]; i++) q[qh++]=f[x][i];
	}
	//cout<<endl;
}

void gen(){
	int i,j,k;
	char t[100];
	int mx2=0;		
	for (j=2; j<=10; j++){
		int mx=0;
		for (i=1; i<=MAX; i++) fc[i]=0;
		for (i=2; i<=MAX; i++){
			itoa(i,t,j);
			int sum=0;
			for (k=0; t[k]; k++)
				sum+=(t[k]-'0')*(t[k]-'0');
			f[sum][fc[sum]++]=i;
			if (fc[sum]>mx2) mx2=fc[sum];
			if (sum>i) mx=sum;
		}
		
	//	cout<<mx<<endl;
		bfs(1<<j);
	}
	//cout<<mx2<<endl;
}

int visited[1<<14];

int main(){
	char s[1001];
	int t,u,b[100],i,j,k,n;
	gen();
	//cout<<happy[2]<<" "<<happy[3]<<" "<<happy[4]<<endl;
	cin.getline(s,1000);
	istringstream ss(s);
	ss >> t;
	char ts[100];
	
	for (u=0; u<t; u++){
		cin.getline(s,1000);
		istringstream ss(s);
		n=0;
		int pat=0;
		while(ss>>b[n]){
			pat|=(1<<b[n]);
			n++;
		}
		if (visited[pat]){
			i=visited[pat];
			cout<<"Case #"<<(u+1)<<": "<<i<<endl;
			continue;
		}
		//cout<<"pat="<<pat<<" "<<(pat&happy[2])<<endl;
		for (i=2; ; i++){
			int sum=i;
			if (sum<=MAX && ((pat&happy[sum])==pat)) break;
			for (j=0; j<n; j++){
				itoa(i,ts,b[j]);
				int sum=0;
				for (k=0; ts[k]; k++)
					sum+=(ts[k]-'0')*(ts[k]-'0');
				if ((happy[sum]&(1<<b[j]))==0) break;
			}
			if (j==n) break;
		}
		visited[pat]=i;
		cout<<"Case #"<<(u+1)<<": "<<i<<endl;
	}
	return 0;
}
