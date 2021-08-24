#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int findIn(int elt, vector<int> array) {
  for(int i = 0; i  < array.size(); i++) {
    if(array[i] == elt)
      return i;
  }
  return -1;
}

int squarify(int arg, int base) {
  int sum = 0;
  //  cout << "Squarifying " << arg << ":\n";
  while(arg) {
    int a = arg%base;
    //    cout << a << " ";
    sum += a*a;
    arg /= base;
  }
  //  cout << "\n";
  return sum;
}

int finalSquare(int arg, int base) {
  vector<int> list;
  //  cout << "Finding final squaresum of " << arg  << "\n";
  while(findIn(arg, list) == -1) {
    list.push_back(arg);
    //    cout << "\t" << arg << "\n";
    arg = squarify(arg, base);
  }
  //  cout << "\tResult: " << arg << "\n";
  return arg;
}

int isHappy(int arg, int base) {
  return finalSquare(arg, base) == 1;
}

void readNums(int *args, int numArgs, string s) {
  for(int i = 0; i < numArgs; i++)
    args[i] = 0;
  int ind = 0;
  for(int i = 0; i < s.size(); i++) {
    if(s[i] == ' ')
      ind++;
    else {
      args[ind] *= 10;
      args[ind] += (s[i] - '0');
    }
  }
}

int main(int argc, char **argv) {
  char *infile = argv[1], *outfile = argv[2];
  ifstream fin(infile);
  ofstream fout(outfile);
  
  int numCases;
  fin >> numCases;
  string s;
  getline(fin, s);

  for(int caseNum = 1; caseNum <= numCases; caseNum++) {
    getline(fin, s);
    //    cout << "Line " << caseNum << ": " << s << "\n";
    
    int numArgs = 1;
    for(int j = 0; j < s.size(); j++) {
      if(s[j] == ' ')
	numArgs++;
    }

    int args[numArgs];
    readNums(args, numArgs, s);

    //    cout << finalSquare(3, 2) << " " << finalSquare(3, 3) << "\n";
    //    return 0;

    int result = 1, cont = 1;
    while(cont) {
      result++;
      cont = 0;
      for(int i = 0; i < numArgs; i++) {
	//	cout << result << " in base " << args[i] << "\n\t";
	if(!isHappy(result, args[i])) {
	  cont = 1;
	  //	  cout << " is not happy.\n";
	}
	//	else
	  //	  cout << " is happy.\n";
      }
    }

    fout << "Case #" << caseNum << ": " << result << "\n";
  }
}
