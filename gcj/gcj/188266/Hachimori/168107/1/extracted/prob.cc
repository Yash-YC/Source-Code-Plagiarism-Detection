#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;
const int OK = 1, YET = 0, FAIL = -1, VISITED = -2;

vector<int> base;

void read(){
  string s; 
  getline(cin,s);

  stringstream in(s);
  
  base.clear();

  int n;
  while(in >> n) base.push_back(n);
}

static int visited[11][1<<24];

int isOk(int cur, int b){
  //cout << cur << ' ' << b << ' ' << visited[b][cur] << endl;
  int &ret = visited[b][cur];
  if(cur==1) return ret = OK;
  if(ret==VISITED) return ret = FAIL;
  if(ret!=YET) return ret;
  ret = VISITED;
  int next = 0;
  while(cur){
    int digit = cur%b;
    next += digit*digit;
    cur /= b;
  }
  return ret = isOk(next,b);
}

void work(int cases){
  for(int i=2;i<(1<<24);i++){
    //cout << i << endl;
    for(int j=0;j<base.size();j++)
      if(isOk(i,base[j])!=OK)
        goto _fail;
    cout << "Case #" << cases << ": " << i << endl;
    break;
  _fail:;
  }
}

int main(){
  memset(visited,0,sizeof(visited));

  int cases;
  cin >> cases;
  
  string dummy;
  getline(cin,dummy);

  for(int i=0;i<cases;i++){
    read();
    work(i+1);
  }
  return 0;
}
