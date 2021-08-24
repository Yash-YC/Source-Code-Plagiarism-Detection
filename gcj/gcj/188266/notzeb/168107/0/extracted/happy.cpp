#include <iostream>
#include <cstring>
#include <cstdlib>

#define f(x,y) for (int x = 0; x < y; ++x)

#define M 12000005
#define B 11
#define N 512

using namespace std;

bool happy[B][M];
bool vis[B][M];

int best[N];

int trans(int b, int num) {
	if (b <= 1) return 0;
	
	int ans = 0;
	while (num) {
		int tmp = num%b;
		ans += tmp*tmp;
		num /= b;
	}
	
	return ans;
}

bool rec(int b, int num) {
	if (num == 1) return true;
	if (num >= M) return false;
	if (happy[b][num]) return true;
	if (vis[b][num]) return false;
	
	vis[b][num] = true;
	return (happy[b][num] = rec(b, trans(b, num)));
}

int test(int mask, int num) {
	for (int x = 2; x <= 10; ++x) {
		if (mask%2 && !happy[x][num]) return false;
		mask /= 2;
	}
	return true;
}

int main() {
	f(b,B) if(b) f(num,M) rec(b, num);
	
	f(num,M) {
		int mask = 0;
		for (int x = 10; x >= 2; --x) {
			mask *= 2;
			if (happy[x][num]) ++mask;
		}
		if (best[mask] == 0) {
			f(m,mask+1) if (best[m] == 0 && test(m, num))
				best[m] = num;
		}
	}
	
	int t;
	
	cin >> t;
	
	char tmp[100];
	cin.getline(tmp, 100);
	
	f(counter,t) {
		char temp[1000];
		cin.getline(temp, 1000);
		
		int mask = 0;
		f(i,strlen(temp)) {
			bool add = false;
			int num = 0;
			if (temp[i] >= '1' && temp[i] <= '9') add = true;
			num = temp[i]-'0';
			if (num == 1) num = 10;
			if (add) mask += 1<<(num-2);
		}
		
		cout << "Case #" << (counter+1) << ": " << best[mask] << endl;
	}

	return 0;
}

