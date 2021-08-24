#include<stdio.h>

FILE *fin=fopen("input.txt","r");
FILE *fout=fopen("output.txt","w");

int b[10];
short chk[11][100000];

void process(int t,int cnt){
	int i,j;
	fprintf(fout,"Case #%d: ",t);
	for(j=2;j<100000;j++){
		for(i=1;i<=cnt;i++){
			if(chk[b[i]][j] != 1) break;
		}
		if(i>cnt) break;
	}
	fprintf(fout,"%d\n",j);
}

int back(int num,int base){
	int sum=0,temp;
	while(true){
		temp = num % base;
		sum += temp*temp;
		num = num / base;
		if(num==0) break;
	}

	if(chk[base][sum] == 1) return 1;
	else if(chk[base][sum] == 0){
		chk[base][sum] = 2;
		chk[base][sum] = back(sum,base);
	}
	else if(chk[base][sum] == 2){
		return 2;
	}
}

int main(void){
	int i,j;
	int n,cnt=0;
	char a;
	for(i=2;i<=10;i++){
		chk[i][1] = 1;
		for(j=2;j<100000;j++){
			chk[i][j] = back(j,i);
		}
	}
	fscanf(fin,"%d\n",&n);
	for(i=1;i<=n;i++){
		cnt =0;
		while(1){
			fscanf(fin,"%c",&a);
			if(a == char(10)){
				process(i,cnt);
				break;
			}
			else if(a != char(32)){
				b[++cnt]=int(a)-48;
				if(b[cnt]==1) b[cnt]=10;
				if(b[cnt]==0) cnt--;
			}
		}
	}
	fcloseall();
	return 0;
}