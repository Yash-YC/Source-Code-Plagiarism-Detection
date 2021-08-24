#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

typedef vector <bool> Vet;

// check if x is happy on base b
void happy_base (int x, int b, Vet *v) {
	int i, j, sum, num;
	vector <int> old_sum;
	vector <int> base;

	for(i=1; i<=x; i++) {
		old_sum.clear();
	    sum = i+1;
	    while(sum > i) {
			base.clear();
			num = sum-1;
	    	old_sum.push_back(num);
			while (num != 0) {
		       base.push_back(num%b);
		       num = num/b;
		    }
			sum = 0;
			for(j=0; j<base.size(); j++)
				sum += base[j]*base[j];
			if (sum==1) {
				(*v).push_back(true);
				break;
			}
			else if (find(old_sum.begin(), old_sum.end(), sum)!=old_sum.end()) {
			 	(*v).push_back(false);
			 	break;
			 }
			else if (sum < i) {
				(*v).push_back((*v)[sum-1]);
				break;
			}
			else sum++;
		}
	}

	return;
}

int main () {
	int t, T;
	vector <short> base;
	short b;
	string s;
	int k, i;
	int happy, h;
	vector < vector <bool> > h_base;
	Vet aux;

	cin >> T;
	getchar();

	for(k=0; k<100000; k++) 
		aux.push_back(1);
	h_base.push_back(aux);
	for (b=3; b<=10; b++) {
		aux.clear();
		happy_base(100000, b, &aux);
		h_base.push_back(aux);
	}

	for(t=1; t<=T; t++) {

		// init
		base.clear();
		s.clear();

		// read input
		getline(cin, s);
		istringstream iss(s);
		while(iss >> b)
			base.push_back(b);

		// find number
		for(k=2; k<=100000; k++) {
			happy = 0;
			for(i=0; i<base.size(); i++) {
				h = h_base[base[i]-2][k-1];
//if(h) cout << k << " e happy na base " << base[i] << endl;
//else cout << k << " NAO e happy na base " << base[i] << endl;
				if(h==0) break;
				else happy++;
			}
			if(happy == base.size())
				break;
		}
		cout << "Case #" << t << ": " << k << endl;

	}

	return 0;
}