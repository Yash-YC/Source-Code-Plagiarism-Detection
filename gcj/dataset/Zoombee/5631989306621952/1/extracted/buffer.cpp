#include<iostream>
#include<algorithm>
#include<string.h>
#include <deque>
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("aoutout.out","w",stdout);
	std::deque <char> cq;
	int t,i,j,k,l,b;
	char a[1003],c[1003];
	scanf("%d",&t);
	if(t>0 && t<=100)
	{
		for(i=0;i<t;i++){
		scanf("%s",&a[0]);
		l=strlen(&a[0]);
		if(l>0 && l<=1000){
		cq.push_back(a[0]);
		for(j=1;j<l;j++){
			b=a[j];
			if(b>=cq.at(0))
			cq.push_front(a[j]);
			else
			cq.push_back(a[j]);
		}
		printf("Case #%d: ",i+1);
		k=0;	
		while(!cq.empty()){
			printf("%c",cq.at(0));
			cq.pop_front();
		}
	}
	printf("\n");
}
}
}
