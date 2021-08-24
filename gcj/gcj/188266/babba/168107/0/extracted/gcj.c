#include<stdio.h>
#include<math.h>
#include<string.h>
//#include<conio.h>

FILE *fp,*fo;

int A[10];
int B[10000];



long long square(long long n)
{
	long long d=0;
	while(n)
	{
		d+=(n%10)*(n%10);
		n/=10;		
	}
	return d;
}
long long solve(int n)
{
	long long num=2;
	int i,j,flag,temp3;
	long long temp1,temp2;
	
	int count;
	while(1)
	{
		flag=0;
		//printf("num=%d\n",num);
		for(i=0;i<n;i++)
		{
			//printf("base=%d\n",A[i]);
			temp1=num;
			flag=1;
			count=0;
			
			temp2=num;
			temp3=0;
			while(temp2)
				{
					temp1=(temp1*10)+(temp2%A[i]);
					temp2/=A[i];
					temp3++;
				}
				temp2=temp1;
				temp1=0;

				for(j=temp3-1;j>=0;j--)
				{
						temp1=(temp1*10)+temp2%10;
						temp2/=10;
				}
				
			
			while(temp1!=1)
			{
			//	printf("temp1=%d",temp1);
				B[count++]=temp1;
				temp1=square(temp1);
				temp2=temp1;
				temp3=0;
				while(temp2)
				{
					temp1=(temp1*10)+(temp2%A[i]);
					temp2/=A[i];
					temp3++;
				}
				temp2=temp1;
				temp1=0;
				for(j=temp3-1;j>=0;j--)
				{
						temp1=(temp1*10)+temp2%10;
						temp2/=10;
				}
				
				//if(count==1000)getch();
				for(j=0;j<count;j++)if(B[j]==temp1)flag=0;
				if(flag==0)break;
				
			}
			if(flag==0){num++;break;}
		}	
		if(flag)return num;
	}
	return 0;	
}



int main()
{
	int K=0,i,T,n;
	long long ans;
	char temp;
	

	fp=fopen("A-small-attempt1.in","r");
	fo=fopen("out.txt","w");	

	fscanf(fp,"%d",&T);
	fscanf(fp,"%c",&temp);	
	
	for(i=0;i<T;i++)
	{
		
		
		fscanf(fp,"%c",&temp);	
		n=0;ans=0;
		while(temp!='\n')
		{
		//	printf("-%c- ",temp);
			//getch();
			if(temp!=' ')
			{
				K*=10;
				K+=((int)temp)-48;
			}
			else if(temp==' ')
			{
				A[n++]=K;
				K=0;
			}			
			fscanf(fp,"%c",&temp);				
		}
		A[n++]=K;
		K=0;
		
		//for(j=0;j<n;j++)printf("%d ",A[j]);
		

		

		ans=solve(n);	
		fprintf(fo,"Case #%d: %lld\n",i+1,ans);
		printf("Case #%d: %lld\n",i+1,ans);
	}//T
	
	fclose(fp);
	fclose(fo);
	printf("over");
	return 0;
}