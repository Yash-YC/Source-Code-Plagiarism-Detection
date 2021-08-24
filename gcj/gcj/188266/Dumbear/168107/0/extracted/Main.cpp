#include <cstdio>
#include <vector>
#include <set>

using namespace std;

int num_min[1 << 9];

int get_min_num(int);
bool happy(int, int);

int main() {
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
        printf("Case #%d: %d\n", i + 1, get_min_num(state));
    }
    return 0;
}

int get_min_num(int state) {
    vector<int> base;
    for (int i = 0; (state >> i) != 0; ++i)
        if (((state >> i) & 1) == 1)
            base.push_back(i + 2);
    for (int i = 2; ; ++i) {
        bool valid = true;
        for (vector<int>::iterator j = base.begin(); j != base.end(); ++j) {
            if (!happy(i, *j)) {
                valid = false;
                break;
            }
        }
        if (valid)
            return num_min[state] = i;
    }
    return -1;
}

bool happy(int num, int base) {
    set<int> s;
    s.insert(num);
    while (true) {
        int next = 0;
        for (; num != 0; num /= base)
            next += (num % base) * (num % base);
        if (next == 1)
            return true;
        if (s.find(next) != s.end())
            return false;
        s.insert(num = next);
    }
}
