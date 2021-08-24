/* 
Google Codejam 2009
A. 

C++ Solution by:
 Marco Chiesi
 chiesi@gmail.com
*/

#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

/**
 * Class for a single instance of the problem
 */
class Instance {
    private:
        static vector<map<int, bool> > happyness;
        static bool init;
        vector <int> bases;
        string solution;

    public:
	void readInput(istream &in) {
        if (!init) {
            happyness = vector <map<int, bool> > (11);
            for (int i=2; i<=10; i++) {
                happyness[i] = map<int, bool> ();
            }
        }
        char buf[100];
        in.getline(buf, 100);
        stringstream ss(buf);
        while (!ss.eof()) {
            int base;
            ss >> base;
            //cerr << "Read base " << base << endl;
            bases.push_back(base);
        }
	}

	void solve() {
        bool all_happy;    
        int num = 2;  
        do {
            all_happy = true;
            for (int i=0; i<bases.size(); i++) {
                int base = bases[i];
                set <int> happy_set;
                if (!happy(num, base, happy_set)) {
                    all_happy = false;
                    num++;
                    break;
                }
            }
        }
        while (!all_happy);
        stringstream ss;
        ss << num;
    	solution = ss.str();
	}
	
	bool happy(int num, int base, set<int> happy_set) {
        //cerr << "Checking " << num << " in base " << base << endl;
        if (happyness[base].find(num) != happyness[base].end()) {
            //cerr << "Already calculated " << happyness[base].find(num)->second << endl;
            return happyness[base].find(num)->second;
        } 
        // find digits
        vector <int> digits;
        int current = num;
        while (current > 0) {
            digits.push_back (current%base);
            current = current / base;
        }
        int calc = 0;
        for (int i=0; i<digits.size(); i++) {
            calc += digits[i] * digits[i];
        }
        if (calc == 1) {
            //cerr << "Found to be happy" << endl;
            happyness[base][num] = true;
            return true;
        }
        else if (happy_set.find(calc) != happy_set.end()) {
            //cerr << "Found cycle -> not appy" << endl;
            happyness[base][num] = false;
            return false;
        }
        else {
            //cerr << "Recursion" << endl;
            happy_set.insert(calc);
            return happy(calc, base, happy_set);
        }
    }

	string getSolution() {
    	stringstream ss;
        ss << solution;
        //cerr << "Solution " << solution << endl;
		return ss.str();
	}
};

bool Instance::init = false;
vector<map<int, bool> > Instance::happyness = vector<map<int, bool> >();

/**
 * Class for a problem
 */
class Problem {
	private:
        Instance *instances;
	    int cases;
	
	public:
	void readInput(istream &in) {
		in >> cases;
		instances = new Instance[cases];
        char ignore[10];
        in.getline(ignore, 10);
		for (int i = 0; i < cases; i++) {
			instances[i].readInput(in);
		}
	}
	
	void solve() {
		for (int i = 0; i < cases; i++) {
			instances[i].solve();
		}
	}
	
	void writeOutput(ostream &out) {
		for (int i = 0; i < cases; i++) {
			out << "Case #" << i+1 << ": " << instances[i].getSolution() << endl;
		}
	}
};

/**
 * Main function
 */
int main(int argc, char *argv[]) {
    istream *in;
    ostream *out;
    if (argc > 1) {
        in = new fstream(argv[1], fstream::in);
    }
    else {
        in = &cin;
    }
    if (argc > 2) {
        out = new fstream(argv[2], fstream::out);
    }
    else {
        out = &cout;
    }
    Problem *problem = new Problem();
    problem->readInput(*in);
    problem->solve();
    problem->writeOutput(*out);
    return 0;
}
