#include<iostream>
using namespace std;
#define MAX_NUMBER 100000;

int base[20];
long temptemp[200000],all;
int n,t;
bool flag;
long long ans,temp;
bool show;
// char   line[100000];   
 char   p;   
 
 
bool check1(long temp,long all)
 {
  	for (int i = 1; i <= all ; i++)
	  {
	   		 if  (temptemp[i]== temp ) return false;
      } 
      return true;
 }
bool check(long  a, int b)
 {
   if (a==1) return true;
   long  temp=0;
   long  temp1;
   long  a1  = a;
   while(a1>0)
    {
	 temp1=a1%b;		  
	 temp=temp+temp1*temp1;
	 a1=a1/b;		  
    } 	 
  
    if (check1(temp,all)==false) return false;
     all++;
     temptemp[all]=temp;
    return check(temp,b);
 }

int main()
 {
  freopen("A.in", "r", stdin) ;
  freopen("a.txt","w",stdout);
 cin>>t;

 for (int test = 1 ; test <= t; test++)
  {
   	 	n=0;
   	 	p='1';
   	 	while ((p!='\n')&& (p!='\r'))
		{
		 	n++;
			 cin>>base[n];  
		 p=getchar();
	//	 	cin>>p;  
        }
    ans=0;
   	for (int j = 2; j <= 10000000; j ++) 
	   { 
	   	 flag=true;	  	 
   	for (int i = 1; i <= n ; i++)
	    {
		 	 all=1;
		 	 temptemp[1]=j;
	      if (check(j,base[i])==false) {flag=false; break;}
		 }
		 if (flag) {ans=j; break;}
       } 	  
    cout<<"Case #"<<test<<": "<<ans<<endl;   
  } 		  
 }
