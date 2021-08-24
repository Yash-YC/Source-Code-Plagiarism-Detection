#include<iostream>
using namespace std;
#include<vector>
vector<int>adj[20];

int data[30],size;
const int MAXN = 63000;
bool visited[MAXN * 10];
bool bad[MAXN];
//bool ok[MAXN];
int base;
vector<int>temp;
bool in[11][MAXN * 2];
vector<int>order;
int fun(int val,int base)
{
    int tmp;
    int sum = 0;
    size = 0;
    while(val)
    {
          tmp = val % base;
          val /= base;
         data[size++] = tmp;
    }
    
    for(int i = 0;i < size;i++)
     sum += data[i] * data[i];
   
   return sum;     
}    
int main()
{
    int i,J,k;
    int tmp;
    freopen("A.txt","w",stdout);
    for(base = 2;base <= 10;base++)
    {
       // printf("base = %d\n",base);
        if(base == 2 || base == 4) continue;
        memset(bad,false,sizeof(bad));
        for(i = 2;i <= MAXN;i++)
        {
        // if(ok[i])
        // adj[base].push_back(i);
         
        // else 
         if(bad[i] == false)
         {
            tmp = i;
            temp.clear();
          //  printf("i = %d",i);
            memset(visited,false,sizeof(visited));
            while(visited[tmp] == false)
            {
                  visited[tmp] = true;
                //  printf("tmp = %d ",tmp);
                  int t = fun(tmp,base);
                //  printf("tmp = %d\n",tmp);
              // if(t >= tmp) break; 
               tmp = t;
              // temp.push_back(t);
               if(tmp == 1) break;
               if(tmp >= MAXN * 10) break;
            }
           if(tmp == 1)
           {
           adj[base].push_back(i);
           in[base][i] = true;
           
           }
           else
           {
               for(J = 0;J < temp.size();J++)
                bad[temp[J]] = true;
           }
              
         }
        }
    }
    /*
    for(i = 2;i <= 3;i++)
    {
        printf("%d\n",adj[i].size());
       
    }             
    */
    
    int ncase;
    char str[1000];
    int casenum = 1;
    scanf("%d",&ncase);
    while(ncase--)
    {
          scanf("\n");
          gets(str);
          int len = strlen(str),val;
          order.clear();
          for(i = 0;i < len;i++)
           if(isdigit(str[i]))
           {
              val = 0;
              while(i < len && isdigit(str[i]))
              {
                    val = val * 10 + str[i] - '0';
                  i++;
              }
            if(val != 2 && val != 4)
            order.push_back(val);
           }
          if(order.size() == 0)
          {
             //printf("2\n");
             printf("Case #%d: %d\n",casenum++,2);
             continue;
          }
          int ans = -1;
          for(J = 0;J < adj[order[0]].size();J++)
          {
              bool flag = true;
              for(k = 1;k < order.size();k++)
               if(in[order[k]][adj[order[0]][J]] == false)
               {
                  flag = false;
                  break;
               }
              
              if(flag)
              {                                  
                 ans = adj[order[0]][J];
                 break;
              }  
           }
           printf("Case #%d: %d\n",casenum++,ans);
    }           
      
                       
   // system("pause");               
             
    return 0;
}
