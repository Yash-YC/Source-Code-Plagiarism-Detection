#include <iostream>
#include <sstream>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <fstream>
#include <vector>

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define FR(i,a) for(int i = 0; i < (a); ++i)

#define FILENAME "input"
static const char* c_pszInFileName = FILENAME ".in";
static const char* c_pszOutFileName = FILENAME ".out";

using namespace std;

template<class T>
void GetLine(ifstream& ifs, T& t) {
    string line;
    getline(ifs, line);
    stringstream(line) >> t;
}

enum {
    NO = 0,
    YES,
    MRK
};
map<pair<int, int>, short> mp;
typedef map<pair<int, int>, short>::iterator mit;

bool works(int nBase, int num, int depth = 0) {
    mit it;
    // FR(i, depth) cout << "  ";
    pair<int, int> pr = make_pair(nBase, num);

    // cout << "works(" << nBase << ", " << num << ")" << endl;
    if (num == 1) {
        mp[pr] = YES;
        // cout << "\tmade(" << nBase << ", " << num << "): " << mp[make_pair(nBase, num)] << endl;
        return true;
    }

    if((it = mp.find(pr)) != mp.end()) {
        // cout << "\tfound(" << nBase << ", " << num << "): " << it->second << endl;
        switch(it->second) {
        case MRK:
            mp[pr] = NO;
        case NO:
            return false;
        default:
            return true;
        }
    } else {
        mp[pr] = MRK;
        // mp.insert(make_pair(make_pair(nBase, num), short(MRK)));
    }
    int cnt = 0;
    int tmp = num;
    while(tmp) {
        int cur = (tmp % nBase);
        cnt += (cur * cur);
        tmp /= nBase;
    }
    bool fWorks = works(nBase, cnt, depth + 1);

    mp[pr] = fWorks ? YES : NO;
    it = mp.find(pr);
    // cout << "\tmade(" << nBase << ", " << num << "): " << it->second << endl;
    return fWorks;
}

ostream& operator<< (ostream& os, pair<int, int> const& p){
    return os << p.first << ", " << p.second;
}

int main() {
    ifstream ifs(c_pszInFileName);
    ofstream ofs(c_pszOutFileName);
    FILE* pFile = fopen(c_pszOutFileName, "w");

    int N;
    GetLine(ifs, N);
    
    // cout << works(2, 7) << endl;
    // return 0;

    FR(t, N) {
        string str;
        getline(ifs, str);
        istringstream iss(str);
        vector<int> rgBases;
        while(iss.good()) {
            int x;
            iss >> x;
            rgBases.push_back(x);
        }
        
        int i = 2;
        while(true) {
            // cout << "i: " << i << endl;
            mit it;
            FR(j, rgBases.size()) {
                if((it = mp.find(make_pair(rgBases[j], i))) != mp.end()) {
                    // cout << "mp[" << it->first << "]: " << it->second << endl;
                    if(it->second == NO)
                        goto No;
                } else {
                    bool fWorks = works(rgBases[j], i);
                    mp.insert(make_pair(make_pair(rgBases[j], i), short(fWorks ? YES : NO)));
                    if (!fWorks)
                        goto No;
                }
            }
            goto Done;
        No:
            ++i;
        }
    Done:

        fprintf(pFile, "Case #%d: %d\n", t+1, i);
    }
    fclose(pFile);
}
