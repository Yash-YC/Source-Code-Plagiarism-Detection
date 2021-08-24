#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <list>
#include <set>
#include <math.h>

using namespace std;

#define pb push_back
#define fori(i, n) for ( int i = 0; i < (n); i++ )
#define forr(i, a, b) for ( int i = (a); i <= (b); i++ )
#define size(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define sorting(x) sort(all(x))
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end()
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define print_m(m) for(int i = 0;i<(int) m.size();i++) print_v(m[i]); cout << endl;
#define print_v(v) { for(int j = 0;j<(int) v.size();j++) cout << v[j] << " "; cout << endl; }
#define trace(x...)
#define PRINT(x...) trace(printf(x))
#define watch(x) trace(cout << #x " = " << x << "\n")

#define GRANDE 6000

const int INF = 0x3FFFFFFF;
const double EPS = 1e-10;
const double PI = 3.14159265;
const double EXP = 2.71828183;

#define BIG 1000

char number[300];
int size_number;
int jah_apareceu[BIG];

void represent(int n, int base){
	int aux = n;
	int t;
	size_number=0;
	for(int b=17; b>=0; b--){
		t = pow(base,b); //base ** b
		if((aux/t > 0)&&(size_number==0)){
			size_number = b+1;
		}
		number[b] = aux/t;
		aux = aux%t;
	}
	//number -> number 'n' in base 'b'
// 	PRINT("Number %d, base %d. size: %d\n",n, base,size_number);
}
			
int is_happy(int n, int base){
	PRINT("IsHappy %d, %d?\t NUMBER: ", n, base);
	represent(n, base);
	
	int sum = 0;
	for(int i=0; i<size_number; i++){
		PRINT("%d",number[size_number-i-1]);
		sum += number[i]*number[i];
	}
	PRINT(". SUM %d\n",sum);
	
	if(sum == 1) return 1;
	if(jah_apareceu[sum]==1) return 0;
	jah_apareceu[sum] = 1;
	return is_happy(sum, base);
}

int call_is_happy(int n, int base){
	fori(i,BIG){
		jah_apareceu[i] = 0;
	}
	return is_happy(n,base);
}

int main()
{
	istringstream instream;
	int T;
	scanf("%d\n",&T);
	char linha[50];
	for(int i=1; i<=T; i++){
		string line;
		getline(cin, line);	//Reads the Raw Pattern.
		
		instream.clear();
		instream.str(line);
		
		int b;
		vector<int> bases;
		while(!instream.eof()){
			instream >> b;
			PRINT("base %d\n",b);
			bases.pb(b);
		}
		
		int ok = 0;
		int n = 1;
		while(!ok){
			n++;
			ok = 1;
			PRINT("Testing number %d\n", n);
			fori(i,size(bases)){
				PRINT("IN BASE %d\n",bases[i]);
				if(!call_is_happy(n,bases[i])){
					PRINT("not...-\n");
					ok = 0; break;
				} else {
					PRINT("HAPPY!\n");
				}
			}
		}
		cout << "Case #" << i << ": " << n << endl;
	}
	return 0;
}