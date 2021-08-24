#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
using namespace std;
typedef __int64 LL;
int N, M;
LL S[32][32], W[32][32], T0[32][32];
LL T[32][32][4];

#define QSIZE 131072
struct Node
{
       int y, x, c;
       LL t;
       Node(int a=0, int b=0, int z=0, LL u=0)
       {
           y = a;
           x = b;
           c = z;
           t = u;
       }
}que[QSIZE];


bool IN(Node a)
{
     if(a.x >=1 || a.x <= M || a.y >= 1 || a.y <= N) return true;
     return false;
}

int front, rear;
int To[4][4][3] = {
   { {0, 0, 2},
    {0, 1, 1},
    {1, 0, 2},
    {0, 0, 1} },
    
  {  {0, 0, 3},
    {0, 0, 0},
    {1, 0, 3},
    {0, -1, 0} },
    
  {  {-1, 0, 0},
    {0, 1, 3},
    {0, 0, 0},
    {0, 0, 3} },
    
  {  {-1, 0, 1},
    {0, 0, 2},
    {0, 0, 1},
    {0, -1, 2} }
};
LL GetNextGreen(int y, int x, LL t, int d)
{
    bool s;
    if(d == 0 || d == 2) s = 1;
    else s = 0;
    
    LL dt;
    LL kt;
    if(s)
    {
        dt = t - T0[y][x];
        dt %= (S[y][x] + W[y][x]);
        if(dt < S[y][x]) 
        {
              kt = 0;
        }
        else 
        {
            kt = S[y][x] + W[y][x] - dt;
        }
        
        
    }
    else
    {
        dt = t - T0[y][x];
        dt %= (S[y][x] + W[y][x]);
        
        if(dt >= S[y][x]) 
        {
              kt = 0;
        }
        else 
        {
            kt = S[y][x] - dt;
        }
    }
    return t + kt;
}
bool GetNext(Node c, int d, Node& ne)
{
   /* if(c.x == 1 && (c.c == 0 || c.c == 2) && d == 3) return 0;
    if(c.x == M && (c.c == 1 || c.c == 3) && d == 1) return 0;
    if(c.y == 1 && (c.c == 0 || c.c == 1) && d == 0) return 0;
    if(c.y == N && (c.c == 2 || c.c == 3) && d == 2) return 0;*/
    
    ne.y = c.y + To[c.c][d][0];
    ne.x = c.x + To[c.c][d][1];
    ne.c = To[c.c][d][2];
    /*printf("D: %d\n", d);
    printf("C:%d %d %d\n", c.y, c.x, c.c);
    printf("N:%d %d %d\n", ne.y, ne.x,ne.c);*/
    if(ne.y < 1 || ne.y > N || ne.x < 1 || ne.x > M) return 0;
    
    if(!(ne.y == c.y && ne.x == c.x))
    {
            ne.t = c.t + 2;
            return 1;
    }
    
    ne.t = GetNextGreen(ne.y, ne.x, c.t, d);
    ne.t += 1;
    return 1;
}
LL BFS()
{
    memset(T, 63, sizeof(T));
    front = rear = 0;
    que[rear++] = Node(N, 1, 1, 0);
    T[N][1][1] = 0;
    Node cur;
    Node ne;
    int d;
    while(front != rear)
    {
        cur = que[front++];
        front %= QSIZE;
        
        for(d = 0; d < 4; ++d)
        {
              if(GetNext(cur, d, ne))
              {
                  if(ne.t < T[ne.y][ne.x][ne.c])
                  {
                          T[ne.y][ne.x][ne.c] = ne.t;
                          que[rear++] = ne;
                          rear %= QSIZE;
                  }
              }
              
        }
    }
    return T[1][M][2];
}
int main()
{
    int Case, Case_Num, j, i;
   // while(1);
   freopen("B_Small.in", "r", stdin);
   freopen("B_Small.out", "w", stdout);
    scanf("%d", &Case_Num);
    for(Case = 1; Case <= Case_Num; ++Case)
    {
       scanf("%d%d", &N, &M);  
       for(i = 1; i <= N; ++i)
       {
           for(j =1; j <= M; ++j) 
           {
                 scanf("%I64d%I64d%I64d", &S[i][j], &W[i][j], &T0[i][j]);
                 T0[i][j] -= (S[i][j] + W[i][j]) * 100000000;
           }
       }    
       printf("Case #%d: %I64d\n", Case, BFS());
    }
}
/*
10

1 1
3 2 10

1 2
1 5 3 1 5 2

1 2
1 5 -9 1 5 -10
*/

