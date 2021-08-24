#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <map>
#include <sstream>
#include <queue>
 
#include <cmath>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
 
#define forn(i, n) for(int i=0;i<int(n);i++)
#define FOR(i, a, b) for(int i=(a);i<int(b);i++)
#define RFOR(i, b, a) for(int i=(b);i>int(a);i--)
#define foreach(it, c)  for(typeof((c).begin()) it = (c).begin();it!=(c).end();++it)
#define ALL(x)   (x).begin(),(x).end()
#define SIZE(x)   (int)(x).size()
#define SORT(x) sort(ALL(x))
using namespace std;
#define VI vector<int>
#define VS vector<string>
#define PB push_back
#define ISS istringstream
#define OSS ostringstream
#define MP make_pair
typedef long long ll;
// NUNCA DEFINIR int max....
struct intersection
{
       int S, W, T;
};
int rows, cols;
intersection inter[21][21];
int best[44][44];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
bool adentro(int r, int c){ if( r < 0 || c < 0 || r >= 2*rows || c >= 2*cols ) return false; return true;}

int calc(int horizontal, int r, int c, int momento)
{
//        cout << inter[r][c].S << "  " << inter[r][c].W << " ........ " << inter[r][c].T << endl;
       int f = momento;
//        cout << momento << "..., , ,,  " << f << endl;
       momento = momento - inter[r][c].T;
       
       momento  %= (inter[r][c].S+inter[r][c].W);
       momento += (inter[r][c].S+inter[r][c].W);
       momento  %= (inter[r][c].S+inter[r][c].W);
       
       if( horizontal )
       {
	      if( momento >= inter[r][c].S )
		     return f+1;
	      return f+(inter[r][c].S)-momento + 1;
       }else
       {
	      if( momento < inter[r][c].S ) return f+1;
	      return f+(inter[r][c].S+inter[r][c].W)-momento + 1;
       }
       
       
       return 0;
       
}






int dijkstra()
{
       set<pair<int,pair<int,int> > > S;
       for( int i = 0 ; i < 44; i ++ ) for( int j = 0 ; j < 44; j ++ ) best[i][j] = 1e9;
       S.insert(MP(0, MP(2*rows-1, 0)));
       best[2*rows-1][0] = 0;
       pair<int,int> FIN = MP(0, 2*cols-1);
       while(S.size())
       {
	      pair<int,pair<int,int> > p = *(S.begin()); S.erase(S.begin());
	      
	      int r = p.second.first, c = p.second.second;
	      int dist = p.first;
	      
	      
	      if( dist > best[r][c] ) continue;
	      if( MP(r,c) == FIN ) return dist;
// 	      cout << r << " " << c << " " << " <--- " << dist << endl;
	      for(int k = 0; k< 4; k++)
	      {
		     int rr = dr[k] + r , cc = dc[k]+c;
		     if( !adentro(rr,cc) ) continue;
		     if( rr/2 != r/2 || cc/2 != c/2 )
		     {
			    
			    if( best[rr][cc] > best[r][c] + 2 )
			    {
				   best[rr][cc] = best[r][c]+2;
				   S.insert(MP(best[rr][cc], MP(rr,cc)) );
			    }
		     }else
		     {
			    int next = 0;
			    if( k & 1 )
				   next = calc(1/*horizontal*/, r/2,c/2,best[r][c]);
			    else next = calc(0 /*vertical*/, r/2, c/2, best[r][c]);
// 			    cout << r/2 << ".."  << c/2 << " ... "  << next << endl;
			    if( best[rr][cc] > next )
			    {
				   best[rr][cc] = next;
				   S.insert(MP(best[rr][cc], MP(rr,cc)) );
			    }
		     }
		     
	      }
       }return 0;
}



int main()
{
       int i,j , k;
       int casos;
       cin >> casos;
       for( int h = 0 ; h < casos; h ++ )
       {
	      cin >> rows >> cols;
	      for( i = 0 ; i < rows; i ++ ) for( j = 0 ; j < cols; j ++ )
		     cin >> inter[i][j].S >> inter[i][j].W >> inter[i][j].T;
	      
	      cout << "Case #" << (h+1) << ": " << dijkstra() << endl;
	      
	      
	      
	      
	      
// 	      break;
       }return 0;
}
