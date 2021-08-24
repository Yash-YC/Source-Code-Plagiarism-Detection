#include <iostream>
#include <vector>
using namespace std;

const int N = 10;

int next[N][13] = {0};

vector<int> change(int x, int b)
{
    //printf("x = %d b = %d\n", x, b);
    vector<int> v;
    while(x)
    {
        v.push_back(x % b);
        x /= b;
    }    
    //for(int i = 0; i < v.size(); i++)   printf("%d ", v[i]); printf("\n");
    return v;
}

void check( vector<int> v, int b, int x)
{
    //printf("x = %d b = %d\n", x, b);
    int mid = 0;
    for(int i = 0; i < v.size(); i++)
    {
        mid += v[i] * v[i];
    } 
    char s[333];
    sprintf(s, "%d", mid);
          
    printf("mid = %d\n", mid); 
               
    mid = 0;
    int k = 1;
    
    for(int i = strlen(s)-1; i >= 0; i--)
    {
        printf("%d ", s[i] - '0');
        mid += k * (s[i] - '0');
        k *= b;    
    }
    
    printf("\n%d %d %d\n", x, b, mid);
    next[x][b] = mid;
}

void cal(int x)
{
    for(int i = 2; i <= N; i++)
    {
        check(change(i, x), x, i);
    }
}

vector<int> res[13];

int ans[N][13];

int head;
bool f;

bool check(int b, int x)
{
    printf("b = %d x = %d\n", b, x); getchar();
    if(ans[x][b] != -1) return ans[x][b];
    
    printf("next = %d\n", next[x][b]);
    
    if(next[x][b] == 1) return ans[x][b] = 1;
    if(x == head) 
    {
        if(!f) f = 1;
        else return ans[x][b] = 0;
    }
    else return ans[x][b] = check(b, next[x][b]);
}

int main()
{
    memset(ans, -1, sizeof(ans));
    for(int i = 8; i <= 8; i++)
    {
        cal(i);
    }    
    
    for(int i = 1; i <= 10; i++)
    {
        for(int j = 1; j <= 10; j++)
        {
                printf("%d ", next[i][j]);    
        }    
        printf("\n");
    }
    
    /*for(int i = 2; i <= 10; i++)
    {
        for(int j = 2; j < 10; j++)
        {
            head = j;
            f = 0;
            if(check(i, j))
            {
                printf("%d %d\n" ,i ,j);
                res[i].push_back(j); 
            }   
        }    
    }*/
    
    while(1);
}
