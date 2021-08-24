#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cassert>

std::string solve(std::string const& str) {
    std::string result;
    result.reserve(str.size());

    for(auto c : str) {
        if(c >= result[0]) {
            result.insert(result.begin(), c);
        }
        else {
            result.push_back(c);
        }
    }

    return result;
}

int main(int argc, char** argv) {
    std::ifstream stream(argv[1]);

    std::string line;

    std::getline(stream, line);


    auto exampleCount = std::atoi(line.c_str());

    for(int i = 0; i < exampleCount; ++i) {
        std::getline(stream, line);

        std::cout << "Case #" << i + 1 << ": " << solve(line) << std::endl;
    }
}