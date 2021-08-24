#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <sstream>
#include <map>
#include <cstring>
#include <complex>
#include <numeric>
#include <functional>
#include <stack>
//#define NDEBUG
#include <assert.h>
using namespace std;
#ifndef NDEBUG
    #define debug(x) cerr<<#x<<"=\""<<x<<"\""<<" at line#"<<__LINE__<<endl;
    #define hline() cerr<<"-----------------------------------------"<<endl;
#else
    #define debug(x)
    #define hline()
#endif
//************************************************
template<typename T>
class vector1D : public vector<T>
{
	public:
	vector1D<T>():vector<T>(){};
	vector1D<T>(size_t a) : vector<T>(a){};
	vector1D<T>(size_t a,const T& v) : vector<T>(a,v){};
	void resize(size_t a) {vector1D<T> tmp(a);this->swap(tmp);};
	void resize(size_t a,const T& v){vector1D tmp(a,v);this->swap(tmp);};
	void print(const string& head="")const 
	{
		if(head!="")cerr<<head<<endl;
		cerr<<"size= "<<this->size()<<endl;
		for(int i=0;i<this->size();i++)cerr<<(*this)[i]<<" ";
		cerr<<endl;
	}
};

template<typename T>
class vector2D : public vector<vector<T> >
{
	public:
		vector2D<T>():vector<vector<T> >(){};
		vector2D<T>(size_t a,size_t b,const T& v):vector<vector<T> >(a,vector<T>(b,v)){};
		vector2D<T>(size_t a,size_t b):vector<vector<T> >(a,vector<T>(b)){};
		void resize(size_t a,size_t b){vector2D<T> tmp(a,b); this->swap(tmp);};
		void resize(size_t a,size_t b,const T& v){vector2D<T> tmp(a,b,v); this->swap(tmp);};
		void print(const string& head="")const 
		{
			if(head!="")cerr<<head<<endl;

			const vector2D<T>& tmp=*this;
			cerr<<tmp.size()<<" X "<<tmp[0].size()<<endl;
			for(int i=0;i<tmp.size();i++,cerr<<endl)
			for(int j=0;j<tmp[i].size();j++)cerr<<tmp[i][j]<<" ";
		};
};

template<typename T>
class vector3D : public vector<vector2D<T> > 
{
	public:
		vector3D<T>():vector<vector<vector<T> > >(){};
		vector3D<T>(size_t a,size_t b,size_t c):vector<vector2D<T> >(a,vector2D<T>(b,c)){};
		vector3D<T>(size_t a,size_t b,size_t c,const T& v):vector<vector2D<T> >(a,vector2D<T>(b,c,v)){};
		void resize(size_t a,size_t b,size_t c){vector3D<T> tmp(a,b,c); this->swap(tmp);};
		void resize(size_t a,size_t b,size_t c,const T& v){vector3D<T> tmp(a,b,c,v); this->swap(tmp);};
		void print(const string& head="")const 
		{
			if(head!="")cerr<<head<<endl;

			const vector3D<T>& tmp=*this;
			cerr<<tmp.size()<<" X "<<tmp[0].size()<<" X "<<tmp[0][0].size()<<endl;
			for(int i=0;i<tmp.size();i++)
			{
				hline();
				for(int x=0;x<tmp[i].size();x++,cerr<<endl)
				for(int y=0;y<tmp[i][x].size();y++)cerr<<tmp[i][x][y]<<" ";
			}
		};
};

template<typename T>
class vector4D : public vector<vector3D<T> > 
{
	public:
		vector4D<T>():vector<vector3D<T> >(){};
		vector4D<T>(size_t a,size_t b,size_t c,size_t d):vector<vector3D<T> >(a,vector3D<T>(b,c,d)){};
		vector4D<T>(size_t a,size_t b,size_t c,size_t d,const T& v):vector<vector3D<T> >(a,vector3D<T>(b,c,d,v)){};
		void resize(size_t a,size_t b,size_t c,size_t d){vector4D<T> tmp(a,b,c,d); this->swap(tmp);};
		void resize(size_t a,size_t b,size_t c,size_t d,const T& v){vector3D<T> tmp(a,b,c,d,v); this->swap(tmp);};
		void print(const string& head) const 
		{
			if(head!="")cerr<<head<<endl;
			hline();
			const vector4D<T>& tmp=*this;
			cerr<<tmp.size()<<" X "<<tmp[0].size()<<" X "<<tmp[0][0].size()<<" X "<<tmp[0][0][0].size()<<endl;
			for(int i=0;i<tmp.size();i++)
			for(int j=0;j<tmp[i].size();j++)
			{
				hline();
				for(int x=0;x<tmp[i][j].size();x++,cerr<<endl)
				for(int y=0;y<tmp[i][j][x].size();y++)cerr<<tmp[i][j][x][y]<<" ";
			}
		};
};

//************************************************
template<class T>
vector<T> parse(const string& ss,const char* cut=" ")
{
	vector<T> re;
	for(int j=0;j<ss.size();j++)
	{
		string s;
		while(j<ss.size()&&NULL==strchr(cut,ss[j]))
			s+=ss[j++];
		if(!s.empty())
		{
			T tmp;
			istringstream is(s);
			is>>tmp;
			re.push_back(tmp);
		}
	}
	return re;
}

typedef long long int llint;
#define low(x) ((((x)^((x)-1))&x))
#define two(x)  ((1)<<(x))
#define PB(x) push_back((x))
#define SORT(x) sort(x.begin(),x.end())
const int dir[][2]={{-1,0},{0,1},{1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
const char dname[]="NWSE";
const int M=1000000;
bool happy[11][M];
int get_sum2(int n,int b)
{
	int res=0;
	while(n)
	{
		res+=(n%b)*(n%b);
		n/=b;
	}
	return res;
}
vector<int> edge[M];
void BFS(bool happy[M],int b)
{
	happy[1]=true;
	for(int i=0;i<M;i++)edge[i].clear();
	for(int i=2;i<M;i++)
	{
		int a=get_sum2(i,b);
		edge[a].push_back(i);
	}
	debug("BFS");
	queue<int> qq;
	qq.push(1);
	debug(edge[1].size());
	while(qq.size())
	{
		int v=qq.front();qq.pop();
		for(int i=0;i<edge[v].size();i++)
		{
			int x=edge[v][i];
			if(happy[x])continue;
			qq.push(x);
			happy[x]=true;
			//debug(x);
		}
	}
	debug("BFS ended");
}
bool is_happy(int n,int b)
{
	while(n>=M)n=get_sum2(n,b);
	return happy[b][n];
}
int ans[1<<10]=
{
0,
2,
3,
3,
2,
2,
3,
3,
5,
5,
23,
23,
5,
5,
23,
23,
6,
6,
79,
79,
6,
6,
79,
79,
49,
49,
79,
79,
49,
49,
79,
79,
7,
7,
143,
143,
7,
7,
143,
143,
7,
7,
143,
143,
7,
7,
143,
143,
49,
49,
2207,
2207,
49,
49,
2207,
2207,
49,
49,
2207,
2207,
49,
49,
2207,
2207,
8,
8,
27,
27,
8,
8,
27,
27,
27,
27,
27,
27,
27,
27,
27,
27,
216,
216,
3879,
3879,
216,
216,
3879,
3879,
1975,
1975,
3879,
3879,
1975,
1975,
3879,
3879,
1001,
1001,
5719,
5719,
1001,
1001,
5719,
5719,
1001,
1001,
5719,
5719,
1001,
1001,
5719,
5719,
47089,
47089,
47089,
47089,
47089,
47089,
47089,
47089,
48769,
48769,
58775,
58775,
48769,
48769,
58775,
58775,
3,
3,
3,
3,
3,
3,
3,
3,
27,
27,
27,
27,
27,
27,
27,
27,
415,
415,
707,
707,
415,
415,
707,
707,
415,
415,
1695,
1695,
415,
415,
1695,
1695,
125,
125,
143,
143,
125,
125,
143,
143,
125,
125,
143,
143,
125,
125,
143,
143,
2753,
2753,
37131,
37131,
2753,
2753,
37131,
37131,
37131,
37131,
37131,
37131,
37131,
37131,
37131,
37131,
27,
27,
27,
27,
27,
27,
27,
27,
27,
27,
27,
27,
27,
27,
27,
27,
4977,
4977,
10089,
10089,
4977,
4977,
10089,
10089,
4977,
4977,
23117,
23117,
4977,
4977,
23117,
23117,
6393,
6393,
35785,
35785,
6393,
6393,
35785,
35785,
6393,
6393,
128821,
128821,
6393,
6393,
128821,
128821,
569669,
569669,
569669,
569669,
569669,
569669,
569669,
569669,
569669,
569669,
569669,
569669,
569669,
569669,
569669,
569669,
7,
7,
13,
13,
7,
7,
13,
13,
7,
7,
23,
23,
7,
7,
23,
23,
44,
44,
79,
79,
44,
44,
79,
79,
49,
49,
79,
79,
49,
49,
79,
79,
7,
7,
167,
167,
7,
7,
167,
167,
7,
7,
7895,
7895,
7,
7,
7895,
7895,
49,
49,
6307,
6307,
49,
49,
6307,
6307,
49,
49,
7895,
7895,
49,
49,
7895,
7895,
97,
97,
219,
219,
97,
97,
219,
219,
219,
219,
219,
219,
219,
219,
219,
219,
608,
608,
3879,
3879,
608,
608,
3879,
3879,
3879,
3879,
3879,
3879,
3879,
3879,
3879,
3879,
34527,
34527,
48041,
48041,
34527,
34527,
48041,
48041,
34527,
34527,
120407,
120407,
34527,
34527,
120407,
120407,
245035,
245035,
697563,
697563,
245035,
245035,
697563,
697563,
245035,
245035,
2688153,
2688153,
245035,
245035,
2688153,
2688153,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
1033,
1033,
6073,
6073,
1033,
1033,
6073,
6073,
4577,
4577,
6073,
6073,
4577,
4577,
6073,
6073,
1337,
1337,
1337,
1337,
1337,
1337,
1337,
1337,
29913,
29913,
120149,
120149,
29913,
29913,
120149,
120149,
71735,
71735,
613479,
613479,
71735,
71735,
613479,
613479,
218301,
218301,
711725,
711725,
218301,
218301,
711725,
711725,
1177,
1177,
1177,
1177,
1177,
1177,
1177,
1177,
1177,
1177,
1177,
1177,
1177,
1177,
1177,
1177,
9867,
9867,
28099,
28099,
9867,
9867,
28099,
28099,
28099,
28099,
28099,
28099,
28099,
28099,
28099,
28099,
48041,
48041,
48041,
48041,
48041,
48041,
48041,
48041,
246297,
246297,
346719,
346719,
246297,
246297,
346719,
346719,
2662657,
2662657,
4817803,
4817803,
2662657,
2662657,
4817803,
4817803,
11814485,
11814485,
11814485,
11814485,
11814485,
11814485,
11814485,
11814485
};
int main()
{
/*	for(int b=2;b<=10;b++)BFS(happy[b],b);
	for(int mk=1;mk<two(9);mk++)
	{
		vector<int> base;
		for(int i=2;i<=10;i++)
			if(mk&two(i-2))base.push_back(i);
		int ans=1;
		for(;;)
		{
			ans++;
			int cnt=0;
			for(int i=0;i<base.size();i++)
			{
				if(is_happy(ans,base[i]))cnt++;
				else break;
			}
			if(cnt==base.size())break;
		}
		::ans[mk]=ans;
		debug(mk);
		cout<<ans<<","<<endl;
	}
	return 0;
	debug("pre ended");*/
	int ca=1,tt;
	char buf[1000];
	scanf("%d",&tt);
	while(getchar()!='\n');
	for(;tt--;ca++)
	{
		gets(buf);
		vector<int> base=parse<int>(string(buf));
		debug(base.size());
		for(int i=0;i<base.size();i++)cerr<<base[i]<<" ";cerr<<endl;
		int ans=1;
		int mk=0;
		for(int i=0;i<base.size();i++)mk^=two(base[i]-2);

		debug(mk);
		ans=::ans[mk];

		cout<<"Case #"<<ca<<": "<<ans<<endl;
	}
	return 0;
}
