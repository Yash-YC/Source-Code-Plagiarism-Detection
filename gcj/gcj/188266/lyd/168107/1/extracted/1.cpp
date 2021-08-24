#include <cstdio>
#include <cstring>
#include <set>

using namespace std;

int rec[1<<9]={-1,-1,-1,-1,-1,2,-1,17,-1,-1,-1,-1,-1,5,-1,25,-1,-1,-1,-1,-1,6,-1,695,-1,-1,-1,-1,-1,
229,-1,533,-1,-1,-1,-1,-1,311,-1,191,-1,-1,-1,-1,-1,401,-1,713,-1,-1,-1,-1,-1,2807,-1,4859,-1,-1,-1,
-1,-1,7307,-1,2207,-1,-1,-1,-1,-1,8,-1,77,-1,-1,-1,-1,-1,309,-1,545,-1,-1,-1,-1,-1,216,-1,4557,-1,-1,
-1,-1,-1,1975,-1,4137,-1,-1,-1,-1,-1,6211,-1,6351,-1,-1,-1,-1,-1,1001,-1,5719,-1,-1,-1,-1,-1,120785,
-1,47089,-1,-1,-1,-1,-1,48769,-1,58775,-1,-1,-1,-1,-1,385,-1,3,-1,-1,-1,-1,-1,95,-1,81,-1,-1,-1,-1,-1,
1135,-1,707,-1,-1,-1,-1,-1,415,-1,1695,-1,-1,-1,-1,-1,9721,-1,2159,-1,-1,-1,-1,-1,125,-1,143,-1,-1,-1,-1,-1,
2753,-1,68091,-1,-1,-1,-1,-1,43465,-1,37131,-1,-1,-1,-1,-1,553,-1,3487,-1,-1,-1,-1,-1,2893,-1,27,-1,-1,-1,-1,
-1,29627,-1,10089,-1,-1,-1,-1,-1,4977,-1,23117,-1,-1,-1,-1,-1,24855,-1,35785,-1,-1,-1,-1,-1,6393,-1,128821,-1,
-1,-1,-1,-1,710761,-1,662619,-1,-1,-1,-1,-1,1026657,-1,569669,-1,-1,-1,-1,-1,10,-1,13,-1,-1,-1,-1,-1,19,-1,23,
-1,-1,-1,-1,-1,44,-1,1277,-1,-1,-1,-1,-1,469,-1,79,-1,-1,-1,-1,-1,8787,-1,167,-1,-1,-1,-1,-1,7,-1,10309,-1,-1,
-1,-1,-1,5527,-1,6307,-1,-1,-1,-1,-1,49,-1,7895,-1,-1,-1,-1,-1,97,-1,623,-1,-1,-1,-1,-1,2455,-1,219,-1,-1,-1,-1,
-1,608,-1,37079,-1,-1,-1,-1,-1,40285,-1,3879,-1,-1,-1,-1,-1,44265,-1,51909,-1,-1,-1,-1,-1,34527,-1,120407,-1,-1,
-1,-1,-1,285357,-1,697563,-1,-1,-1,-1,-1,245035,-1,2688153,-1,-1,-1,-1,-1,397,-1,739,-1,-1,-1,-1,-1,1009,-1,91,
-1,-1,-1,-1,-1,1033,-1,12399,-1,-1,-1,-1,-1,4577,-1,6073,-1,-1,-1,-1,-1,3137,-1,1337,-1,-1,-1,-1,-1,29913,-1,120149,
-1,-1,-1,-1,-1,71735,-1,613479,-1,-1,-1,-1,-1,218301,-1,711725,-1,-1,-1,-1,-1,7961,-1,12085,-1,-1,-1,-1,-1,4417,
-1,1177,-1,-1,-1,-1,-1,9867,-1,47775,-1,-1,-1,-1,-1,108161,-1,28099,-1,-1,-1,-1,-1,142901,-1,48041,-1,-1,-1,-1,-1,
246297,-1,346719,-1,-1,-1,-1,-1,2662657,-1,4817803,-1,-1,-1,-1,-1,-1,-1,11814485,};

inline int cal(int num,int ba)
{
	int res=0,tmp;
	while(num)
	{
		tmp=num%ba;
		res+=tmp*tmp;
		num/=ba;
	}
	return res;
}

int ba[20];
char in[60];

int getint(char s[],int &start)
{
	int res=0;
	while(s[start]!='\0' && s[start]==' ') start++;
	if(s[start]=='\0') return -1;
	while(s[start]!='\0' && s[start]>='0' && s[start]<='9')
	{
		res=res*10+s[start]-'0';
		start++;
	}
	return res;
}

int main()
{
    //freopen("A-large.in","r",stdin);
    //freopen("out.txt","w",stdout);
	int ca=1,t,n,i,len,tmp,uu,ans;
	scanf("%d",&t);
	gets(in);
    for(ca=1;ca<=t;ca++)
	{
		gets(in);
		len=0,n=0;
		while((tmp=getint(in,len))!=-1)
			ba[n++]=tmp;
		tmp=0;
		for(i=0;i<n;i++)
			tmp|=(1<<(ba[i]-2));
		uu=(1<<9);
		ans=99999999;
		for(i=1;i<uu;i++)
			if(rec[i]!=-1 && (i&tmp)==tmp && ans>rec[i])
				ans=rec[i];
		printf("Case #%d: %d\n",ca,ans);
	}
	
	return 0;
} 