#include<stdio.h>
#include<string.h>

int main(){
    freopen("A-large.in.txt","r",stdin);
    freopen("A-large.out.txt","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        char data[1005]={0};
        scanf("%s",data);
        int data_len = strlen(data);
        for(int j=0;j<data_len;j++){
            if(data[0]<=data[j]){
                char t = data[j];
                for(int k=j-1;k>=0;k--){
                    data[k+1]=data[k];
                }
                data[0] = t;
            }
        }
        printf("Case #%d: %s\n",i,data);
    }
    return 0;
}