#include <stdio.h>
#include <stdlib.h>

int test[1000];

int IsHappy(int number, int radix)
{
//	int count;
	int i;
	char strItoa[11];

	while(1)
	{
		itoa(number, strItoa, radix);
		number = 0;

		for(i = 0; strItoa[i] != 0; i++)
		{
			number += (strItoa[i] - '0') * (strItoa[i] - '0');
		}

		if(test[number] != radix)
			test[number] = radix;
		else
			break;
	}


	if(test[1]==radix) return 1;
	else return 0;
}

int main()
{
	int no_case;
	int i, j, k;
	char inputBuf[110];
	char* pInputBuf;
	int inputCount = 0;
	int input[10];

	int radix;
	int testNumber = 0;

	scanf("%d", &no_case);
	fgets(inputBuf,100,stdin);

	for(k = 0; k < no_case; k++)
	{
		fgets(inputBuf,100,stdin);

		inputCount = 0;
		pInputBuf = inputBuf;
		while(sscanf(pInputBuf,"%d", &radix) == 1)
		{
			input[inputCount++] = radix;
			pInputBuf = pInputBuf+2;
		}

		for(i = 2; ;i++)
		{
			for(j = 0; j < 1000; j++)
				test[j] = 0;

			for(j = 0; j < inputCount; j++)
				if(IsHappy(i, input[j]) != 1)
					break;

			if(j == inputCount)
			{
				printf("Case #%d: %d\n", k+1, i);
				break;
			}
		}
	}
}