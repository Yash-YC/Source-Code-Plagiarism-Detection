/* Copyright NTUEE 2009. All Rights Reserved. */
/* =====================================================================================
 *       Filename:  main.cpp
 *    Description:  Watersheds
 *        Created:  09/03/09 14:34:27 CST
 *         Author:  Gary Wu (NTUEE), researchgary@gmail.com
 * ===================================================================================== */

#include <set>
#include <map>
#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

/////UTILITY FUNCTIONS LISTS///////////////////////////////////////
size_t   getTokens( string s, char itrpt, vector<string>& tokens );
size_t   getTokensPar( string s, vector<string>& vcStr );
bool     isNum( char c );
int      toDec( char c );
int      str2Int( const string& s);
int      DecToBase(int base, long iDec, char* szString);
template<class T>
void     vc_out( vector<T>& vc );
///////////////////////////////////////////////////////////////////

/////MAIN FUNCTIONS LISTS///////////////////////////////////////
///////////////////////////////////////////////////////////////////

size_t nCases;
vector<vector<int> > qs;

void
readIn( ifstream& ifs ){
   char c[256];
   ifs.getline(c,256);   
   string s = c;
   nCases = str2Int(s);
   for ( unsigned i = 0 ; i < nCases ; ++i ){
      char c1[256];
      ifs.getline(c1,256);
      string s1 = c1;
      vector<string> vcS;
      qs.resize(nCases);
      getTokens( s1, ' ', vcS );
      for ( unsigned j = 0 ; j < vcS.size() ; ++j )
         qs[i].push_back( str2Int(vcS[j]) );
   }
}

void
case_out( ofstream& ofs, size_t ith, int num ){
   ofs << "Case #" << ith << ": " << num << endl;
}

char symbols[37] = "0123456789ABCDEFGHIJKLMNoPQRSTUVWXYZ";

void
solveRec( string s, int tmp, int& rst, int base, map<int,bool>& mapNum ){
   if ( mapNum.find(tmp) != mapNum.end() ){
      rst = tmp;
      return;
    }
   int rst1 = 0;
   for ( int k = 0 ; k < s.size() ; ++k ){
      ostringstream sout;
      sout << s[k];
      int n = str2Int(sout.str());
      rst1 += n*n;
   }
   mapNum.insert(make_pair(tmp,1));
   if ( rst1 == 1){
      rst = 1;
      return;
   }
   char c[256];
   DecToBase( base ,rst1 ,c);
   string ss = c;
   solveRec(ss,rst1,rst,base, mapNum);
   return;
}

void
solve( ofstream& ofs ){
   for ( int i = 0 ; i < nCases; ++i ){
      int rst = 0;
      int num = 1 ;
      do{
         ++num;
         for ( int j = 0; j < qs[i].size() ; ++j ){   // bases
            map<int,bool> mapNum;
            rst = 0;
            int tmp = 0;
            char c[256];
            mapNum[0] = 1;
            DecToBase( qs[i][j], num, c);
            string s = c;
            rst = num;
            solveRec( s,num,rst,qs[i][j],mapNum);
            if ( rst != 1 )
               break;
         }
      }while(rst!=1);
      case_out(ofs,i+1, num );
   }
}

int
main( int argc, char* argv[] ){
   ifstream ifs; 
   ofstream ofs("output");
   ifs.open(argv[1]);
   if ( !ifs.is_open() ){
      cerr << "Can't open file " << argv[1] << endl;
      return 0;
   }
   readIn(ifs);
   solve(ofs);
   ifs.close();
   ofs.close();
   return 0;
}


//utility functions

int DecToBase(int base, long iDec, char* szString)
{
   //Check base is between 2 and 36
   if(base<2)
      return 0; //Failed
   //If input is 0, output is 0
   if(iDec==0){
      strcpy(szString,"0");
      return 1;
   }

   int count = 0;
   char chResult[256] = "";
   char* pChResult = chResult;
   while(iDec > 0 && count++<256)
   {
      *pChResult = symbols[iDec % base];
      pChResult++;
      iDec = iDec/base; //iDec = itself divided by base
   }
   ostringstream sout;
   string s = chResult;
   for( int i = s.size()-1 ; i >=0 ; --i ){
      sout << s[i];
   }
   s = sout.str();
   strcpy(chResult,s.c_str()); 
   strcpy(szString,chResult);

   return 1;
}

bool
   isNum( char c ){
      if ( c >= 48 && c<=57 )
         return true;
      return false;
   }

int
   toDec( char c ){
      if ( isNum(c) )
         return ((int)c-48);
      return -1;
   }

int
str2Int( const string& s){
   int ret = 0;
   int tens = 1;
   bool isMinus = (s[0]=='-');

   for ( int i = s.size()-1 ; i >= 0 ; --i ){
      if ( i == 0 && isMinus )
         continue;
      int x = toDec(s[i]);
      if ( x < 0 )
         return 0;
      ret = ret + x*tens;
      tens = tens * 10;
   }
   ret = isMinus ? -ret : ret;
   return ret;
}

size_t
getTokens( string s, char itrpt, vector<string>& tokens ){
   int prePos = 0, nxtPos = 0;
   do{
      ostringstream sout;
      nxtPos = s.find_first_of( itrpt, prePos+1 );
      if ( nxtPos == string::npos )
         nxtPos = s.size();
      for ( int i = prePos; i < nxtPos ; ++i ){
         sout << s[i];
      }
      prePos = nxtPos+1;
      tokens.push_back(sout.str());
      //cout << sout.str() << " ";

   } while(nxtPos!=s.size());
   //cout << endl;
   return tokens.size();
}

template<class T> void
vc_out( vector<T>& vc ){
   for ( size_t i = 0 ; i < vc.size() ; ++i )
      cout << vc[i] << " ";
   cout << endl;
}

size_t
getTokensPar( string s, vector<string>& vcStr ){
   bool start = 0;
   ostringstream sout;
   for ( size_t i = 0 ; i < s.size() ; ++i ){
      if ( s[i] == '(' ){
         start = 1;
         continue;
      }
      if ( s[i] == ')' ){
         string ps = sout.str();
         sort(ps.begin(),ps.end());
         vcStr.push_back(ps);
         sout.str("");
         start = 0;
         continue;
      }
      if ( start == 0 ){
         vcStr.push_back(string(1,s[i]));
      }
      if ( start == 1 )
         sout << s[i];
   }
   return vcStr.size();
}
