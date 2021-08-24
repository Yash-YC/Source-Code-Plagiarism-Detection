#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cmath>
#include <cstring>

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <deque>
#include <string>
#include <sstream>

void double_word(std::vector<std::string>& words, char c) {
  std::vector<std::string> new_words = words;
  for(auto& word: words) {
    word = c + word;
  }
  for(auto& word : new_words) {
    words.push_back(word + c);
  }
  
  //words += new_words;
}

std::vector<std::string> valids(std::string word) {
  std::vector<std::string> words;
  int sz = word.size();
  char a[10] = " ";
  a[0] = word[0];
  words.push_back(std::string(a));
  for(int i = 1; i < sz; i++) {
    double_word(words, word[i]);
  }
  return words;
}

std::string solve() {
  std::string word;
  std::cin >> word;
  
  std::vector<std::string> words = valids(word);
  std::sort(words.begin(), words.end());
  return words.back();
}

int main(int argc, char* argv[]) {
  int T;
  std::cin >> T;
  for(int t = 1; t <= T; ++t) {
    
    std::string response = solve();
    std::cout << "Case #" << t << ": " << response << std::endl;
  }
  return 0;
}