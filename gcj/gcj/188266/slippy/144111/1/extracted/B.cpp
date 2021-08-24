#include <iostream>
#include <fstream>
#include <string>
#include <set>

using namespace std;


int main()
{
	ofstream fout("B-large.out");
	ifstream fin("B-large.in");
	
	int T;
	fin >> T;
	
	for(int tt = 0; tt < T; tt++)
	{
		int N, M;
		fin >> N >> M;
		int S[20][20], W[20][20], T[20][20];
		for(int t = 0; t < N; t++)
		for(int u = 0; u < M; u++)
			fin >> S[t][u] >> W[t][u] >> T[t][u];
		
		
		bool done[40][40];
		for(int t = 0; t < 40; t++)
		for(int u = 0; u < 40; u++)
			done[t][u] = 0;
			
		set<long long> SS;
		SS.insert(0*10000 + (2*N-1)*100 + 0);
		
		while(SS.empty() == 0)
		{
			long long k = *SS.begin();
			SS.erase(k);
			long long cost = k/10000;
			int x = (k/100)%100;
			int y = k%100;
			
			done[x][y] = 1;
			
			if(x == 0 && y == 2*M-1)
			{
				fout << "Case #" << tt+1 << ": " << cost << endl;
				break;
			}
			
			if(x > 0 && done[x-1][y] == 0)
			{
				if(x % 2 == 0)
					SS.insert((cost+2)*10000 + (x-1)*100 + y);
				else
				{
					int indx = x/2, indy = y/2;
					long long L = cost - T[indx][indy];
					L %= (W[indx][indy] + S[indx][indy]);
					L += (W[indx][indy] + S[indx][indy]);
					L %= (W[indx][indy] + S[indx][indy]);
					if(L < S[indx][indy]) //cross immediately
						SS.insert((cost+1)*10000 + (x-1)*100 + y);
					else SS.insert((cost+1+S[indx][indy]+W[indx][indy]-L)*10000 + (x-1)*100 + y);
				}
			}
			if(x < 2*N-1 && done[x+1][y] == 0)
			{
				if(x % 2 == 1)
					SS.insert((cost+2)*10000 + (x+1)*100 + y);
				else
				{
					int indx = x/2, indy = y/2;
					long long L = cost - T[indx][indy];
					L %= (W[indx][indy] + S[indx][indy]);
					L += (W[indx][indy] + S[indx][indy]);
					L %= (W[indx][indy] + S[indx][indy]);
					if(L < S[indx][indy]) //cross immediately
						SS.insert((cost+1)*10000 + (x+1)*100 + y);
					else SS.insert((cost+1+S[indx][indy]+W[indx][indy]-L)*10000 + (x+1)*100 + y);
				}
			}		
						
			if(y > 0 && done[x][y-1] == 0)
			{
				if(y % 2 == 0)
					SS.insert((cost+2)*10000 + x*100 + y-1);
				else
				{
					int indx = x/2, indy = y/2;
					long long L = cost - T[indx][indy];
					L %= (W[indx][indy] + S[indx][indy]);
					L += (W[indx][indy] + S[indx][indy]);
					L %= (W[indx][indy] + S[indx][indy]);
					if(L >= S[indx][indy]) //cross immediately
						SS.insert((cost+1)*10000 + x*100 + y-1);
					else SS.insert((cost+1+S[indx][indy]-L)*10000 + x*100 + y-1);
				}
			}
			if(y < 2*M-1 && done[x][y+1] == 0)
			{
				if(y % 2 == 1)
					SS.insert((cost+2)*10000 + x*100 + y+1);
				else
				{
					int indx = x/2, indy = y/2;
					long long L = cost - T[indx][indy];
					L %= (W[indx][indy] + S[indx][indy]);
					L += (W[indx][indy] + S[indx][indy]);
					L %= (W[indx][indy] + S[indx][indy]);
					if(L >= S[indx][indy]) //cross immediately
						SS.insert((cost+1)*10000 + x*100 + y+1);
					else SS.insert((cost+1+S[indx][indy]-L)*10000 + x*100 + y+1);
				}
			}
		}	
		
	}

	return 0;
}
		
