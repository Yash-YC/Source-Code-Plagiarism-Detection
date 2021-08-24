#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

ifstream fin("p1in2.txt");
ofstream fou("p1out2.txt");

int base[12];
int totb;


bool test( int n, int b){

	bool p[100000];
    memset( p , 0 , sizeof(p));

	while (1){
    	if (n==1) return true;
        if (p[n]) return false;

        p[n]=true;
        int tmp=0;
    	while (n>0){
        	tmp += (n%b)*(n%b);
	        n=n/b;
    	}

        n=tmp;


    }




}


int work()
{
    for (int n=2; n<=100000; n++){
    	bool findout = true;
    	for (int k=1; k<=totb; k++){
        	if (!test(n,base[k])){
            	findout = false;
                break;
            }
        }
        if (findout){
            return n;
        }
    }
}


int main()
{
	int T;
    char s[100];
//    string str;
    fin.getline(s,100);
    T=atoi(s);
    for (int i=1; i<=T; i++){


		fin.getline(s,100 );
        totb=0;
        for (int k=0; k<strlen(s); k++){
            if (s[k]>='2' && s[k]<='9'){
                totb++;
                base[totb]=s[k]-'0';
            }else{
                if (s[k]=='1'){
                    totb++;
                    base[totb]=10;
                }
            }
        }

         fou << "Case #" << i << ": " << work() << endl;

    }
    return 0;
}
