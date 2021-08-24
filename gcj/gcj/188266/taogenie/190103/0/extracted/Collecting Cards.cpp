#include <fstream>
#include <iostream>
using namespace std;

double combine(int m,int n) 
{
	double result=1;
	if(n>m-n)
	{
		n=m-n; //C(m,n)==C(m,m-n) pick small
	}
	for(int i=1;i<=n;i++)
	{
		result*=((double)(m-n+i)/i);
	}
	return result; 
} 

int main()
{
	ifstream fin("C-small-attempt3.in",ios::in);
	ofstream fout("output.txt",ios::out);
	int i,j,k;
	int t;
	int c,n;
	double nposs[41],nposs2[41];
	double avg;
	double newavg;
	int current;
	int index;
	fin>>t;
	for(i=0;i<t;i++)
	{
		fout<<"Case #"<<i+1<<": ";
		//in
		fin>>c;
		fin>>n;
		if(n>=c)
		{
			fout<<1<<endl;
			continue;
		}
		if(i==99)
		{
			int bp=1;
		}
		//count
		for(j=0;j<=c;j++)
		{
			nposs[j]=0;
		}
		avg=0;
		nposs[n]=1;
		current=1;
		while(1)
		{
			current++;
			for(j=0;j<=c;j++)
			{
				nposs2[j]=0;
			}
			for(j=n;j<=c;j++)
			{
				if(nposs[j]==0)
				{
					continue;
				}
				for(k=0;k<=n;k++)
				{
					if(j+k>c)
					{
						continue;
					}
					else
					{
						index=j+k;
					}
					nposs2[index]+=nposs[j]*combine(j,n-k)*combine(c-j,k)/combine(c,n);
				}
			}
			newavg=(nposs2[c]-nposs[c])*current;
			avg+=newavg;
			if(newavg<0.0000000001&&avg>1)
			{
				break;
			}
			for(j=n;j<=c;j++)
			{
				nposs[j]=nposs2[j];
			}
		}
		//out
		fout<<avg<<endl;
//		printf("%.7f\n",avg);
	}
	system("pause");
	fin.close();
	fout.close();
	return 0;
}