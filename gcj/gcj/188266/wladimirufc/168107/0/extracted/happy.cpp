#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char encontrado[1000000];
char linha[1024]; 
int bases[1024];
int cont;
int x;
int happy(int n, int base){
	
	int soma = 0;
	int k;
	
			
	while( n !=0  ){
		k = n%base;
		soma = soma + k*k;
		n = n / base;
	}
	
	
	
	if (soma == 1) {  return 1; }
	else{
		 if(encontrado[soma]==1){
		 		
		 		return 0;
		 }else{
		    encontrado[soma]=1;
		    return happy(soma,base);
		 }
	}
	

}

int main(){
	int T;
	int i;
	int k;
  int teste=1;		
	
	
	gets(linha);
	T = atoi(linha);
	
	while(T--){
	   
		gets(linha);
		
		x = 0;
		cont = 0;
		for(i=0;linha[i]!='\0';i++){
		  if(linha[i]!=' ') x = x*10 + linha[i]-'0';
		  else { bases[cont++] = x; x= 0; }
	  }
	  
		bases[cont++]=x;
		
		
		   
		 
	
		k = 2;
	  while(1){
		
			for(i=cont-1;i>=0;i--){
				memset(encontrado,0,sizeof(encontrado));
				encontrado[k]=1;
				
			  if( happy(k,bases[i])==0 ){
				   k++;
				   break;
				}
			}
			
			if(i>=0) continue;
			
			printf("Case #%d: %d\n",teste++,k);
			break;
		
		}
		
		
			
					
		
		
		
		 
	}
	
	
}

