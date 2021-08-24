#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define forn(i,n) for (int i=0; i<(int)(n); i++)
#define forsn(i,m,n) for (int i=(m); i<(int)(n); i++)


#define MAXN 1000000


vi res;
vi base;
bool happy[MAXN][10];
bool used[MAXN][10];
bool cand[MAXN];

int conv(int n, int b){
    res.clear();
    
    //cout << n << " en base " << b << " --> ";
    if(n==0) res.pb(0);
    else{
        while(n>0){
            res.pb(n%b);
            n/=b;    
        }
    }    
    reverse(res.begin(), res.end());

    //forn(i,sz(res)) cout << res[i]; cout << endl;
    return 0;
}

bool ish(int n, int b){
    //cout << "probando " << n << endl;
    if(used[n][b] == true) { return happy[n][b]; }
    else{
        conv(n, b);
        int a = 0;
        forn(i,res.size()) a+=res[i]*res[i];            
        if(a==1) return true;
        else{
            used[n][b] = true;
            bool k = ish(a, b);
            happy[n][b] = k;
            return k;
        }
    }
}

int main(){
    int T, N;
    string tmp;
    
    cin >> T;
    getline(cin, tmp);
    forn(nc,T){
        base.clear();
        getline(cin, tmp);
        stringstream in(tmp);
        
        int k;
        while(in >> k){base.pb(k); }
        memset(happy,false,sizeof(happy));
        memset(used,false,sizeof(used));
        memset(cand,false,sizeof(cand));
        forsn(i, 2, MAXN){
            int cond = 1;
            forn(j, sz(base)){
                if(ish(i, base[j]) == false) { cond = -1; break; }
            }
            if(cond == 1){ cout << "Case #" << nc+1 << ": " << i << endl; break; }    
        }
    }
        
    return 0;
}
