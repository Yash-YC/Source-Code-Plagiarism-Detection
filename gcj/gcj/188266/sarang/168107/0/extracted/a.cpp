#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <sstream>
using namespace std;

bool poss(int n, int base)
{
	set <int> rems;
	while(n != 1)
	{
		int temp = n;
		int newn = 0;
		while(temp)
		{
			int r = temp%base;
			newn += r*r;
			temp/=base;
		}
		
		n = newn;
		//cout << n <<endl;
		if(find(rems.begin() , rems.end() , newn) != rems.end())
			break;
		rems.insert(newn);
	}

	//cout<< base << " " <<n<<endl;	
	return n==1;
}

void output(vector<int>  &N)
{
	int n=2;
	while(true)
	{
		int good=1;
		for(int i=0 ; i<N.size() ; i++)
			if(!poss(n,N[i]))
			{
				good = 0;
				break;
			}

		if(good)
		{
			cout << n;
			return;
		}
		n++;
	}
}


int main()
{
	int T;
	cin>>T;

	cin.ignore();
	for(int __t=1 ; __t<=T ; __t++)
	{
		char str[100];
		cin.getline(str, 100);
		istringstream in(str);
		
		vector<int> N;
		while(in)
		{
			int a;
			in>>a;
			N.push_back(a);
		}

		cout<<"Case #"<<__t<<": ";
		output(N);
		cout<<endl;
	}

	return 0;
}
