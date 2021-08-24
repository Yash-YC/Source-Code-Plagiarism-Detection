#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cassert>

int loopLength(std::vector<int> const& friends, int i, std::vector<int>& loopEnd) {
    std::vector<int> seen(friends.size());

    int result = 0;
    int two_ago = -1;
    int previous = -1;
    int current = i;

    for(;;) {
        result += 1;
        two_ago = previous;
        previous = current;
        current = friends[current];

        if(two_ago == current) {
            loopEnd[current] = std::max(loopEnd[current], result);
            result = 0;
            break;
        }

        if(current == i) {
            break;
        }

        if(seen[current]) {
            result = 0;
            break;
        }

        seen[current] = 1;
    }

    return result;
}

int pairLength(std::vector<int> const& friends, int i, std::vector<int> const& loopEnd) {
    if(loopEnd[i] == 0) {
        return 0;
    }

    assert(friends[friends[i]] == i);

    return loopEnd[i] + loopEnd[friends[i]] - 2;
}


int solveInstance(std::vector<int> const& friends) {
    int max = 0;
    std::vector<int> loopEnd(friends.size());

    for(size_t i = 0; i < friends.size(); ++i) {
        max = std::max(max, loopLength(friends, i, loopEnd));
    }

    int pl = 0;

    for(size_t i = 0; i < friends.size(); ++i) {
        pl += pairLength(friends, i, loopEnd);
    }

    return std::max(max, pl / 2);
}

bool isValid(std::vector<int> const& friends, std::vector<int> const& circle, int size) {
    for (int i = 0; i < size; ++i) {
        if (friends[circle[i]] != circle[(i - 1 + size) % size] && friends[circle[i]] != circle[(i + 1) % size]) {
            return false;
        }
    }

    return true;
}

int solveInstanceBruteForce(std::vector<int> const& friends) {
    int friend_size = friends.size();
    std::vector<int> permutation(friends.size());

    for(int i = 0; i < permutation.size(); ++i) {
        permutation[i] = i;
    }

    int min_length = 2;

    do {

        for (int i = min_length + 1; i <= friend_size; ++i) {
            if (isValid(friends, permutation, i)) {
                min_length = i;
            }
        }
    } while (std::next_permutation(permutation.begin(), permutation.end()));

    return min_length;
}


int main(int argc, char** argv) {
    std::ifstream stream(argv[1]);

    std::string line;

    std::getline(stream, line);


    auto exampleCount = std::atoi(line.c_str());

    for(int i = 0; i < exampleCount; ++i) {
        std::getline(stream, line);
        int length = atoi(line.c_str());
        std::getline(stream, line);
        char* line_c = _strdup(line.c_str());

        std::vector<int> problem(length);

        for(int j = 0; j < length; ++ j) {
            problem[j] = strtol(line_c, &line_c, 0) - 1;
        }

        auto result = solveInstance(problem);

        std::cout << "Case #" << i + 1 << ": " << result << std::endl;
    }
}