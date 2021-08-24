#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>    
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cfloat>
using namespace std;

int base[20];
char str[50];
map<int, bool> m;

int main(){
    int ts, t, ans;
	char *tok;
    freopen("input.txt","r",stdin); 
	freopen("output.txt","w",stdout);

    scanf("%d\n",&ts);
	for(int st=1;st<=ts;st++){
		char ch = 10;
		int cnt = 0;
		scanf("%[^\n]\n",str);
		tok = strtok(str," \n");
		while(tok != NULL){
			base[cnt++] = strtol(tok,NULL,10);
			tok = strtok(NULL," \n");
		}

		for(int i=2;i<100000;i++){
			
			bool flag = false;
			int j;
			for(j=0;j<cnt;j++){
				m.clear();

				int temp = i, number=0;
				m[temp] = true;
				while(1){
					while(temp > 0){
						int t = temp%base[j];
						temp /= base[j];
						number += t*t;
					}
					if(number == 1){
						flag = true;
						break;
					}else if(m[number]){
						flag = false;
						break;
					}
					m[number] = true;
					temp = number;
					number = 0;
				}
				if(!flag)
					break;
			}
			if(j == cnt && flag){
				ans = i;
				break;
			}
		}
		printf("Case #%d: %d\n",st,ans);
    } 
    return 0;
}
