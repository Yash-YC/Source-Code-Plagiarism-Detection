#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

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

#define MAXT 100

double P[MAXT][45];
double CC[45][45];
double TT;

double Cmb(int A, int B){
    if(B==A) return 1;
    if(B>A || B<0) return 0;
    else return CC[A][B];     
    
}

int main(){
    int NC, N, C;
    double E;
    
    memset(CC,0,sizeof(CC));
    CC[1][1] = CC[1][0] = 1;
    forn(i,12) CC[i][0] = 1;
    forsn(i,2,12) forsn(j,1,12) CC[i][j] = CC[i-1][j] + CC[i-1][j-1];
    cin >> NC;
    forn(nc, NC){
        cin >> C >> N;
        TT = CC[C][N];
        E = 0;
        memset(P,0,sizeof(P));
        P[1][N] = 1;
        if (N == C) E = 1;
        else{
        forsn(n,2,MAXT){
            forsn(c,N,C+1){
                //cout << "calculando " << n << " " << c;
                double tmp = 0;
                forsn(j,N,c+1){
                    tmp += P[n-1][j] * ( ( Cmb(C-j,c-j) * Cmb(j, N-c+j) ) / TT );
                    if (c == C && j==c-1) E += n*tmp;
                }
                P[n][c] = tmp;
                //cout << " - - " << P[n][c] << endl;
            }
        }    
        }
        cout << "Case #" << nc+1 << ": " <<  E << endl;
        
    }    
    
    return 0;
}
