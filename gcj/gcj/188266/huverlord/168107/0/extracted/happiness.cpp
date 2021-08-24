//============================================================================
// Name        : happiness.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream fcin;
	ofstream fcout;
	fcout.open("output.txt");
	fcin.open("A-small-attempt0.in");

	int n;

	fcin >> n;

	int number_bases[10];
	char data[100];
	fcin.getline(data,0);
	for(int i = 0 ; i < n ; ++i )
	{
		fcin.getline(data,100);
		int count = 0;
		int base=0;

		for(int j = 0 ; j < strlen(data); ++j)
		{
			if(data[j] >= '0' && data[j] <= '9')
			{
				if(j != 0 && data[j-1] >='0' && data[j] <= '9') base *= 10;
				base += data[j]-'0';
			}else{
				number_bases[count++] = base;
				base = 0;
			}
		}
		number_bases[count++] = base;

		int result = 1;
		while(true){
			++result;
			int sum = 0;
			for(int j = 0 ; j < count ; ++j)
			{
				int temp = result;
				int test = 0;
				do{
					sum = 0;

					while(true){
						int a = temp % number_bases[j];
						int b = temp / number_bases[j];
						sum += a * a;

						if(b*b >= number_bases[j]) temp = b;
						else{
							sum += b*b;
							break;
						}
					}
					++test;
					if(test > 1000) break;
					temp = sum;
				}while(true);
				if(sum != 1) break;

			}
			if( sum == 1 ) break;

		}

		cout << "Case #" << i+1 << ": " << result << endl;
		fcout << "Case #" << i+1 << ": " << result << endl;
	}
	return 0;
}
