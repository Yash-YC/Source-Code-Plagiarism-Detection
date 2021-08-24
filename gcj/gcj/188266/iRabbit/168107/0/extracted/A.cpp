#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
const int max_number = 11814485;
vector<int> res[11];
int u[max_number + 1];
bool t[max_number + 1][11];

bool happy(int number, int base) {
    int ord = number;
    while (true) {
        if (u[number] == -1) {
            return true;
        }
        if (u[number] == -2) {
            return false;
        }
        int sum = 0;
        while (number > 0) {
            sum += (number % base) * (number % base);
            number /= base;
        }
        if (sum == 1) {
            u[sum] = -1;
            return true;
        }
        if (u[sum] == ord) {
            u[sum] = -2;
            return false;
        }
        u[sum] = ord;
        number = sum;
    }
}

char s[10000];

int main()
{
    freopen("A-test.in", "r", stdin);
    freopen("A-test.out", "w", stdout);
    memset(t, false, sizeof t);
    for (int base = 2; base <= 10; base++) {
        memset(u, 0, sizeof u);
        //printf("%d\n", base);
        for (int i = 2; i <= max_number; i++) {
            if (happy(i, base)) {
                t[i][base] = true;
            }
        }
//        printf("%d\n", t[max_number][base]);
    }
    vector<int> ibase;
    int caseT;
    scanf("%d", &caseT);
    int temp;
    char ch;
    for (int caseN = 1; caseN <= caseT; caseN++) {
        ibase.clear();
        while (true) {
            scanf("%d%ch", &temp, &ch);
            ibase.push_back(temp);
            if (ch == '\n') {
                break;
            }
        }
        bool flag;
        for (int i = 2; i <= max_number; i++) {
            flag = true;
            for (int j = 0; j < (int)ibase.size(); j++) {
                if (!t[i][ibase[j]]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                printf("Case #%d: %d\n", caseN, i);
                break;
            }
        }
    }
    return 0;
}
