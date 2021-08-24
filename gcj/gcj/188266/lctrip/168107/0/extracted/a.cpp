#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

typedef struct Seq
{
int i;
int j;
int k;
int h;
char bz;
struct Seq * next;
struct Seq * begin;
struct Seq * end;
}Seq;

void * type_calloc(size_t size)
{
	void * ret;

	ret=malloc(size);
	if(ret!=NULL)
	{
	//	sum_size+=size;
		memset(ret,0,size);
		return ret;
	}
	else 
	{	
		return NULL;
	}
}
#define talloc(type)    (type *)type_calloc(sizeof(type))
int last[200];
int lastn;
void clearlast()
{
	for(int i=0;i<=lastn;i++)
	{
		last[i]=0;	
	}
	lastn=0;
}
bool happy(long n,int base)
{
	char na[200];
	long ha,hb;
	for(int i=lastn;i>=0;i--)
	{
		if(n==last[i])
		{
			clearlast();
			return false;
		}
	}
	last[lastn]=n;
	lastn++;
	
	if(n==1) 
	{
		clearlast();
		return true;
	}
	else 
	{
		itoa(n,na,base);
		ha=atoi(na);
		hb=0;
		while(ha>0)
		{
			hb+=(ha%10)*(ha%10);
			ha/=10;
		}
		return happy(hb,base);
	}
}
int main()
{
	long i,j,k,n;
	char c;
	char *p="1.2.";
		int rt;
		int major,minor,micro;
	FILE *fp_in,*fp_out;
	char ch;
	char file_name[100]="";
	int file_name_pos=0;
	int input[100][100]={0};
	int output[100][100]={0};
int T,H,W,dt;
char bz='a';
char b[]="143",*end;
long bb;
Seq seq[100];
Seq min;
Seq *last;
bool out[100]={0};
Seq stack;
char o[1000];
bool rth;
int base[10];
char str[10];
//char ch;
min.h=10000;
	fp_in=fopen("A-small.in","r");
	if(fp_in==NULL)
		exit(0);
	fp_out=fopen("A-small.out","w");
	if(fp_out==NULL)
		exit(0);
	fscanf(fp_in,"%d\n",&dt);
	for(i=0;i<dt;i++)
	{
		j=0;
		while(j<10)
		{	if(feof(fp_in))
				break;
			ch=fgetc(fp_in);
			if(ch=='\n')
				break;
			if(ch>='0'&&ch<='9')
			{	if(ch=='1')
				{
					ch=fgetc(fp_in);
					base[j]=10;
					j++;
				}
				else
				{	base[j]=ch-'0';
					j++;
				}
			}


		}
		k=j;
		n=2;
		for(n=2;n<=121232767;n++)
		{	rth=true;
			for(j=0;j<k;j++)
			{
				rth&=happy(n,base[j]);
				if(!rth)
					break;
			}
			if(rth)
			{	fprintf(fp_out,"Case #%d: %d\n",i+1,n);
				break;
			}
		}
	}
//	bb=atoi(b);
	//bb=strtol(b,NULL,8);
	clearlast();
	rth=happy(143,7);
	//itoa(bb,o,7);
	//printf("b=%ld,%s",bb,o);
	//for(dt=1;dt<=500;dt++)
	//fprintf(fp_out,"Case #%d: 2\n",dt);
}