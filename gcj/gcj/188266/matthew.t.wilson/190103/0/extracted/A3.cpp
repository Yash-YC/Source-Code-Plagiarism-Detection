// A3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "libfns.h"

__int64 fact(__int64 n)
{
  if(n==0)
    return 1;
  else
    return n*fact(n-1); 
}
int _tmain(int argc, _TCHAR* argv[])
{
  if(argc!=2)
  {
    fprintf(stderr,"usage: %s infile\n",argv[0]);
    exit(0);
  }
  FILE* inFile = fopen(argv[1],"rt");
  if(!inFile)
  {
    fprintf(stderr,"Could not open %s\n",argv[1]);
    exit(0);
  }
  char outFileName[256] = {0};
  sprintf(outFileName,"%s.out.txt",argv[1]);
  FILE* outFile = fopen(outFileName,"wt");
  if(!outFile)
  {
    fprintf(stderr,"Could not open %s\n",outFileName);
    exit(0);
  }
  tokenizer t(inFile);
  int testCases = atoi(t.getToken());

  __int64 C, N, CchooseN;
  double fC, fN;
  __int64 num;

  for(int i=1; i<=testCases;++i)
  {
    C=atoi(t.getToken());
    N=atoi(t.getToken());
    CchooseN = fact(C)/fact(N);
    CchooseN /= fact(C-N);
    num = CchooseN+N;
    fC = num;
    fN = N;
    fprintf(outFile,"Case #%d: %.6f\n",i,num/fN);
  }

  fclose(outFile);
  fclose(inFile);


  return 0;
}

