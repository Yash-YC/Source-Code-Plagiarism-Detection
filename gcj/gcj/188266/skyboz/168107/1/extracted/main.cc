////
//// Multi-base happiness
////
#include <iostream>
#include <iomanip>
#include <cstdlib> 
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <numeric>
#include <algorithm>


bool
isHappy(int n, int base)
{
    bool happy = true;
    
    int sqSum = n;
    int a;
    std::vector<int> nVec;
    std::set<int> pastSet;

    while (sqSum != 1) {
        while (sqSum) {
            a = sqSum % base;
            nVec.push_back(a);
            sqSum -= a;
            sqSum /= base;
        }


        for (std::vector<int>::const_iterator i = nVec.begin(); i != nVec.end(); ++i) {
            sqSum += (*i) * (*i);
        }
        
        if (pastSet.find(sqSum) != pastSet.end()) {
            happy = false;
            break;
        }

        pastSet.insert(sqSum);
        nVec.clear();
    }

    return happy;
}


int
main (int argc, char **argv)
{
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " filename" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::ifstream fin(argv[1]);

    if (!fin) {
        std::cerr << "cannot open input file: " << argv[1] << std::endl;
        exit(EXIT_FAILURE);
    }

    /// =====================================================================
    std::string::size_type idx;
    std::string inputLine;

    /// number of test cases
    getline(fin,inputLine);
    const int nTestCase = atoi(inputLine.c_str());

    // std::cout << "nTestCase: " << nTestCase << std::endl;


    /// for each ...
    std::vector<int> baseVec;
    int num = 0;
    bool allHappy;

    for (int i = 1; i <= nTestCase; ++i) {
        getline(fin,inputLine);

        while (true) {
            idx = inputLine.find(' ');

            if (idx == std::string::npos) {
                baseVec.push_back(atoi(inputLine.c_str()));
                break;
            }
            else
                baseVec.push_back(atoi((inputLine.substr(0, idx)).c_str()));

            inputLine = inputLine.substr(++idx);
        }


        for (num = 2; ; ++num) {
            allHappy = true;
            for (std::vector<int>::const_iterator ibase = baseVec.begin();
                 ibase != baseVec.end(); ++ibase) {
                if (!isHappy(num, *ibase)) {
                    allHappy = false;
                    break;
                }
            }

            if (allHappy)
                break;
        }


        std::cout << "Case #" << i << ": " << num << std::endl;


        baseVec.clear();
    }
}
    
