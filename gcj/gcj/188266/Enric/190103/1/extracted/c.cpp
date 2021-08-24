#include <iostream>
#include <vector>
#include <algorithm>
#define x first
#define y second
using namespace std;
typedef pair<int,int> PII;
typedef long double LD;
int c, n;
LD memo[50];

LD fac(LD x) {
    if (x<=0) return 1.;
    return x*fac(x-1);
}

LD cn(int a, int b) { //a>=b
    LD x=LD(a);
    LD y=LD(b);
    return fac(x)/(fac(y)*fac(x-y));
}

LD f(int k) { //expected cards when I have x distinct
    if (k>=c) return 0.;
    if (memo[k]>=0) return memo[k];
    LD sum=0,p;
    if (n>k) { //surt alguna nova per palomar
        for (int i=0;i<=k;++i) { //numero de repes
            p=cn(k,i)*cn(c-k,n-i)/cn(c,n);
            sum+=p*f(n-i+k);
        }
        return memo[k]=1.+sum;
    }
    else {
        for (int i=0;i<n;++i) { //numero de repes menor que n
            p=cn(k,i)*cn(c-k,n-i)/cn(c,n);
            sum+=p*f(n-i+k);
        }
        LD tmp=cn(k,n)/cn(c,n); //prob que es repeteixin totes
        return memo[k]=(1.+sum)/(1.-tmp);
    }
}

int main() {
    cout.setf(ios::fixed);
    cout.precision(7);
    int t; cin >> t;
    for (int z=1;z<=t;++z) {
        cin >> c >> n;
        for (int i=0;i<50;++i) memo[i]=-1;
        cout << "Case #"<<z<<": ";
        cout << 1.+f(n) << endl;
    }
}
