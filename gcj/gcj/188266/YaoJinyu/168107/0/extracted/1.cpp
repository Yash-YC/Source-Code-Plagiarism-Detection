#include <iostream>

using namespace std;

const int MAXN = 100000;

bool mark[11][MAXN];
bool used[1000];
bool ss[20];

void turn(int base, int &x)
{
     int s = 0;
     while (x!=0){
           s += (x%base)*(x%base);
           x/=base;
     }    
     x = s;  
}

bool check(int base, int x)
{
     memset(used, 0, sizeof(used));
     turn(base, x);
     while (!used[x] && x!=1){
           used[x] = true;
           turn(base, x);
     }
     if (x==1) return true; else return false;
}
     
void prepare()
{
     int base, i;
     for (base = 2; base <= 10; base ++)
         for (i=2; i<MAXN; i++)     
             mark[base][i] = check(base, i);
}
    
void init()
{
     char c;
     int x;
     
     memset(ss, 0, sizeof(ss));
     while (true){
           scanf("%d", &x);
           ss[x] = true;
           scanf("%c", &c);
           if (c=='\n') break;
     }
           
}
      
bool judge(int x)
{
     int i;
     for (i=2; i<=10; i++)
         if (ss[i] && !mark[i][x]) return false;
     return true;         
}

void work()
{
     int i;
     i = 2;
     while (!judge(i)) i++;     
     printf("%d\n", i);
}
     
int main()
{
    prepare();
    int t, i;
    i = 0;
    scanf("%d", &t);
    while (t--){
          init();
          printf("Case #%d: ", ++i);
          work();
    }
    return 0;
}
