// MultiBase happines.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <stdio.h>
#include <vector>
#include <math.h>

using namespace std;



int convert(int n, int base)
{
    int pos=0;
    int sum=0;
    while(n>0)
    {
        sum+=(n%base)*(int)pow(10.0,pos);
        n/=base;
        pos++;
    }
    return sum;

}


bool happy(int n, int base)
{
    char buffer[100];
    if(base==2 || base == 4)
        return true;

    if(base == 3)
    {
        n=convert(n,base);
        while(true)
        {
            if(n==2 || n==12 || n==22)
                return false;
            
            sprintf(buffer,"%d",n);
            int sum=0;
            int i=0;
            while(buffer[i]!='\0'){
                sum+=(buffer[i]-'0')*(buffer[i]-'0');
                i++;
            }
            if(sum==1)
                return true;
            n=convert(sum,base);            
        }

    }

    if(base == 5)
    {
        n=convert(n,base);
        while(true)
        {
            if(n==4 || n==23 || n==33)
                return false;
            
            sprintf(buffer,"%d",n);
            int sum=0;
            int i=0;
            while(buffer[i]!='\0'){
                sum+=(buffer[i]-'0')*(buffer[i]-'0');
                i++;
            }
            if(sum==1)
                return true;
            n=convert(sum,base);            
        }

    }

    if(base == 6)
    {
        n=convert(n,base);
        while(true)
        {
            if(n==32)
                return false;
            
            sprintf(buffer,"%d",n);
            int sum=0;
            int i=0;
            while(buffer[i]!='\0'){
                sum+=(buffer[i]-'0')*(buffer[i]-'0');
                i++;
            }
            if(sum==1)
                return true;
            n=convert(sum,base);            
        }

    }

    if(base == 7)
    {
        n=convert(n,base);
        while(true)
        {
            if(n==2 || n==34 || n==13 || n==23 || n==63 || n==44)
                return false;
            
            sprintf(buffer,"%d",n);
            int sum=0;
            int i=0;
            while(buffer[i]!='\0'){
                sum+=(buffer[i]-'0')*(buffer[i]-'0');
                i++;
            }
            if(sum==1)
                return true;
            n=convert(sum,base);            
        }

    }

    if(base == 8)
    {
        n=convert(n,base);
        while(true)
        {
            if(n==4 || n==5 || n==32 || n==24 || n==64)
                return false;
            
            sprintf(buffer,"%d",n);
            int sum=0;
            int i=0;
            while(buffer[i]!='\0'){
                sum+=(buffer[i]-'0')*(buffer[i]-'0');
                i++;
            }
            if(sum==1)
                return true;
            n=convert(sum,base);            
        }

    }

    if(base == 9)
    {
        n=convert(n,base);
        while(true)
        {
            if(n==55 || n==58 || n==45 || n==75)
                return false;
            
            sprintf(buffer,"%d",n);
            int sum=0;
            int i=0;
            while(buffer[i]!='\0'){
                sum+=(buffer[i]-'0')*(buffer[i]-'0');
                i++;
            }
            if(sum==1)
                return true;
            n=convert(sum,base);            
        }

    }

    if(base == 10)
    {
        n=convert(n,base);
        while(true)
        {
            if(n==4)
                return false;
            
            sprintf(buffer,"%d",n);
            int sum=0;
            int i=0;
            while(buffer[i]!='\0'){
                sum+=(buffer[i]-'0')*(buffer[i]-'0');
                i++;
            }
            if(sum==1)
                return true;
            n=convert(sum,base);            
        }

    }





}



int _tmain(int argc, _TCHAR* argv[])
{

    freopen("A-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);

    int n;
    scanf("%d",&n);
    for(int z=0;z<n;z++)
    {
        vector<int> bases;
        vector<int> converted(9);
        int tmp;
        char tc;

        scanf("%d", &tmp);
        scanf("%c", &tc);

        
        bases.push_back(tmp);

        while(tc!='\n')
        {
            scanf("%d", &tmp);
            scanf("%c", &tc);
            
            
            bases.push_back(tmp);
        }

        int i=2;
        int j;

        while(true)
        {
            
            for(j=0;j<bases.size();j++)
            {
                if(!happy(i,bases[j]))
                    break;
            }
            if(j==bases.size())
            {
                printf("Case #%d: %d\n", z+1, i);
                break;

            }
            i++;
        }

    }


	return 0;
}

