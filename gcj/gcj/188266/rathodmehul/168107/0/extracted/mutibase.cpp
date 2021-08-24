/*
 * =====================================================================================
 *
 *       Filename:  waterSheds.cpp
 *
 *    Description:
 *           
 *            How to run:   ./a.out inputfile outputfile
 *
 *        Version:  1.0
 *        Created:  09/03/2009 09:26:33 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Mehul Rathod ( rathodmehul@gmail.com )
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <ctype.h>


using namespace std;

void addNo(long inNo, int Base);
long nextNo(long inNo, int Base);

struct  happyData
{
    set<long> happyList;
    set<long> unHappyList;
};

vector<happyData>  data(11);



static void solveAProblem(int no, ifstream &din, ofstream &dout);

int main(int argc, char** argv)
{
    if(argc < 3)
        return 0;

    int problemCount = 0;

    ifstream din(argv[1]);
    ofstream dout(argv[2]);

    din >> problemCount;    

    string junk;

    getline(din,junk);

    for(int i = 0; i < problemCount; i++)
    {
        solveAProblem(i,din,dout);
    }
  
    din.close();
    dout.close();

    return 0;

}

static void solveAProblem(int no, ifstream &din, ofstream &dout)
{
    


    vector<int> baseList;

    string line;
    
    getline(din,line);

    int base = 0;

    for(int i=0; i<line.size(); i++)
    {
        if(isdigit(line[i]))
        {
           base *= 10;
           base += int(line[i]-'0');
        }
        else
        {
         
            baseList.push_back(base);
            base = 0;
        }
    }

    baseList.push_back(base);  


    
    long currNo = 2;
    long limit = 100000000;

    while(--limit > 0)
    {
        for(int i=0; i<baseList.size(); i++)
        {
            addNo(currNo,baseList[i]);       
        } 
         
        bool flag = 1;
        for(int i=0; i<baseList.size(); i++) 
        {

           set<long>::iterator it =  data[baseList[i]].unHappyList.find(currNo);      
           if(it !=  data[baseList[i]].unHappyList.end())
           {
                flag = 0;
                break;
           }
        } 

        if(flag)
        {
            break;     
        }

        currNo++;
        
               
    }    


    dout << "Case #" << (no+1) << ": " << currNo  << endl ;


}


void addNo(long inNo, int Base)
{
   set<long>  currStack;
   set<long>::iterator it;
   static const int limit = 10000;
   for(int i=0; i<limit; i++)
   {
       
      if(inNo == 1)
      {
          for(it = currStack.begin(); it != currStack.end(); it++)
          {
              data[Base].happyList.insert(*it);         
          }   

          return;
      }
      else 
      {
          it = data[Base].happyList.find(inNo);
          if(it != data[Base].happyList.end())
          {
             for(it = currStack.begin(); it != currStack.end(); it++)
            {
              data[Base].happyList.insert(*it);         
            }   

            return;                
          }

          it = data[Base].unHappyList.find(inNo);
          if(it != data[Base].unHappyList.end())
          {
            for(it = currStack.begin(); it != currStack.end(); it++)
            {
              data[Base].unHappyList.insert(*it);         
            }   

            return;                
          }       

          it = currStack.find(inNo);
          
          if(it !=  currStack.end())
          {
             for(it = currStack.begin(); it != currStack.end(); it++)
            {
              data[Base].unHappyList.insert(*it);         
            }   

            return;  
          }
          else
          {
            currStack.insert(inNo);     
          }

      }

      inNo = nextNo(inNo,Base);
   }
   cout << "Error: Limit reached" << endl;
}

long nextNo(long inNo, int Base)
{
    long squareSum = 0;

    while(inNo > 0)
    {
       int baseDigit  = inNo % Base;  
       squareSum  += (baseDigit*baseDigit); 
       inNo /= Base;
    }

    return squareSum;

}
