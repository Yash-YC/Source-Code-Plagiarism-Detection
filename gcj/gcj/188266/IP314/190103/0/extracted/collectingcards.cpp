#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class collectingcards
{
	private:
		const int NUMIT;
		int n,c;
		double nchoosek(int n,int k)
		{
			double sol=1.;
			for(int f=n-k+1;f<=n;++f)
			{
				sol*=f;
			}
			for(int f=2;f<=k;++f)
			{
				sol/=f;
			}
			return sol;
		}
	public:
		collectingcards():NUMIT(10000) {}
		void input()
		{
			cin>>n>>c;
		}
		double solve()
		{
			if(n==c) return 1.;
			vector<double> ccp(n+1,0.),nccp(n+1,0.),sol(n+1,0.);
			ccp.at(c)=1.;
			sol.at(c)=1.;
			for(int f=2;f<NUMIT;++f)
			{
				for(int g=c;g<n;++g)
				{
					for(int h=0;h<=min(c,n-g);++h)
					{
						nccp.at(g+h)+=ccp.at(g)*nchoosek(g,c-h)*nchoosek(n-g,h)/nchoosek(n,c);
					}
				}
				for(int g=c;g<=n;++g)
				{
					//cout<<nccp.at(g)<<' ';
					sol.at(g)+=f*nccp.at(g);
				}//cout<<endl;
				ccp.clear();
				swap(ccp,nccp);
				nccp.resize(n+1,0.);
			}
			return sol.at(n);
		}
};
int main(void)
{
	int znj;
	cin>>znj;
	cout.setf(ios_base::fixed);
	cout.precision(7);
	for(int f=0;f<znj;++f)
	{
		collectingcards task;
		task.input();
		cout<<"Case #"<<f+1<<": "<<task.solve()<<endl;
	}
	return 0;
}
