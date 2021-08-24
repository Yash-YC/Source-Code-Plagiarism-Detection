#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<vector<int> > bas;
vector<vector<int> > ok;
vector<int> raw;

int conv(int n,int b) {
     int i,n1 = 0,a = n,temp;
     while (n>0) {
           n1 += (n%b)*(n%b);
           n /= b;
     }     
     ok[a][b] = -1;
     //printf ("%d %d %d ok:%d\n",a,b,n1,ok[n1][b]);
     if (ok[n1][b]==1) {
        ok[a][b] = 1;     
        bas[a][b] = bas[n1][b]; 
        return bas[n1][b]; 
     }
     if (ok[n1][b]==-1) {
        ok[a][b] = 1;
        bas[a][b] = 0;
        return 0;
     }
     temp = conv(n1,b);
     ok[a][b] = 1;
     bas[a][b] = temp;
     return temp;
}

int main () {
    freopen ("in.txt","r",stdin);
    freopen ("out.txt","w",stdout);
    int t,i,j,k,l,mark;
    string s;
    bas.resize(100000); ok.resize(100000);
    for (i=0;i<100000;i++)
        for (j=0;j<11;j++) {
            bas[i].push_back(0);
            ok[i].push_back(0);    
        }
    for (j=2;j<=10;j++) {
        bas[1][j] = 1;
        ok[1][j] = 1;
    }
    for (i=2;i<100000;i++)
        for (j=2;j<=10;j++)  
            if (ok[i][j]==0)
               conv(i,j);
    scanf ("%d\n",&t);
    for (i=1;i<=t;i++) {
        printf ("Case #%d: ",i);  
        raw.clear(); 
        mark = 0;
        getline (cin,s);
        l = s.length();
        for (j=0;j<l;j++) {
            if (s[j]>='2' && s[j]<='9')
               raw.push_back(s[j]-48);
            if (s[j]=='1')
               raw.push_back(10);
        }
        for (j=2;j<100000;j++) {
            for (k=0;k<raw.size();k++) {                 
                if (bas[j][raw[k]]==0) break;
                if (k==raw.size()-1) {
                   printf ("%d\n",j);
                   mark = 1;
                }
            }
            if (mark==1) break;
        } 
    }
    return 0;    
}
