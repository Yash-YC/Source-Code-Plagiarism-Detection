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

typedef long long int llint;
#define low(x) ((((x)^((x)-1))&x))
#define two(x)  ((1)<<(x))
#define PB(x) push_back((x))
#define SORT(x) sort(x.begin(),x.end())
const int dir[][2]={{-1,0},{0,1},{1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
const char dname[]="NWSE";
const int C=40;
const int N=C;
llint com[C+1][C+1];


double dp[C+1];

int main()
{
	llint up=0;
	com[0][0]=1;
	for(int i=1;i<=N;i++)
	{
		com[i][0]=com[i][i]=1;
		for(int j=1;j<i;j++)com[i][j]=com[i-1][j-1]+com[i-1][j],up=max(up,com[i][j]);
		//cerr<<endl;
	}
	debug(up);
	debug(com[40][20]);
	int ca=1,tt;
	for(cin>>tt;tt--;ca++)
	{
		int c,n;
		cin>>c>>n;
		dp[c]=0.0;
		for(int k=c-1;k>=0;k--)
		{
			double sum=0.0;
			double self;
			for(int a=0;a<=n;a++)
			{
				if(a)sum+=1.0*com[c-k][a]*com[k][n-a]/com[c][n]*dp[k+a];
				else self=1.0*com[c-k][a]*com[k][n-a]/com[c][n];
			}
			debug(k);
			debug(self);
			debug(sum);
			dp[k]=(sum+1)/(1.0-self);
			debug(k);
		}
		printf("Case #%d: %.8lf\n",ca,dp[0]);
//		double h=0.0;
//		for(int i=1;i<=c;i++)h+=1.0/i;
//		h*=c;
//		printf("%.8lf\n",h);
		//cout<<"Case #"<<ca<<": "<<dp[0]<<endl;
	}
	return 0;
}
