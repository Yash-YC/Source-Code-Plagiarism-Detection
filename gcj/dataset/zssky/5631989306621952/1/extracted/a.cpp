#include<iostream>
#include<cstring>
#include<deque>
using namespace std;
char s[1001];

int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	int t;
	cin>>t;
	for(int ca=1;ca<=t;ca++){
		cin>>s;
		deque<char>word;
		word.push_front(s[0]);
		for(int i=1;i<strlen(s);i++){
			if(s[i]>=word.front()){
				word.push_front(s[i]);
			}else{
				word.push_back(s[i]);
			}
		}
		deque<char>::iterator itr=word.begin();
		cout<<"Case #"<<ca<<": ";
		while(itr!=word.end()){
			cout<<*itr++;
		}
		cout<<endl;
	}
	return 0;
}
