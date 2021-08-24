#include"iostream"
#include"unordered_set"
#include"string"
using namespace std;
string Solve(string &s, int index)
{
	if (index == 0){ return s.substr(0,1); }
	string str = Solve(s, index - 1);

	char CurrentVal = s[index];

	if (CurrentVal >= str.front())
	{
		str.insert(str.begin(), CurrentVal);
	}
	else
	{
		str.push_back(CurrentVal);
	}

	return str;
}
int main()
{
	int Times = 0;
	::cin >> Times;

	for (int seek = 0; seek < Times; seek = seek + 1)
	{
		char Buffer[1024];
		::cin >> Buffer;

		string strString = Buffer;

		::cout << "Case #" << seek + 1 << ": " << Solve(strString, strString.size()).c_str() << endl;
	}

	//::system("pause");

	return 0;
}