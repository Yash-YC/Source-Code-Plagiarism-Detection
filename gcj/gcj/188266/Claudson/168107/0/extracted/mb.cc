#include <stdio.h>
#include <map>
#include <set>

using namespace std;

map<int,int> happy[11];


int ishappyinBase(int x,int base) {

  int result = 0;
  int mod;

  int div = x;
  
  set<int> numbers;

  if (x == 1) return 1;

  if (happy[base].find(x) != happy[base].end()) {
    return happy[base][x];
  }

  

  while (numbers.find(div) == numbers.end()) {

    int newnum = 0;
    numbers.insert(div);
    while (div != 0) {
      
      mod = div % base;
      div = div / base;
      // mod is a digit in the base;
      
      newnum += mod*mod;
      
    }

    
    
    if (newnum == 1) {
      result = 1;
      break;
    }
    if (happy[base].find(newnum) != happy[base].end()) {
      result = happy[base][newnum];
      break;
    }    
    div = newnum;
  }
  
  for (set<int>::iterator it = numbers.begin(); it != numbers.end();
       it++) {
    happy[base][*it] = result;
  }
  
  
  
  return result;
}


main()


{
  
  int T;
  int b[11];
  char line[1000];
  char a;

  scanf("%d\n",&T);

  for (int i = 1; i <= T; i++) {
    
    printf("Case #%d: ",i);

    scanf("%[^\n]",line);
    
    scanf("%c",&a);

    int n = sscanf(line,"%d %d %d %d %d %d %d %d %d",&b[0],&b[1],&b[2],&b[3],
		   &b[4],&b[5],&b[6],&b[7],&b[8],&b[9]);

    int found = 0;
    
    for (int i = 2; found == 0; i++) {
      
      int ishappy = 1;
      
      for (int base = 0; ((ishappy == 1) && (base < n)); base++) {
	ishappy = ishappyinBase(i,b[base]);
      }
      
      if (ishappy==1) {
	found = i;
      }
      
    }
    printf("%d\n",found);

  }


  


}
