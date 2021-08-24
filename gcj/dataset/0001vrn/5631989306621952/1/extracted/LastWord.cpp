#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
	int t;
	cin>>t;
	int c=1;
	while(t--){
	    string s="";
	    cin>>s;
	    string ans="";
	    ans = ans + s.at(0);
	    for(int j=1;j<s.length();j++)
			{
				char ch=s.at(j);
				if(ch>=ans.at(0))
					ans=ch+ans;
				else
					ans=ans+ch;
			}
		cout<<"Case #"<<c++<<": "<<ans<<endl;
	    
 	}
	return 0;
}
