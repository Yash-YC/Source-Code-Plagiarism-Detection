#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>

using namespace std;
#define iMAX 0xffff 
#define iMAXStep  10
vector<int>  getDigit(int num, int base)
{
	vector<int>  dig;
	int t = num  ;
	//cout << "\n num:" << num << " base: " << base << " dig: ";

	while (t >= 1){
		int s = t % base ;
		t = t / base ; 
		dig.push_back(s);
		//cout << " " << s ; 
	}
	//cout << "dig size(): " << dig.size() ;	
	return dig ;
	
}
int calc_single_happy(int base,  int start = 2){
	//cout << "\nsingle calc: start:" << start  << " base:" << base;
	for(int i = start ; i < iMAX ; i ++){
		//cout<< "\ncalc base " << base << " num :" << i ; 
		int sum = iMAX ; 
		int ii = i ; 
		int step = 0 ; 
		while(sum  > 1 && sum <= iMAX ){
			vector<int> dig = getDigit(ii,base);	
			sum = 0 ; 
			for(int j = 0 ; j < dig.size() ; j ++){	
				sum += dig[j] * dig[j] ; 
			}
			if(sum > iMAX){
				break ;
			}
			if(sum == 1){
				return i ; 
			}
			ii = sum ; 
			step ++ ; 
			if(step > iMAXStep) break;
		}
		
	}
	//cout << "\n###ERROR" ;
	return 0 ;
}
int calc_happy(vector<int>  &bases){
	int a = 2; 
	int start = 2;
	int cnt = 0 ; 
	while(cnt  !=  bases.size() ){
		cnt = 0 ; 
		for(int i = 0 ; i < bases.size() ; i ++){
			a = calc_single_happy(bases[i],start);
			//cout << "\nget happy: " << a << " base:" << bases[i] << " start:" << start << " a " << a << " cnt " << cnt  << " i " << i; 
			if(a == start ){
				cnt ++ ;
			}
			if( a > start ){
				start = a;
			}
		}
	}
	return a ; 
	//cout << "\n";
}
int main(int argc, char** argv){
	//cout << "hello world\n";

	FILE *fp = fopen(argv[1],"r");
	char  buf[2048];
	fgets(buf,2048,fp);
	int case_num;
	sscanf(buf,"%d",&case_num);
	//cout << "cases:" << case_num << "\n"; 
	vector<int>  bases;	
	int cc = 1; 
	for( int kk =0 ; kk< case_num ; kk ++){
		fgets(buf,2048,fp) ;
		//cout << "\n"<< buf ;
		int pos = 0 ;
		int tmp;
		while (pos < strlen(buf)){
			tmp = 0 ; 
			sscanf(buf+pos,"%d",&tmp);
			if(tmp > 0){
				//cout << "\nget a base:" << tmp;
				bases.push_back(tmp);
				if( tmp <=9 ){
				pos += 2 ; 
				} else{
					pos += 3 ; 
				}
			}
		}
		int a = calc_happy(bases);
		cout << "Case #"<< kk + 1 << ": " << a << "\n" ; 
		bases.clear();
	}
	fclose(fp);
	return  0 ;
}
