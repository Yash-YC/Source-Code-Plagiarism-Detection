#include<fstream>
using namespace std;

int shu[11][301];
int main()
{
	ifstream in;
	ofstream out;
	in.open("A-small-attempt2.in");
	out.open("out.txt");
	int i,j,z;
	for(i=2;i<11;i++)
	{
		for(j=2;j<301;j++)
		{
			shu[i][j]=0;
		}
		shu[i][1]=1;
	}
	int ne,old;
	for(i=2;i<11;i++)
	{
		for(j=2;j<301;j++)
		{
			if(shu[i][j]!=0)continue;
			old=j;ne=0;
			while(1)
			{
				shu[i][old]=2;
				while(old!=0)
				{
					int temp=old%i;
					ne+=(temp*temp);
					old=old/i;
				}
				old=ne;
				ne=0;
				if(shu[i][old]!=0)break;
				
			}
			if(shu[i][old]==1)
			{
				for(int z=2;z<301;z++)
				{
					if(shu[i][z]==2)shu[i][z]=1;
				}
			}
			else
			{
				for(int z=2;z<301;z++)
				{
					if(shu[i][z]==2)shu[i][z]=-1;
				}
			}
		}
	}

	int n,sum;
	bool de[11];
	in>>n;
	for(z=0;z<n;z++)
	{
		for(i=0;i<11;i++)de[i]=false;
		int t;
		while(1)
		{
			in>>t;
			de[t]=true;
			if(in.peek()=='\n')break;
		}
		for(i=2;i<301;i++)
		{
			for(j=2;j<11;j++)
			{
				if(de[j]==false)continue;
				if(shu[j][i]!=1)break;
			}
			if(j==11)break;
		}
		if(i!=301)sum=i;
		else
		{
			for(i=301;;i++)
			{
				for(j=2;j<11;j++)
				{
					if(de[j]==false)continue;
					old=i;ne=0;
					while(old>=301)
					{
						while(old!=0)
						{
							int temp=old%j;
							ne+=(temp*temp);
							old=old/j;
						}
						old=ne;
						ne=0;
					}
					if(shu[j][old]!=1)break;
				}
				if(j==11)break;
			}
			sum=i;
		}
		out<<"Case #"<<z+1<<": "<<sum<<endl;
	}
	return 0;
}