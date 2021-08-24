#include<iostream>
#include<queue>
using namespace std;

struct cross
{
	int s, w, t;
};

struct node
{
	int id;
	long long dis;
};
bool operator<(const node& a, const node& b)
{
	return a.dis>b.dis;
}

bool update(long long& a, long long b)
{
	if(b<a){a=b;return 1;}

	return 0;
}
int main()
{
	freopen("b2in.txt","r",stdin);
	freopen("b2out.txt","w",stdout);

	int C;
	cin>>C;

	for(int cc=1;cc<=C;cc++)
	{
		int N,M;
		cin>>N>>M;

		cross mat[24][24];
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<M;j++)
			{
				cin >> mat[i][j].s >> mat[i][j].w >> mat[i][j].t;
				mat[i][j].t %= mat[i][j].s+mat[i][j].w;

				mat[i][j].t -= mat[i][j].s+mat[i][j].w;
			}
		}

		//dijkstra
		priority_queue<node> pq;
		node tmp;
		tmp.id=2*M*(2*N-1);
		tmp.dis=0;
		long long dis[1700];
		memset(dis, 0x7f, sizeof(dis));
		dis[2*M*(2*N-1)]=0;

		pq.push(tmp);
		while(!pq.empty())
		{
			node now = pq.top();
			pq.pop();
			if(now.dis > dis[now.id])continue;

			//cout<<now.id<<" "<<now.dis<<endl;

			
		//4 directions
			//east
			if(now.id%(M*2) < 2*M-1)
			{
				node next;
				int id = now.id;
				int t = mat[id/(M*2)/2][id%(M*2)/2].t;
				int s = mat[id/(M*2)/2][id%(M*2)/2].s;
				int w = mat[id/(M*2)/2][id%(M*2)/2].w;

				next.id = id+1;
				//cout<<next.id<<endl;
				if(id%2==0)
				{
					if( (now.dis - t)%(s+w)>=s)
					{
						next.dis = now.dis + 1;
					}
					else//wait
					{
						next.dis = t + (now.dis-t)/(s+w)*(s+w) + s+1;
					}
				}
				else
				{
					next.dis = now.dis + 2;
				}

				if(update(dis[next.id], next.dis))
					pq.push(next);
			}

			//south
			if(now.id/(M*2) < 2*N-1)
			{
				node next;
				int id = now.id;
				int t = mat[id/(M*2)/2][id%(M*2)/2].t;
				int s = mat[id/(M*2)/2][id%(M*2)/2].s;
				int w = mat[id/(M*2)/2][id%(M*2)/2].w;

				next.id = id+M+M;
				if(id/(2*M)%2==0)
				{
					if( (now.dis - t)%(s+w)<s)
					{
						next.dis = now.dis + 1;
					}
					else//wait
					{
						next.dis = t + (now.dis-t)/(s+w)*(s+w) + s+w+1;
					}
				}
				else
				{
					next.dis = now.dis + 2;
				}

				if(update(dis[next.id], next.dis))
					pq.push(next);
			}

			//west
			if(now.id%(M*2) > 0)
			{
				node next;
				int id = now.id;
				int t = mat[id/(M*2)/2][id%(M*2)/2].t;
				int s = mat[id/(M*2)/2][id%(M*2)/2].s;
				int w = mat[id/(M*2)/2][id%(M*2)/2].w;

				next.id = id-1;
				if(id%2==1)
				{
					if( (now.dis - t)%(s+w)>=s)
					{
						next.dis = now.dis + 1;
					}
					else//wait
					{
						next.dis = t + (now.dis-t)/(s+w)*(s+w) + s+1;
					}
				}
				else
				{
					next.dis = now.dis + 2;
				}

				if(update(dis[next.id], next.dis))
					pq.push(next);
			}

			//north
			if(now.id/(M*2) > 0)
			{
				node next;
				int id = now.id;
				int t = mat[id/(M*2)/2][id%(M*2)/2].t;
				int s = mat[id/(M*2)/2][id%(M*2)/2].s;
				int w = mat[id/(M*2)/2][id%(M*2)/2].w;

				next.id = id-M-M;
				if(id/(2*M)%2==1)
				{
					if( (now.dis - t)%(s+w)<s)
					{
						next.dis = now.dis + 1;
					}
					else//wait
					{
						next.dis = t + (now.dis-t)/(s+w)*(s+w) + s+w+1;
					}
				}
				else
				{
					next.dis = now.dis + 2;
				}

				if(update(dis[next.id], next.dis))
					pq.push(next);
			}
		}

		cout<<"Case #" << cc <<": "<<dis[2*M-1]<<endl;
	}
}