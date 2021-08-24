#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std; 

#define maxi 30000000

using namespace std ; 

int table[maxi][11], globalmax ; 

long changebase(int n, int b) {
    long result = 0 ;
    while (n>0 ) {
        result *= 10 ; 
        result += n%b ;
        n /= b; 
    }
    return result ; 
}

long calc(int n, int b ) {
    long nn = n ; // changebase(n,b ) ; 

    long sum = 0 ; 
    while( nn>0) {
        long x = nn%b ; 
        nn /= b ; 
        sum += x*x; 
    }

    return sum ; 
}


int recur(int n, int b ) {
    //cout << n << b  << endl ; 

    if( n<maxi ) {
        if( table[n][b]!=-1) { return table[n][b] ; }
        if (table[n][b]==-2 ) { return 0 ; }
        table[n][b] = -2 ; 
    }  else {
        globalmax = n ; 
    //    cout << "global" << globalmax << endl ; 
    }

    int x = calc(n,b) ; 
    //cout << "result : (" << n<< "," << b << ") : " << x << endl ; 
    if( x==1 ) { table[n][b] =1 ;  return 1 ; }

    table[n][b]  = recur(x,b) ; 

    return table[n][b] ;
}

void init() {
    int i,j ; 
    for(i=0;i<maxi;i++) {
        for(j=2;j<=10;j++) {
            table[i][j] = -1 ;
        }
    }
    globalmax = maxi ;

    for(i=1;i<maxi;i++) {
        //cout << "count : " << i << endl ; 
        for(j=2;j<=10;j++) {
            if (table[i][j]==-1) {
                table[i][j] = recur(i,j) ;
            }
        }
    }
}

int main()  {

    int t,i , num[10]; 
    string instr; 
    cin >> t ; // >> endl; 
    getline(cin,instr);

    init();

    for(i=0;i<t;i++) {
        getline(cin,instr);

        stringstream ss(instr);
        int x ; 

        int idx = 0 ; 
        cout << "Case #"<< i+1<<": ";

        while( !ss.eof()) {
            ss >> x ; 
//            cout << x << "-" ; 
            num[idx++] = x ; 
        }
      int j,k ;
        for(j=2;j<maxi;j++) {
            for(k=0;k<idx;k++) {
                if(table[j][num[k]]!=1 ) break ; 
            }
            if (k==idx) { cout << j << endl; break ;}
        }
    }


    cout.flush();


    return 0 ; 
}
