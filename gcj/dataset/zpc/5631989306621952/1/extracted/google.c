#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compute(char *line, int len, char *lastword){
	int start=1000,end=1000;	
	int i=0;
	lastword[start] = line[0];
	for(i=1;i<len;i++){
		if(line[i]>=lastword[start]){
			lastword[--start] = line[i];
		}
		else{
			lastword[++end] = line[i];
		}
	}
	lastword[++end] = '\0';
	
	return start;
}

int main(){
	int T,M,N,i,result,n;
	char c,line[1005],lastword[2005];
	int len=0;

	FILE *input = fopen("input.txt", "r");
	FILE *output = fopen("output.txt", "w");
	fscanf(input,"%d", &T);
	fgetc(input);

	n=1;
	while(n<=T){
		len=0;
		while((c=fgetc(input))!=EOF && c!='\n'){
			line[len++]=c;
			line[len]='\0';
		}
		
		result = compute(line,len,lastword);
		
		fprintf(output, "Case #%d: %s\n", n, &lastword[result]);
		n++;
	}

	return 0;
}
