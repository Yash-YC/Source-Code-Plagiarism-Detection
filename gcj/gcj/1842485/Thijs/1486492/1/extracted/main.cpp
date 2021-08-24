#include <vector>
#include <string>
#include <algorithm>

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

typedef vector<int> ret_t;
typedef long long ll;

class Solver {
public:
    ret_t ret;
    int n;
    vector<int> see;
    bool pos;
    void interval(int a, int b, int rc) {
        if (a + 1 >= b)
            return;
        for (int i = a + 1; i < b; ++i) {
            if (see[i] <= i || see[i] > b) {
                cerr << "["<<a<<','<<b<<"] = fail"<<endl;
                pos = false;
                return;
            }
        }
        //int at = b - 1;
        //ret[at] = ret[b] + rc;
        int at = b;
        for (int i = a + 1; i < at; ++i) {
            if (see[i] == at) {
                cerr << "["<<a<<','<<b<<"] = "<<i<<endl;
                ret[i] = ret[b] + rc * (b - i);
                interval(a, i, rc);
                interval(i, b, rc - 1);
                return;
            }
        }
        pos = false;
        cerr << "Failed by reaching end" << endl;
        /*do {
            for (int i = a + 1; i < at; ++i) {
                if (see[i] == at) {
                    ret[i] = ret[b] + rc * (b - i);
                    at = i;
                    break;
                }
            }
        } while (at > a + 1);*/
    }
    ret_t solve(int n_, vector<int> see_) {
        pos = true;
        n = n_;
        see = see_;
        ret = vector<int>(n + 1, -1);
        ret[n] = 0;
        interval(0, n, 1E9 / (n - 1));
        return pos ? ret : vector<int>(0);
    }
};

int main(int argc, char ** argv) {
    ifstream fin;
    ofstream fout;
    if (argc > 1) {
        fin.open(argv[1]);
        string fname(argv[1]);
        //fname.insert(fname.rfind('.'), "_out");
        fname.replace(fname.size() - 2, 2, "out");
        cerr << "Writing output to file " << fname << endl;
        fout.open(fname.c_str());
    }
    else {
        fin.open("test.txt");
    }
    ostream & retout = (argc > 1) ? fout : cout;

    string s;
    int NO;
    getline(fin, s);
    {
        stringstream A(s);
        A >> NO;
    }
    for (int no = 1; no <= NO; ++no) {
        cerr << "Case " << no << " / " << NO << endl;
        Solver solver;
        // *** get input ***
        getline(fin, s);
        int N;

        stringstream A(s);
        A >> N;
        vector<int> see(N, -1);
        getline(fin, s);
        stringstream B(s);
        for (int i = 1; i < N; ++i)
            B >> see[i];

        ret_t ret = solver.solve(N, see);

        // *** give output ***
        retout << "Case #" << no << ":";
        if (ret.size() > 0) {
            for (int i = 1; i <= N; ++i)
                retout << ' ' << ret[i];
            retout << endl;
        }
        else {
            retout << " Impossible" << endl;
        }
        //retout << "Case #" << no << ":\n" << ret; // multi-line
        //retout << "Case #" << no << ": " << fixed << setprecision(7) << ret << endl; // float
    }
    if (argc > 1) {
        cerr << "Press <Enter> to continue...";
        getline(cin, s);
    }
    return 0;
}
