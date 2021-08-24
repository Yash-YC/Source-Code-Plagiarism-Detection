
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <cmath>
using namespace std;
typedef unsigned char byte;
namespace std {
	inline ostream& operator<<(ostream& os, const unsigned char& v) {
		os << (int)v;
		return os;
	}
	inline istream& operator>>(istream& is, unsigned char& v) {
		int intval = v;
		is >> intval;
		v = (unsigned char)intval;
		return is;
	}
	template<typename T>
	ostream& operator<<(ostream& os, const vector<T>& v) {
		for (size_t i = 0; i < v.size(); ++i) {
			if (i >= 1) {
				os << " ";
			}
			os << v[i];
		}
		return os;
	}
	template<typename T1, typename T2>
	ostream& operator<<(ostream& os, const pair<T1,T2>& v) {
		return os << v.first << " " << v.second;
	}
	template<typename T1, typename T2, typename T3>
	ostream& operator<<(ostream& os, const tuple<T1, T2, T3>& v) {
		return os << get<0>(v) << " " << get<1>(v) << " " << get<2>(v);
	}
	template<typename T1, typename T2>
	struct hash<pair<T1, T2>> {
	public:
		size_t operator()(const pair<T1, T2>& v) const
		{
			size_t prime = 16777619U;
			size_t val = 0;
			val = (val * prime) ^ (hash<T1>()(v.first) + sizeof(T1));
			val = (val * prime) ^ (hash<T2>()(v.second) + sizeof(T2));
			return val;
		}
	};
	template<typename T1, typename T2, typename T3>
	struct hash<tuple<T1, T2, T3>> {
	public:
		size_t operator()(const tuple<T1, T2, T3>& v) const
		{
			size_t prime = 16777619U;
			size_t val = 0;
			val = (val * prime) ^ (hash<T1>()(get<0>(v)) + sizeof(T1));
			val = (val * prime) ^ (hash<T2>()(get<1>(v)) + sizeof(T2));
			val = (val * prime) ^ (hash<T3>()(get<2>(v)) + sizeof(T3));
			return val;
		}
	};
	template<typename T>
	struct hash<vector<T>> {
	public:
		size_t operator()(const vector<T>& v) const
		{
			size_t prime = 16777619U;
			size_t val = 0;
			for (size_t i = 0; i < v.size(); ++i) {
				val = (val * prime) ^ (hash<T>()(v[i]) + sizeof(T));
			}
			return val;
		}
	};
}
class ostreamstring : public ostringstream {
public:
	template<typename T>
	ostreamstring& operator<<(const T& v) {
		ostream::operator<<(v);
		return *this;
	}
};

void Solve(istream& is, ostream& os) {
	string letters;
	is >> letters;
	string result;
	for (int i = 0; i < letters.size(); ++i) {
		char letter = letters[i];
		string r1 = letter + result;
		string r2 = result + letter;
		if (r1 > r2) {
			result = r1;
		}
		else {
			result = r2;
		}
	}
	os << result;
}

int main(int argc, char** argv) {
	istream& is = cin;
	ostream& os = cout;
	int casecount = 0;
	is >> casecount;
	for (int i = 0; i < casecount; ++i) {
#if 0 // multiline output
		os << "Case #" << (i + 1) << ":" << endl;
		Solve(is, os);
#else
		os << "Case #" << (i + 1) << ": ";
		Solve(is, os);
		os << endl;
#endif
	}
	if (is.fail()) {
		return 1;
	}
	return 0;
}
