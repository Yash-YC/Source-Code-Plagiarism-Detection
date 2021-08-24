#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <sstream>
#include <map>
using namespace std;

typedef vector<int>vi;
typedef vector<string>vs;

#define pb push_back
#define sz size()
#define MAXN 

const int oo=(int)1e9;

int test,base[10],num,jlh;
string s;

void open(){
    freopen("hasil.txt","w",stdout);
}

string to(int a,int b){
    string res="";
    while (a){
        res+=(char)(a%b+'0');
        a/=b;
    }
    return res;
}

inline int sqr(int a){
    return a*a;
}

inline int sum_digit(string a){
    int res=0;
    for (int i=0;i<a.length();i++) res+=sqr(a[i]-'0');
    return res;
}

inline int sum(int a){
    int res=0;
    while (a){
        res+=(a%10)*(a%10);
        a/=10;
    }
    return res;
}

bool ok(int a){
    bool used[1000000];
    //cout<<"Z"<<a<<endl;
    for (int i=0;i<jlh;i++){
        string tmp;
        if (base[i]<10){
            tmp=to(a,base[i]);
            num=sum_digit(tmp);
        }
        else num=sum(a);
        //cout<<i<<' '<<tmp<<' '<<num<<' '<<a<<endl;
        memset(used,0,sizeof(used));
        while (1){
            if (num==1) break;
            else if (used[num]) return 0;
            used[num]=1;
            if (base[i]<10){
                tmp=to(num,base[i]);
                num=sum_digit(tmp);
            }
            else num=sum(num);
            //cout<<num<<endl;
        }
    }
    return 1;
}

int main(){
    open();
    scanf("%d",&test);
    getchar();
    for (int i=1;i<=test;i++){
        num=jlh=0;
        char x;
        while (x=getchar()){
            if (x=='\n') break;
            if (x==' '){
                base[jlh++]=num;
                num=0;
            }
            if (x>='0' && x<='9'){
                num*=10;
                num+=x-'0';
            }
        }
        base[jlh++]=num;
        //for (int j=0;j<jlh;j++) cout<<base[j]<<' ';
        //cout<<endl;
        //cout<<"Z"<<endl;
        for (int j=2;;j++){
            if (ok(j)){
                printf("Case #%d: %d\n",i,j);
                break;
            }
        }
    }
    //system("pause");
    return 0;
}
