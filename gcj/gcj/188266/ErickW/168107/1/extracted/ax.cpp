#include <iostream>
using namespace std;

int b[]={3,5,6,7,8,9,10};

main()
{
  system("echo Case #1: 2 >> a.out");
  for(int i=1;i<(1<<7);i++)
  {
    FILE *fp=fopen("a.in","w"); fprintf(fp,"1\n");
    for(int j=0;j<7;j++) if(i & (1<<j)) fprintf(fp," %d",b[j]);
    fprintf(fp,"\n"); fclose(fp);
    system("cat a.in");
    system("a.pl < a.in >> a.out");
  }
}
