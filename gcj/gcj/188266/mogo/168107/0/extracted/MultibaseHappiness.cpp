#include <iostream>


using namespace std;

int getsum(int x, int b)
{
    int result = 0;
    while(x>0)
    {
        int d = x % b;
        result += d*d;
        x/=b;
    }
    return result;
}

const int MAXSTORE=10000;

bool visited[MAXSTORE];
int happy[11][MAXSTORE];
int vislist[MAXSTORE];
int bases[10];

int main()
{
    //cout<<"Hello world";
    FILE* in = freopen("A-small-attempt0.in", "r", stdin);
    FILE* out = freopen("A-small-attempt0.out", "w+", stdout);


    //int b = 10;
    memset(happy, 0, sizeof(happy));

    int tests;
    int bc;
    cin>>tests;
    char c;
    scanf("%c", &c);

    for(int t = 1; t<=tests;++t)
    {
        memset(bases, 0, sizeof(bases));
        bc = 0;
        while(c<'0' || c >'9')
        {
            scanf("%c", &c);
        }

        while(true)
        {
            while(c>='0' && c<='9')
            {
                bases[bc] *= 10;
                bases[bc] += c-'0';
                scanf("%c", &c);
            }
            bc++;
            while((c<'0' || c >'9')&& ! feof(in))
            {
                if('\n' == c)
                    break;
                scanf("%c", &c);
            }
            if('\n' == c || feof(in))
                break;
        }


        for(int i=2;i<100000;i++)
        {
            int hc = 0;
            for(int k=0;k<bc;k++)
            {
                memset(visited, 0, sizeof(visited));
                int n = i;
                int vc = 0;
                if(n<MAXSTORE)
                {
                    if(1 == happy[bases[k]][n])
                    {
                        hc++;
                        //cout<<n<<" - happy\n";
                        continue;
                    }
                    else if (0 != happy[bases[k]][n])
                    {
                        //cout<<n<<" - unhappy :(\n";
                        continue;
                    }
                }
                while(n != 1)
                {
                    //cout<<n;
                    //cout<<" -> ";
                    if(n<MAXSTORE && visited[n])
                        break;
                    if(n<MAXSTORE && 0!=happy[bases[k]][n])
                    {
                        n = happy[bases[k]][n];
                        break;
                    }
                    if(n<MAXSTORE)
                    {
                        visited[n] = true;
                        vislist[vc++] = n;
                    }
                    n = getsum(n,bases[k]);
                }
                for(int j=0;j<vc;j++)
                {
                    if(vislist[j]<MAXSTORE)
                        happy[bases[k]][vislist[j]] = n;
                }
                if(1 == n)
                {
                    //cout<<" - happy\n";
                    hc++;
                }
                else
                {
                    //cout<<" - unhappy :(\n";
                }
            }
            if(bc==hc)
            {
                cout<<"Case #"<<t<<": "<<i<<"\n";
                break;
            }

        }
    }
}
