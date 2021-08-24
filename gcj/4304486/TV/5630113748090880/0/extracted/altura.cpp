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


std::string solve() {
  int N;
  std::cin >> N;
  //std::cout << "N: " << N << std::endl;
  
  int N_2 = N * N;
  //std::cout << "N_2: " << N_2 << std::endl;
  
  int n_lists = 2 * N - 1;
  //std::cout << "n_lists: " << n_lists << std::endl;
  
  //int matrix[n_lists][N];
  int soldados[2501] = {0};
  for(int i = 0; i < 2501; ++i) soldados[i] = 0;
  
  //std::cout << "n_lists: " << n_lists << std::endl;
  
  for (int i = 0; i < n_lists; i++) {
    for(int j = 0; j < N; j++) {
      int k;
      std::cin >> k;
      //matrix[i][j] = k;
      soldados[k]++;
    }
  }
  
  std::vector<int> coluna;
  for(int i = 0; i < 2501; ++i) {
    if (soldados[i] % 2) {
      coluna.push_back(i);
    }
  }
  std::sort(coluna.begin(), coluna.end());
  std::stringstream ss;
  for(auto c : coluna) {
    ss << " " << c;
  }
  return ss.str();
}

int main(int argc, char* argv[]) {
  int T;
  std::cin >> T;
  for(int t = 1; t <= T; ++t) {
    
    std::string response = solve();
    std::cout << "Case #" << t << ":" << response << std::endl;
  }
  return 0;
}