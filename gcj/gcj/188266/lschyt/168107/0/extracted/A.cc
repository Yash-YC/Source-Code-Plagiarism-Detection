#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int b[15],c;
bool a[100000][12];
bool v[100000][12];

bool thetes(int n,int b){
  int mk = n;
  
  if (v[n][b])
    return a[n][b];
  
  v[n][b] = true;
  if (n==1){  
    a[n][b] = true; return true;
  }  
  else a[n][b] = false;
  if (n==0){
    a[n][b] = false;
    return false;
  }
  //  cout <<n <<" ";
  
  int k = 0;
  while (n){
    k+=(n%b)*(n%b);
    n/=b;
  }
  //  cout << k << "?" << b<<endl;
  
  if (k==1){
    //    cout << mk << "???" <<b<<endl;
    a[mk][b] = true;
    return true;
  }
  //  cout << k<< "??" << b <<endl;
  
  a[mk][b] = thetes(k,b);
  return a[mk][b];
}

int main(){
  int n;
  string s;
  memset(v,0,sizeof v);
  memset(a,0,sizeof a);
  
  cin >> n;
  getline(cin,s);
  int cas = 0;
  while(n--){
    cout << "Case #"<< ++cas << ": ";
    getline(cin,s);
    istringstream iss(s);
    c=0;
    while (iss >> b[c]) ++c;
    int i = 2;
    for (; ; ++i){
      //      cout << i <<endl;
      bool alt = true;
      for (int j = 0; j < c; ++j)
	if (!thetes(i,b[j])){
	  //	  cout << a[i][b[j]] <<endl;
	  alt = false;
	  break;
	}
      
      if (alt)
	break;
    }
    cout << i << endl;
  }
}
