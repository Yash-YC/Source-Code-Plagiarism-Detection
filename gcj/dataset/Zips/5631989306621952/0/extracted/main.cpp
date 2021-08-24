#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#define max_S 1005
using namespace std;

void findans(char* S, int len){
	if(len == 1) {printf("%c", S[0]); return;}
	if(len == 0) return;
	int temp = len-1;
	for(int i=len-1; i>=0; i--){
		if(S[temp]<S[i]) temp = i;
	}
	printf("%c", S[temp]);
	findans(S, temp);
	for(int i=temp+1; i<len; i++) printf("%c", S[i]);
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;

	scanf("%d", &T);

	char S[max_S];

	for(int i=0; i<T; i++){
		scanf("%s", S);
		printf("Case #%d: ", i+1);
        findans(S, strlen(S));
        printf("\n");
	}

	return 0;
}
