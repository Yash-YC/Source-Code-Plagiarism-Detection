#include <cstdio>
#include <stack>
#include <set>

using namespace std;
set<int> h[11], nh[11];

int base;

stack<int> convert(int n, int b){
	stack<int> aux;
	while(n>=b){
		aux.push(n%b);
		n/=b;
	}
	aux.push(n);
	return aux;
}

int happy(int n, int b){
	int a=0;
	stack<int> p = convert(n,b);
	while(!p.empty()){
		a+=p.top()*p.top();
		p.pop();
	}
	return a;
}


int isHappy(int n, int b){
	int i,j,k;
	set<int> gota;
	set<int>::iterator g;
	
	while(n!=1){
		if(gota.count(n) || nh[b].count(n)){
			if(!gota.count(n)){
				for(g=gota.begin();g!=gota.end();g++){
					nh[b].insert(*g);
				}
			}
			return 0;
		}
		if(h[b].count(n)){
			for(g=gota.begin();g!=gota.end();g++){
				h[b].insert(*g);
			}
			return 1;
		}
		gota.insert(n);
		n = happy(n,b);
	}
	for(g=gota.begin();g!=gota.end();g++){
		h[b].insert(*g);
	}
	return 1;
}

int main(){
	int i,j,k=1,cases;
	int v[20],size,is;
	char aux;
	

	scanf("%d\n",&cases);
	while(cases--){
		i=0;
		while(1){
			scanf("%d%c",&v[i++],&aux);
			if(aux == '\n') break;
		}
		size = i;
		is = 0;
		printf("Case #%d: ",k++);
		for(i=v[0];!is;i++){
			is = 1;
			for(j=0;is && j<size;j++){
				if(nh[v[j]].count(i)){
					is = 0;
				} else if(h[v[j]].count(i)){
					is = 1;
				} else{
					is*= isHappy(i,v[j]);
				}
			}
			if(is) printf("%d\n",i);
		}
		
	}
}
