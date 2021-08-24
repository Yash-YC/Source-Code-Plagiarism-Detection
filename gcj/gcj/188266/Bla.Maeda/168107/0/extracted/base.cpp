#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
using namespace std;



int base(int x, int base) {
   string number;
   stringstream ss;
   int asdf;
   int mod;
   
   while (x > 0) {
      mod = x%base;
      number.insert(number.begin(), char(mod+48));
      x = x/base;
   } 
   
   ss << number;
   ss >> asdf;
   return asdf;
   
}


bool happy(int x, int bas) {
   stringstream ss; string num;
   int sum;
   int a;
   set<int> prob;
   
   while (prob.find(x) == prob.end() && x != 1) {
      prob.insert(x);
      x = base(x, bas);
      ss << x;
      ss >> num;
      sum = 0;
      for (int i = 0; i < num.size(); i++) {
         a = num[i] - 48;
         sum += a*a;
      }
      x = sum;
      ss.clear();
   }
   
   return (x==1);
   
   
   
}

int main(int argc, char *argv[]) {
	//*
   int c;
   string line;
   int bas;
   int x;
   bool flag;
   vector<int> vec;
   stringstream ss;
   
   cin >> c;
   getline(cin, line);
   
   for (int i = 0; i < c; i++) {
      getline(cin, line);
      ss << line;
      while (ss >> bas) vec.push_back(bas);
      
      x = 2;
      while (true) {
         flag = true;
         for (int j = 0; j < vec.size() && flag; j++) {
            if (!happy(x,vec[j])) 
               flag = false;
         }
         if (flag) break;
         x++;
      }
      
      cout << "Case #" << i+1 << ": " << x << endl;
      ss.clear();
      
      vec.clear();
      
   }
   //*
   
	return 0;
}

