#include<cstdio>
#include<vector>
#include<algorithm>
#include<climits>

// Manually Added -1 at end of line

using namespace std;

#define FOR(i,N) for(int i=0; i<(N); ++i)

int sqrd(int);
bool isHappy(int,int);
int base(int,int);

int main()
  {
    int N,t,f;
    
    int arr[20];
    
    scanf("%d ", &N);

    FOR(i,N)
      {
	FOR(j,20)
	  {
	    scanf("%d", arr+j);
	    if(arr[j]==-1)
	      {
		t=j;
		break;
	      }
	  }
	


	FOR(k,INT_MAX)
	  {
	    
	    if(!k) ++k;
	    f=1;
	    FOR(j,t)
	      {
		if(isHappy(base(k+1,arr[j]),arr[j]))
		  continue;
		else
		  {
		    f=0;
		    break;
		  }
	      }
	    if(f) 
	      {
		printf("Case #%d: %d\n",i+1, k+1);
		break;
	      }
	  }
      }
    		
    return(0);
  }

bool isHappy(int n, int B)
  {
    vector<int> V;
    
    int a,s;

    do
      {
	a=sqrd(n);
	
	if(a==1) return true;
	
	a=base(a,B);

	s=V.size();
	FOR(i,s) if(V[i]==a) return false;
	
	V.push_back(a);
	
	n=a;
      }
    while(true);
  }

int base(int a,int B)
  {
    int b=0;

    while(a)
      {
	b=b*10+(a%B);
	
	a/=B;
      }

    return(b);
  }
    
    

int sqrd(int a)
  {
    int ans,d;
    ans=0;
    
    while(a)
      {
	d=a%10;
	ans+=d*d;
	a/=10;
      }
    
    return(ans);
  }
