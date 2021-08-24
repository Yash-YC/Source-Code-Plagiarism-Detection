//#include <math.h>
#include <stdio.h>
#include <map.h>
#include <list.h>
#include <vector.h>
#include <iostream.h>
#include <iomanip.h>
//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused

vector<map<long,bool> > pre = vector<map<long,bool> >(11);

typedef map<long,bool>::iterator mip;

long trans(long n, int bas)
{
        long acc = 0;
        while(n != 0) {
                long l = n % bas;
                acc += l * l;
                n /= bas;
        }
        return acc;
}

bool isHap(long n, int bas)
{
        mip mi = pre[bas].find(n);
        if(mi == pre[bas].end()) {
                pre[bas][n] = false;
                bool ret = isHap(trans(n, bas), bas);
                if(ret) {
                        pre[bas][n] = ret;
                }
                return ret;
        } else {
                return mi->second;
        }
}


int main(int argc, char* argv[])
{
	int N;
	cin >> N;
	for( int i = 0; i < N; ++i ) {
                char buf[256] = "";
                cin.getline(buf, 256);
                int bas[9];
                int cntb = sscanf(buf, "%d%d%d%d%d%d%d%d%d%d", bas, bas+1, bas+2, bas+3, bas+4, bas+5, bas+6, bas+7, bas+8);
                long j = 1;
                bool hap = true;
                do {
                        ++j;
                        hap = true;
                	for( int k = 0; hap && k < cntb; ++k ) {
                                hap = isHap(j, bas[k]);
                        }
                }
                while(!hap);
                cout << "Case #" << i+1 << ": " << j << endl;
	}
	return 0;
}
//---------------------------------------------------------------------------
