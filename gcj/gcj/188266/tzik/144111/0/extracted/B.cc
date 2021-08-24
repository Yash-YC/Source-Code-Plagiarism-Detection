
#include <iostream>
#include <queue>

using namespace std;

const int NW=0,NE=1,SW=2,SE=3;

struct pos
{
  int j,i,d,t;
};

bool operator<(const pos& a,const pos& b)
{
  return a.t > b.t;
}

void dump(pos& p)
{
  cout << "pos: " << p.j << " " << p.i << " " << p.d << " " << p.t << endl;
}

struct solver
{
  int N,M;
  vector<int> S,W,T;

  int at(int j,int i)
  {
    return j*M+i;
  }

  solver()
  {
    cin >> N >> M;
    S.resize(N*M);
    W.resize(N*M);
    T.resize(N*M);

    for(int j=0;j<N;++j)
      for(int i=0;i<M;++i)
	cin >> S[at(j,i)] >> W[at(j,i)] >> T[at(j,i)];
  }

  int cross_NS(pos& p)
  {
    int idx = at(p.j,p.i);
    int SW = S[idx]+W[idx];
    int k = (((p.t-T[idx])%SW)+SW)%SW;
    if(k < S[idx])
      return 1;
    else
      return 1+SW-k;
  }

  int cross_WE(pos& p)
  {
    int idx = at(p.j,p.i);
    int SW = S[idx]+W[idx];
    int k = (((p.t-T[idx])%SW)+SW)%SW;
    if(k >= S[idx])
      return 1;
    else
      return 1+S[idx]-k;
  }

  int operator()()
  {
    vector<int> vis(N*M,-1);
    priority_queue<pos> q;
    q.push((pos){N-1,0,SW,0});

    while(!q.empty())
    {
      pos c = q.top();
      q.pop();
      //dump(c);

      if(c.j==0 && c.i==M-1 && c.d==NE)
	return c.t;

      if(vis[at(c.j,c.i)]>=0)
	continue;

      //step
      switch(c.d)
      {
      case NW:
	if(c.j>0)
	  q.push((pos){c.j-1,c.i,SW,c.t+2});//to North
	if(c.i>0)
	  q.push((pos){c.j,c.i-1,NE,c.t+2});//to West
	q.push((pos){c.j,c.i,NE,c.t+cross_WE(c)});//to East
	q.push((pos){c.j,c.i,SW,c.t+cross_NS(c)});//to South
	break;
      case NE:
	if(c.j>0)
	  q.push((pos){c.j-1,c.i,SE,c.t+2});//to North
	q.push((pos){c.j,c.i,NW,c.t+cross_WE(c)});//to West
	if(c.i<M-1)
	  q.push((pos){c.j,c.i+1,NW,c.t+2});//to East
	q.push((pos){c.j,c.i,SE,c.t+cross_NS(c)});//to South
	break;
      case SW:
	q.push((pos){c.j,c.i,NW,c.t+cross_NS(c)});//to North
	if(c.i>0)
	  q.push((pos){c.j,c.i-1,SE,c.t+2});//to West
	q.push((pos){c.j,c.i,SE,c.t+cross_WE(c)});//to East
	if(c.j<N-1)
	  q.push((pos){c.j+1,c.i,NW,c.t+2});//to South
	break;
      case SE:
	q.push((pos){c.j,c.i,NE,c.t+cross_NS(c)});//to North
	q.push((pos){c.j,c.i,SW,c.t+cross_WE(c)});//to West
	if(c.i<M-1)
	  q.push((pos){c.j,c.i+1,SW,c.t+2});//to East
	if(c.j<N-1)
	  q.push((pos){c.j+1,c.i,NE,c.t+2});//to South
	break;
      }
    }
  }

};


int main(int,char**)
{

  int C = 0;
  cin >> C;
  for(int c=0;c<C;++c)
    cout << "Case #" << (c+1) << ": " << solver()() << endl;

  return 0;
}
