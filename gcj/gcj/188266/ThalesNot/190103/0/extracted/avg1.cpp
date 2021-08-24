#include <iostream>
#include <algorithm>
#include <ext/algorithm>
using namespace std;
using namespace __gnu_cxx;

int cards[50];
int sample[50];
int haveIt[50];

const int R=1000000;

void printAr(int *p, int m)
{
   for(int i=0; i!=m; i++) cout << p[i] << " ";
   cout << endl;
}

int main()
{
  int i,j,jj,k,T=0;
  cin >> T;

  for(i=0; i!=50; i++) cards[i]=i;

  for(i=0; i!=T; i++)
  {
    int C=0, N=0;
    cin >> C >> N;  
//  cout << C << " " << N << endl;

    unsigned SUM=0;
    for(k=0;k!=R;k++) // averaging
    {
       bool complete=false;
       for(j=0;j!=C;j++) haveIt[j]=0;

       for(j=1;j!=10;j++)  // repeat until a hit
       {
          random_sample_n(cards,cards+C,sample,N); 
          for(jj=0;jj!=N;jj++) haveIt[sample[jj]]=1;
//        cout << " Sample: " ;
//        printAr(&sample[0],N);
//        cout << " Have it: " ;
//        printAr(&haveIt[0],C);
          complete=true;
          for(jj=0;jj!=C;jj++) if(haveIt[jj]==0) 
//                 { cout << " Missing " << j << endl; complete=false;}
                                                       complete=false; 
//        if (complete)  { cout << " complete!"<< endl; break;}
          if (complete)                                 break;
       }
      SUM+=j;
 //   cout << k << ". " << j << " SUM=" << SUM << endl;
    }
 // cout << SUM << " / " <<  R << endl;
    cout << "Case #"<< i+1 <<": " << SUM/(R*1.0) << endl;
  }
  return 0;
}
