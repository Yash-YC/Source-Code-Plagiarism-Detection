#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
int main()
{
  char s[1010];
  string out = "";
  int T;
  cin >> T;
  char* p = s;
  for(int i=0;i<T;i++){
    cin >> s;
    out = "";
    p =s;
    while(*p != '\0'){
        if(*p>=out[0]) out = *p +out;
        else out = out+*p;
        p++;
    }
    printf("Case #%d: ",i+1);
    cout << out << endl;
  }
}
