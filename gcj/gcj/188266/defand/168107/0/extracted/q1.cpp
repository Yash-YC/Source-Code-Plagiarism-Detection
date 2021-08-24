#include <iostream>

using namespace std;


unsigned long long int con(long int x,int base)
{
  char num[100];
  int len=0;
  unsigned long long int ans=0;
  while(x>=base)
    {
      
      num[len]=x%base;
      len++;
      x/=base;
    }
  num[len]=x;
  for(int i=len;i>=0;i--)
    {
      ans=ans*10 + num[i];
    }
  
}



long int sqValue(unsigned long long int x)
{
  if(x==0)
    return 0;
  return ((x%10)*(x%10)) + sqValue(x/10);
}

bool isHappy(unsigned long long int x, int base,int tryes)
{
  unsigned long long int num=x;
  int tried=0;
  while(num!=1 && tried<tryes)
    {
      num=sqValue(con(num,base));
      tried++;      
    }
  return num==1;
}

int processLine(char s[],int *bas)
{
  int i=0,count=0,currentNum=0;
  
  while(s[i]!='\0')
    {
      
      // cout<<s[i]<<"   "<<s[i+1]<<"   "<<s[i+2]  <<"   inside while.."<<endl;
      
      if(s[i]==' ')
	{
	  //   cout<<currentNum<<endl;
	  bas[count]=currentNum;
	  count++;	
	  currentNum=0;
	}
      else
	{
	  currentNum=currentNum*10 +s[i]-'0';	  
	}
      i++;
    }
  //  cout<<currentNum;
  bas[count]=currentNum;
  count++;
  return count;
}




int main()
{
  int bases[10],n,noBase,k;
  unsigned long long int j;
  char line[100];
  // cout<<isHappy(3,3,100)<<endl;
  cin>>n;
  cin.getline(line,100);
 
  
  for(int i=0;i<n;i++)
    {
      // cout<<"in  the for.."<<endl;
      cin.getline(line,100);
      //cout<<"afetr the input.."<<endl;
     noBase=processLine(line,bases);

     
     for(j=2;true;j++)
       {
	 // cout<<j<<endl;
	 for( k=0;k<noBase;k++)
	   {
	     if(! isHappy(j,bases[k],100))
	       break;
	   }
	 if(k==noBase)
	   break;
       }
     
     cout<<"Case #"<<i+1<<": "<<j<<endl;
    }
} 
