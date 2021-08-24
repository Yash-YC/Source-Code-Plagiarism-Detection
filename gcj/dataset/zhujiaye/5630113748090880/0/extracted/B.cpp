#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
//#define debug
using namespace std;

int Q,N;
vector<vector<int> >num;

bool smaller(vector<int>& a,vector<int> &b){
	int n=a.size();
	for (int i=0;i<n;i++)
		if (a[i]>=b[i])
			return false;
	return true;
}
bool checkRow(vector<vector<int> > &res,int u,int n){
	if (u==-1)
		return true;
	for (int i=0;i<n;i++)
		if (!(res[n][i]==-1 || num[u][i]==res[n][i]))
			return false;
	return true;
}
bool checkCol(vector<vector<int> > &res,int u,int n){
	if (u==-1)
		return true;
	for (int i=0;i<n;i++)
		if (!(res[i][n]==-1 || num[u][i]==res[i][n]))
			return false;
	return true;
}
void fillRow(vector<vector<int> > &res,int u,int n){
	if (u==-1)
		return;
	for (int i=0;i<N;i++)
		res[n][i]=num[u][i];
}
void fillCol(vector<vector<int> > &res,int u,int n){
	if (u==-1)
		return;
	for (int i=0;i<N;i++)
		res[i][n]=num[u][i];
}
bool dfs(int l,int N,vector<pair<int,int> > &level,vector<vector<int> > &res){
	if (l==N)
		return true;
	int u=level[l].first,v=level[l].second;
	if (checkRow(res,u,l) && checkCol(res,v,l)){
		fillRow(res,u,l);
		fillCol(res,v,l);
		if (dfs(l+1,N,level,res))
			return true;
	}
	if (checkRow(res,v,l) && checkCol(res,u,l)){
		fillRow(res,v,l);
		fillCol(res,u,l);
		if (dfs(l+1,N,level,res))
			return true;
	}
	return false;
}
int main(){
	freopen("i.txt","r",stdin);
	cin>>Q;
	for (int testcase=1;Q--;testcase++){
		cout<<"Case #"<<testcase<<":";
		cin>>N;
		num.clear();
		for (int i=0;i<2*N-1;i++){
			vector<int>tmp;
			for (int j=0;j<N;j++){
				int x;
				cin>>x;
				tmp.push_back(x);
			}
			num.push_back(tmp);
		}
		vector<bool>vis(2*N-1,false);
		vector<pair<int,int> > level;
		for (int i=0;i<N;i++){
			int x=-1;
			for (int j=0;j<2*N-1;j++){
				if (vis[j]) continue;
				if (x==-1 || x>num[j][i])
					x=num[j][i];
			}
			vector<int>tmp;
			for (int j=0;j<2*N-1;j++){
				if (vis[j]) continue;
				if (x==num[j][i]){
					tmp.push_back(j);
					vis[j]=true;
				}
			}
			if (tmp.size()==1)
				level.push_back(make_pair(tmp[0],-1));
			else
				level.push_back(make_pair(tmp[0],tmp[1]));
		}
#ifdef debug
		for (int i=0;i<N;i++)
			cout<<level[i].first<<" "<<level[i].second<<endl;
#endif
		vector<vector<int> > res(N,vector<int>(N,-1));
		dfs(0,N,level,res);
#ifdef debug
		for (int i=0;i<N;i++,cout<<endl)
			for (int j=0;j<N;j++)
			       cout<<res[i][j]<<" ";	
#endif
		for (int i=0;i<N;i++){
			if (level[i].first==-1 || level[i].second==-1){
				int u=level[i].first==-1?level[i].second:level[i].first;
				bool row=false;
				for (int j=0;j<N;j++){
					if (num[u][j]!=res[i][j]){
						row=true;
						break;
					}
				}
				if (!row){
					for (int j=0;j<N;j++)
						cout<<" "<<res[j][i];
				}
				else{
					for (int j=0;j<N;j++)
						cout<<" "<<res[i][j];
				}
				break;	
			}
		}
		cout<<endl;
	}
	return 0;
}
