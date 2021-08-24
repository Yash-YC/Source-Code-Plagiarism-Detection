#include <iostream>
#include <map>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <stack>
#include <queue>
using namespace std;

const int INF = 1000000000;
typedef pair<int, int> PII;
int main() {
    int k, caso = 1;
    cin >> k;
    while (k--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > S(n, m), W(n, m), T(n, m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> S[i][j] >> W[i][j] >> T[i][j];
            }
        }
        vector<int> dist(n*m*4, INF);
        dist[n*m*4 - m*2] = 0;
        priority_queue<pair<int, int> > Q;
        Q.push(pair<int, int>(0,m*4*n -m*2));
        while (not Q.empty()) {
            pair<int, int> a = Q.top();
            Q.pop();
            a.first *= -1;
            if (a.second%2 == 0) {
                if (a.second - m*2 >= 0  and (a.second/(m*2))%2 == 0 and dist[a.second - m*2] > dist[a.second] + 2) {
                    dist[a.second - m*2] = dist[a.second] + 2;
                    Q.push(PII(-dist[a.second - m*2],a.second - m*2));
                }
                if (a.second + m*2 < dist.size() and (a.second/(m*2))%2 == 1 and dist[a.second + m*2] > dist[a.second] + 2) {
                    dist[a.second + m*2] = dist[a.second] + 2;
                    Q.push(PII(-dist[a.second + m*2],a.second + m*2));
                }
                if ((a.second - 1)/(m*2) == (a.second)/(m*2) and a.second - 1 >= 0 and dist[a.second - 1] > dist[a.second] + 2) {
                    dist[a.second - 1]= dist[a.second] + 2;
                    Q.push(PII(-dist[a.second - 1],a.second - 1));
                }
                int i = a.second/(m*4);
                int j = a.second/2%m;
                int temps = a.first;
                int camb;
                bool vert = false, hor = false;
                if (temps > T[i][j]) {
                    temps -= T[i][j];
                    temps %= (S[i][j] + W[i][j]);
                    if (temps >= S[i][j]) {
                        hor = true;
                        camb = (S[i][j] + W[i][j]) - temps;
                    }
                    else {
                        vert = true;
                        camb = S[i][j]  - temps;
                    }
                }
                else {
                    temps -= T[i][j];
                    temps = (temps%(S[i][j] + W[i][j])+(S[i][j] + W[i][j]))% (S[i][j] + W[i][j]);
                    if (temps >= S[i][j]) {
                        hor = true;
                        camb = (S[i][j] + W[i][j]) - temps;
                    }
                    else {
                        vert = true;
                        camb = S[i][j]  - temps;
                    }
                }
                if (vert) {
                    if (a.second - m*2>=0 and (a.second/(m*2))%2 == 1 and dist[a.second - m*2] > dist[a.second] + 1) {
                        dist[a.second -m*2] = dist[a.second] + 1;
                        Q.push(PII(-dist[a.second - m*2], a.second - m*2));
                    }
                    if (a.second + m*2 >= 0  and (a.second/(m*2))%2 == 0 and dist[a.second + m*2] > dist[a.second] + 1) {
                        dist[a.second +m*2] = dist[a.second] + 1;
                        Q.push(PII(-dist[a.second + m*2],a.second + m*2));
                    }
                    if ((a.second + 1)/(m*2) == (a.second)/(m*2) and a.second + 1 < dist.size() and dist[a.second + 1] > dist[a.second] + 1 + camb) {
                        dist[a.second + 1]= dist[a.second] + 1 + camb;
                        Q.push(PII(-dist[a.second + 1],a.second + 1));
                    }
                }
                if (hor) {
                    if ((a.second + 1)/(m*2) == (a.second)/(m*2) and a.second + 1 < dist.size() and dist[a.second + 1] > dist[a.second] + 1) {
                        dist[a.second + 1]= dist[a.second] + 1;
                        Q.push(PII(-dist[a.second + 1],a.second + 1));
                    }
                    if (a.second - m*2>=0 and (a.second/(m*2))%2 == 1 and dist[a.second - m*2] > dist[a.second] + 1 + camb) {
                        dist[a.second -m*2] = dist[a.second] + 1 + camb;
                        Q.push(PII(-dist[a.second - m*2], a.second - m*2));
                    }
                    if (a.second + m*2 >= 0  and (a.second/(m*2))%2 == 0 and dist[a.second + m*2] > dist[a.second] + 1 + camb) {
                        dist[a.second +m*2] = dist[a.second] + 1 + camb;
                       Q.push(PII(-dist[a.second + m*2],a.second + m*2));
                    }
                }
            }
            else if (a.second%2 == 1) {
                if ((a.second + 1)/(m*2) == (a.second)/(m*2) and a.second + 1 < dist.size() and dist[a.second + 1] > dist[a.second] + 2) {
                    dist[a.second + 1]= dist[a.second] + 2;
                    Q.push(PII(-dist[a.second + 1],a.second + 1));
                }
                if (a.second - m*2 >= 0  and (a.second/(m*2))%2 == 0 and dist[a.second - m*2] > dist[a.second] + 2) {
                    dist[a.second - m*2] = dist[a.second] + 2;
                    Q.push(PII(-dist[a.second - m*2], a.second - m*2));
                }
                if (a.second + m*2 < dist.size() and (a.second/(m*2))%2 == 1 and dist[a.second + m*2] > dist[a.second] + 2) {
                    dist[a.second + m*2] = dist[a.second] + 2;
                    Q.push(PII(-dist[a.second + m*2],a.second + m*2));
                }
                int i = a.second/(m*4);
                int j = a.second/2%m;
                int temps = a.first;
                int camb;
                bool vert = false, hor = false;
                if (temps > T[i][j]) {
                    temps -= T[i][j];
                    temps %= (S[i][j] + W[i][j]);
                    if (temps >= S[i][j]) {
                        hor = true;
                        camb = (S[i][j] + W[i][j]) - temps;
                    }
                    else {
                        vert = true;
                        camb = S[i][j]  - temps;
                    }
                }
                else {
                    temps -= T[i][j];
                    temps = (temps%(S[i][j] + W[i][j])+(S[i][j] + W[i][j]))% (S[i][j] + W[i][j]);
                    if (temps >= S[i][j]) {
                        hor = true;
                        camb = (S[i][j] + W[i][j]) - temps;
                    }
                    else {
                        vert = true;
                        camb = S[i][j]  - temps;
                    }
                }
                if (vert) {
                    if (a.second - m*2>=0 and (a.second/(m*2))%2 == 1 and dist[a.second - m*2] > dist[a.second] + 1) {
                        dist[a.second -m*2] = dist[a.second] + 1;
                        Q.push(PII(-dist[a.second -m*2],a.second - m*2));
                    }
                    if (a.second + m*2 >= 0  and (a.second/(m*2))%2 == 0 and dist[a.second + m*2] > dist[a.second] + 1) {
                        dist[a.second +m*2] = dist[a.second] + 1;
                        Q.push(PII(-dist[a.second + m*2],a.second + m*2));
                    }
                    if ((a.second - 1)/(m*2) == (a.second)/(m*2) and a.second - 1 >= 0 and dist[a.second - 1] > dist[a.second] + 1 + camb) {
                    dist[a.second - 1]= dist[a.second] + 1 + camb;
                    Q.push(PII(-dist[a.second - 1],a.second - 1));
                }
                }
                if (hor) {
                   if ((a.second - 1)/(m*2) == (a.second)/(m*2) and a.second - 1 >= 0 and dist[a.second - 1] > dist[a.second] + 1) {
                    dist[a.second - 1]= dist[a.second] + 1;
                    Q.push(PII(-dist[a.second - 1],a.second - 1));
                }
                    if (a.second - m*2>=0 and (a.second/(m*2))%2 == 1 and dist[a.second - m*2] > dist[a.second] + 1 + camb) {
                        dist[a.second -m*2] = dist[a.second] + 1 + camb;
                        Q.push(PII(-dist[a.second -m*2],a.second - m*2));
                    }
                    if (a.second + m*2 >= 0  and (a.second/(m*2))%2 == 0 and dist[a.second + m*2] > dist[a.second] + 1 + camb) {
                        dist[a.second +m*2] = dist[a.second] + 1 + camb;
                        Q.push(PII(-dist[a.second + m*2],a.second + m*2));
                    }
                }
            }
        }
        cout << "Case #" << caso++ << ": " << dist[m*2 - 1] << endl;
    }
}
