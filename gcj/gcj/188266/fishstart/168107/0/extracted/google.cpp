#include <iostream>
#include <map>
#include <string>
using namespace std ; 

map<int ,int> Map ;
int list[100000] , len ;
int match[11][10000] , num[11] ;
map<int , int> mm[11] ;
map<int , int>::iterator it ;

int Tran(int n , int base)
{
	int ans = 0 ;
	while(n  > 0)
	{
		int temp = n%base ;
		ans += temp*temp ;
		n /= base ;
	}
	return ans ;
}

void init()
{
	memset(num , 0 ,sizeof(num)) ;
	int i , j ; 
	int n; 
	for(i = 2 ; i <= 10 ; i++)
		mm[i].clear() ; 
	for(i = 2 ;i <= 10 ; i++)
	{
		num[i] = 0 ;
		if(i == 2 || i == 4)
		{
			for(j = 2 ; j <= 100000 ; j++)
				match[i][num[i]++] = j ; 
			continue ;
		}
		if(i%2 == 0)
		{
			for(j = 2 ; j <= 50000 ; j++)
			{
				n = j ; 
				Map.clear() ; 
				Map[n]++ ;
				bool flag = false ;
				while( (n = Tran(n , i)) > 1 )
				{
					if( Map.find(n) != Map.end() )
						break ;
					Map[n]++ ;
					if( mm[i].find(n) != mm[i].end() )
					{
						n = 1 ; 
						break ;
					}
					if(num[i] > 0 && n < match[i][num[i]-1]) break ;
				}
				if( n == 1 )
				{
					mm[i][j]++  ; 
					match[i][num[i]++] = j ;
				}
			}
		}
		else 
		{
			for(j = 3 ; j <= 50000 ; j += 2)
			{
				n = j ; 
				Map.clear() ; 
				Map[n]++ ;
				bool flag = false ;
				while( (n = Tran(n , i)) > 1 )
				{
					if( Map.find(n) != Map.end() )
						break ;
					Map[n]++ ;
					if( mm[i].find(n) != mm[i].end() )
					{
						n = 1 ; 
						break ;
					}
					if(num[i] > 0 && n < match[i][num[i]-1]) break ;
				}
				if( n == 1 )
				{
					mm[i][j]++  ; 
					match[i][num[i]++] = j ;
				}
			}
		}
		
	}
}

int main()
{
	freopen("A-small-attempt2.in" , "r" , stdin) ;
	freopen("A-small-attempt2.out" , "w" , stdout) ;
	init() ;
	//printf("dfd\n") ;
	int T , st ,en ; 
	char str[1000] ;
	int i , j , n ;
	int t ;
	scanf("%d" ,&T) ;
	t = 1 ;
	getchar() ;
	while(T--)
	{
		gets(str) ;
		len = strlen(str) ;
		str[len] = ' ' ;
		str[len+1] = '\0' ;
		len = 0 ;
		for(i = 0 ; str[i] != '\0' ; i++)
		{
			n = 0 ;
			while( str[i] >= '0' && str[i] <= '9' )
			{
				n = n*10 + str[i] - '0' ;
				i++ ;
			}
			if(n > 0)
			{
				if( n == 2 || n == 4) continue ;
				list[len++] = n ;
				
			}
		}
		if( len == 0 )
		{

			printf("Case #%d: %d\n" ,t++ , 2 ) ;
			continue ;
		}
		if( len == 1 )
		{
			printf("Case #%d: %d\n" ,t++ , match[list[0]][0] ) ;
			continue ;
		}
		for(i = 0 ; i < num[list[0]] ; i++)
		{
			for(j = 1 ; j < len ; j++)
			{
				if( mm[list[j]].find(match[list[0]][i]) == mm[list[j]].end() )
					break ;
			}
			if( j == len )
			{
				printf("Case #%d: %d\n" ,t++ , match[list[0]][i] ) ;
				break ;
			}
		}

		//scanf("%d" ,&list[0]) ;
		//len = 1 ;
		//for(i = 2 ; i < 1000 ; i++)
		//{
		//	Map.clear() ;
		//	bool flag = false ;
		//	for(j = 0 ; j < len ; j++)
		//	{
		//		Map[i]++ ;
		//		n = i ;
		//		while( (n = Tran(n, list[j])) > 1)
		//		{
		//			if( Map.find(n) != Map.end() )
		//			{
		//				flag = true ; 
		//				break ;
		//			}
		//			Map[n]++ ;
		//		}
		//		if( flag ) break ;
		//	}
		//	if( !flag )
		//	{
		//		printf("Case #%d: %d\n" ,t++ , i ) ;
		//		//break ;
		//	}
		//}
	}
	return 0 ;
}