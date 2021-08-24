#include <cstdio>
#include <cstring>
#include <sstream>
using namespace std;

int C,n,ans;
int b[100];
char bl[10],s[10000];

int get_next(int k,int b) {
    int sum=0;
    while (k!=0) {
        int dig=k%b;
        sum=sum+dig*dig;
        k=k/b;
    }    
    return sum;
}    

bool test(int ans,int b) {
    int f1=ans,f2=ans;
    while (1) {
        f1=get_next(f1,b);
        f2=get_next(get_next(f2,b),b);
        if (f1==f2) return f1==1;
    }    
}    

int main() {
    scanf("%d",&C);
    gets(bl);
	for (int c=1;c<=C;c++) {
	    gets(s);
	    istringstream lin(s);
	    n=0;
	    int tmp;
 		while (lin>>tmp) {
 		    n++;
 		    b[n]=tmp;
 		}   
   		ans=2; 
 		while (1) {
 		    bool check=true;
 		    for (int i=1;i<=n;i++) {
 		        if (!test(ans,b[i])) {
 		            check=false;
 		            break;
 		        }    
 		    }    
 		    if (check) {
 		        printf("Case #%d: %d\n",c,ans);
 		        break;
 		    }    
 		    ans++;
 		}    
	}    
}    
