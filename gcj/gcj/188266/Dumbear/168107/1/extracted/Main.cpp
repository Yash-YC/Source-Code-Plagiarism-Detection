#include <cstdio>

using namespace std;

int num_min[1 << 9];

int main() {
    FILE* fin = fopen("table.txt", "r");
    int a, b;
    while (fscanf(fin, "%d%d", &a, &b) != EOF)
        num_min[a] = b;
    fclose(fin);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        int state = 0, num;
        char tmp;
        while (scanf("%d%c", &num, &tmp) != EOF) {
            state += 1 << (num - 2);
            if (tmp == '\n')
                break;
        }
        printf("Case #%d: %d\n", i + 1, num_min[state]);
    }
    return 0;
}
