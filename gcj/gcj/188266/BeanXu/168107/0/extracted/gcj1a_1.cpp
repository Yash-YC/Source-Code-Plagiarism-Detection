#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int t,i,j,len,base[10];
int a[100],aa[100];
int b[50000];

bool calc(int x,int base)
{
     memset(b,false,sizeof(b));
     b[x]=true;
     int l=0,temp=x;
     while (temp)
     {
           a[++l]=temp%base;
           temp/=base;
     }
     while (true)
     {
           int len=0;
           memset(aa,0,sizeof(aa));
           for (int i=1;i<=l;i++)
           {
               aa[1]+=a[i]*a[i];
               int j=1;
               while(aa[j]>=base)
               {
                                 aa[j+1]+=aa[j]/base;
                                 aa[j]%=base;
                                 j++;
               }
               len=max(len,j);
           }
           if (len==1)
           {               
                      if (aa[1]==1) return true;
                      if (b[aa[1]]) return false;
                      else b[aa[1]]=true;
                      l=1;
                      a[1]=aa[1];
           }
           else
           {
               l=len;
               int sum=0,pp=1;
               for (int i=1;i<=l;i++)
               {
                   a[i]=aa[i];
                   sum+=a[i]*pp;
                   pp*=base;
               }
               if (b[sum]) return false;
               else b[sum]=true;
           }
     }
}

int main()
{
    freopen("gcj1.in","r",stdin);
    freopen("gcj1.out","w",stdout);
    cin>>t;
    string temp;
    getline(cin,temp);
    for (int ii=1;ii<=t;ii++)
    {
        getline(cin,temp);
        i=0;len=0;
        while (i<temp.size())
        {
              if (temp[i]!='1')
              {
                            base[++len]=int(temp[i])-48;
              }
              else
              {
                            base[++len]=10;
                            i++;
              }
              i+=2;
        }
        i=2;
        while (true)
        {
              bool b=true;
              for (j=len;j>=1;j--)
              {
                  b=calc(i,base[j]);
                  if (!b) break;
              }
              if (b) break;
              i++;
        }
        cout<<"Case #"<<ii<<": "<<i<<endl;
    }
    return 0;
}
