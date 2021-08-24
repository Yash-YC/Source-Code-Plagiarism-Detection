/* 
 * File:   main.cpp
 * Author: maul
 *
 * Created on 2009. szeptember 12., 2:18
 * R1A - A
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <sstream>
#include <set>

std::vector<unsigned int> convert_to_base(int actual_number, int base) {
    //std::cout<<actual_number<<" "<<base <<"\n";
    double size;
    size = ceil(log10(actual_number) / log10(base)) + 1;
    //std::cout << size <<"\n";
    std::vector<unsigned int> ret(size);
    unsigned int i = size - 1;
    for (unsigned int quotient = actual_number; quotient > 0; quotient = quotient / base, --i)
        ret[i] = quotient % base;
    return ret;

}

bool ishappy(unsigned int number, unsigned int base, std::set<unsigned int>&prev) {
    unsigned int numsum = 0;
    //unsigned int cur_pos = 0;

    std::vector<unsigned int> num_base = convert_to_base(number, base);

    for (unsigned int i = 0; i < num_base.size(); i++) {
        numsum += num_base[i] * num_base[i];
        //std::cout<<num_base[i]<<"\n";
    }
    //std::cout<<number<< " " <<numsum<<"\n";
    prev.insert(number);

    if (prev.count(numsum) > 0)return false;
    //if (numsum == 0) return false;
    if (numsum == 1) return true;
    //if (numsum < base) return false;
    return ishappy(numsum, base,prev);
}

unsigned int search(std::vector<unsigned int>bases) {
    bool done = false;
    unsigned int res = 1;
    while (!done) {
        res++;
        bool part_done = true;
        for (unsigned int i = 0; i < bases.size() && part_done == true; i++) {
            //std::cout<<res << " "<<bases[i]<< "\n";
            std::set<unsigned int> prev;
            prev.clear();
            if (!ishappy(res, bases[i],prev)) part_done = false;
        }
        if (part_done) done=true;
    }
    return res;
}

int main(int argc, char** argv) {

    
/*
    std::vector<unsigned int> num_base = convert_to_base(10,10);
    for (unsigned int i=0;i<num_base.size();i++){
        std::cout<<num_base[i]<<"\n";
    }
    exit(0);

  */
/*
    std::set<unsigned int> prev;
    std::cout<< ishappy(216,6,prev);
    exit(0);
*/

    unsigned int T;
    std::cin >> T;
    std::cin.get();

    for (unsigned int i = 0; i < T; i++) {
        std::cout << "Case #" << i + 1 << ": ";
        char l[100];
        std::cin.getline(l, 100);
        std::istringstream line(l);
        std::vector<unsigned int> bases;
        while (!line.eof()) {
            unsigned int base;
            line >> base;
            bases.push_back(base);
        }
        std::cout << search(bases);
        std::cout << "\n";
    }

    return (EXIT_SUCCESS);
}

