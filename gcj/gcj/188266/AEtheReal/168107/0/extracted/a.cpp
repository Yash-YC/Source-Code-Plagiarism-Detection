#include<cstdio>
#include<cstring>
#include<cmath>
#define eps 1e-8
#define maxa 100000

char s[200];
int b[200];
int kk[10][maxa+1];
int nb;
int vi[maxa+1];
int vp;

int kok(int a, int i){
	//printf("Chk %d base %d\n",a,b[i]);
	if(kk[i][a])return kk[i][a]-1;
	if(a==1){
		kk[i][a]=2;
		return 1;
	}
	if(vi[a]==vp){
		kk[i][a]=1;
		return 0;
	}
	vi[a]=vp;
	int su = 0;
	int aa = a;
	while(aa>0){
		su += (aa % b[i])*(aa%b[i]);
		aa = aa / b[i];
	}
	if(su<=maxa)
		kk[i][a] = kok(su,i)+1;
	else
		kk[i][a] = 1;
	vi[a]=0;
	return kk[i][a]-1;
}

int main(){
	int nn,ii;
	gets(s);
	sscanf(s,"%d",&nn);
	for(ii=1;ii<=nn;ii++){
		gets(s);
		nb = 0;
		int cc = 0;
		int tc;
		while(sscanf(s+cc,"%d%n",&b[nb],&tc)!=EOF){
			nb++;
			cc+=tc;
		}
		memset(kk,0,sizeof(kk));
		memset(vi,0,sizeof(vi));
		//for(int i=0;i<nb;i++)printf(" %d\n",b[i]);
		int ac = 1;
		for(int a=2;a<=maxa;a++){
			ac = 1;
			for(int i=0;i<nb;i++){
				vp =a * nb + i+1;
				if(!kok(a,i))ac = 0;
			}
			if(ac){
				printf("Case #%d: %d\n",ii, a);
				break;
			}
		}
	}
	return 0;
}
