#include<iostream>
#include<string>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<map>
#include<set>
#include<sstream>
#include<vector>
#include<deque>
using namespace std;

#define all(x) (x).begin(),(x).end()
#define forn(i,s,e) for(int i=(s),_e=(e);i<_e;i++)
#define rep(i,n) forn(i,0,n)
#define pb push_back 
#define db(i) cout<<#i<<"= "<<i<<endl; 

ifstream fin("A-small.in");
ofstream fout("output.out");


vector<int>bases;

void myitoa(unsigned long long Val,string &STr1,int BAse)
{
    STr1="";
    static const char AsCII[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(unsigned long long i=Val;i!=0;i/=BAse)
    {
        STr1=AsCII[(i%BAse)]+STr1;
    }
    if(STr1=="")
        STr1="0";
}

int main()
{
    int z;
    int ntests;
    fin>>ntests;
    string input;
    getline(fin,input);
    rep(ij,ntests)
    {
        bases.clear();
        //get line of bases
        getline(fin,input);
        stringstream ss(input);
        int base;
        while(ss>>base)
        {
            bases.pb(base);
        }
        int bsize=bases.size();
        //while not true
        for(int curnum=2;;curnum++)
        {
            //db(curnum);
            //test bases on curnum
            bool happy=true;
            rep(i,bsize)
            {
                //convert num to curbase
                int curbase=bases[i];
                //db(curbase);
                int tnum=curnum;
                string num;
                map<int,bool>mymap;
                while(true)
                {
                    if(mymap[tnum])break;
                    else mymap[tnum]=true;
                    myitoa(tnum,num,curbase);
                    //cout<<"conversion "<<num<<endl;
                    //fin>>z;
                    //if(num.size()==1)break;
                    //for each digit find square
                    int sum=0;
                    for(int i=0;i<num.size();i++)
                    {
                        int digit=num[i]-'0';
                        sum+=digit*digit;
                    }
                    //db(sum);
                    tnum=sum;
                }
                if(num!="1")
                {
                    happy=false;
                    break;
                }
                
            }
            if(happy)
            {
                fout<<"Case #"<<ij+1<<": "<<curnum<<endl;
                break;
            }
        }
        
        
    }
    printf("done\n");
    scanf("%d",&z);
    return 0;
}
