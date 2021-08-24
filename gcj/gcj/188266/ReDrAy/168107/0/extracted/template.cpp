// template.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <set>
#include <fstream>
using namespace std;

inline int convertbasedigit(char a,int base)
{
   if (( a >= 48) && (a <=57))
   {
      return a %48;
   }
   else if (( a>=97) && (a<=122))
   {
      return (a%97)+10;
   }
   else
   {
      assert(false);
      return -1;
   }
}

bool isHappy(long long a,int base)
{
 
   set<long long> computed;
   char buf[2048]={};
   _itoa_s(a,buf,2048,base);
   
   int len = strlen(buf);
   computed.insert(a);
   long long sum = 0;
   bool unhappy = false;
   while ( true ) 
   {
      sum = 0;
      for (int i = 0 ; i<len ;++i)
      {
         
         int vv = convertbasedigit(buf[i],base);         
         sum += vv*vv;
      }
      set<long long>::iterator find_it = computed.find(sum);
      if ( find_it != computed.end())
      {
         //cout<<"v:"<<a<<", base:"<<base<<" is unhappy"<<endl;
         return false;
      }

      computed.insert(sum);
      
      if (sum ==1)
      {
         //cout<<"v:"<<a<<", base:"<<base<<" is happy"<<endl;
         return true;
      }

      _itoa_s(sum,buf,2048,base);

      len = strlen(buf);


   }
   
}

int process ( int a[3] , int size )
{
   bool result = false;
   long long h = 2;

   while (!result)
   {
      bool happy = false;
      int ch = h;
      for (int j = 0 ; j< size ; ++j)
      {
         if (happy)
         {
            bool allhappy = false;
            for (int z = j ; z < size ; ++z)
            {
               allhappy = isHappy(ch,a[z]);
               if (!allhappy)
               {
                  ++ch;
                  happy = false;
                  j = 0;
                  break;
               }
            }
            if (allhappy)
            {
               return ch;
            }
         }
         
         
         while ( !happy )
         {


            happy = isHappy(ch,a[j]);
            
            if (!happy)
            {
               ++ch;
               
            }
            else
            {
               
            }
         }

      }
   }
   
}

int _tmain(int argc, _TCHAR* argv[])
{




   
   int count = 0;
   cin>>count;     
   cin.get();

   ofstream of("out.txt");
   for (int i = 0 ; i< count ; ++i)
   {      
      int a[3]={ -1,-1,-1 };
      char buf[1024]={};
      cin.getline(buf,1024);

      char* token = strtok(buf," ");
      a[0] = atoi(token);
      int j = 0;
      while(token!=0)
      {
         token = strtok(NULL," ");
         if (token)
         {
            if (j == 0)
            {
               a[1] = atoi(token);
            }
            else if (j==1)
            {
               a[2] = atoi(token);
            }
            j++;
         }
         
      }

      int len = 0;
      if ( j==1)
      {
         len = 2;
      }
      else if (j==2)
      {
         len =3;
      }
      
      of<<"Case #"<<i+1<<": "<<process(a,len)<<endl;      
      cout<<"Case #"<<i+1<<": "<<process(a,len)<<endl;      
      

   }



   /*
   ofstream of("out.txt");
   int aa = 1;
   for ( vector<int>::iterator it = result.begin() ;
         it != result.end(); ++it)
   {
      of<<"Case #"<<aa<<": "<<*it<<endl;
      aa++;
   }
   */
	return 0;
}

