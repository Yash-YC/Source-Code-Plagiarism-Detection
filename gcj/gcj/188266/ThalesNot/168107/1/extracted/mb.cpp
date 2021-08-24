#include <iostream>
#include <strstream>
#include <vector>
using namespace std;

void printAr(int *p, int m)
{
   for(int i=0; i!=m; i++) cout << p[i] << " ";
   cout << endl;
}

int convert(int n, int b)
{
   unsigned d=0, sum=0;
   while(n>0)
   {
     d=n%b;
     n/=b; 
     sum+=d*d;
   }
   return sum;
}

bool isHappy(int n, int b)
{
   int n1=n;
   int j=0;
   while (true)
   { 
       n1=convert(n1,b);
       if (n1==1) return true;
       n1=convert(n1,b);
       if (n1==1) return true;
       n=convert(n,b);
       if (n1==n) return false;
   }
}

int main()
{
  
  int i,j,jj,k,T=0, M=1;
  cin >> T;

  for(i=1; i<=T; i++)
  {
    vector<int> bases; 
    int b=1;
    while (b) 
    {
       cin >> b; 
       if (b) bases.push_back(b);
    }
 
    bool happy=true;
    for(j=2; j<10000000; j++)
    {
       happy=true;
       for(k=0; k!=bases.size(); k++)
       {
//     cout << " Checking " << j << " w base"  << bases[k] << " - " ;
          bool h = isHappy(j,bases[k]);
//        cout << h << endl;
          if (!h) { happy=false; break;} 
       }
       if (happy)  break;
    }

    if (happy)
     cout << "Case #"<< i <<": " << j << endl;
    else
     cout << "Case #"<< i <<": " << -1 << endl;

  }
  return 0;
}
