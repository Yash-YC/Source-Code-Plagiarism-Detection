#include <stdio.h>
#include <string.h>
#include <math.h>

void decimal_to_base(int num,int base, char* output)
{
	int i = 0;
	for(;; i++)
	{
		if(pow((double) base, i) > num)
			break;
	}
	i--;

	int out_position = 0;

	for(; i >= 0; i--) 
	{
		int j = 0;
		for(;; j++)
		{
			if(pow((double) base, i) * j > num)
				break;
		}
		j--;
		num -= pow((double) base, i) * j;

		output[out_position] = (char)(j+48);
		out_position++;		
	}
	output[out_position] = '\0';
}

bool isHappy(int num, int bases[])
{
	int temp = num;
	
	for(int i = 0; i < 3; i++)
	{
		num = temp;
		if(bases[i] == 0)
			return true;
		if(bases[i] == 2)
			continue;	

		int nums[1000]={0};
		//nums[0] = num;

		char result[1000];
		for(int j = 0; ; j++)
		{
			decimal_to_base(num, bases[i], result);
			sscanf(result, "%d", &nums[j]);
			if(nums[j] == 1)
				break;
			for(int k = 0; k < j; k++)
			{
				if(nums[k] == nums[j])
					return false;
			}

			int sum = 0;
			for(int k = 0;k < strlen(result); k++)
			{
				if(result[k] == 0)
					continue;
				sum += (int)(result[k]-48) * (int)(result[k]-48);
			}
			num = sum;
		}
	}
	return true;
}
void main()
{
	FILE * file_ptr = fopen("A-large.in", "r");
	FILE * file_out = fopen("output.txt", "w");

	int tasks = 0;
	int bases[1000] = {0};
	char buffer[100];
	char * base;

	fscanf(file_ptr, "%d\n", &tasks);

	for(int j = 0; j < tasks; j++)
	{
		int bases[1000] = {0};
		fgets(buffer, 100, file_ptr); 

		base = strtok(buffer, " ");
		int i = 0;
		while(base != NULL)
		{
			sscanf(base, "%d", &bases[i]);
			base = strtok(NULL, " ");
			i++;
		}

		int num = 2;
		while(true)
		{
			if(isHappy(num, bases))
				break;
			num++;
		}
		fprintf(file_out, "Case #%d: %d\n", j+1, num);
	}
	fclose(file_out);
	fclose(file_ptr);

}