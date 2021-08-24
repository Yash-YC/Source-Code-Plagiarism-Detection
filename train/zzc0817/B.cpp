#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;



int main()
{
    int T;
    scanf("%d", &T);
    for(int ca = 1; ca <= T; ++ca)
    {
        int N;
        scanf("%d", &N);
        vector<int> inp[2*N-1];
        for(int i = 0; i < 2*N-1; ++i)
            inp[i].resize(N);
        for(int i = 0; i < 2*N-1; ++i)
        {
            for(int j = 0; j < N; ++j)
            {
                int t;
                scanf("%d", &t);
                inp[i][j] = t;
            }
        }
        sort(inp, inp+2*N-1);

        int diag[N] = {0};
        int mis = -1;
        vector<int> grp[N][2];
        int mask2[2*N-1] = {0};
        for(int idx = 0; idx < N; ++idx)
        {
            int first = -1, second = -1;
            for(int i = 0; i < 2*N-1; ++i)
            {
                if(mask2[i]) continue;
                if(first == -1 || inp[i][idx] < inp[first][idx])
                {
                    first = i;
                    second = -1;
                    continue;
                }
                if(inp[i][idx] == inp[first][idx])
                {
                    second = i;
                    continue;
                }
            }
            diag[idx] = inp[first][idx];
            if(second == -1)
            {
                mis = idx;
                grp[idx][0] = grp[idx][1] = inp[first];
                mask2[first] = 1;
            }
            else
            {
                grp[idx][0] = inp[first];
                grp[idx][1] = inp[second];
                mask2[first] = mask2[second] = 1;
            }
        }

        vector<int> ans[N];
        for(int i = 0; i < N; ++i)
            ans[i].resize(N);
        ans[mis] = grp[mis][0];
        for(int j = 0; j < N; ++j)
            ans[j][mis] = grp[mis][0][j];
        int mask[N] = {0};
        mask[mis] = 1;
        for(int i = 0; i < N; ++i)
            ans[mis][i] = ans[i][mis];
        bool found = true;
        while(found)
        {
            found = false;
            for(int i = 0; i < N; ++i)
            {
                if(mask[i]) continue;
                if(grp[i][0] == grp[i][1])
                {
                    ans[i] = grp[i][0];
                    for(int j = 0; j < N; ++j)
                        ans[j][i] = grp[i][1][j];
                    mask[i] = 1;
                    found= true;
                    continue;
                }
                if(grp[i][0][mis] != grp[i][1][mis])
                {
                    if(grp[i][0][mis] == grp[mis][0][i])
                    {
                        ans[i] = grp[i][1];
                        for(int j = 0; j < N; ++j)
                            ans[j][i] = grp[i][0][j];
                    }
                    else
                    {
                        ans[i] = grp[i][0];
                        for(int j = 0; j < N; ++j)
                            ans[j][i] = grp[i][1][j];
                    }
                    mask[i] = 1;
                    found = true;
                    continue;
                }
            }
        }
        printf("Case #%d:", ca);
        for(int j = 0; j < N; ++j)
            printf(" %d", ans[j][mis]);
        printf("\n");

    }
}
