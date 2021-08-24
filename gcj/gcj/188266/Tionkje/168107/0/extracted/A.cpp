#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <math.h>
#include <iomanip>
using namespace std;

#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;i++)
#define REP(i,n) FOR(i,0,(n)-1)

typedef long long LL;
typedef long double LD;

 typedef vector<LL> VI;
// typedef map<int,int> MII;
// typedef map<int,int>::iterator MIIT;
// typedef vector<MII> VMII;

string DecimalToBaseNr(LL decimal, int base)
{
	int digitpos=0;
	while(pow((LD)base , (LD)digitpos) * base-1 < decimal)
	{
		++digitpos;
	}

	stringstream out;
	for(int i=digitpos;i>=0;--i)
	{
		int digitval = base;
		while(pow((LD)base , (LD)i)*digitval > decimal)
		{
			--digitval;
		}
		decimal -= pow((LD)base , i)*digitval;
		out << digitval;
	}
	return out.str();
}
int cti(char c){return (int)c-'0';}

bool isHappy(string nr,int base)
{
	LL out=0;
	set<int> si;
	while(out!=1)
	{
		out=0;
		REP(i,nr.size())
		{
			out+=cti(nr.at(i))*cti(nr.at(i));
		}
		nr = DecimalToBaseNr(out,base);
		if(si.find(out)!=si.end())return false;
		si.insert(out);
	}
	return true;
}
void main()
{
	ifstream inf;
	inf.open("A-small-attempt0.in");
	ofstream ouf;
	ouf.open("file.out");

	int nrOcs;

	inf>>nrOcs;
	string sli;
	getline(inf,sli);
	REP(ca,nrOcs)
	{
		getline(inf,sli);
		int nrObn = (int)count(sli.begin(),sli.end(),' ');
		VI basses;
		stringstream buf(sli);
		REP(bn,nrObn+1)
		{
			int base;
			buf>>base;
			basses.push_back(base);
		}

		LL nr=2;
		REP(i,basses.size())
		{
			if(!isHappy(DecimalToBaseNr(nr,basses[i]),basses[i]))
			{
				i=-1;
				++nr;
			}
		}


		ouf<<"Case #"<<ca+1<<": "<<nr<<endl;
	}
	inf.close();
	ouf.close();
}