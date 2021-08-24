#include<fstream>
#include<algorithm>
using namespace std;
ifstream fin("Bs.in");
ofstream fout("Bs.out");
int main()
{
    int T;
    fin>>T;
    for(int k=0;k<T;k++)
    {
       int C,N;
       fin>>C>>N;
       double aver;
       aver=double(C+N)/double(N);
       fout.precision(8);

       fout<<"Case #"<<k+1<<": "<<aver<<endl;
    }
}
