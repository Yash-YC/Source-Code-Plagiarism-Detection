#include <iostream>
#include <set>

using namespace std;

void do_testcase() {
    int horiz;
    int vert;
    cin >> horiz;
    cin >> vert;

    int intersections [5] [5] [3];
    for (int i = 0; i < horiz; i++) {
        for (int j = 0; j < vert; j++) {
           cin >> intersections [i] [j] [0];
           cin >> intersections [i] [j] [1];
           cin >> intersections [i] [j] [2];
        }
    }

    set<std::pair<int, int> > untouched;
    std::pair<int, int> start(0, 0);
    untouched.insert(start);

    int cost [10] [10];
    for (int i = 0 ; i < 10; i++) {
        for (int j =0 ; j < 10; j++) {
            cost [i] [j] = -1;
        }
        }
    cost [0] [0] = 0;

    while (untouched.size() > 0) {
        set<std::pair<int, int> >::iterator it = untouched.begin();
        std::pair<int, int> myloc = *it;
        untouched.erase(it);

        int mycost = cost [myloc.first] [myloc.second];

        cerr << "AT: " << myloc.first << "," << myloc.second << endl;
        cerr << "COST: " << mycost << endl;

        int cost_ns;
        int cost_ew;

        int real_hor = myloc.first / 2;
        int real_ver = myloc.second / 2;

        int s = intersections [real_hor] [real_ver] [0];
        int w = intersections [real_hor] [real_ver] [1];
        int t = intersections [real_hor] [real_ver] [2];

        if (t == 0 || (s + w) == 0) {
             continue; } 

        int cycle_base = (mycost % t) % (s + w);
        if (cycle_base < s) {
            // Can immediately do ns
            cost_ns = 1;
            cost_ew = (s - cycle_base) + 1;
        } else {
            // Can immediately do ew
            cost_ew = 1;
            cost_ns = (s + w - cycle_base) + 1;
        }

        for (int j = 0; j < 4; j++) {
            int dx;
            int dy;
            bool ns = false;
            switch (j) {
                case 0: ns= true;dx = 0; dy = -1; break;
                case 1: ns= true;dx = 0; dy = 1; break;
                case 2: dx = -1; dy = 0; break;
                case 3: dx = 1; dy = 0; break;
            }

            int new_h = myloc.first + dx;
            int new_v = myloc.second + dy;
            if (new_h < 0 || new_h >= (horiz * 2)) {
                continue;
            }

            if (new_v < 0 || new_v >= (vert * 2)) {
                continue;
            }

            int tcost = (ns ? cost_ns : cost_ew) + mycost;
            cerr << "CURRENT COST AT " << new_h << "," << new_v << " IS  " << cost [new_h] [new_v] << endl;
            cerr << "TRIAL: " << tcost << endl;
            if (cost [new_h] [new_v] == -1 || tcost < cost [new_h] [new_v]) {
                cerr << "UPDATING COST AT " << new_h << "," << new_v << " TO " << tcost << endl;    

                cost [new_h] [new_v] = tcost;
                pair<int, int> new_pt(new_h, new_v);
                untouched.insert(new_pt);
            }
        }
    } 

    cout << cost [horiz  ] [vert];
}

int main(int argc, char **argv) {
    int buffer;
    cin >> buffer;

    for (int i = 1; i <= buffer; i++){ 
        cout << "Case #" << i << ": ";
        do_testcase();
        cout << endl;
    }
}
