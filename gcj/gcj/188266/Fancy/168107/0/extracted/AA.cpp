#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <sstream>

using namespace std;

const int ret[] = {2, 7, 3, 91, 8, 97, 27, 1177, 7, 7, 125, 1337, 1001, 34527, 6393, 48041,
 6, 44, 415, 1033, 216, 608, 4977, 9867, 49, 49, 2753, 71735, 47089, 245035, 569669,
  2662657, 5, 7, 27, 91, 27, 219, 27, 1177, 7, 7, 125, 29913, 1001, 34527, 6393, 246297,
   49, 49, 415, 4577, 1975, 3879, 4977, 28099, 49, 49, 37131, 218301, 48769, 245035,
    569669, 11814485, 2, 7, 3, 91, 8, 97, 27, 1177, 7, 7, 125, 1337, 1001, 34527, 6393,
     48041, 6, 44, 415, 1033, 216, 608, 4977, 9867, 49, 49, 2753, 71735, 47089, 245035,
      569669, 2662657, 5, 7, 27, 91, 27, 219, 27, 1177, 7, 7, 125, 29913, 1001, 34527,
       6393, 246297, 49, 49, 415, 4577, 1975, 3879, 4977, 28099, 49, 49, 37131, 218301,
        48769, 245035, 569669, 11814485, 3, 13, 3, 91, 27, 219, 27, 1177, 143, 167, 143,
         1337, 5719, 48041, 35785, 48041, 79, 79, 707, 6073, 3879, 3879, 10089, 28099,
          2207, 6307, 37131, 613479, 47089, 697563, 569669, 4817803, 23, 23, 27, 91, 27,
           219, 27, 1177, 143, 7895, 143, 120149, 5719, 120407, 128821, 346719, 79, 79,
            1695, 6073, 3879, 3879, 23117, 28099, 2207, 7895, 37131, 711725, 58775,
             2688153, 569669, 11814485, 3, 13, 3, 91, 27, 219, 27, 1177, 143, 167, 143,
              1337, 5719, 48041, 35785, 48041, 79, 79, 707, 6073, 3879, 3879, 10089, 28099,
               2207, 6307, 37131, 613479, 47089, 697563, 569669, 4817803, 23, 23, 27, 91,
                27, 219, 27, 1177, 143, 7895, 143, 120149, 5719, 120407, 128821, 346719,
                 79, 79, 1695, 6073, 3879, 3879, 23117, 28099, 2207, 7895, 37131, 711725,
                  58775, 2688153, 569669, 11814485};

int main(){
	int t, temp;
	string str;
	
	scanf("%d", &t);getline(cin, str);
	for(int test = 1;test <= t;test++){
		getline(cin, str);
		istringstream sin(str);
		int i = 0, cur = 0;
		while(sin >> temp){
			if(temp > 2){
				cur = cur | (1 << (10 - temp));
			}
		}
		printf("Case #%d: %d\n", test, ret[cur]);
	}
	return 0;
}
