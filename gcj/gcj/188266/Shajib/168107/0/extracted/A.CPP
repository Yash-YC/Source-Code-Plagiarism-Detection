#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<vector>
#include<string>
using namespace std;

#define MAX 100000

main()
{
	char buffer[1000];
	int i,j,k;
	int min;
	int T,CASE=0;

	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);

	vector<int> bases;

	T = atoi(gets(buffer));

	while(T--)
	{
		CASE++;

		gets(buffer);

		bases.clear();

		for(i=j=0; buffer[i]; i++)
		{
			if(buffer[i] == ' ')
			{
				bases.push_back(j);
				j = 0;
			}
			else
			{
				j = j*10 + buffer[i]-'0';
			}
		}
		bases.push_back(j);


		bool finished = false;

		min = 1;

		int flag[MAX];

		while(!finished)
		{
			finished = true;

			min++;

			for(i=0; i<bases.size(); i++)
			{
				int base = bases[i];
				int temp = min;

				for(j=0; j<MAX; j++)
					flag[j] = 0;
				
				while(temp != 1)
				{
					int digitsum = 0;

					while(temp/base)
					{
						digitsum += ((temp%base)*(temp%base));					
						temp /= base;
					}			
					digitsum += ((temp%base)*(temp%base));					

					temp = digitsum;

					if(flag[temp] == 1)
					{
						finished = false;
						break;
					}

					flag[temp] = 1;

//					if(temp == min)
//					{
//						finished = false;
//						break;
//					}						

				}

				if(!finished)
					break;
			}

		}

		printf("Case #%d: %d\n",CASE, min);

		


	}

	


}