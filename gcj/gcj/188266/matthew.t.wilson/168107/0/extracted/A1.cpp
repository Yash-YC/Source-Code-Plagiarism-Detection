// A1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "libfns.h"
#define SEARCHSIZE 50000

bool isHappy(int b, int val)
{
  bool seen[SEARCHSIZE] = {0};
  int digit;
  int sum;
  do{
    sum=0;
    while(val>0)
    {
      digit = val%b;
      sum+=digit*digit;
      val/=b;
    }
    if(sum==1) return true;
    if(seen[sum]) return false;
    val = sum;
    seen[sum] = true;
  }while(1);
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
  
  //2-10
  bool bitmap[9][SEARCHSIZE] = {0};
  char testCase[50];
  int bases[10];
  int numBases;

  for(int b=2;b<=10;++b)
  {
    for(int v=2;v<SEARCHSIZE;++v)
    {
      bitmap[b-2][v] = isHappy(b,v);
    }
  }

  bool found;
  int caseAnswer;
  char* currTok;
  for(int i=1; i<=testCases;++i)
  {
    numBases=1;
    strcpy(testCase,t.getToken());
    bases[0] = atoi(strtok(testCase," \n\t"));
    do{
      currTok = strtok(0," \n\t");
      if(currTok)
      {
        bases[numBases] = atoi(currTok);
        ++numBases;
      }
    }while(currTok);

    found = false;
    caseAnswer = 1;
    while(!found && caseAnswer<SEARCHSIZE)
    {
      found=true;
      ++caseAnswer;
      for(int j=0;j<numBases;++j)
      {
        if(!(bitmap[bases[j]-2][caseAnswer]))
        {
          j=numBases;
          found=false;
        }
      }
    }
    if(found)
    {
      fprintf(outFile,"Case #%d: %d\n",i,caseAnswer);
    }
    else
    {
      fprintf(stderr,"Could not find answer");
    }
  }
  
  return 0;
}

