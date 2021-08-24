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
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
  
using namespace std; 
  
//BEGINTEMPLATE
#define SIZE(X) ((int)(X.size()))//NOTES:SIZE( 
#define LENGTH(X) ((int)(X.length()))//NOTES:LENGTH( 
#define MP(X,Y) make_pair(X,Y)//NOTES:MP( 
typedef long long int64;//NOTES:int64 
typedef unsigned long long uint64;//NOTES:uint64 
#define two(X) (1<<(X))//NOTES:two( 
#define twoL(X) (((int64)(1))<<(X))//NOTES:twoL( 
#define contain(S,X) (((S)&two(X))!=0)//NOTES:contain( 
#define containL(S,X) (((S)&twoL(X))!=0)//NOTES:containL( 
const double pi=acos(-1.0);//NOTES:pi 
const double eps=1e-11;//NOTES:eps 
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}//NOTES:checkmin( 
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}//NOTES:checkmax( 
template<class T> inline T sqr(T x){return x*x;}//NOTES:sqr 
typedef pair<int,int> ipair;//NOTES:ipair 
template<class T> inline T lowbit(T n){return (n^(n-1))&n;}//NOTES:lowbit( //最小有效位
template<class T> inline int countbit(T n){return (n==0)?0:(1+countbit(n&(n-1)));}//NOTES:countbit( 
//Numberic Functions 
template<class T> inline T gcd(T a,T b)//NOTES:gcd( 
  {if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);} 
template<class T> inline T lcm(T a,T b)//NOTES:lcm( 
  {if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));} 
template<class T> inline T euclide(T a,T b,T &x,T &y)//NOTES:euclide( 
  {if(a<0){T d=euclide(-a,b,x,y);x=-x;return d;} 
   if(b<0){T d=euclide(a,-b,x,y);y=-y;return d;} 
   if(b==0){x=1;y=0;return a;}else{T d=euclide(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}} 
template<class T> inline vector<pair<T,int> > factorize(T n)//NOTES:factorize( 
  {vector<pair<T,int> > R;for (T i=2;n>1;){if (n%i==0){int C=0;for (;n%i==0;C++,n/=i);R.push_back(make_pair(i,C));} 
   i++;if (i>n/i) i=n;}if (n>1) R.push_back(make_pair(n,1));return R;} 
template<class T> inline bool isPrimeNumber(T n)//NOTES:isPrimeNumber( 
  {if(n<=1)return false;for (T i=2;i*i<=n;i++) if (n%i==0) return false;return true;} 
template<class T> inline T eularFunction(T n)//NOTES:eularFunction( 
  {vector<pair<T,int> > R=factorize(n);T r=n;for (int i=0;i<R.size();i++)r=r/R[i].first*(R[i].first-1);return r;} 
//Translator 
bool isUpperCase(char c){return c>='A' && c<='Z';}//NOTES:isUpperCase( 
bool isLowerCase(char c){return c>='a' && c<='z';}//NOTES:isLowerCase( 
bool isLetter(char c){return c>='A' && c<='Z' || c>='a' && c<='z';}//NOTES:isLetter( 
bool isDigit(char c){return c>='0' && c<='9';}//NOTES:isDigit( 
char toLowerCase(char c){return (isUpperCase(c))?(c+32):c;}//NOTES:toLowerCase( 
char toUpperCase(char c){return (isLowerCase(c))?(c-32):c;}//NOTES:toUpperCase( 
//Fraction 
template<class T> struct Fraction{T a,b;Fraction(T a=0,T b=1);string toString();};//NOTES:Fraction 
template<class T> Fraction<T>::Fraction(T a,T b){T d=gcd(a,b);a/=d;b/=d;if (b<0) a=-a,b=-b;this->a=a;this->b=b;} 
template<class T> string Fraction<T>::toString(){ostringstream sout;sout<<a<<"/"<<b;return sout.str();} 
template<class T> Fraction<T> operator+(Fraction<T> p,Fraction<T> q){return Fraction<T>(p.a*q.b+q.a*p.b,p.b*q.b);} 
template<class T> Fraction<T> operator-(Fraction<T> p,Fraction<T> q){return Fraction<T>(p.a*q.b-q.a*p.b,p.b*q.b);} 
template<class T> Fraction<T> operator*(Fraction<T> p,Fraction<T> q){return Fraction<T>(p.a*q.a,p.b*q.b);} 
template<class T> Fraction<T> operator/(Fraction<T> p,Fraction<T> q){return Fraction<T>(p.a*q.b,p.b*q.a);} 
//ENDTEMPLATE

const int maxn=100000;
const int maxbase=15;

int a[maxn];
int ishappy[maxn][maxbase];
bool mk[maxn];

void ntobase(int n,int base)
{
	int tmp=n,i=0;
	while(tmp)
	{
		a[++i]=tmp%base;
		tmp/=base;
	}
	a[0]=i;
}

int dfs(int n,int base)
{
	int i,tmp=0;
	mk[n]=true;
	if(ishappy[n][base]>=0)return ishappy[n][base];
	ntobase(n,base);
	//for(i=a[0];i>=1;i--)printf("%d ",a[i]);puts("");
	for(i=1;i<=a[0];i++)tmp+=a[i]*a[i];
	if(mk[tmp]) 
	{
		ishappy[n][base]=0;
		return 0;
	}else 
	{
		ishappy[n][base]=dfs(tmp,base);
		return ishappy[n][base];
	}
}

int main()
{

	int i,b;
	memset(ishappy,-1,sizeof(ishappy));
	for(b=2;b<=10;b++)ishappy[1][b]=1;
	for(b=2;b<=10;b++)
	{
		for(i=1;i<maxn;i++)
		{
			memset(mk,0,sizeof(mk));
			dfs(i,b);
			//if(ishappy[i][b]>0)printf("%d ",i);
		}
		//puts("");
	}
	
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	int T;
	scanf("%d",&T);
	int ans;
	for(i=1;i<=T;i++)
	{
		printf("Case #%d: ",i);
		ans=maxn;
		int base[maxbase],tot=0;
		while(1)
		{
			scanf("%d",&base[++tot]);
			char ch=getchar();
			if(ch=='\n')break;
		}
		int k,j;
		for(j=2;j<maxn;j++){
			bool good=true;
			for(k=1;k<=tot;k++)if(ishappy[j][base[k]]==0){
				good=false;
				break;
			}
			if(good)
			{
				printf("%d\n",j);
				break;
			}
		}
	}
	freopen("CON","r",stdin);
	fclose(stdout);
	//system("PAUSE");
	return 0;
}