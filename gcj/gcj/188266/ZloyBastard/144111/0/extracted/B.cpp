#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

#define TASK "file"

int n,m;
long long s[30][30];
long long w[30][30];
long long t[30][30];
long long dist[60][60];
int mark[60][60];
long long Inf=1000000000000000000LL;

int main(void){
	freopen(TASK".in","r",stdin);
	freopen(TASK".out","w",stdout);
	int test;
	
	cin>>test;
	for (int z=0;z<test;z++){
		cin>>n>>m;
		for (int i=0;i<n;i++){
			for (int j=0;j<m;j++){
				cin>>s[j][i]>>w[j][i]>>t[j][i];	
			}
		}
		swap(n,m);
		for (int i=0;i<2*n;i++)
			for (int j=0;j<2*m;j++){
				dist[i][j]=Inf;
				mark[i][j]=0;
			}
			
		dist[0][0]=0;
		while (true){
			int x=-1;
			int y=-1;
			for (int i=0;i<2*n;i++)
				for (int j=0;j<2*m;j++){
					if (!mark[i][j] && (x==-1 || dist[x][y]>dist[i][j])){
						x=i;
						y=j;
					}
				}
			//cout<<x<<" "<<y<<endl;
			//cout<<dist[x][y]<<endl;
			if (x==-1) break;
			mark[x][y]=1;
			//left
			if (x>0){
				if (x&1){
					int xx=x/2;
					int yy=y/2;
					long long cnt=(dist[x][y]-t[xx][yy])/(s[xx][yy]+w[xx][yy]);
					long long begin=t[xx][yy]+cnt*(s[xx][yy]+w[xx][yy]);
					long long newtime;
					if (begin>dist[x][y]){
						begin-=s[xx][yy]+w[xx][yy];					
					}
					//cout<<"dist "<<dist[x][y]<<" beg 1 - "<<begin<<" beg 2 - "<<begin+s[xx][yy]+w[xx][yy]<<endl;
					if (dist[x][y]>=begin-w[xx][yy] && dist[x][y]<begin) newtime=dist[x][y]+1;
					else newtime=max(begin+s[xx][yy],dist[x][y])+1;
					//cout<<"new time "<<newtime<<endl;
					if (dist[x-1][y]>newtime) dist[x-1][y]=newtime;					
				}else{
					if (dist[x-1][y]>dist[x][y]+2) dist[x-1][y]=dist[x][y]+2;
				}
			}

			//rigth
			if (x<2*n-1){
				if (!(x&1)){
					int xx=x/2;
					int yy=y/2;
					long long cnt=(dist[x][y]-t[xx][yy])/(s[xx][yy]+w[xx][yy]);
					long long begin=t[xx][yy]+cnt*(s[xx][yy]+w[xx][yy]);
					long long newtime;
					if (begin>dist[x][y]){
						begin-=s[xx][yy]+w[xx][yy];					
					}
					//cout<<"dist "<<dist[x][y]<<" beg 1 - "<<begin<<" beg 2 - "<<begin+s[xx][yy]+w[xx][yy]<<endl;
					if (dist[x][y]>=begin-w[xx][yy] && dist[x][y]<begin) newtime=dist[x][y]+1;
					else newtime=max(begin+s[xx][yy],dist[x][y])+1;
					//cout<<"new time "<<newtime<<endl;
					if (dist[x+1][y]>newtime) dist[x+1][y]=newtime;					
				}else{
					if (dist[x+1][y]>dist[x][y]+2) dist[x+1][y]=dist[x][y]+2;
				}
			}

			//down
			if (y>0){
				if (y&1){
					int xx=x/2;
					int yy=y/2;
					long long cnt=(dist[x][y]-t[xx][yy])/(s[xx][yy]+w[xx][yy]);
					long long begin=t[xx][yy]+cnt*(s[xx][yy]+w[xx][yy]);
					long long newtime;
					if (begin>dist[x][y]){
						begin-=s[xx][yy]+w[xx][yy];					
					}
					//cout<<"dist "<<dist[x][y]<<" beg 1 - "<<begin<<" beg 2 - "<<begin+s[xx][yy]+w[xx][yy]<<endl;
					if (dist[x][y]>=begin && dist[x][y]<begin+s[xx][yy]) newtime=dist[x][y]+1;
					else newtime=begin+s[xx][yy]+w[xx][yy]+1;
					//cout<<"new time "<<newtime<<endl;
					if (dist[x][y-1]>newtime) dist[x][y-1]=newtime;					
				}else{
					if (dist[x][y-1]>dist[x][y]+2) dist[x][y-1]=dist[x][y]+2;
				}
			}

			//up
			if (y<2*m-1){
				if (!(y&1)){
					int xx=x/2;
					int yy=y/2;
					long long cnt=(dist[x][y]-t[xx][yy])/(s[xx][yy]+w[xx][yy]);
					long long begin=t[xx][yy]+cnt*(s[xx][yy]+w[xx][yy]);
					long long newtime;
					if (begin>dist[x][y]){
						begin-=s[xx][yy]+w[xx][yy];					
					}
					//cout<<"dist "<<dist[x][y]<<" beg 1 - "<<begin<<" beg 2 - "<<begin+s[xx][yy]+w[xx][yy]<<endl;
					if (dist[x][y]>=begin && dist[x][y]<begin+s[xx][yy]) newtime=dist[x][y]+1;
					else newtime=begin+s[xx][yy]+w[xx][yy]+1;
					//cout<<"new time "<<newtime<<endl;
					if (dist[x][y+1]>newtime) dist[x][y+1]=newtime;					
				}else{
					if (dist[x][y+1]>dist[x][y]+2) dist[x][y+1]=dist[x][y]+2;
				}
			}
			//cout<<"----------\n";

		}
		printf("Case #%i: ",z+1);
		cout<<dist[2*n-1][2*m-1]<<endl;

	}

	return 0;
}