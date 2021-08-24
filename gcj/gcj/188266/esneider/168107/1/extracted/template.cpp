#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cstring>
#include <cassert>

using namespace std;

#define all(n) n.begin(), n.end()
#define sz size()
//#define forn(i, n) for( int ___n=(n), i = 0 ; i < ___n ; i++ )
//#define fordn()
//#define forsn(i, s, n) for(int i = (s); i < (n); i++)
//#define forall(i, n) for( typeof( (n).begin() ) i = (n).begin(); i != (n).end(); ++i) 
#define debug(x) cout << __LINE__ << " => " << #x << " : " << x << flush; cin.get()

#define forn(i,n) for(int ___n=n, i=0;i<___n;++i)
#define fordn(i,n) for(int i=(n)-1;i>=0;--i)
#define forsn(i,s,n) for(int ___n=n, i=s;i<___n;++i)
#define fordsn(i,s,n) for(int i = (int)(n)-1; i>=((int)s); i--)
#define forall(it,X) for(typeof((X).begin()) it = (X).begin(); it != (X).end(); ++it)
#define fordall(it,X) for(typeof((X).rbegin()) it = (X).rbegin(); it != (X).rend(); ++it)
//#define all(X) (X).begin(), (X).end()
#define esta(e, c) (c.find(e) != c.end())
//#define DBG(a) cerr << #a << " = " << a << endl;

template<class T> string itos(const T&x) { ostringstream o; o<<x; return o.str(); }


template <class T> ostream& operator<<(ostream& o, vector<T>& v){
	o << endl << '[';
	forall(i,v) o << (*i) << ',';
	o << ']' ;
	return o;
}

template <class U, class V> ostream& operator<<(ostream& o, pair<U,V>& p){
	o << '(' << p.first << ',' << p.second << ')';
	return o;
}

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<bool> VB;
typedef vector<VB> VVB;
typedef vector<string> VS;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<VPII> VVPII;
typedef pair<int, string> PIS;
typedef pair<string, int> PSI;
typedef pair<string, string> PSS;


struct punto{
	int x,y;
	punto():x(0),y(0){}
	punto(int x,int y):x(x),y(y){}
	punto operator+(punto& p){ return punto(x+p.x,y+p.y);}
	punto operator-(){ return punto(-x,-y); }
	punto operator-(punto& p){ return punto(x-p.x,y-p.y); }
	bool operator<(punto& p){ return (y==p.y)?x<p.x:y<p.y; }
};

const int mat[]=
{2 , 3 , 3 , 2 , 2 , 3 , 3 , 5 , 5 , 23 , 23 , 5 , 5 , 23 , 23 , 6 , 6 , 79 , 79
, 6 , 6 , 79 , 79 , 49 , 49 , 79 , 79 , 49 , 49 , 79 , 79 , 7 , 7 , 143 , 143 ,
7 , 7 , 143 , 143 , 7 , 7 , 143 , 143 , 7 , 7 , 143 , 143 , 49 , 49 , 2207 ,
2207 , 49 , 49 , 2207 , 2207 , 49 , 49 , 2207 , 2207 , 49 , 49 , 2207 , 2207 , 8
, 8 , 27 , 27 , 8 , 8 , 27 , 27 , 27 , 27 , 27 , 27 , 27 , 27 , 27 , 27 , 216 ,
216 , 3879 , 3879 , 216 , 216 , 3879 , 3879 , 1975 , 1975 , 3879 , 3879 , 1975 ,
1975 , 3879 , 3879 , 1001 , 1001 , 5719 , 5719 , 1001 , 1001 , 5719 , 5719 ,
1001 , 1001 , 5719 , 5719 , 1001 , 1001 , 5719 , 5719 , 47089 , 47089 , 47089 ,
47089 , 47089 , 47089 , 47089 , 47089 , 48769 , 48769 , 58775 , 58775 , 48769 ,
48769 , 58775 , 58775 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 27 , 27 , 27 , 27 , 27 ,
27 , 27 , 27 , 415 , 415 , 707 , 707 , 415 , 415 , 707 , 707 , 415 , 415 , 1695
, 1695 , 415 , 415 , 1695 , 1695 , 125 , 125 , 143 , 143 , 125 , 125 , 143 , 143
, 125 , 125 , 143 , 143 , 125 , 125 , 143 , 143 , 2753 , 2753 , 37131 , 37131 ,
2753 , 2753 , 37131 , 37131 , 37131 , 37131 , 37131 , 37131 , 37131 , 37131 ,
37131 , 37131 , 27 , 27 , 27 , 27 , 27 , 27 , 27 , 27 , 27 , 27 , 27 , 27 , 27 ,
27 , 27 , 27 , 4977 , 4977 , 10089 , 10089 , 4977 , 4977 , 10089 , 10089 , 4977
, 4977 , 23117 , 23117 , 4977 , 4977 , 23117 , 23117 , 6393 , 6393 , 35785 ,
35785 , 6393 , 6393 , 35785 , 35785 , 6393 , 6393 , 128821 , 128821 , 6393 ,
6393 , 128821 , 128821 , 569669 , 569669 , 569669 , 569669 , 569669 , 569669 ,
569669 , 569669 , 569669 , 569669 , 569669 , 569669 , 569669 , 569669 , 569669 ,
569669 , 7 , 7 , 13 , 13 , 7 , 7 , 13 , 13 , 7 , 7 , 23 , 23 , 7 , 7 , 23 , 23 ,
44 , 44 , 79 , 79 , 44 , 44 , 79 , 79 , 49 , 49 , 79 , 79 , 49 , 49 , 79 , 79 ,
7 , 7 , 167 , 167 , 7 , 7 , 167 , 167 , 7 , 7 , 7895 , 7895 , 7 , 7 , 7895 ,
7895 , 49 , 49 , 6307 , 6307 , 49 , 49 , 6307 , 6307 , 49 , 49 , 7895 , 7895 ,
49 , 49 , 7895 , 7895 , 97 , 97 , 219 , 219 , 97 , 97 , 219 , 219 , 219 , 219 ,
219 , 219 , 219 , 219 , 219 , 219 , 608 , 608 , 3879 , 3879 , 608 , 608 , 3879 ,
3879 , 3879 , 3879 , 3879 , 3879 , 3879 , 3879 , 3879 , 3879 , 34527 , 34527 ,
48041 , 48041 , 34527 , 34527 , 48041 , 48041 , 34527 , 34527 , 120407 , 120407
, 34527 , 34527 , 120407 , 120407 , 245035 , 245035 , 697563 , 697563 , 245035 ,
245035 , 697563 , 697563 , 245035 , 245035 , 245035 , 245035 , 91 , 91 , 91 , 91
, 91 , 91 , 91 , 91 , 91 , 91 , 91 , 91 , 91 , 91 , 91 , 91 , 1033 , 1033 , 6073
, 6073 , 1033 , 1033 , 6073 , 6073 , 4577 , 4577 , 6073 , 6073 , 4577 , 4577 ,
6073 , 6073 , 1337 , 1337 , 1337 , 1337 , 1337 , 1337 , 1337 , 1337 , 29913 ,
29913 , 120149 , 120149 , 29913 , 29913 , 120149 , 120149 , 71735 , 71735 ,
613479 , 613479 , 71735 , 71735 , 613479 , 613479 , 218301 , 218301 , 711725 ,
711725 , 218301 , 218301 , 711725 , 711725 , 1177 , 1177 , 1177 , 1177 , 1177 ,
1177 , 1177 , 1177 , 1177 , 1177 , 1177 , 1177 , 1177 , 1177 , 1177 , 1177 ,
9867 , 9867 , 28099 , 28099 , 9867 , 9867 , 28099 , 28099 , 28099 , 28099 ,
28099 , 28099 , 28099 , 28099 , 28099 , 28099 , 48041 , 48041 , 48041 , 48041 ,
48041 , 48041 , 48041 , 48041 , 246297 , 246297 , 346719 , 346719 , 246297 ,
246297 , 346719 , 346719};


int main(){
	ofstream sal("sol.txt");
	
	int t;
	string s;
	cin >> t;
	getline(cin,s);
	
	forn(w,t){
		getline(cin,s);
		istringstream iss(s);
		int b, old=-1,bases = 0;
		iss >> b;
		do{
			bases|=1<<(b-2);
			old = b;
			iss >> b;
		}while(b!=old);
//		debug(bases);
		sal << "Case #" << w+1 << ": " << mat[bases-1] << endl;
	}
	return 0;
}