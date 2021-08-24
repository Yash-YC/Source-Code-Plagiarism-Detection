#include <fstream>
using namespace std;
int main()
{
	fstream fin,fout;
	fin.open("A-small-attempt0.in",ios::in);
	fout.open("out.out",ios::out);
	int bases[10];
	int temp[1000];
	int T,ishappy;
	char c;
	fin>>T;
	int i,j,k,l;
	for(i=0;i<T;i++)
	{
		j=0;
		c=' ';
		while(c!='\n')
		{
			fin>>bases[j++];
			c=fin.get();
		}
		int baseN=j;
		for(k=2;1;k++)
		{
			for(j=0;j<baseN;j++)
			{
				for(l=1,temp[0]=k;1;l++)
				{
					temp[l]=0;
					for(int x=temp[l-1];x!=0;x=x/bases[j])
						temp[l]+=(x%bases[j])*(x%bases[j]);
					if(temp[l]==1)
					{
						ishappy=1;
						break;
					}
					for(int x=0;x<l;x++)
					{
						if(temp[l]==temp[x])
						{
							ishappy=0;
							goto NEXT;
						}
					}
				}
NEXT:			if(ishappy==0)
					break;
			}
			if(ishappy)
			{
				fout<<"Case #"<<i+1<<": "<<k<<endl;
				break;
			}
		}
	}
}				
	
