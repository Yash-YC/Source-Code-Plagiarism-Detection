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

#define MA 500010

int vis[12][MA];
int hap[12][MA];

//FILE* pFile;
//int c;
//pFile = fopen("ou.txt","w");
//pFile=fopen ("beads.txt","r");

int comp(long long i, long long ba)
{
   if (vis[ba][i] == 1)
	 return hap[ba][i];

   vis[ba][i] = 1;
    long long cur = i;
       long long newn = 0;  
       long long curp = ba;
       while (cur > 0)
	   {
          long long rem = cur%ba;
	      newn = newn + rem*rem;
          cur = (cur - rem)/curp;
	      //curp=curp*ba;
	   }
	   int resNew = comp(newn, ba);
	   hap[ba][i] = resNew;
	   return resNew;
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


  memset(vis, 0, sizeof(vis));
  memset(hap, 0, sizeof(hap));

  for (int ba=2; ba<=10; ba++)
  {
    vis[ba][1] = 1;
	hap[ba][1] = 1;
  }

  for (int ba = 2; ba<=10; ba++)
  {
    for (int i=2; i<MA; i++)
	{
      comp(i, ba);
	}
  }

  int T;

  fin >> T;

  for (int tt=0; tt<T; tt++)
  { 
     vector <int> bases;
	 bases.clear();
     string na;
     if (tt == 0)
       getline(fin,na);

     getline(fin,na);

     istringstream sin(na); 
     int v; 
     while (sin>>v) 
       bases.push_back(v);

	 int mi = 2;
	 bool done = false;
     int n = bases.size();

	 while (!done)
	 {
        bool locDone = true; 
        for (int i=0; i<n && locDone; i++)
		{
           if (hap[bases[i]][mi] != 1)
			   locDone = false;
		}
		if (locDone)
		{
          done = true; 
		}
		else
		  mi++;
	 }

     fout << "Case #" << tt+1 << ": " << mi << endl;
  }

   return 0;
}
