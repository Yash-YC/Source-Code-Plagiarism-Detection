#include <iostream> 
#include <vector>
#include <string>
#include <string.h>
#include <algorithm> 
#include <sstream>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <bitset>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cfloat>
#include <bitset> 

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
int tonum(string cad)
{
    int res;
    stringstream is(cad);
    is>>res;
    return res;
}
long long val(long long num)
{
    long long res=0;
    long long dig;
    while(num)
    {   
        dig=num%10;
        res+=((long long)dig*dig);
        num/=10;
    }
    return res;
}
long long to10(long long num,int base)
{
    long long res=0LL;
    long long pot=1;
    int dig;
    while(num)
    {
        dig=num%10;
        res+=((long long)pot*dig);
        num/=10;
        pot=(long long)pot*base;
    }
    return res;
}
long long toba(long long num,int base)
{
        long long res=0;
        int dig;
        while(num>=base)
        {
            dig=num%base;
            res=(long long)res*10+dig;
            num/=base;
        }
         res=(long long)res*10+num;
         return res;
}
bool feliz(long long num,int base)
{
    //long long num2=to10(num,base);
    //cout<<num2<<" "<<num<<" "<<base<<endl;
    
    map<long long,bool> esta;
    esta.clear();
    while(1)
    {   
        num=toba(num,base);
        //num=to10(num,base);
        num=val(num);
        if(esta[num])
            return false;
        if(num==1)
            return true;
        esta[num]=true;
                
    }
    return false;
    
}
int saca(vector <int> v)
{
    bool es;
    long long ini=0;
   /* for(int i=0;i<v.size();i++)
            ini=max(ini,(long long)v[i]);
            ini++;
    
    */
    for(ini=2;;ini++)
    {
    
        es=true;
        //cout<<i<<endl;
        for(int j=0;j<v.size()&&es;j++)
        {
            
            if(!feliz(ini,v[j]))
             es=false;
        }
        if(es)
        return ini;
    }
    return 0;

}
int main()
{
    string cad;
    getline(cin,cad);
    int n=tonum(cad);
    for(int i=0;i<n;i++)
    {
        getline(cin,cad);
        vector <int> todo;
        int aux;
        stringstream is(cad);
        while(is>>aux)
        {
            todo.push_back(aux);
        }
        //cout<<todo.size()<<endl;
        int res2=saca(todo);
        cout<<"Case #"<<i+1<<": "<<res2<<endl; 
    }
    /*
    cout<<to10(3,8)<<endl;
    cout<<to10(13,8)<<endl;
    cout<<val(13)<<endl;
    */
    //cout<<toba(5,2)<<endl;
    return 0;
}
