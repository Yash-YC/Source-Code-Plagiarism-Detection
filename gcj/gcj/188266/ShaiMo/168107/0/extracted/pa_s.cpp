#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool used[11];
char hp[11][1000];

char is_happy(int number, int base){
	int sum, tmp, x;
	if( number >= 1000 ){		
		x = number;
		sum = tmp = 0;
		while( x!=0 ){
			tmp = x%base;
			sum += tmp*tmp;
			x /= base;
		}
		if( sum==1 )	return 1;
		else	return is_happy( sum, base );
	}
	if( hp[ base ][ number ] == 5 )	return 2;
	if( hp[ base ][ number ] == 2 )	return 2;
	if( hp[ base ][ number ] == 1 )	return 1;
	hp[ base ][ number ] = 5;
	x = number;
	sum = tmp = 0;
	while( x!=0 ){
		tmp = x%base;
		sum += tmp*tmp;
		x /= base;
	}
	if( sum==1 ){
		hp[ base ][ number ] = 1;
		return 1;
	}
	hp[ base ][ number ] = is_happy( sum, base );
	return hp[ base ][ number ];
}

int main(){
	freopen("A-small-attempt2.in","r",stdin);
	char buf[1000];
	int turn, T;
	fgets(buf, 1000, stdin);
	sscanf(buf,"%d",&T);
	for(turn=0;turn<T;++turn){
		fgets(buf, 1000, stdin);
		int i, x;
		for(i=0;i<=10;++i)	used[i] = false;
		char *p;
		p = strtok( buf, " " );
		while( p!=NULL ){
			sscanf(p,"%d",&x);
			used[x] = true;
			p = strtok( NULL, " " );
		}
		x = 1;
		memset( hp, 0, sizeof(hp) );
		while( 1 ){
			++x;
			bool flag = true;
			for(i=2;i<=10;++i){
				if( !used[i] )	continue;
				//printf("Ask is_happy( %d, %d )\n",x,i);
				if( is_happy(x, i)==1 )	continue;
				flag = false;
				break;
			}
			if( flag )	break;
		}
		printf("Case #%d: %d\n",1+turn,x);
	}
	return 0;
}
