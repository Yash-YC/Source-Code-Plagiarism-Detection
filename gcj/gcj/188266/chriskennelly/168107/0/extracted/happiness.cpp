#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <set>

const static int MAXLIMIT  = 100000;

using namespace std;
        // Base  Previous
int cache [25]  [MAXLIMIT];

bool is_happy(int base, int val) {
    if (val == 1) { return true; }
    assert(val < MAXLIMIT);
    int tmp = val;

    cerr << "-----------";
    cerr << "At " << val << " (on " << base << ")" << endl;

    std::set<int> seen;

    do {
        seen.insert(tmp);
        if (cache [base] [tmp] != -1) {
            tmp = cache [base] [tmp];
        } else {
            // Fill cache
            int power = base;
            while (tmp >= power) {
                power *= base;
            }
            power /= base; 
            int sum = 0;
            int old_tmp = tmp;
            while (tmp != 0) {
                int val_at_digit = tmp / power;
                tmp -= val_at_digit * power;

                sum += val_at_digit * val_at_digit;
                cerr << "DIGIT: " << val_at_digit << endl;

                power /= base;
            }
            assert(sum < MAXLIMIT);
            cache [base] [old_tmp] = sum;
            tmp = sum;
        }

        if (seen.find(tmp) != seen.end()) {
            break;
        }

        cerr << "At " << tmp << endl;
    } while (tmp != 1 && tmp != val);


    cerr << "STOPPED AT: " << tmp << endl;
    cerr << "RETURNING: " << (tmp == 1 ? "TRUE" : "FALSE") << endl;
    return (tmp == 1);
}

void do_testcase() {
    string line;
    std::getline(cin, line);

    stringstream ss;
    ss << line;

    int buffer;
    int bases[50];
    int base_count = 0;

    cerr << "LINE : " << line;

    while (ss >> buffer) {
        bases [base_count] = buffer;
        cerr << "BASE: " << buffer << endl;
        base_count++;
    }

    assert(base_count > 0);

    int trial = 2;
    int stupid = MAXLIMIT;
    while (stupid-- > 0) {
        bool success = true;
        for (int i = 0; i < base_count; i++) {
            cerr << "Trying " << trial << " on " << bases [i] << endl;
            if (!(is_happy(bases [i], trial))) {
                cerr << trial << " not happy on " << bases [i] << endl;
                success = false;
                break;
            }
        }

        if (success) {
            cout << trial;
            return;
        } else {
            cerr << "MOVING NEXT FROM " << trial << endl;
            trial++;
        }
    }

    assert(false);
}

int main (int argc, char **argv) {
    for (int i = 0; i < 25; i++){ 
        for (int j = 0; j < MAXLIMIT; j++) {
            cache [i] [j] = -1;
        }
    }
    int testcases;
    cin >> testcases;
    string dummy;
    getline(cin, dummy);

    for (int i = 1; i <= testcases; i++){ 
        cout << "Case #" << i << ": ";
        do_testcase();
        cout << endl;
    }
}
