/*
-----BEGIN PGP SIGNED MESSAGE-----
Hash: SHA256

a.out.dSYM/
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int getDigit(int digit, int num)
{
    return (num % (int)pow((double)10, (double)digit + 1)) / (int)pow((double)10, (double)digit);
}

int changeToBase(int num, int base)
{
    int ret = 0;
    
    /*for(int x = 0; x <= (int)log(num); x++)
    {
        ret += getDigit(x, num) * (int)pow((double)base, (double)x);
    }*/
        int tempnum = num;
    int x = 0;
        while(tempnum != 0)
        {
            ret += (tempnum % base) * (int)pow((double)10, (double)x);
            tempnum = tempnum / base;
            x++;
        }
    
    return ret;
}

bool isHappy(int num, int base)
{
    int val = 0;
    int prev = 0;
    bool ret = false;
    num = changeToBase(num, base);

    for(int y = 0; y < 1000/*big number*/; y++)
    {
        val = 0;
        
        for(int x = 0; x <= (int)log(num); x++)
        {
            val += (int)pow((double)getDigit(x, num), (double)2);
        }
        
        val = changeToBase(val, base);
        
        if(val == 1)
        {
            ret = true;
            break;
        }
        else if(val == prev)
        {
            break;
        }
        
        prev = val;
        num = val;
    }
    
    return ret;
}

void handleCase(int caseNum, int *bases, int numBases)
{
    int answer = 2;
    
    while(true)
    {
        bool a = true;
        
        for(int x = 0; x < numBases; x++)
        {
            if(!isHappy(answer, bases[x]))
            {
                a = false;
                break;
            }
        }
        
        if(a)
        {
            break;
        }
        
        answer++;
    }
    
    cout << "Case #" << caseNum << ": " << answer << endl;
}

int countSpaces(string input)
{
    int ret = 0;
    
    int index = input.find_first_of(' ', 0);
    while(index != 0)
    {
        ret++;
        index = input.find_first_of(' ', index) + 1;
    }
    
    return ret;
}

int *parseBases(string input, int spaces)
{
    int *ret = new int[spaces];
    int currIndex = 0;
    int nextIndex = 0;
    
    for(int x = 0; x < spaces; x++)
    {
        nextIndex = input.find_first_of(' ', currIndex);
        ret[x] = atoi(input.substr(currIndex, nextIndex - currIndex).c_str());
        currIndex = nextIndex + 1;
    }
    
    return ret;
}

int main(int argc, char *argv[])
{
    int T;
    string input;
    
    cin >> T;
    
    getline(cin, input);
    for(int x = 0; x < T; x++)
    {
        getline(cin, input);
        
        int spaces = countSpaces(input);
        
        handleCase(x + 1, parseBases(input, spaces), spaces);
    }
    
    return 0;
}



// test functions:

void printBases(int *bases, int numBases)
{
    for(int x = 0; x < numBases; x++)
    {
        cout << bases[x] << " ";
    }
    
    cout << endl;
}

/*int main()
{
    cout << getDigit(5, 28476294) << " " << getDigit(0, 1358792) << " " << getDigit(9, 1386937456) << endl;
    
    cout << changeFromBase(345, 8) << " " << changeFromBase(11001001, 2) << " " << changeFromBase(2341, 5) << endl;
    
    cout << countSpaces("324 64 34 26") << " " << countSpaces("845 3452 358 4 46 3 46") << endl;
    
    printBases(parseBases("364 457 453 4567 2 4 734 3 46 3 5", countSpaces("364 457 453 4567 2 4 734 3 46 3 5")), countSpaces("364 457 453 4567 2 4 734 3 46 3 5"));
    printBases(parseBases("8359 38 39 274 8 628 5", countSpaces("8359 38 39 274 8 628 5")), countSpaces("8359 38 39 274 8 628 5"));
    
    return 0;
}*/
/*
-----BEGIN PGP SIGNATURE-----
Version: GnuPG/MacGPG2 v2.0.12 (Darwin)

iF4EAREIAAYFAkqrC18ACgkQf7sAhIwsAlAsTAD+KP2MZMSzJOEkCDYlexrr4bpm
lEYk/22cvHAfrmOtHM0A/iP+ILi/2BSBBFLghqsRSDte8YuR17TI4n5p39cia2Tg
=6xQe
-----END PGP SIGNATURE-----
*/
