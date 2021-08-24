#include <cstdio>
#include <sstream>
#include <vector>
#include <set>

std::set<std::pair<int, int> > ok, ng, ct;

int happy(int n, int base){
	std::pair<int, int> c(n, base);
	if(ok.find(c) != ok.end()) return true;
	if(ng.find(c) != ng.end()) return false;
	if(ct.find(c) != ct.end()) return false;
	ct.insert(c);
	int ret = 0;
	while(n > 0){
		const int m = n % base;
		n /= base;
		ret += m * m;
	}
	if(ret == 1 || happy(ret, base)){
		ct.erase(c);
		ok.insert(c);
		return true;
	}
	ct.erase(c);
	ng.insert(c);
	return false;
}

int main(){
	int T = 0;
	char buf[1024];
	scanf("%d ", &T);
	for(int ttt = 1; ttt <= T; ttt++){
		scanf("%[^\n]%*c", buf);
		std::istringstream ss(buf);
		std::vector<int> base;
		for(int n; ss >> n; base.push_back(n)){}
		const std::vector<int>::const_iterator end = base.end();
		int ret = 2;
		for(bool cont = true; cont; ret++){
			cont = false;
			for(std::vector<int>::const_iterator it = base.begin(); it != end; it++){
				if(happy(ret, *it)) continue;
				cont = true;
			}
		}
		printf("Case #%d: %d\n", ttt, ret - 1);
	}
	return 0;
}
