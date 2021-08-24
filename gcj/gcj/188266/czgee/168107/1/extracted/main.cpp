#include <stdio.h>
#include <vector>
#include <string.h>

bool isHappy(int number, int base, std::vector<int>& prev)
{
	int lNumber=number;
	int lDigit;

	int lNew=0;

	while (lNumber>0)
	{
		lDigit=lNumber%base;
		lNumber/=base;

		lNew+=lDigit*lDigit;
	}

	if (lNew==1) return true; else
	{
		for (int i=0;i<prev.size();i++)
			if (prev[i]==lNew) return false;
		prev.push_back(lNew);

		return isHappy(lNew, base, prev);
	}

}


int main(int argc, char *argv[])
{
  FILE* in=fopen("A-large.in","r");
  FILE* out=fopen("A-large.out","w");
  int n;
  fscanf(in,"%i\n",&n);


  for (int i=0;i<n;i++)
  {
	char ltmp[1000];
	char* lwtf;

	std::vector<int> bases;

	fgets(&ltmp[0],1000,in);

	int ttmp;

	lwtf=&ltmp[0];

	char omfg[50];

	while (sscanf(lwtf,"%i ",&ttmp)!=EOF)
	{
		bases.push_back(ttmp);
		lwtf+=strlen(itoa(ttmp,omfg,10))+1;
	}

	for (int wtf=2;;wtf++)
	{
		bool ok=true;
		for (int x=0;x<bases.size();x++)
		{
			std::vector<int> prevs;
			if (!isHappy(wtf,bases[x],prevs)) {ok=false; break;}
		}
		if (ok) {fprintf(out,"Case #%u: %u\n",i+1,wtf);break;}
	}

  }

  

  fclose (in);
  fclose (out);

}