#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

typedef struct
{
    int S,W,T;
}corner;

corner R[25][25];
int G[50][50];
int N,M;

void gg(int a,int b,int t)
{
    int x,y,z,c;
    
    if(a == 0 && b == M * 2 - 1);
    else
    {
        //go up
        if(a > 0)
        {
            if(a % 2 == 0) //jalan
            {
                if(G[a - 1][b] > t + 2)
                {
                    G[a - 1][b] = t + 2;
                    gg(a - 1,b,t + 2);
                }
            }
            else //nyebrang
            {
                x = R[a / 2][b / 2].T;
                y = R[a / 2][b / 2].S;
                z = R[a / 2][b / 2].W;
                while(x < t)
                    x += y + z;
                if(x > t)
                    x -= y + z;
                
                if(x + y > t) //go
                {
                    if(G[a - 1][b] > t + 1)
                    {
                        G[a - 1][b] = t + 1;
                        gg(a - 1,b,t + 1);
                    }
                }
                else //wait
                {
                    x += y + z;
                    c = x - t;
                    c++;
                    if(G[a - 1][b] > t + c)
                    {
                        G[a - 1][b] = t + c;
                        gg(a - 1,b,t + c);
                    }
                }
            }
        }
        
        //go down
        if(a < N * 2 - 1)
        {
            if(a % 2 == 1) //jalan
            {
                if(G[a + 1][b] > t + 2)
                {
                    G[a + 1][b] = t + 2;
                    gg(a + 1,b,t + 2);
                }
            }
            else //nyebrang
            {
                x = R[a / 2][b / 2].T;
                y = R[a / 2][b / 2].S;
                z = R[a / 2][b / 2].W;
                while(x < t)
                    x += y + z;
                if(x > t)
                    x -= y + z;
                
                if(x + y > t) //go
                {
                    if(G[a + 1][b] > t + 1)
                    {
                        G[a + 1][b] = t + 1;
                        gg(a + 1,b,t + 1);
                    }
                }
                else //wait
                {
                    x += y + z;
                    c = x - t;
                    c++;
                    if(G[a + 1][b] > t + c)
                    {
                        G[a + 1][b] = t + c;
                        gg(a + 1,b,t + c);
                    }
                }
            }   
        }
        
        //go left
        if(b > 0)
        {
            if(b % 2 == 0) //jalan
            {
                if(G[a][b - 1] > t + 2)
                {
                    G[a][b - 1] = t + 2;
                    gg(a,b - 1,t + 2);
                }
            }
            else //nyebrang
            {
                x = R[a / 2][b / 2].T;
                y = R[a / 2][b / 2].S;
                z = R[a / 2][b / 2].W;
                while(x < t)
                    x += y + z;
                if(x > t)
                    x -= y + z;
                
                if(x + y + z > t && x + y < t) //go
                {
                    if(G[a][b - 1] > t + 1)
                    {
                        G[a][b - 1] = t + 1;
                        gg(a,b - 1,t + 1);
                    }
                }
                else //wait
                {
                    x += y;
                    c = x - t;
                    c++;
                    
                    if(G[a][b - 1] > t + c)
                    {
                        G[a][b - 1] = t + c;
                        gg(a,b - 1,t + c);
                    }
                }
            }
        }
        
        //go right
        if(b < M * 2 - 1)
        {
            if(b % 2 == 1) //jalan
            {
                if(G[a][b + 1] > t + 2)
                {
                    G[a][b + 1] = t + 2;
                    gg(a,b + 1,t + 2);
                }
            }
            else //nyebrang
            {
                x = R[a / 2][b / 2].T;
                y = R[a / 2][b / 2].S;
                z = R[a / 2][b / 2].W;
                while(x < t)
                    x += y + z;
                if(x > t)
                    x -= y + z;
                
                if(x + y + z > t && x + y < t) //go
                {
                    if(G[a][b + 1] > t + 1)
                    {
                        G[a][b + 1] = t + 1;
                        gg(a,b + 1,t + 1);
                    }
                }
                else //wait
                {
                    x += y;
                    c = x - t;
                    c++;
                    
                    if(G[a][b + 1] > t + c)
                    {
                        G[a][b + 1] = t + c;
                        gg(a,b + 1,t + c);
                    }
                }
            }
        }
    }
}

int main()
{
    int ncase,ccase;
    int x,y,z;
    int a,b,c;
    
    cin >> ncase;
    for(ccase = 1;ccase <= ncase;ccase++)
    {
        cin >> N >> M;
        for(x = 0;x < N;x++)
        {
            for(y = 0;y < M;y++)
            {
                cin >> a >> b >> c;
                c %= (a + b);
                if(c > 0) c -= (a + b);
                R[x][y].S = a;
                R[x][y].W = b;
                R[x][y].T = c;
            }
        }
        
        for(x = 0;x < N * 2;x++)
        {
            for(y = 0;y < M * 2;y++)
                G[x][y] = 1000000;
        }
        
        //start from G[N * 2 - 1][0]
        //goal G[0][M * 2 - 1]
        G[N * 2 - 1][0] = 0;
        gg(N * 2 - 1,0,0);
        cout << "Case #" << ccase << ": " << G[0][M * 2 - 1] << endl;
    }
    
    while(getchar()!=EOF);
    return 0;
}
