#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cassert>

bool isValid(std::vector<std::vector<int>> const& ranks, int size, std::vector<int> const& direction, std::vector<int>& result, int missing) {
    std::vector<int> grid(size * size);

    for (int i = 0; i < size; ++i) {
        int j = 2 * i;
        if(direction[i]) {
            j += 1;
        }

        std::copy(ranks[j].begin(), ranks[j].end(), grid.begin() + i * size);
    }

    for(int j = 0; j < size; ++j) {
        int k = 2*j;

        if(missing == j) {
            continue;
        }

        if(!direction[j]) {
            k += 1;
        }

        for(int i = 0; i < size; ++i) {
            if(ranks[k][i] != grid[i*size + j]) {
                return false;
            }
        }
    }

    for(int i = 0; i < size; ++i) {
        result[i] = grid[i * size + missing];
    }

    return true;
}

std::vector<int> solveSmall(std::vector<std::vector<int>> ranks, int size) {
    int missing = -1;

    auto curr_rank = 0;

    for (int i = 0; i < size; ++i) {
        if (curr_rank + 2 > ranks.size()) {
            missing = i;
            ranks.emplace(ranks.end() - 1);
            continue;
        }

        std::partial_sort(ranks.begin() + curr_rank, ranks.begin() + curr_rank + 2, ranks.end(), [&i](auto& a, auto& b) { return a[i] < b[i]; });

        if(ranks[curr_rank][i] != ranks[curr_rank + 1][i]) {
            missing = i;
            ranks.emplace(ranks.begin() + curr_rank);
        }

        curr_rank += 2;
    }

    std::vector<int> direction(size);
    std::vector<int> result(size);

    direction[missing] = 1;

    for(;;) {
        if(isValid(ranks, size, direction, result, missing)) {
            return result;
        }

        direction[0] += 1;

        for(int i = 0; i < size - 1; ++i) {
            if(direction[i] > 1) {
                direction[i] = i == missing ? 1 : 0;
                direction[i + 1] += 1;
            }
        }

        if (direction[size - 1] > 1) {
            assert(false);
        }
    }

}

int main(int argc, char** argv) {
    std::ifstream stream(argv[1]);

    std::string line;

    std::getline(stream, line);


    auto exampleCount = std::atoi(line.c_str());

    for(int i = 0; i < exampleCount; ++i) {
        std::getline(stream, line);

        int size = std::atoi(line.c_str());

        std::vector<std::vector<int>> ranks;
        ranks.reserve(2 * size);

        for(int j = 0; j < 2 * size - 1; ++j) {
            std::vector<int> rank(size);

            std::getline(stream, line);
            auto line_c = _strdup(line.c_str());

            for(int k = 0; k < size; ++k) {
                rank[k] = strtol(line_c, &line_c, 0);
            }

            ranks.emplace_back(std::move(rank));
        }

        auto solution = solveSmall(std::move(ranks), size);

        std::cout << "Case #" << i + 1 << ':';

        for(auto n : solution) {
            std::cout << ' ' << n;
        }

        std::cout << std::endl;
    }
}