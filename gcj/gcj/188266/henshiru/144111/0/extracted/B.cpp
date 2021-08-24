#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <boost/foreach.hpp>
#include <boost/tokenizer.hpp>
#include <boost/lexical_cast.hpp>
#include <assert.h>
#include <climits>

using namespace std;
using namespace boost;

struct Light{
  int S,W,T;
};

enum Corner{
  SW=0,
  NW=1,
  NE=2,
  SE=3
};

struct Point{
  int i,j;
  Corner c;
  Point(int i_, int j_,Corner c_):i(i_),j(j_),c(c_){}
  bool operator==(const Point& rhs)const{
    return i==rhs.i && j==rhs.j && c==rhs.c;
  }
  bool operator<(const Point& rhs)const{
    return i<rhs.i || j<rhs.j || c < rhs.c;
  }
};

int t_arrive(int t, const vector<vector<Light> >& ls, const Point& src, Corner dst){
  const Light& l = ls[src.i][src.j];
  const int cycle = l.S + l.W;
  const Corner cmx = std::max(src.c, dst);
  const Corner cmn = std::min(src.c, dst);
  int t_base(t-l.T);
  while(t_base < 0){
    t_base += cycle;
  }
  t_base%=cycle;
  if((cmx==SE && cmn==NE) || (cmx==NW && cmn==SW)){//north-south
    if(t_base < l.S){
      return t + 1;
    }
    else{
      return t + (cycle-t_base) + 1;
    }
  }
  else if((cmx==NE && cmn==NW) || (cmx==SE && cmn==SW)){//east-west
    if(l.S <= t_base){
      return t + 1;
    }
    else{
      return t + (l.S - t_base) + 1;
    }
  }
  else{
    return INT_MAX;
  }
}

void print(const vector<vector<vector<int> > >& ts){
  for(int i=0;i!=ts.size();++i){
    for(int j=0;j!=ts[i].size();++j){
      cout << "#";
      for(int k=0;k!=ts[i][j].size();++k){
	cout << ts[i][j][k] << ",";
      }
      cout << "#";
    }
    cout << endl;
  }
}

int solve(const vector<vector<Light> >& ls){
  const int N = ls.size();
  const int M = ls[0].size();

  vector<vector<vector<int> > > ts(N);
  for(int i=0;i!=N;++i){
    ts[i].resize(M);
    for(int j=0;j!=M;++j){
      ts[i][j].resize(4, INT_MAX);
    }
  }
  vector<Point> s;
  s.push_back(Point(N-1, 0, SW));
  ts[N-1][0][SW]=0;
  while(!s.empty()){
    vector<Point> ns;
    for(int i=0;i!=s.size();++i){
      const Point& pt = s[i];
      const int t = ts[pt.i][pt.j][pt.c];
      for(int c=0;c!=4;++c){
	if(c != pt.c){
	  const int ta = t_arrive(t, ls, pt, (Corner)c);
	  if(ta < ts[pt.i][pt.j][c]){
	    ts[pt.i][pt.j][c] = ta;
	    ns.push_back(Point(pt.i, pt.j, (Corner)c));
	  }
	}
      }
      int di,dj;
      Corner iic,jjc;
      switch(pt.c){
      case SW:
	di = 1;
	dj = -1;
	iic = NW;
	jjc = SE;
	break;
      case NW:
	di = -1;
	dj = -1;
	iic = SW;
	jjc = NE;
	break;
      case NE:
	di = -1;
	dj = 1;
	iic = SE;
	jjc = NW;
	break;
      case SE:
	di = 1;
	dj = 1;
	iic = NE;
	jjc = SW;
	break;
      }
      const int ii = pt.i + di;
      const int jj = pt.j + dj;
      if(0<=ii && ii<N && t+2 < ts[ii][pt.j][iic]){
	ts[ii][pt.j][iic] = t+2;
	ns.push_back(Point(ii,pt.j,iic));
      }
      if(0<=jj && jj<M && t+2 < ts[pt.i][jj][jjc]){
	ts[pt.i][jj][jjc] = t+2;
	ns.push_back(Point(pt.i,jj,jjc));
      }
    }
    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());
    s = ns;
  }
  return ts[0][M-1][NE];
}

int main(int argc, char* argv[]){
  int C;
  cin >> C;
  for(int i=0;i!=C;++i){
    int N, M;
    cin >> N >> M;
    vector<vector<Light> > ls(N);
    for(int y=0;y!=N;++y){
      ls[y].resize(M);
      for(int x=0;x!=M;++x){
	Light l;
	cin >> l.S >> l.W >> l.T;
	ls[y][x]=l;
      }
    }
    cout << "Case #" << i+1 << ": " << solve(ls) << endl;
  }
  
  return 0;
}
