#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <set>
#include <vector>

namespace {
  bool isMagic(int base, int n, std::set<int>& seen) {
    std::vector<int> digits;
    while (n) {
      digits.push_back(n % base);
      n /= base;
    }
    int sum;
    for (int i = 0; i < digits.size(); ++i) {
      sum += digits[i]*digits[i];
    }
    if (sum == 1) {
      return true;
    } else if (seen.find(sum) != seen.end()) {
      return false;
    } else {
      seen.insert(sum);
      return isMagic(base, sum, seen);
    }
    return false;
  }
}

int main(int argc, char *argv[]) {
	if (argc < 2) return 1;
	std::ifstream infile(argv[1]);
	int nlines;
	infile >> nlines;
	std::string line;
	std::getline(infile, line);
	for (int i = 1; i <= nlines; ++i) {
		std::getline(infile, line);
    std::istringstream iss(line);
    std::vector<int> bases;
    int b;
    while (iss >> b) {
      bases.push_back(b);
      //std::cerr << b << "\n";
    }
    
    int smallest = 1;
    bool found;
    do {
      found = true;
      ++smallest;
      for (int j = 0; j < bases.size(); ++j) {
        std::set<int> seen;
        seen.insert(smallest);
        if (!isMagic(bases[j], smallest, seen)) {
          found = false;
          break;
        }
      }
    } while (!found);

		std::cout << "Case #" << i << ": " << smallest << "\n";
	}
	return 0;
}

