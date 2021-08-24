#include<stdio.h>
#include<string.h>
#include<vector.h>

FILE *in=stdin;
FILE *out=stdout;
FILE *dbg=stderr;
void file()
{
	in =fopen("a.in" ,"r");
	out=fopen("a.out","w");
	dbg=fopen("debug.txt","w");
	//dbg=out;
}
long long abs(long long x) { if( x<0 ) return -x; return x; }
int len(char* x) { return strlen(x); }

char j[1024];
int i[16];
int v[1024];
int b[16][1024];

int test(int p,int x)
{
	int y,t,o;
	if( x==1 ) return 1;
	if( x<1024 )
	{
		if( v[x]==1 ) return 0;
		if( b[p][x]!=-1 ) return b[p][x];
		v[x]=1;
	}
	y=0;
	t=x;
	while( t>0 )
	{
		y+=(t%p)*(t%p);
		t/=p;
	}
	o=test(p,y);
	if( x<1024 )
	{
		b[p][x]=o;
		v[x]=0;
	}
	return o;
}

int main()
{
	file();
	int k;
	int n;
	int a,s,d,f;
	char chr;
	for(a=0;a<16;a++) for(s=0;s<1024;s++) b[a][s]=-1;
	fscanf(in,"%d ",&k);
	for(a=0;a<k;a++)
	{
		fscanf(in,"%[^\n]s",&j); fscanf(in,"%c",&chr);
		if( j[len(j)-1]!=' ' ) { j[len(j)+1]=0; j[len(j)]=' '; }
		n=0;
		d=0;
		for(s=0;s<len(j);s++)
		{
			if( j[s]==' ' )
			{
				i[n]=d;
				d=0;
				n++;
			}
			else
			{
				d=d*10+(j[s]-'0');
			}
		}
fprintf(dbg,"[%d] ",n);
for(s=0;s<n;s++) fprintf(dbg,"%d ",i[s]); fprintf(dbg,"\n");
fflush(dbg);
		for(s=2;;s++)
		{
			for(d=0;d<n;d++)
			{
				if( test(i[d],s)==0 ) break;
			}
			if( d==n ) break;
		}
		fprintf(out,"Case #%d: ",a+1);
		fprintf(out,"%d\n",s);
		fflush(out);
	}
	return 0;
}