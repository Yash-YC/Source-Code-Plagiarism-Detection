#include<iostream>
#include<string>
using namespace std;
int a[20],c[20],d[1000],t;
bool b[1000],bbb[11][1000],bbbb[11][1000];
string s;
char ch[1000];
void zhanhuan(int ba,int x){
     a[0]=0;
     while (x!=0){
           a[++a[0]]=x%ba;
           x/=ba;
     }
}
bool cheak(int ba,int x){
     memset(b,0,sizeof(b));
     memset(d,0,sizeof(d));
     a[0]=0;
     if (x<1000) b[x]=true;
     if (x<1000) d[++d[0]]=x;
     while (x!=0){
           zhanhuan(ba,x);
           int xx=0;
           for (int i=1;i<=a[0];i++)
           xx+=a[i]*a[i];
           x=xx;
           if (b[x]) break;
           if (bbb[ba][x]) return false;
           if (bbbb[ba][x]) return true;
           b[x]=true;
           d[++d[0]]=x;
     }
     if (b[1]) return true;
     return false;
}
int main(){
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    cin>>t;
    gets(ch);
    for (int tt=1;tt<=t;tt++){
        memset(bbb,0,sizeof(bbb));
        memset(bbbb,0,sizeof(bbbb));
        gets(ch);
        s=ch;
        s=s+" ";
        int n=0;
        c[0]=0;
        for (int i=0;i<s.size();i++){
            if (s[i]==' ') c[++n]=0;else
            c[n]=c[n]*10+s[i]-'0';
        }
        int ans=1;
        bool bb=false;
        while (!bb){
              ans++;
              bb=true;
              for (int i=0;i<n;i++)
              if (!cheak(c[i],ans)) {
                 for (int j=1;j<=d[0];j++)
                 bbb[c[i]][d[j]]=true;
                 bb=false;
              }else{
                    for (int j=1;j<=d[0];j++)
                    bbbb[c[i]][d[j]]=false;
              }
        }
        cout<<"Case #"<<tt<<": "<<ans<<endl;
    }
    return 0;
}
