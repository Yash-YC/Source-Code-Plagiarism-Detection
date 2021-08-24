#include <stdio.h>
#include <string.h>

int happy[100010][15],base[15];
char used[100010];

bool ishappy(int num,int b) {
	int s[100],len,i,sum,tmp;
	
	memset(used,0,sizeof(used));
	tmp = num;
	//printf("%d %d:\n",num,b);
	//printf("%d %d\n",tmp,sum);
	/*if(num == 91)
		printf("%d %d:\n",num,b);*/
	used[tmp] = 1;
	while(1) {
		//if(happy[tmp][b] != -1)	return happy[tmp][b];
		if(tmp == 1)	return true;
		//if(tmp < b) 	break;
		len = sum = 0;
		while(tmp > 0) {
			s[len++] = tmp%b;
			tmp /= b;
		}
		for(i=0;i<len;i++)
			sum += s[i]*s[i];
		tmp = sum;
		/*if(num == 91)
			printf("%d %d\n",tmp,sum);*/
		if(used[tmp])	return used[1] == 1;
		used[tmp] = 1;
		//scanf("%d",&i);
	}
	return 0;
}

int main() {
	int i,j,t,c=0,n;
	char cc;
	
	for(i=2;i<=60010;i++)
		for(j=2;j<=10;j++)
			happy[i][j] = -1;
	
	for(i=2;i<=60010;i++)  {
		for(j=2;j<=10;j++)
			happy[i][j] = ishappy(i,j);
	}
	
	scanf("%d",&t);
	while(t--) {
		n=0;
		while(scanf("%d%c",&base[n],&cc) && cc != '\n') n++;
		
		for(i=2;i<=60010;i++) {
			for(j=0;j<=n;j++)
				if(happy[i][base[j]] != 1)
					break;
			if(j > n)	break;
		}
		printf("Case #%d: %d\n",++c,i);
	}
	
	return 0;
}
