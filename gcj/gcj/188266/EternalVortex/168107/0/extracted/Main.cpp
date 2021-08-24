#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <numeric>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <utility>
using namespace std;

typedef int uint;
class DisjointSet
{
private:
	std::vector<int> _parentVector;
	std::vector<int> _rankVector;

public:
	DisjointSet(uint n) : _parentVector(n)
	{
		for (uint i = 0; i < n; ++i)
			_parentVector[i] = i;
	}

	uint Find(uint n)
	{
		if (_parentVector[n] == n)
			return n;
		
		return (_parentVector[n] = Find(_parentVector[n]));
	}

	void Union(uint n, uint m)
	{
		n = Find(n);
		m = Find(m);

		// Union by smallest rep
		if (m > n)
			_parentVector[m] = n;
		else
			_parentVector[n] = m;
	}
};
struct Matrix
{
	int* _data;
	int _rows, _cols;
	
	Matrix(int rows, int cols) : _data(new int[rows * cols]), _rows(rows), _cols(cols)
	{
		fill(_data, _data + (rows * cols), 0);
	}

	~Matrix()
	{
		delete [] _data;
	}

	int& operator()(int r, int c)
	{
		return _data[r * _cols + c];
	}

	int operator()(int r, int c) const
	{
		return _data[r * _cols + c];
	}
};

Matrix M(11, 100000); // 1 = happy, 2 = unhappy, 3 = seen

int IsHappy(int i, int base)
{
	int sum = 0;
	int num = i;
	if (M(base, i) == 3)
		return (M(base, i) = 2);

	if (M(base, i) != 0)
		return M(base, i);

	while (i > 0)
	{
		int j = i % base;
		sum += j * j;
		i /= base;
	}
	if (sum == 1)
		return (M(base, num) = 1);

	M(base, num) = 3; // mark seen

	return (M(base, num) = IsHappy(sum, base)); // save value
}

int Smallest(const vector<int>& v)
{
	for (int i = 2; ;++i)
	{
		// Check i for happiness
		bool flag = true;
		for (int j = 0; j < v.size(); ++j)
		{
			if (IsHappy(i, v[j]) == 2)
			{
				flag = false;
				break;
			}
		}
		if (flag) return i;
	}
}

void Bases()
{
	int T;
	ifstream cin("A-small.in");
	ofstream cout("A.out");
	cin >> T;
			string s;
			getline(cin, s);
	for (int cs = 1; cs <= T; ++cs)
	{

		getline(cin, s);
		istringstream istr(s);
		vector<int> v;
		int tmp;
		while (istr >> tmp) 
			v.push_back(tmp);

		cout << "Case #" << cs << ": " << Smallest(v) << endl;
	}
}

int main()
{
	Bases();
	while (true) ;
}