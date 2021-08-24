#include <cstdio>
#include <string>
#include <cstring>
#include <sstream>
#include <map>

using namespace std;

char input[50000];
int resposta[2<<10];

bool mascara[9]; // 2..10

map<int, bool> sorte[9];

//bool debug = false;

bool lucky(int num, int base) {
	if (sorte[base-2].find(num) == sorte[base-2].end()) {
		if (num == 1) {
			sorte[base-2][num] = true;
		} else {
			int temp = num;
			int outro = 0;
			int t2;
			
			while (temp) {
				t2 = temp%base;
				temp/=base;
				outro += t2*t2;
				
			}
			
			sorte[base-2][num] = false;
			sorte[base-2][num] = lucky(outro, base);
			
		}
	}
	//if (debug) printf("    sorte[%d-2][%d] = %d\n", base, num, sorte[base-2][num]);
	return sorte[base-2][num];
}

void back(int num, int mask, int qtd) {
	if (num == 11) {
		// calcula
		if (mask != 0) {
			int j;
			//if (mask == 3) debug = true;
			//if (debug) printf("Opa\n");
			for (int i = 2 ; true ; i++) {
				for (j = 0 ; j < 9 ; j++) {
					if (mascara[j]) {
						//if (debug) printf("testando %d-ésima base no numero %d\n", j, i);
						if (!lucky(i,j+2)) {
							//if (debug) printf("  false!\n");
							break;
						}
					}
				}
				if (j==9) {
					resposta[mask] = i;
					//printf("resposta[%d] = %d\n", mask, i);
					break;
				}
			}
			//debug = false;
		}
		
	} else {
		
		mascara[num-2] = false;
		back(num+1, mask, qtd);
		if (qtd <= 2) {
			mascara[num-2] = true;
			back(num+1, mask + (1<<(num-2)) , qtd+1);
			mascara[num-2] = false;
		}
	}
}

int process() {
	gets(input);
	istringstream s(input);
	string s2;
	
	int num;
	int mask = 0;
	while (s >> s2) {
		sscanf(s2.c_str(), "%d", &num);
		//printf("%d ", num);
		
		num-=2;
		mask += (1<<num);
	}
	
	return resposta[mask];
}

int main() {
	
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	
	memset(mascara, false, sizeof(mascara));
	back(2,0, 0);
	
	int T;
	scanf("%d ", &T);
	for (int i = 0 ; i < T ; i++) {
		printf("Case #%d: %d\n", i+1, process());
	}
	
	return 0;
}
