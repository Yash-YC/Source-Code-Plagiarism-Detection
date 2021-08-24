#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <sstream>
#include <iterator>

using namespace std;

std::vector<std::string> split(string s) {
	istringstream iss(s);
    vector<string> tokens;
	copy(istream_iterator<string>(iss),istream_iterator<string>(),back_inserter<vector<string> >(tokens));
	return tokens;
}


vector<int> tobase(int n, int base)
{
	vector<int> chars;
	
	while(n!=0)
	{
		int rem = n % base;
		n=n/base;	
		chars.push_back(rem);
	}
	reverse(chars.begin(),chars.end());
	return chars;
}

bool happy(int num,int base)
{
	vector <int> c,done;
	c=tobase(num,base);
	int sum=0;
	int prevnum=-1;
	while(1)//while((num/base)!=0 && prevnum!=num)
	{	
		//cout<<num;
		sum=0;
		for(int i=0;i<c.size();i++)
		{
			sum+=(c.at(i)*c.at(i));
		}
		prevnum=num;
		num=sum;
		//cout<<"\t"<<num/base<<" "<<base<<endl;
		c.clear();
		c=tobase(sum,base);
		
		bool flag = false;
		for(int j=0;j<done.size();j++)
		{
			if(done.at(j)==num){
					flag=true;
					break;
			}
		}
		if(flag==true) break; else done.push_back(num);
	}
	
	if(num==1) return true; else return false;
}

int main()
{
	//cout<<happy(91,9)<<happy(91,10)<<endl;
	//cout<<2/3<<endl;
	int cases,casecount=1;
	string s;
	cin>>cases;	
	getline(cin,s);
	
	while(cases!=0)
	{
		string str;
		getline(cin,str);
		
		vector<string> tokens = split(str);
		int curr=2;
		
		while(1)
		{	
			//cout<<curr<<endl; //debug
			bool flag = true;
			for(int i=0;i<tokens.size();i++) 
			{
				if(!happy(curr,atoi(tokens.at(i).data()))) flag=false;
				if(flag==false) break;
			}
			if(flag==true) break;
			curr++;
		}
		cout<<"Case #"<<casecount<<": "<<curr<<endl;
		cases--;
		casecount++;
	}
	return 0;
}