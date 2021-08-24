#include <iostream>
#include <string>
#include <sstream>
#include <vector>

struct info {
    bool h;
    bool done;
};

const int max = 1000000;
typedef std::vector<bool> st;
st blank(max, false);
std::vector<st> sieve(11, blank);

bool happy(st& sv, int n, int base)
{
    int nn = n;
    for (int i = 0; i < 100; ++i) {
	int m = 0;
	while (nn) {
	    int l = nn % base;
	    nn /= base;
	    m += l * l;
	}
	if (m < n) {
	    return sv[m];
	}
	nn = m;
    }
    //std::cout << n << " " << base << std::endl;
    return false;
}

int main()
{
    for (int i = 2; i <= 10; ++i) {
	sieve[i][1] = true;
	for (int j = 2; j < max; ++j) {
	    sieve[i][j] = happy(sieve[i], j, i);
	}
    }

    int T;
    std::cin >> T;
    std::string line;
    std::getline(std::cin, line);
    for (int cs = 1; cs <= T; ++cs) {
	std::getline(std::cin, line);
	std::istringstream iss(line);
	int bases[10];
	int count = 0;
	while (iss >> bases[count])
	    ++count;
	for (int i = 2; i < max; ++i) {
	    bool done = true;
	    for (int j = 0; j < count; ++j) {
		if (!sieve[bases[j]][i])
		    done = false;
	    }
	    if (done) {
		std::cout << "Case #" << cs << ": " << i << std::endl;
		break;
	    }
	}
    }
}
