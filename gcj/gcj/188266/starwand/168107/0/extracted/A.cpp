#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

const int DEBUG = 0;

using namespace std;

static string s_inputFile = "A-small.in";

static void GetInputStrings(vector<string>* strings);
static void DebugPrintLines(vector<string>& strings);
static void PrintLines(vector<string>& strings);

//static int GetInt(const string& s);

struct Test {
  vector<int> m_bases;
};

struct Problem {
  vector<Test> m_tests;
  int m_numTests;
};

enum HAPPY {
  NOT_FOUND = 0,
  IS_HAPPY,
  UN_HAPPY,
};
static HAPPY happies[10][1000000];

static void GetProblem(vector<string>& strings, Problem* problem);
static void SolveTest(vector<string>& strings, Problem* problem, int& nextTestLine);

int main() {
  // read input txt and get input strings
  vector<string> inputStrings;
  GetInputStrings(&inputStrings);

  memset(happies, 10*1000000, 0);

  // debug print input
  DebugPrintLines(inputStrings);

  // get problem
  Problem problem;
  GetProblem(inputStrings, &problem);

  return 0;
}

void GetInputStrings(vector<string>* strings) {
  ifstream inputStream(s_inputFile.c_str());

  // append string while input is not EOF
  while(!inputStream.eof()) {
    string inputString;
    getline(inputStream, inputString);
    strings->push_back(inputString);
  }
}

void PrintLines(vector<string>& strings) {
  vector<string>::iterator iter = strings.begin();
  while(strings.end() != iter) {
    cout << *iter << endl;
    iter++;
  }
}

void DebugPrintLines(vector<string>& strings) {
  if(DEBUG) {
    PrintLines(strings);
  }
}

/*
int GetInt(const string& s) {
  return atoi(s.c_str());
}
*/

void GetProblem(vector<string>& strings, Problem* problem) {
  istringstream iss(strings[0]);
  // get test nums
  iss >> problem->m_numTests;

  // get tests
  int nextTestLine = 1; // because input "test num" is 1line
  for(int i = 0; i < problem->m_numTests; i++) {
    cout << "Case #" << i+1 << ": ";
    SolveTest(strings, problem, nextTestLine);
    if(i+1 != problem->m_numTests) {
      cout << endl;
    }
  }
}

void GetEachDigits(const long long num_, const long long base, vector<long long>& digits) {
  long long num = num_;
  vector<long long> digits_;
  while(num >= base) {
    digits_.push_back(num % base);
    num /= base;
  }
  digits_.push_back(num);
  for(unsigned int i = 0; i < digits_.size(); i++) {
    digits.push_back(digits_[digits_.size() - i - 1]);
  }
}

bool isPassBase(const long long result_, const long long base) {
  long long result = result_;
  /*
  if(happies[base][result_] != NOT_FOUND) {
    return (IS_HAPPY == happies[base][result_]);
  }
  */

  vector<long long> lasts;
  lasts.push_back(result_);

  while(1) {
    vector<long long> digits;
    GetEachDigits(result, base, digits);
    result = 0;
    for(unsigned long long i = 0; i < digits.size(); i++) {
      result += digits[i] * digits[i];
    }
    bool sameOneFound = false;
    for(unsigned long long i = 0; i < lasts.size(); i++) {
      if(lasts[i] == result) {
        sameOneFound = true;
      }
    }
    if(sameOneFound) {
      break;
    } else {
      lasts.push_back(result);
    }
  }
  /*
  for(unsigned long long i = 0; i < lasts.size(); i++) {
    if(result == 1) {
      happies[base][lasts[i]] = IS_HAPPY;
    } else {
      happies[base][lasts[i]] = UN_HAPPY;
    }
  }
  */
  return result == 1;
}

void SolveTest(vector<string>& strings, Problem* problem, int& nextTestLine) {
  vector<long long> bases;
  
  istringstream iss(strings[nextTestLine]);
  long digit = -1;
  while(iss >> digit) {
    bases.push_back(digit);
  }

  long long result = 2;
  while(1) {
    bool isPass = false;
    for(unsigned long long i = 0; i < bases.size(); i++) {
      if(isPassBase(result, bases[i])) {
        isPass = true;
        continue;
      } else {
        isPass = false;
        break;
      }
    }

    if(isPass) {
      break;
    } else {
      result++;
      continue;
    }
  }
  
  cout << result;
  nextTestLine++;
}
