#include<cstdio>
#include<cstring>
#include<deque>
using namespace std;
deque<char> ans;
char S[1050];
int L;
int main()
{
	deque<char>::iterator t;
	int i,T,_T;
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d",&T);
	for (_T=1;_T<=T;_T++)
	{
		printf("Case #%d: ",_T);
		scanf("%s",S);
		L=strlen(S); ans.clear();
		for (i=0;i<=L-1;i++)
		{
			if (ans.empty()||(S[i]>=ans.front())) ans.push_front(S[i]);
			else ans.push_back(S[i]);
		}
		for (t=ans.begin();t!=ans.end();t++) printf("%c",*t);
		printf("\n");
	}
}
