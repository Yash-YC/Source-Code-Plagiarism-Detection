#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

vector<int> unhappyNums[11];

bool isHappy(vector<int>& nums, int num, int base)
{
    if(num == 1)
        return true;
    
    vector<int>::iterator itr;
    for(itr = nums.begin(); itr != nums.end(); itr++)
    {
        if(*itr == num)
            return false;
    }
    nums.push_back(num);
    
    int newNum = 0;
    while(num > 0)
    {
        int x = num%base;
        newNum += x * x;
        num /= base;
    }
    return isHappy(nums, newNum, base);
}

int main()
{
    ifstream myFile("example.txt");
    ofstream myAnswer("answer.txt");
    if (myFile.is_open())
    {
        int T;
        myFile >> T;
        string temp;
        getline(myFile, temp);

        for(int i = 1; i <= T; i++)
        {
            vector<int> numsInProblem;
            string nums_s;
            getline(myFile, nums_s);
            stringstream stream(nums_s);
            while(1)
            {
                int n;
                stream >> n;
                if(!stream)
                    break;

                numsInProblem.push_back(n);
            }
            
            int n = 2;
            while(1)
            {
                vector<int>::iterator itr;
                bool worked = true;
                for(itr = numsInProblem.begin(); itr != numsInProblem.end(); itr++)
                {
                    vector<int> unhappyVector;
                    if(!isHappy(unhappyVector,  n, *itr))
                    {
                        worked = false;
                        break;
                    }
                }
                if(worked)
                {
                    myAnswer << "Case #" << i << ": " << n << endl;
                    break;
                }
                n++;
            }
        }
    }
}