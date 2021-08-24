#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

int vis[1000001],no[11];
int is[11][1000001],ind[11];
vector <int> b[11];

int trans(int num, int base)
{
	int ret=0;
	
	while(num) {
		ret += (num%base) * (num%base);
		num /= base;
	}
	
	return ret;
}

int get(int num, int base)
{
	if(is[base][num]!=-1) return is[base][num];
	if(vis[num]) return 0;
	
	vis[num]=1;
	is[base][num] = get(trans(num,base), base);
	vis[num]=0;
	return is[base][num];
}

int main()
{
	int T,t,i,j,c,k,n;
	char cc;
	
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	
	memset(vis,0,sizeof(vis));
	memset(is,-1,sizeof(is));
	
	for(i=0;i<11;i++) is[i][1] = 1;
	
	for(i=2;i<=10;i++) {
		for(j=2;j<=1000000;j++)
			if(get(j,i)) b[i].push_back(j);
	}
	b[1].push_back(1);
	
	scanf("%d",&T);
	
	for(t=0;t<T;t++) {
		memset(no,0,sizeof(no));
		memset(ind,0,sizeof(ind));
		n=0;
		
		while(1) {
			scanf("%d",&k);
			n++;
			no[k]=1;
			scanf("%c",&cc);
			if(cc=='\n') break;
		}
	
		while(1) {
			for(k=1,j=2;j<=10;j++)
				if(no[j]) if(b[j][ind[j]] > b[k][ind[k]]) k = j;
				
			k = b[k][ind[k]];
				
			for(c=0,j=2;j<=10;j++) {
				if(!no[j]) continue;
				while(1) {
					if(ind[j] == b[j].size()) return j;
					
					if(b[j][ind[j]] < k) ind[j]++;
					else break;
				}
				
				if(b[j][ind[j]] == k) c++;
			}
			
			if(c==n) {
				printf("Case #%d: %d\n",t+1,k); 

				break;
			}
		}
	}
	
	
}

