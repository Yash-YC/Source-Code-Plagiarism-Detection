#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <stack>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#define forn(i) for(int i = 0; i< (int) n; ++i)

using namespace std;


bool is_happy(int input, int base) ;
vector <int> change_base(int number, int to) ;
void sum_sqr_digits(vector<int> &input, int base) ;
void leer(vector < vector <int> > & bases);



int main () { 
  ofstream salida("output.out");
  vector < vector<int> > bases;
  leer(bases);
  int i = 1;
  bool found = false;
  int n = bases.size();
  
  forn(k) {
    i = 1;
    found = false;
    while(!found) {
      ++i;
      found = true;
      for(int j=0;j<bases[k].size();++j) {
	found = found && is_happy(i,bases[k][j]);
      }
      
    }
    cout << k << endl;
    salida << "Case #" << k + 1<<": " << i << endl;
  }
  return 0;
}
vector <int> change_base(int number, int to) {
  vector <int> res;
  while(number >= to) {
    res.push_back(number % to);
    number = number/to;
  }
  res.push_back(number);
  return res;
}

void leer(vector< vector <int> > & bases) {
  ifstream input("input.in");
  int n;
  input >>n;
  string s;
  getline(input,s,'\n');
  forn(i) {
    getline(input,s,'\n');
    stringstream ss (s,stringstream::in | stringstream::out);
    int temp;
    vector<int> temp_v;
    while(ss >> temp) {
      temp_v.push_back(temp);
    }
    bases.push_back(temp_v);
  }
  
}

bool should_go_on(vector<bool> &happened, vector<int> &number, vector< vector<int> > &last) {
  vector< vector<int> >::iterator result;
   result = find( last.begin(), last.end(), number );

  if(   result != last.end() ) return false;
  
  if(number.size()>1) return true;
  if(number[0]==1) return false;
  if(happened[number[0]+2]) return false;
  happened[number[0]+2] = true;
  return true;
}

bool is_happy(int input, int base) {
  vector< vector <int> > been_there;
  been_there.push_back(change_base(input, base));
  
  vector <int> next = been_there[0];
  sum_sqr_digits(next,base);
  vector <bool> happened;
  int n = base-2;
  forn(i) {
    happened.push_back(false);
  }
  while(should_go_on(happened,next, been_there)) {
    been_there.push_back( next);
    sum_sqr_digits(next,base);
  }
  return next[0] == 1 && next.size() == 1;
}

void sum_sqr_digits(vector<int> &input, int base) {
  int acum = 0;
  for(int i = 0;i < input.size();++i) {
    acum += input[i] * input[i];
  }
  input.clear();
  input = change_base(acum, base);
}