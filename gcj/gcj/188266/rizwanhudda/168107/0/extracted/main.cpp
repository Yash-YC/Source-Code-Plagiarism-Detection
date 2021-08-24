#include<stdio.h>
#include<string.h>
int sq(int x){
    return x*x;
}

int path[10000],l=0;

int happy(int x,int b){
    int i;
    for(i=0;i<l;i++)
    if(path[i]==x)
    return 0;
    path[l++]=x;
    //printf("%d %d\n",x,b);
	int s=0,in=x;
	if( (x/b == 0) && (x==1) )
	return 1;
	//else if( x/b == 0)
//	return 0;
	while(x>0)
	{
		s += sq(x%b);
		x /= b;
	}
	if(s==in)
	return 0;
	return happy(s,b);
}

int main(){
	int b[10],i,j,num,cases,k,bases;
	char str[50],*tok;
	gets(str);
	sscanf(str,"%d",&cases);
	for(k=0;k<cases;k++)
	{
		gets(str);
        //printf("%d\n",k);
        tok=strtok(str," ");
		i=0;
		while(tok!=NULL)
		{
		sscanf(tok,"%d",&b[i++]);
		//
        tok=strtok(NULL," ");
		//
        }
		num=2;
		bases=i;
		//for(i=0;i<bases;i++)
		//printf("%d\n",b[i]);
		while(1){
			//printf("candidate %d\n",num);
            for(i=0;i<bases;i++)
			{
            l=0;
            if(!happy(num,b[i]))
			break;
            }
			//printf("%d\n",num);
            if(i==bases)
			break;
			num++;
		}
		printf("Case #%d: %d\n",k+1,num);
		
	}
	return 0;
}
