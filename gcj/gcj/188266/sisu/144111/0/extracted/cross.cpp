#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};

struct Inter {
	int ok, fail, t;
};

struct Edge {
	Inter i;
	int l;
};

struct Loc {
	vector<Edge> edges;
};

struct S {
	int loc;
	int t;

	bool operator<(const S& s) const {
		return t>s.t;
	}
};
Loc places[1<<16];
int best[1<<16];
bool done[1<<16];

int N,M;
int W,H;

void addEdge(int a, int b, int c, int d, Inter i)
{
	int f=a*W+b, t=c*W+d;
	places[f].edges.push_back((Edge){i, t});
	places[t].edges.push_back((Edge){i, f});
}

int solve()
{
	int dest=W-1;
	int start=(H-1)*W;
	priority_queue<S> q;
	q.push((S){start,0});
	while(!q.empty()) {
		S s = q.top();
		q.pop();

		if (s.loc==dest) return s.t;

		if (done[s.loc]) continue;
		done[s.loc]=1;

		Loc& l=places[s.loc];
		for(unsigned i=0; i<l.edges.size(); ++i) {
			Edge e = l.edges[i];
			int tx = s.t-e.i.t;
			int d=e.i.ok+e.i.fail;
			tx %= d;
			if (tx<0) tx+=e.i.ok+e.i.fail;

			if (tx < e.i.ok) {
				q.push((S){e.l, s.t+1});
			} else {
				int z=s.t+(d-tx)+1;
				if (best[e.l]<0 || z<best[e.l])
					q.push((S){e.l, s.t+(d-tx)+1}), best[e.l]=z;
			}
		}
	}
	return -1;
}

int main()
{
	int c; cin>>c;
	for(int a=0; a<c; ++a) {
		memset(best, -1, sizeof(best));
		memset(done, 0, sizeof(done));
		cin>>N>>M;
		W=M*3-1, H=N*3-1;
		for(int i=0; i<=W*H; ++i) places[i].edges.clear();
		for(int i=0; i<N; ++i) {
			for(int j=0; j<M; ++j) {
				int s,w,t;
				cin>>s>>w>>t;
				Inter we={w,s,t+s};
				Inter ns={s,w,t};
				int a=i*3, b=j*3;
				addEdge(a,b,a,b+1,we);
				addEdge(a,b,a+1,b,ns);
				addEdge(a+1,b,a+1,b+1,we);
				addEdge(a,b+1,a+1,b+1,ns);

				Inter ix={1,0,0};
				if (i<N-1) {
					addEdge(a+1, b, a+2, b, ix);
					addEdge(a+2, b, a+3, b, ix);
					addEdge(a+1, b+1, a+2, b+1, ix);
					addEdge(a+2, b+1, a+3, b+1, ix);
				}
				if (j<M-1) {
					addEdge(a, b+1, a, b+2, ix);
					addEdge(a, b+2, a, b+3, ix);
					addEdge(a+1, b+1, a+1, b+2, ix);
					addEdge(a+1, b+2, a+1, b+3, ix);
				}
			}
		}
		cout<<"Case #"<<a+1<<": "<<solve()<<'\n';
	}
}
