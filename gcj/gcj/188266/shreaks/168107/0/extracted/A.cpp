#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
 
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
using namespace std; 


int sumOfSqr(int n)
{
    int ans = 0;
    while(n){
             ans += (n % 10)*(n % 10);
             n = n / 10;
    }    
    return ans;
}

int p(int a, int b)
{
    int ans = 1;
    while(b--)
            ans *= a;
            
    return ans;
}

int convertToBase(int n, int b)
{
    int ans = 0;
    int i = 0;
    while(n){
         //    cout<<endl<<n<<" "<<b<<" "<<n % b<<" "<<((int)pow((double) 10, (double) i))<<" "<<((n % b)* (int)pow((double) 10, (double) i));
             ans += (n % b)* p(10, i);
         //    cout<<endl<<ans;
             n = n / b;         
             i++;
    }   
    return ans;
}
map<int, int> mp;
bool happy(int a, int b)
{
     mp[a]++;
     if(mp[a] == 2) return false;
     int based =  convertToBase(a, b);
     int smsq = sumOfSqr(based);
     if( smsq == 1) return true;
     return happy(smsq, b);
}

int main()
{
    int n;
    cin >> n;
    string str;
    getline(cin, str, '\n');
    
    int b;
    
    for(int i = 1; i <= n; i++){
            getline(cin, str, '\n');

            istringstream sin(str);
            vector<int> bases;
            while(sin >> b)
                      bases.pb(b);
                      
            int j = 2;
//            tr(bases, itr)
 //                     cout<<endl<<"base : "<<*itr<<" "<<convertToBase(j, *itr);
            
            while(j){
                     bool ishappy = true;
                     tr(bases, itr){
                               b = *itr;
                               mp.clear();
                               ishappy = happy(j, b);
                               if(!ishappy)
                                           break;
                     
                     }
                     if(ishappy){
                                 cout<<"Case #"<<i<<": "<<j;
                                 cout<<endl;
                                 break;
                     }
                     j++;         
            }                   
          
            
    }
    return 0;    
}
