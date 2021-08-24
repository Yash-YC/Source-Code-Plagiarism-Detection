#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

bool Happiness(int base, int n)
{
	bool ans;
	int res = n;
	int tmp;
	vector<int> list;
	while(n != 1)
	{
		for(int i=0; i<list.size(); i++) if(n == list[i]) return false;
		list.push_back(n);
		res = 0;
		while(n > 0)
		{
			tmp = n % base;
			res += tmp * tmp;
			n = n / base;
		}
//		cout << res << endl;
		n = res;
	}
	if(res==1) ans = true;
	else ans = false;

	return ans;
}

int MultibaseHappiness(vector<int> base)
{
	int res = 2;
	bool flag;
	while(true)
	{
		flag = true;
		for(int i=0; i<base.size(); i++)
		{
	//		cout << "base: " << base[i] << "   num: " << res << endl;
			if(!Happiness(base[i], res)) { flag = false; break; }
		}
		if(flag) break;
		res++;
	}
	return res;
}

int main()
{
	string file = "A-small-attempt1";
	ifstream ifs((file + ".in").c_str());
	ofstream ofs((file + ".out").c_str());
	string buf;
	string tmp;
	vector<int> data;
	getline(ifs, buf);
	int n = atoi(buf.c_str());
	for(int i=0; i<n; i++)
	{
		data.clear();
		getline(ifs, buf);
		int ind = 0, _ind = -1;
		while(buf.find(" ", _ind+1) != -1)
		{
			ind = buf.find(" ", _ind+1);
			data.push_back(atoi(buf.substr(_ind+1, ind-_ind-1).c_str()));
			_ind = ind;
		}
		data.push_back(atoi(buf.substr(ind+1).c_str()));
	//	for(int j=0; j<data.size(); j++) cout << "!!!" << data[j] << endl;
		ofs << "Case #" << i+1 << ": " << MultibaseHappiness(data) << endl;
	}

	return 0;
}

