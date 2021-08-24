#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool grid[20][20][4][3];
int M,N,S[20][20],W[20][20],T[20][20];
//nw,ne,sw,se
void update(int i,int j,int k,int t)
{
  t=(t-T[i][j])%(S[i][j]+W[i][j]);
  bool signal=(t>=S[i][j]);
  // cout<<t<<" "<<signal<<"\n";
  if(signal)
    {
      if(k%2)
	grid[i][j][k-1][1]=true;
      else
	grid[i][j][k+1][1]=true;
    }
  else
    {
      if(k<2)
	grid[i][j][k+2][1]=true;
      else
	grid[i][j][k-2][1]=true;
    }
  if((j!=0)&&(!(k%2)))
    grid[i][j-1][k+1][2]=true;
  if((i!=0)&&(k<2))
    grid[i-1][j][k+2][2]=true;
  if((j!=M-1)&&(k%2))
    grid[i][j+1][k-1][2]=true;
  if((i!=N-1)&&(k>1))
    grid[i+1][j][k-2][2]=true;
}

int main()
{
  int C,i,j,k,x;
  cin>>C;
  for(x=1;x<=C;x++)
    {
      cin>>N>>M;
      for(i=0;i<N;i++)
	for(j=0;j<M;j++)
	  {
	    cin>>S[i][j]>>W[i][j]>>T[i][j];
	    T[i][j]%=(S[i][j]+W[i][j]);
	    T[i][j]-=(S[i][j]+W[i][j]);
	    //   cout<<T[i][j];
	    for(k=0;k<4;k++)
	      grid[i][j][k][0]=grid[i][j][k][1]=grid[i][j][k][2]=false;
	  }
      grid[N-1][0][2][0]=grid[N-1][0][2][1]=grid[N-1][0][2][2]=true;
      int t=0;
      while(!((grid[0][M-1][1][0])||grid[0][M-1][1][1]))
	{
	  for(i=0;i<N;i++)
	    for(j=0;j<M;j++)
	      for(k=0;k<4;k++)
		if(grid[i][j][k][0])
		  update(i,j,k,t);
	  t++;
	  for(i=0;i<N;i++)
	    for(j=0;j<M;j++)
	      for(k=0;k<4;k++)
		{
		  grid[i][j][k][0]|=grid[i][j][k][1];
		  grid[i][j][k][1]|=grid[i][j][k][2];
		  grid[i][j][k][2]|=false;
		}
	}
      cout<<"Case #"<<x<<": "<<t;
      if(x<C)
	cout<<"\n";
    }
}
