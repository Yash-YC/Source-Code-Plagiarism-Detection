#include <iostream>
#include <vector>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;

long long D[2000];
bool final[2000];
long long N, M;
long long Begin[64][64], Ciclo[64][64], Change[64][64];

struct pos{
    int i, j, c;
    pos (int a, int b, int d){
        i = a, j = b, c = d;
    }
    pos (int n){
        c = n%4;
        n /= 4;
        i = n/M;
        j = n%M;
    }
    int code(){
        return 4*(i*M+j)+c;
    }
    pos vecino(int k){
        if (c == 0){
            if (k == 0){
                if (j == 0) return pos(i, j, c);
                return pos(i, j-1, 3);
            }
            if (k == 1) return pos(i, j, 1);
            if (k == 2) return pos(i, j, 3);
            if (k == 3){
                if (i+1 == N) return pos(i, j, c);
                return pos(i+1, j, 1);
            }
        }
        if (c == 1){
            if (k == 0){
                if (j == 0) return pos(i,j,c);
                return pos(i, j-1, 2);
            }
            if (k == 1){
                if (i == 0) return pos(i, j, c);
                return pos(i-1, j, 0);
            }
            if (k == 2) return pos(i, j, 2);
            if (k == 3) return pos(i, j, 0);
        }
        if (c == 2){
            if (k == 0) return pos(i, j, 1);
            if (k == 1){
                if (i == 0) return pos(i,j,c);
                return pos(i-1, j, 3);
            }
            if (k == 2){
                if (j+1 == M) return pos(i,j,c);
                return pos(i, j+1, 1);
            }
            if (k == 3) return pos(i, j, 3);
        }
        if (c == 3){
            if (k == 0) return pos(i, j, 0);
            if (k == 1) return pos(i, j, 2);
            if (k == 2){
                if (j+1 == M) return pos(i,j,c);
                return pos(i, j+1, 0);
            }
            if (k == 3){
                if (i+1 == N) return pos(i,j,c);
                return pos(i+1, j, 2);
            }
        }
    }
};

long long llegar(int desde, int hasta, long long tiempo){
    pos d(desde);
    pos h(hasta);
    if (d.j != h.j || d.i != h.i)
        return 2;
    int row = d.i;
    int col = d.j;
    int cruzeSur = false;
    if (d.c == 0 && h.c == 1 || d.c == 3 && h.c == 2 || d.c == 1 && h.c == 0 || d.c == 2 && h.c == 3)
        cruzeSur = true;
    long long lastSur = Begin[row][col] + Ciclo[row][col]*((tiempo-Begin[row][col])/Ciclo[row][col]);
    if (cruzeSur){
        if (tiempo < lastSur+Change[row][col])
            return 1;
        return lastSur+Ciclo[row][col]-tiempo+1;
    }
    else{
        if (lastSur+Change[row][col] <= tiempo && tiempo < lastSur+Ciclo[row][col])
            return 1;
        return lastSur+Change[row][col]-tiempo+1;
    }
}

int main(){
    int Casos;
    cin >> Casos;
    for(int caso = 1; caso <= Casos; caso++){
        cin >> N >> M;
        int corner = 4*((N-1)*M);
        int target = 4*(M-1)+2;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                long long a, b, c;
                cin >> a >> b >> c;
                Ciclo[i][j] = a+b;
                Begin[i][j] = c - Ciclo[i][j]*((c+Ciclo[i][j]-1)/Ciclo[i][j]);
                Change[i][j] = a;
            }
        }
        memset(D, 0x7f7f7f7f, sizeof D);
        memset(final, 0, sizeof final);
        D[corner] = 0;
        int visitadas = 0;
        while(visitadas < 4*N*M){
            corner = 0;
            for(int i = 0; i < 4*N*M; i++)
                if (!final[i])
                    corner = i;
            for(int i = 0; i < 4*N*M; i++)
                if (!final[i] && D[i] < D[corner])
                    corner = i;
            if (final[corner]) break;
            cerr << "Visitando " << corner << endl;
            for(int i = 0; i < 4; i++){
                int vecino = pos(corner).vecino(i).code();
                if (vecino != corner && !final[vecino]){
                    D[vecino] = min(D[vecino], D[corner]+llegar(corner, vecino, D[corner]));
                    cerr << "    " << vecino << endl;
                    cerr << "          " << llegar(corner, vecino, D[corner]) << endl;
                }
            }
            
            final[corner] = 1;
            visitadas++;
        }
        cout << "Case #" << caso << ": " << D[target] << endl;
    }
    return 0;
}
