#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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
#include <ctime>
#include <queue>
#include <stdio.h>

#include <math.h>

using namespace std;

ofstream fout("oooo.txt");
ifstream fin ("iiii.in");

//FILE* pFile;
//int c;
//pFile = fopen("ou.txt","w");
//pFile=fopen ("beads.txt","r");

int N, C;

int SC;

#define MA 2048

double expe[MA];
int    vis[MA];

double CNK;
double rcnk;

double chose(int n, int k)
{
  if (k > n)
     return 0;
  double ret = 1;
  for (int i=1; i<= k; i++)
  {
    ret *= (n+1-i);
    ret /= i;
  }
  return ret;
}

double comp(int mask)
{
   if (vis[mask] == 1)
      return expe[mask];

   int cur[11];
   memset(cur, 0, sizeof(cur));

   int locmask = mask;
   int i = 0;
   while (locmask > 0)
   {
     int rem = locmask%2;
     cur[i] = rem;
	 i++;
	 locmask = (locmask - rem)/2;
   }

   double tot    = 0;
   double totsame = 0;
   double totdif  = 0;
   double needdif = 0.0;
   double totfin  = 0;
   for (int j=0; j<=SC; j++)
   {
      int Ncur[11];
      memset(Ncur, 0, sizeof(Ncur));

	  int num = 0;
      int Nlocmask = j;
      int i = 0;
      while (Nlocmask > 0)
      {
         int Nrem = Nlocmask%2;
		 num = num + Nrem;
         Ncur[i] = Nrem;
	     i++;
	     Nlocmask = (Nlocmask - Nrem)/2;
      }
	  if ( num == N)
	  {
         tot++;
		 int newmask = 0;
		 int po = 1;
		 for (int i=0; i<11; i++)
		 {
			if ( cur[i] == 1 || Ncur[i] == 1 )
			{
               newmask = newmask + po;
			}
			po = po*2;
		 }
         if ( newmask == SC )
			 totfin++;
		 else if ( newmask == mask )
			 totsame++;
		 else
		 {
            totdif++;
            needdif = needdif + comp(newmask);
		 }
	  }
   }

   double res = rcnk*(totsame+totfin+totdif+needdif);
   double inv = 1/( 1.0 - rcnk*totsame );

   vis[mask] = 1;
   expe[mask] = res*inv;
   return expe[mask];
}

int main() {

//FILE* pFile;
//pFile = fopen("ou.txt","w");

// string na;
// if (tt == 0)
//  getline(fin,na);

// getline(fin,na);

// istringstream sin(na); 
// string v; 
// while (sin>>v) 
//   names.push_back(v); 


//sscanf(stringHM,"%d:%d",&h,&m);


 //fprintf(pFile, "Case #%d: ", t+1);
 //fprintf(pFile,"%d\n",res);

  int T;

  fin >> T;

  for (int tt=0; tt<T; tt++)
  { 
     memset(expe, 0, sizeof(expe));
	 memset(vis, 0, sizeof(vis));
     fin >> C >> N;

	 SC = (1 << C) - 1 ;

     CNK = chose(C,N);
	 rcnk = 1/CNK;

	 double res = 0.0;

	 res = comp(0);

     fout << "Case #" << tt+1 << ": " << res << endl;
  }

   return 0;
}
