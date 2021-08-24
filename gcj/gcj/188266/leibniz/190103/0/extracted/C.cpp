#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <set>
#include <map>
#include <deque>
#include <sstream>
using namespace std;
typedef vector<string> vs;
typedef vector<vector<string> > vvs;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;

vector<string> split(string x, string cs);
int findxth(string source, string srch, int occ);
int letidx(char c);
string lower(string s);
string upper(string s);
int stoi(string x);
string itos(int x);
int ctoi(char x);
char itoc(int x);
string frbase10(int x, int fr);
int tobase10(string x, int to);
string convbase(string x, int fr, int to);
int ipow(int a, int b);
double polyarea(vector<double> x, vector<double> y);
double triarea(double a, double b, double c);
double ptdist(double x1, double y1, double z1, double x2, double y2, double z2);

// ------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------

int main()
{
   double combs[41][41];
   for (int n=1; n<41; n++)
   {
      int r;
      double s = 1.0 + n;
      combs[n][0] = 1.0;
      combs[n][1] = n;
      for (r=2; r<=n; r++)
      {
         combs[n][r] = combs[n][r-1] * (n - (r-1));
         s += combs[n][r];
      }
//      for (r=0; r<=n; r++)
//         combs[n][r] /= s;
   }

   int numTests;
   scanf("%d\n", &numTests);
   for (int a=1; a<=numTests; a++)
   {
      int cards, boost;
      scanf("%d %d\n", &cards, &boost);
      double prob = 1.0;
      prob = prob + (double)(cards-boost) / ( ((double)(boost)) / ((double)(cards)) );
      printf("Case #%d: %.6lf\n", a, prob);
   }

   return 0;
}

// ------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------

vector<string> split(string x, string cs)
{
   vector<string> ans;
   ans.clear();
   string temp="";
   for (unsigned int ctr=0; ctr<x.length(); ctr++)
      if (cs.find(x[ctr])<cs.length() && temp.length()>0)
      {
         ans.push_back(temp);
         temp="";
      }
      else if (cs.find(x[ctr])>=cs.length())
         temp += x[ctr];
   if (temp.length()>0) ans.push_back(temp);
   return ans;
}

int findxth(string source, string srch, int occ)
{
   int res = -1;
   int ctr = 0;
   while (ctr<occ)
   {
      res = source.find(srch, res+1);
      if (res > source.length())
         return -1;
      ctr++;
   }
   return res;
}

int letidx(char c)
{
   if (c >= 'a' && c <= 'z')
      return (c-'a');
   else if (c >= 'A' && c <= 'Z')
      return (c-'A');
   else
      return -1;
}

string lower(string s)
{
   string ans = "";
   for (int ctr=0; ctr<s.length(); ctr++)
      if (s[ctr]>='A' && s[ctr]<='Z')
         ans += (char)(s[ctr]-'A'+'a');
      else
         ans += s[ctr];
   return ans;
}

string upper(string s)
{
   string ans = "";
   for (int ctr=0; ctr<s.length(); ctr++)
      if (s[ctr]>='a' && s[ctr]<='z')
         ans += (char)(s[ctr]-'a'+'A');
      else
         ans += s[ctr];
   return ans;
}

int stoi(string x)
{
   int ans=0;
   for (unsigned int ctr=0; ctr<x.length(); ctr++)
   {
      if (x[ctr]>='0' && x[ctr]<='9')
      {
         ans *= 10;
         ans += (int)(x[ctr]-'0');
      }
   }
   if (x[0]=='-')
      ans *= -1;
   return ans;
}

string itos(int x)
{
   string ans="";
   bool neg=false;
   long long temp=x;
   if (x<0)
   {
      neg = true;
      temp *= -1;
   }
   int last=0;
   while(!last)
   {
      if (temp<10) last=1;
      ans = (char)((temp%10)+'0') + ans;
      temp /= 10;

   }
   if (neg)
      ans = "-" + ans;
   return ans;
}

int ctoi(char x)
{
   if (x>='0' && x<='9')
      return ((int)(x-'0'));
   else
      return (10+(int)(x-'A'));
}

char itoc(int x)
{
   if (x<10)
      return ((char)(x+'0'));
   else
      return ((char)(x-10 + 'A'));
}

string frbase10(int x, int fr)
{
   string ans="";
   int temp=x;
   int ctr=0;
   if (x==0) return "0";

   while(temp >= ipow(fr,ctr)) ctr++;
   ctr--;

   while(ctr>=0)
   {
      ans += itoc(temp / ipow(fr,ctr));
      temp = temp % ipow(fr,ctr);
      ctr--;
   }
   return ans;
}

int tobase10(string x, int to)
{
   int ans=0;
   for (unsigned int ctr=0; ctr<x.length(); ctr++)
      ans+=(ipow(to,x.length()-1-ctr) * ctoi(x[ctr]));
   return ans;
}

string convbase(string x, int fr, int to)
{
   return frbase10(tobase10(x,fr),to);
}

int ipow(int a, int b)
{
   int x=1;
   b = abs(b);
   if (a==0)
      return 0;
   if (a==1)
      return 1;
   if (b==0)
      return 1;
   for (int ctr=0; ctr<b; ctr++)
      x *= a;
   return x;
}

double polyarea(vector<double> x, vector<double> y)
{
   double res = 0.0;
   int n = x.size();
   for (int ctr=0; ctr<n-1; ctr++)
      res += (x[ctr]*y[ctr+1] - x[ctr+1]*y[ctr]);
   if (n > 2)
      res += (x[n-1]*y[0] - x[0]*y[n-1]);
   res *= 0.5;
   if (res < 0.0) res *= -1.0;
   return res;
}

double triarea(double a, double b, double c)
{
   double p = (a+b+c)/2.0;
   return sqrt(p*(p-a)*(p-b)*(p-c));
}

double ptdist(double x1, double y1, double z1, double x2, double y2, double z2)
{
   return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2));
}
