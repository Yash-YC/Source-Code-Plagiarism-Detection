#include<iostream>
using namespace std;

int label[100] = {};
int label_num = 0;
bool ishappy(int n, int base);

int main()
{
	int T = 0;
	int base_num = 0;
	int base[10] = {};
	char c;
	cin>>T;
	cin.get(c);
	for(int t=1; t<=T; t++){
		base_num = 0;
		memset(base, 0, sizeof(base));
		do{
			cin>>base[base_num ++];
			cin.get(c);
		}while(c != 10);
		
		for(int n=2; true; n++){
			int i;
			for(i=0; i<base_num; i++){
				memset(label, 0, sizeof(label));
				label_num = 0;
				if(! ishappy(n, base[i])){
					break;
				}
			}
			if(i == base_num){
				cout<<"Case #"<<t<<": "<<n<<endl;
				break;
			}
		}
	}
	return 0;
}

bool ishappy(int n, int base){
	if(n == 1)
		return true;
	
	int sum_sqr = 0;
	int rem = n;
	while(rem){
		sum_sqr += (rem%base)*(rem%base);
		rem = rem / base;
	}
	
	if(sum_sqr < 100){
		if(sum_sqr == 1)
			return true;
		int i;
		for(i = 0; i<label_num; i++){
			if(sum_sqr == label[i])
				return false;
		}
		if(label_num == i){
			label[label_num ++] = sum_sqr;
		}
	}
	return ishappy(sum_sqr, base);
}

























