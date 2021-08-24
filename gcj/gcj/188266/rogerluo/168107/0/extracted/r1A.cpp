#include <stdio.h>

bool hash[100000];

bool Judge(unsigned base, const unsigned val){
	unsigned _val = val;
	for(int i = 0; i < 100000; i++)
		hash[i] = 0;
	while(1){
		unsigned sum = 0;
		hash[_val] = 1;
		while(_val > 0){
			int v = (_val % base);
			sum += v*v;
			_val /= base;
		}
		if(1 == sum)
			return 1;
		else if(hash[sum])
			return false;
		else{
			_val = sum;
		}
	}
}

int main(){
	int T;
	scanf("%d", &T);
	char ch;
	scanf("%c", &ch);

	char s[100];
	unsigned base[11];
	int i;
	for(i = 0; i < T; i++){		
		gets(s);
		int b_cnt = 0, b = 0;
		int k = 0;
		while(s[k]){
			if(s[k] == ' '){
				++k;
				continue;
			}
			if(s[k]!='1'){
				base[b_cnt++] = s[k] - '0';
				k++;
			}
			else{
				base[b_cnt++] = 10;
				k += 2;
			}
		}
	
		unsigned val = 2;
		while(1){
			int k;
			bool fail = 0;
			for(k = 0; k < b_cnt; k++){
				if(Judge(base[k], val) == false){
					fail = 1;
					break;
				}
			}
			if(fail){
				val++;
				continue;
			}else{
				printf("Case #%d: %d\n", i+1, val);
				break;
			}			
		}
	}

	
	return 1;
}