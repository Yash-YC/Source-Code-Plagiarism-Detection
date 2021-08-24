#include<stdio.h>
#include<string.h>

int		b[300];

int		Base(int d, int k){
		int s = 0, t = 0, a;
		memset(b,0,sizeof(b));
		while(s!=d){
			t = 0; s = d;
			while(d){
				a = d % k;
				t += a*a;
				d /= k;
			}
			if (b[t]) return t;
			b[d = t] = 1;
		}
		return s;
}


int		a[11];

int		main(){
	//	freopen("in.txt","r",stdin);
	//	freopen("out.txt","w",stdout);	
		int i,x,t,T; char c;

		for(scanf("%d",&T), t=1; t<=T; t++)
		{
			memset(a,0,sizeof(a));
			while(scanf("%d%c",&x,&c)==2){
				a[x] = 1;
				if (c!=' ') break;
			}
			
			for(i=6; i<=10; i++) if (!a[i]) break;
			if (i>10){ printf("Case #%d: %d\n",t, 11814485); continue; }
			x = 2;
			while(true){
				for(i=2; i<=10; i++){
					if (a[i] && Base(x,i)!=1) break;
				}
				if (i>10){ 
					printf("Case #%d: %d\n",t, x); break; 
				}
				x++;
			}
		}

		return 0;
}