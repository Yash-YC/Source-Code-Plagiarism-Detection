#include <iostream>  /* Provide support for stand input and output such as cout*/
#include <fstream>  /* Provide support for file input and output*/
#include <algorithm>
#include <set>

using namespace std; /* Use stand name space*/

long long next(int number, int base)
{
	int q;
	int remainder;
	long long sum;

	q = number;
	sum = 0;
	while(q>0)
	{
		   remainder  = q%base;
		   sum = sum+ remainder*remainder;
			q = q/base;
	}

	return sum;
}

bool happy(long long number, int base)
{
	set<long long>  checked;
 //   set<long long>::size_type i;
	long long  a=number;


	while(a != 1 && checked.count(a)!=1)
	{
		checked.insert(a);
		a = next(a, base);
	}

	if(a == 1)
	{
		return true;
	}
	else
	{
		return false;
	}

}

long long solve(int count, int* bases)
{	
	bool found=false;
	int i = 2;
	
	while(!found)
	{
		found = true;

		for(int j=0; j<count; j++)
		{
			if(!happy(i, bases[j]))
			{
				found = false;	
			}
		}
		i++;
	}
	return i-1;
}

#define MAX_N 800
#define MAX_NUMBER_OF_BASES 10

int main(int argc, char** args)
{
		long long result;
		int bases[MAX_NUMBER_OF_BASES];
		int T; /* Number of test cases */
		int count;
		char c;

		/* Test case parameter */
		int n;

	 /* Initialize input and output file */ 
		fstream input_file("A-small-attempt0.in"/*"Debug\\input.in"*/, ios_base::in);
		fstream output_file("output.txt"/*"Debug\\output.txt"*/, ios_base::out);
		if(!input_file.is_open() || !output_file.is_open())
		{
				cout << "Unalbe to open file!" << endl;
				return 1;
		}

	/* Read the number of test cases*/
		input_file >> T;
		input_file.get();
		
		//cout << "The number of test cases is " << T << endl;

	/* For each test case, load variables*/
		for(int i=0; i<T; i++)
		{
			count = 0;
		
			while(input_file.peek()!= '\n' && input_file.peek()!=EOF)
			{
				input_file >> bases[count];
				count++;
				while(input_file.peek() == ' ')
				{
					input_file.get();
				}
			}

			input_file.get();

			for(int j=0; j<count; j++)
			{
				   cout << bases[j] << "	";
			}

			cout << endl;

			result = solve(count, &bases[0]);

	
			cout << "Case #" << i +1<< ":	" << result << endl;
			output_file << "Case #" << i+1 << ":	" << result << endl;
		}

		//cout << "Testing fuction next:"<< next(81, 10) << endl;
		//cout << "Testing fuction next:"<< next(82, 3) << endl;
		//cout << "Testing fuction happy:"<< happy(82, 10) << endl;
		//cout << "Testing fuction happy:"<< happy(82, 3) << endl;


	/* Close input and output file */ 
		input_file.close();
		output_file.close();

		return 0;
}