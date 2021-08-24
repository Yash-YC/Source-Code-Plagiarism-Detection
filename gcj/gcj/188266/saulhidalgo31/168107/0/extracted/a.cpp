#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <complex>
#include <cstdio>
#include <cassert>
#include <cmath>
#include <numeric>
#include "regex.h"

#define DEBUG(x) cerr << '>' << #x << ": " << x << endl;
#define CLEAR(x,c) memset(x,c,sizeof(x))
#define FOR(i,a,b) for(int i=(a),_b=(b);i<_b;i++)
#define FORD(i,a,b) for(int i=(b)-1,_b=(a);i>=_b;i--)
#define FORF(i,a,b,c) for(double i=(a),_b=(b);i<_b;i+=c)
#define FORC(i, n) for (typeof (n.begin()) i = n.begin() ; i != n.end() ; i++)
#define sz size()
#define mp make_pair
#define X first
#define Y second
#define pb push_back
#define SORT(x) sort(all(x))
#define REVERSE(x) reverse(all(x))
#define CLEAR(x,c) memset(x,c,sizeof(x))
#define all(x) (x).begin(),(x).end()

#define pi acos(-1.)
#define eps 1e-7
#define aprox(a,b) (fabs((a)-(b))<eps)
#define FIND_MAX(type) (type)(~(1 << ((sizeof(type) * 8) - 1)))

template<typename T> inline T sqr(T a) { return a*a; }
//template<typename T> inline int Size(const T& c) { return (int)c.size(); }
template<typename T> inline void checkMin(T& a, T b) { if (b < a) a = b; }
template<typename T> inline void checkMax(T& a, T b) { if (b > a) a = b; }
template<typename T> inline bool isSet(T number, int bit) { return (number&(T(1)<<bit)) != 0; }
template<class T> T abs(T x){return x>0 ? x:(-x);}
/*template<class T> T& operator >?= (T& x, T y) {if(y>x) x=y; return x;}
template<class T> T& operator <?= (T& x, T y) {if(y<x) x=y; return x;}
template<class T> T operator >? (T x, T y) {return x>y?x:y;}
template<class T> T operator <? (T x, T y) {return x<y?x:y;}*/

using namespace std;

template<typename T, typename S> T cast(S s) { stringstream ss; ss << s; T res; ss >> res; return res; }

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef vector<long> VL;

/* Saul Hidalgo
   Venezuela!! :)
*/

set<LL> repetidos;


LL convertir(LL num,int base){
   //cerr << "Convertir " << num << " " << base << endl;
   string respuesta;
   while(num !=0){
      respuesta.pb(num%base+'0');
      num/=base;
   }
   REVERSE(respuesta);
   return cast<LL>(respuesta);
}

bool eshappy(LL numA,int base){
   //cout  << numA << endl;
   LL num = convertir(numA,base);
   if (repetidos.count(num)){
      //cerr << "Ya estaba\n";
      return 0;
   }
   if (num == 0) return 0;
   repetidos.insert(num);
   string cadena = cast<string>(num);
   int temp=0;
   FOR(i,0,cadena.sz){
      int c = cadena[i] - '0';
      temp += c*c;
   }
   if (temp == 1) return 1;
   return eshappy(cast<LL>(temp),base);
}


int main(){
   int casos;
   cin >> casos;
   //cout << convertir(82,3) << endl;
   //cerr << eshappy(3,2) << "asd\n";
   //cerr <<   "12312312333333 \n";
   //cerr << eshappy(3,3)<< endl;
   //return 0;
   string cadena;
   getline(cin,cadena);
   FOR(caso,0,casos){
      getline(cin,cadena);
      vector<int> bases;
      stringstream ss;
      ss << cadena;
      int temp;
     //    cerr << "Leitos\n";
      while(ss>>temp){
         //cerr << temp << endl;
         bases.pb(temp);
      }
      //cerr << "Fin\n";
      int intento = 2;
      bool conseguido = false;
      //cout << "Que paso\n";
      while(!conseguido){
         conseguido = true;
         FOR(i,0,bases.sz){
            repetidos.clear();
            //cerr << "Repetido " << repetidos.sz << endl;
            //DEBUG(intento);
            if (!eshappy(intento,bases[i])){
               conseguido = false;
               //cerr << "No es happy con " << i << endl;
            }
         }
         intento++;
      }
      cout << "Case #" << (caso+1) << ": " << intento-1 << endl;
   }
   
   return 0;
}


