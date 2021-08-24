#include <iostream>
using namespace std;

const int infi=600000;
int p[40], base[40];
char ch[100];
bool f[infi][11];
bool flag=false;
bool used[infi];
void dfs(int a, int b)
{
    int temp=0;
    int sum;
    
    if (f[a][b])
    {
        flag=true;
        return;
    }
    if (used[a] && !f[a][b])
    {
        return;
    }
    else
    {
        temp=a;
        used[a]=true;
        memset(p, 0, sizeof(p));
        while (temp!=0)
        {
            p[++p[0]]= temp%b;
            temp/=b;
        }
        sum=0;
        for (int i=1; i<=p[0]; i++)
        {
            sum += p[i]*p[i];
        }
        p[0]=0;
        while (sum!=0)
        {
            p[++p[0]]=sum%b;
            sum/=b;
        }
        temp=1;
        sum=0;
        for (int i=1; i<=p[0]; i++)
        {
            temp*=b;
            sum+=p[i]*temp/b;
        }
        if (sum>infi) 
        {
            flag=false;
            return;
        }
        dfs(sum, b);
        f[a][b]=flag;
    }
}
void work(int b)
{
    int temp , sum=0;
    
    memset(used, 0, sizeof(used));
    for (int i=2; i<=infi; i++)
    {
        flag=false;
        dfs(i, b);
    }
}
int main(void)
{
    int t;
    int ans;
    
    freopen("A-small-attempt2.in", "r", stdin);
    freopen("A-small-attempt2.out","w", stdout); 
    for (int i=2; i<=10; i++)
    {
        f[1][i]=true;
        work(i);
    }

    
    cin>>t;
    gets(ch);
    for (int ca=1; ca<=t; ca++)
    {
        gets(ch);
        memset(base, 0, sizeof(base));
        for (int i=0; i<strlen(ch); i++)
        {
            base[0]++;
            while (ch[i]>='0' && ch[i]<='9')
            {
                base[base[0]]=base[base[0]]*10+ch[i]-'0';
                i++;
            }
        }

        flag=false;
        for (int i=2; !flag; i++)
        {
            flag=true;
            for (int j=1; j<=base[0]; j++)
            {
                if (!f[i][base[j]])
                {
                    flag=false;
                    break;
                }
            }
            if (flag) ans=i;
        }
        printf("Case #%d: %d\n", ca, ans);
    }
    
    return 0;
}
