//CODEJAM A

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	//vars
	ifstream cin ("A-large.in");
	ofstream g ("A-large.out");
	int T,N,n,i,j=0,x,y,z,a,b;
	char s[1000];
	int base[20];
#define LIM 10000001
	static int zeen[LIM]={0};
	//testcase loop
	cin >> N;
	cin.getline(s,1000,'\n');
		for (T=1; T<=N; T++)
		{
			//input
			cin.getline(s,1000,'\n');
			n=b=0;
				for (a=0; a<strlen(s); a++)
					if (s[a]==' ')
						base[n++]=b,b=0;
					else
						b=b*10+s[a]-'0';
			base[n]=b;
			//brute force
				for (x=2;;x++)
				{
					//cout << x << endl;
					for (b=n; b>=0; b--)
					{
						j++;
						y=x;
							while (true)
							{
								zeen[y]=j;
								z=0;
									while (y)
									{
										z+=(y%base[b])*(y%base[b]);
										y/=base[b];
									}
									if (z==1)
										goto yes;
									if ((z>=LIM) || (zeen[z]==j))
										goto no;
								y=z;
							}
						goto no;
yes:;
					}
					break;
no:;
				}
			//output
			g << "Case #" << T << ": " << x << endl;
			cout << T << endl;
		}
	return(0);
}