#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
int base[10];
int tot;
int arr[1000];

bool check(int num,int m)
{
    set<int> st; 
    while(1){
		if(num==1)
			return true;
		if(st.find(num)!=st.end())
			return false;
		st.insert(num);
        int tott=0;
        while(num){
            arr[tott++]=num%m;
            num/=m;
		}
        reverse(arr,arr+tott);
        for(int i=0;i<tott;i++)
            num+=arr[i]*arr[i];
    }

}

bool solve(int num){
    int i;
    for(i=0;i<tot;i++){
        if(!check(num,base[i]))
            return false;
    }
    return true;
}
char st[100];

int main()
{
    freopen("F:\\A-small-attempt1.in","r",stdin);
    freopen("F:\\A.out","w",stdout);
    int test=0;
    scanf("%d",&test);
    char ch;
    gets(st);
    for(int p=1;p<=test;p++){
        tot=0;
       gets(st);
	   int rr=0;
	   for(int i=0;st[i]!='\0';i++){
		   if(st[i]==' '){
			   base[tot++]=rr;
			   rr=0;
		   }
		   else
			   rr=rr*10+(st[i]-'0');
	   }
	   base[tot++]=rr;
        int m;
        for(int j=2;j<=100000;j++){
            if(solve(j)){
                m=j;
                break;
            }
        }
        printf("Case #%d: %d\n",p,m);

    }
}
