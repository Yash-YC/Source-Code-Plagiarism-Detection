#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

typedef bool ret_t;
typedef long long ll;

class Solver {
public:
    ret_t solve(int n, int D, vector<int> d, vector<int> len) {
        vector<int> lo(n, 0);
        lo[0] = d[0];
        bool ret = false;
        if (lo[0] >= D - d[0])
            ret = true;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (lo[j] >= d[i] - d[j]) {
                    lo[i] = max(lo[i], min(len[i], d[i] - d[j]));
                }
            }
            if (lo[i] >= D - d[i])
                ret = true;
        }
        return ret;
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
        int N, D;
        stringstream A(s);
        A >> N;
        vector<int> d(N), len(N);
        for (int i = 0; i < N; ++i) {
            getline(fin, s);
            stringstream A(s);
            A >> d[i] >> len[i];
        }
        getline(fin, s);
        stringstream B(s);
        B >> D;

        ret_t ret = solver.solve(N, D, d, len);

        // *** give output ***
        retout << "Case #" << no << ": " << (ret ? "YES" : "NO") << endl; // one line
        //retout << "Case #" << no << ":\n" << ret; // multi-line
        //retout << "Case #" << no << ": " << fixed << setprecision(7) << ret << endl; // float
    }
    if (argc > 1) {
        cerr << "Press <Enter> to continue...";
        getline(cin, s);
    }
    return 0;
}
