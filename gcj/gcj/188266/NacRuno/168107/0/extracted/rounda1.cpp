#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int happyConvert (int num, int base)
{
	int a, b, new_num;

	if (num > 0)
	{
		a = num%base;
		b = happyConvert(num/base, base);
		new_num = a*a + b;
	}
	else
	{
		new_num = 0;
	}
		
		return new_num;
}

int isHappy (int num, int base)
{
	int result;
	int out;

	int result_pre[10000];
	int index = 0, error = 0;

	result	= happyConvert(num, base);
	while (true)
	{
		result_pre[index] = result;
		result	= happyConvert(result, base);
		index++;

		if (index==10000)
			index = 0;

		if (result == 1)
		{
			out = 1;
			break;
		}
		else
		{
			for (int i = 0; i < index; i++)
			{
				if (result_pre[i] == result)
				{
					out = 0;
					error = 1;
				}
			}

			if (error == 1)
				break;
		}
	}

	return out;
}

int main ()
{
	// Generic File Instantiations
	ifstream input;
	ofstream output;
	
	string inputname, outputname;
	
	inputname = "i.in";
	outputname = "output.out";
	input.open (inputname.c_str ());
	output.open (outputname.c_str ());
	
	// Input Read & Initializations
	
	int N; // number of test cases
	input >> N;

	int i,k,hap,index,current;

	string str;
	istringstream instream;
	getline(input, str); // Read to disregard N

	int base_arr[9];

	bool all_happy;

	// Fill array and print	
	for (i = 1; i <= N; i++)
	{
		getline(input, str);
		instream.clear();
        instream.str(str);

		all_happy = false;

		k=0;
		while (instream >> base_arr[k])
		{
			k++;
		}

		output << "Case #" << i << ": ";

		hap = 1;

		while(!all_happy)
		{
			hap++;
			for (index = 0; index < k; index++)
			{
				current = isHappy(hap,base_arr[index]);

				if (current == 0)
				{
					break;
				}
				else
				{
					if (index == k-1)
					{
						all_happy=true;
						break;
					}
				}
			}			
		}

		output << hap << endl;	
		
	}

	input.close();
	output.close();
	return 0;
}