#include<iostream>
#include<vector>
#include<set>
#define INF 100000000
using namespace std;

typedef pair<int,int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int map[20][20][3],n,m,t;

void update(set<iii> &q, vvi &d, ii pos, int dist){
	if(pos.first>(n-1)*3+1) return;
	if(pos.second>(m-1)*3+1) return;
	if(d[pos.first][pos.second] > dist){
		if(d[pos.first][pos.second]<INF)
			q.erase(q.find(iii(d[pos.first][pos.second], pos)));
		d[pos.first][pos.second]=dist;
		q.insert(iii(dist, pos));
	}
}

int main(){
	cin >> t;
	for(int i = 0; i < t; ++i){
		cin >> n >> m;
		for(int j = 0; j < n; ++j)
			for(int k = 0; k < m; ++k){
				cin >> map[j][k][0] >> map[j][k][1] >> map[j][k][2];
				if(map[j][k][2]<0)
					map[j][k][2]+=(map[j][k][0]+map[j][k][1])*((-map[j][k][2])/(map[j][k][0]+map[j][k][1])+1);
				map[j][k][2]%=(map[j][k][0]+map[j][k][1]);
			}
		set<iii> q;
		vvi d(3*n+2, vi(3*m+2, INF));
		d[0][0]=0;
		q.insert(iii(0,ii(0,0)));
		while(!q.empty()){
			iii top = *q.begin();
			q.erase(q.begin());
			ii pos = top.second;
			int dist = top.first;
//			cout << pos.first << " " << pos.second << " " << dist << endl;
			if(pos.first%3==0&&pos.first/3<n&&pos.second%3!=2){
				int x=pos.first/3, y=pos.second/3;
				int t=(dist+map[x][y][0]+map[x][y][1]-map[x][y][2])%(map[x][y][0]+map[x][y][1]);
				if(t>=map[x][y][0])
					t=0;
				t+=map[x][y][2];
				t+=(dist/(map[x][y][0]+map[x][y][1]))*(map[x][y][0]+map[x][y][1]);
				if(t<dist)t+=(map[x][y][0]+map[x][y][1]);
				if(t<dist)t+=(map[x][y][0]+map[x][y][1]);
				if(t-(map[x][y][0]+map[x][y][1])>=dist)t-=(map[x][y][0]+map[x][y][1]);
				if(t-(map[x][y][0]+map[x][y][1])>=dist)t-=(map[x][y][0]+map[x][y][1]);
//				cout << "1 " << t << endl;
				update(q, d, ii(pos.first+1, pos.second), t+1);
			}
			if(pos.second%3==0&&pos.second/3<m&&pos.first%3!=2){
				int x=pos.first/3, y=pos.second/3;
				int t=(dist+map[x][y][0]+map[x][y][1]-map[x][y][2])%(map[x][y][0]+map[x][y][1]);
				if(t<map[x][y][0])
					t=map[x][y][0];
				t+=map[x][y][2];
				t+=(dist/(map[x][y][0]+map[x][y][1]))*(map[x][y][0]+map[x][y][1]);
				if(t<dist)t+=(map[x][y][0]+map[x][y][1]);
				if(t<dist)t+=(map[x][y][0]+map[x][y][1]);
				if(t-(map[x][y][0]+map[x][y][1])>=dist)t-=(map[x][y][0]+map[x][y][1]);
				if(t-(map[x][y][0]+map[x][y][1])>=dist)t-=(map[x][y][0]+map[x][y][1]);
				update(q, d, ii(pos.first, pos.second+1), t+1);
//				cout << "2 " << t << endl;
			}
			if(pos.first%3==1&&pos.second%3!=2){
				int x=pos.first/3, y=pos.second/3;
				int t=(dist+map[x][y][0]+map[x][y][1]-map[x][y][2])%(map[x][y][0]+map[x][y][1]);
				if(t>=map[x][y][0])
					t=0;
				t+=map[x][y][2];
				t+=(dist/(map[x][y][0]+map[x][y][1]))*(map[x][y][0]+map[x][y][1]);
				if(t<dist)t+=(map[x][y][0]+map[x][y][1]);
				if(t<dist)t+=(map[x][y][0]+map[x][y][1]);
				if(t-(map[x][y][0]+map[x][y][1])>=dist)t-=(map[x][y][0]+map[x][y][1]);
				if(t-(map[x][y][0]+map[x][y][1])>=dist)t-=(map[x][y][0]+map[x][y][1]);
				update(q, d, ii(pos.first-1, pos.second), t+1);
//				cout << "3 " << t << endl;
			}
			if(pos.second%3==1&&pos.first%3!=2){
				int x=pos.first/3, y=pos.second/3;
				int t=(dist+map[x][y][0]+map[x][y][1]-map[x][y][2])%(map[x][y][0]+map[x][y][1]);
				if(t<map[x][y][0])
					t=map[x][y][0];
				t+=map[x][y][2];
				t+=(dist/(map[x][y][0]+map[x][y][1]))*(map[x][y][0]+map[x][y][1]);
				if(t<dist)t+=(map[x][y][0]+map[x][y][1]);
				if(t<dist)t+=(map[x][y][0]+map[x][y][1]);
				if(t-(map[x][y][0]+map[x][y][1])>=dist)t-=(map[x][y][0]+map[x][y][1]);
				if(t-(map[x][y][0]+map[x][y][1])>=dist)t-=(map[x][y][0]+map[x][y][1]);
				update(q, d, ii(pos.first, pos.second-1), t+1);
//				cout << "4 " << t << endl;
			}
			if(pos.first%3!=1&&pos.first>0&&pos.second%3!=2)
				update(q, d, ii(pos.first-1, pos.second), dist+1);
			if(pos.first%3!=0&&pos.first<3*n+1&&pos.second%3!=2)
				update(q, d, ii(pos.first+1, pos.second), dist+1);
			if(pos.second%3!=1&&pos.second>0&&pos.first%3!=2)
				update(q, d, ii(pos.first, pos.second-1), dist+1);
			if(pos.second%3!=0&&pos.second<3*m+1&&pos.first%3!=2)
				update(q, d, ii(pos.first, pos.second+1), dist+1);
		}
		cout << "Case #" << i+1 << ": " << d[(n-1)*3+1][(m-1)*3+1] << endl;
	}
}
