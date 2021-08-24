#include <vector>
#include <string>
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <stack>
#include <fstream>
#include <sstream>

using namespace std;


#define All(v) (v).begin(), (v).end()
#define ffor(i,n) for(int i=0; i<n; i++)
#define LL long long
#define LD long double
#define psh push_back
#define Fill(a,c) memset(&a, c, sizeof(a))
#define MP(x, y) make_pair((x), (y))




string itoa (int n) {
 
        char * s = new char[17];
        string u;
 
        if (n < 0) { //turns n positive
                n = (-1 * n); 
                u = "-"; //adds '-' on result string
        }
 
        int i=0; //s counter
  
        do {
                s[i++]= n%10 + '0'; //conversion of each digit of n to char
                n -= n%10; //update n value
        }
 
        while ((n /= 10) > 0);
 
        for (int j = i-1; j >= 0; j--) { 
                u += s[j]; //building our string number
        }
 
        delete[] s; //free-up the memory!
        return u;
}

string tobase(int num, int base)
{
	string str;
	char t[3];
	while(num > 0)
	{
		int r	= num % base;
		num	-= r;
		num /= base;
		str	= itoa(r)+str;
	}

	return str;
}

string addbase(string n1, string n2, int base)
{
	reverse(All(n1));
	reverse(All(n2));

	int a	= n1.size();
	int b	= n2.size();

	string res;
	int mov	= 0;
	ffor(j, ((a > b) ? a : b))
	{
		int t;
		int e,f;
		if(j > a-1)
			e	= 0;
		else
			e	= n1[j]-48;

		if(j > b-1)
			f	= 0;
		else
			f	= n2[j]-48;

		t	= e+f+mov;
		mov	= t/base;
		t	%= base;
		res	= itoa(t)+res;
	}
	if(mov)
		res	= "1"+res;
	return res;
}

bool happy(string s, int base)
{
	vector<string> ress;
	for(;;)
	{

		string res	= "0";
		ffor(i,s.size())
		{
			int num	= s[i]-48;
			num	*= num;
			res	= addbase(res,tobase(num,base),base);
			//cout << "num " << num << "res: " << res << endl;
		}
		//cout << res << endl;
		if(res == "1")
			return true;
		//else if(res.size() == 1)
		//	return false;
		else
			s	= res;
		ffor(i,ress.size())
			if(res == ress[i])
				return false;
		ress.push_back(res);
	}

}

int main()
{
	int c;
	cin >> c;


	string t;
	getline(cin,t);

	for(int i = 0; i < c; i++)
	{
		getline(cin,t);

		stringstream st(t);

		vector<int> bases;

		while(st.good())
		{
			int a;
			st >> a;
			bases.psh(a);
		}

		int res;
		for(int j = 2;; j++)
		{
			bool h	= true;
			ffor(k,bases.size())
				if(!happy(tobase(j,bases[k]),bases[k]))
				{
					h	= false;
					break;
				}

			if(h)
			{
				res	= j;
				break;
			}
		}


		cout << "Case #" << i+1 << ": " <<  res <<     endl;
	}
}
