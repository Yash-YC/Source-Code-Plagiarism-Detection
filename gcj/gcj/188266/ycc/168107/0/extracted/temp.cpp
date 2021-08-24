#include <iostream>

using namespace std;
int main()
{
    int*p;
    p=new int[20];
    *p = 1;
    *(++p) = 1;
    ++p;
    cout <<p[0] << endl <<p[1] << endl;
	delete[]p;
    return 0;
}
