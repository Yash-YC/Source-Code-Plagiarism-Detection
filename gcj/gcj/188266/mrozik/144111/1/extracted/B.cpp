#include <iostream>
#include <queue>
using namespace std;

int N, M;
int S[20][20], W[20][20], T[20][20];

bool visited[40][40];

struct HeapEl {
    int a, b;
    int d;
    HeapEl() {}
    HeapEl(int a, int b, int d) : a(a), b(b), d(d) { }
    
    bool operator<(const HeapEl& x) const {
        return d > x.d; 
    }
};


int main() {
    
    int C; cin>>C;
    for (int c=0; c<C; c++) {
        cin>>N>>M;
        for (int i=0; i<N; i++)
            for (int j=0; j<M; j++) {
                cin>>S[i][j]>>W[i][j]>>T[i][j];
                visited[2*i][2*j] = visited[2*i+1][2*j]
                    = visited[2*i][2*j+1] = visited[2*i+1][2*j+1] = false;
            }
        
        priority_queue<HeapEl> queue;
        queue.push(HeapEl(2*N-1, 0, 0));
        while (true) {
            HeapEl curr = queue.top();
            queue.pop();
            
            
            if (curr.a==0 && curr.b==2*M-1) {
                cout<<"Case #"<<(c+1)<<": "<<curr.d<<endl;
                break;
            }
            
            if (visited[curr.a][curr.b])
                continue;
            visited[curr.a][curr.b] = true;
            
            int mod = S[curr.a/2][curr.b/2]+W[curr.a/2][curr.b/2];
            int ph;
            if (T[curr.a/2][curr.b/2] <= curr.d)
                ph = (curr.d-T[curr.a/2][curr.b/2]) % mod;
            else
                ph = (mod - (T[curr.a/2][curr.b/2]-curr.d) % mod) % mod;
            
            int s, w;
            if (ph<S[curr.a/2][curr.b/2])
                s=0, w=S[curr.a/2][curr.b/2]-ph;
            else
                s=(mod-ph), w=0;
            int ts = s+curr.d+1, tw=w+curr.d+1;
            
//             cerr<<curr.a<<","<<curr.b<<"  d:"<<curr.d<<" ph:"<<ph<<" ts:"<<ts<<" tw:"<<tw<<endl;
            
            
            if ((curr.a&1)==1) {
                queue.push(HeapEl(curr.a-1, curr.b, ts));
                if (curr.a+1<2*N)
                    queue.push(HeapEl(curr.a+1, curr.b, curr.d+2));
            }
            
            if ((curr.a&1)==0) {
                queue.push(HeapEl(curr.a+1, curr.b, ts));
                if (curr.a-1>=0)
                    queue.push(HeapEl(curr.a-1, curr.b, curr.d+2));
            }
            
            if ((curr.b&1)==1) {
                queue.push(HeapEl(curr.a, curr.b-1, tw));
                if (curr.b+1<2*M)
                    queue.push(HeapEl(curr.a, curr.b+1, curr.d+2));
            }
            
            if ((curr.b&1)==0) {
                queue.push(HeapEl(curr.a, curr.b+1, tw));
                if (curr.b-1>=0)
                    queue.push(HeapEl(curr.a, curr.b-1, curr.d+2));
            }
        }
    }
    
    return 0;
}
