#include<iostream>
using namespace std;
int main(void)
{
    int ans[512];
    FILE *fin0 = fopen("a.txt","r");
    FILE *fin = fopen("A-large.in","r");
    FILE *fout = fopen("A-large.out","w");
    for(int i=0,k,a;i<512;i++){
        fscanf(fin0,"%d%d",&k,&a);
        ans[k]=a;
    }    
    int num;
    char str[120];
    fscanf(fin,"%d ",&num);
    for(int cas=1;cas<=num;cas++){
        fgets(str,100,fin);
        int b[9]={0},k=0;
        for(int i=0;str[i]!='\n';i++){
            if(str[i]=='1'){
                b[8]=1;
                break;
            }    
            if(str[i]>='2'&&str[i]<='9'){
                b[str[i]-'0'-2]=1;
            }    
        }
        for(int i=8;i>=0;i--)
            k=k*2+b[i];
        fprintf(fout,"Case #%d: %d\n",cas,ans[k]);
    }    
    fclose(fin0);
    fclose(fin);
    fclose(fout);
    //system("pause");
    return 0;
}    
