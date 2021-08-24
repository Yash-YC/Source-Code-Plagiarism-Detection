#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class multibasehappiness
{
	private:
		const int BN,CCNST;
		vector<vector<bool> > pct;
		string ins;
		inline int digitsqs(int x,int b)
		{
			int sol=0,t;
			while(x>0)
			{
				t=x%b;
				x/=b;
				sol+=t*t;
			}
			return sol;
		}
	public:
		multibasehappiness():BN(9),CCNST(1000000) {}
		void precompute()
		{
			pct.resize(BN,vector<bool>(CCNST,false));
			for(int f=0;f<BN;++f)
			{
				vector<bool> done(CCNST,false);
				vector<int> stk;
				done.at(1)=true;
				pct.at(f).at(1)=true;
				for(int g=2;g<CCNST;++g)
				{
					if(done.at(g)) continue;
					int cx=g;
					while(true)
					{
						if(done.at(cx))
						{
							while(!(stk.empty()))
							{
								done.at(stk.back())=true;
								pct.at(f).at(stk.back())=pct.at(f).at(cx);
								stk.pop_back();
							}
							break;
						}
						else
						{
							stk.push_back(cx);
							done.at(cx)=true;
							cx=digitsqs(cx,f+2);
						}
					}
				}
			}
		}
		void input()
		{
			getline(cin,ins);
		}
		int solve()
		{
			for(int f=2;f<CCNST;++f)
			{
				bool sol=true;
				for(uint g=0;g<ins.size();g+=2)
				{
					if(ins.at(g)=='1')
					{
						sol&=pct.at(BN-1).at(f);
						++g;
					}
					else
					{
						sol&=pct.at(ins.at(g)-'2').at(f);
					}
				}
				if(sol) return f;
			}
			throw 42;
		}
};
int main(void)
{
	multibasehappiness task;
	task.precompute();
	int znj;
	cin>>znj;
	string tmp;
	getline(cin,tmp);
	for(int f=0;f<znj;++f)
	{
		task.input();
		cout<<"Case #"<<f+1<<": "<<task.solve()<<endl;
	}
	return 0;
}
