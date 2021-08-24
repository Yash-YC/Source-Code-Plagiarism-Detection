#include<iostream>
#include<vector>
using namespace std;

int convert_base(int base,int num)
{
	int acc=0;
	while(num!=0)
	{
		int rem=num%base;
		acc+=rem*rem;
		num/=base;
	}
	return acc;
}


int main()
{
	int T;
	cin>>T;
	char a=getchar();
	int i=0;
	while(T--)
	{
		i++;
		char inp[100];
		scanf("%[^\n]",inp);
		string input(inp);
		char ch=getchar();
		//cout<<input<<ch<<"pzlzz"<<endl;
		int ind=0;
		vector<int> store;
		while(1)
		{
		ind=input.find(" ");
		if(ind==-1)
			break;
		string str_base=input.substr(0,ind);
		input=input.substr(ind+1,input.length()-1);
		//cout<<"sttt"<<str_base<<"yyyyyy"<<input<<endl;
		store.push_back(str_base[0]-'0');
		//cout<<str_base[0]<<"base"<<endl;
		}
		if(input.length()==1)
		store.push_back(input[0]-'0');
		else
			store.push_back(10);
		int num=2;
		while(1)
		{
			int j;
		for(j=0;j<store.size();j++)
		{
			int b=store[j];
			bool mark[100000];
			memset(mark,false,100000);
		int com=convert_base(b,num);
		mark[com]=true;
		//cout<<"com isss"<<com<<" "<<num<<" "<<b<<"storeee"<<endl;
		while(1)
		{
			if(com==1)
				break;
			int result=0;
			//cout<<"heyyy"<<com<<"yeeee"<<num<<endl;
			while(com!=0)
			{
				result+=(com%b)*(com%b);
				com/=b;
			}
			//cout<<result<<mark[result]<<"wtf"<<endl;
			if(mark[result]==true)
				break;
			com=result;
			mark[com]=true;
		}
		if(com!=1)
			break;
		}
		if(j==store.size())
			break;
		num++;

		}
		cout<<"Case #"<<i<<":"<<" "<<num<<endl;
		//cout<<"heyyy"<<num<<endl;
	}
}

