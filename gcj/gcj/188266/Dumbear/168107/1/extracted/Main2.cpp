#include <cstdio>
#include <vector>
#include <set>

using namespace std;

int num_min[1 << 9];

int get_min_num(int);
bool happy(int, int);

int main() {
    freopen("table.txt", "w", stdout);
    num_min[0] = 2;
    for (int i = 1; i < (1 << 9); ++i)
        printf("%d %d\n", i, get_min_num(i));
    return 0;
}

int get_min_num(int state) {
    vector<int> base;
    for (int i = 0; (state >> i) != 0; ++i)
        if (((state >> i) & 1) == 1)
            base.push_back(i + 2);
    for (int i = num_min[state - (state & -state)]; ; ++i) {
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
