#include <cstdio>
#include <algorithm>
#include <cstring>
using std::lower_bound;

const int MAX_L = 1000000;
const int COUNT = 10;

int list[20][MAX_L * 4];
int num[20];
char buf[1000];

inline int sqr(int x) {
    return x * x;
}

bool is_happy(int x, int base) {
    int len, sum, count;
    
    //if (x == 91 && base == 9)
    //    printf("..\n");
    count = 0;
    do {
        len = 0;
        sum = 0;
        while (x != 0) {
            sum += sqr(x % base);
            x /= base;
            len++;
        }
        x = sum;
        count++;
    } while (sum != 1 && count < COUNT);
    return sum == 1;
}

int main() {
    int i, j, t, T, curr, n, x, y;
    int b[20];
    bool flag;
    char* pos;
    for (i = 3; i <= 10; i++) {
        if (i == 4) continue;
        curr = 0;
        for (j = 2; j < MAX_L * 13; j++) {
            //if (i == 3)
            //    fprintf(stderr, "j = %d\n", j);
            if (is_happy(j, i)) {
                list[i][curr++] = j;
            }
        }
        num[i] = curr;
        fprintf(stderr, "i = %d, num = %d\n", i, curr);
    }
    num[2] = num[4] = 1;
    list[2][0] = list[4][0] = 2;
    fprintf(stderr, "go!\n");
    scanf("%d ", &T);
    for (t = 1; t <= T; t++) {
        fgets(buf, sizeof(buf), stdin);
        for (pos = buf, n = 0; pos != NULL; n++, pos = strchr(pos + 1, ' ')) {
            sscanf(pos, "%d", &b[n]);
            if (b[n] == 2 || b[n] == 4)
                n--;
        }
        if (n != 0)
        for (i = 0; i < num[b[n - 1]]; i++) {
            x = list[b[n - 1]][i];
            flag = true;
            for (j = n - 2; j >= 0; j--) {
                //if (b[j] == 4 || b[j] == 2)
                //    continue;
                y = lower_bound(list[b[j]], list[b[j]] + num[b[j]], x) - list[b[j]];
                if (list[b[j]][y] != x) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                break;
        }
        if (n == 0) {
            flag = true;
            // modify by hand
            x = -1;
        }
        if (!flag)
            printf("err!!\n");
        else
            printf("Case #%d: %d\n", t, x);
    }
}
