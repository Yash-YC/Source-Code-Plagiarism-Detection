#include "Round_1A_A.h"

using namespace std;

int main()
{	
	char* inputFileName = "a.in";
	char* outputFileName = "a.out";

	ifstream inFile(inputFileName, ios::in);
	ofstream outFile(outputFileName, ios::out);

	multiBase(inFile, outFile);	
	return 0;
}