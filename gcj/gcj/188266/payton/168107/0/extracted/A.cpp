#include <iostream>
#include <sstream>
#include <set>
#include <vector>
using namespace std;

int result[512];

bool isHappy(int num, int base)
{
    set<int> all;
    int setSize = -1;
    do
    {
//        cout << num << " "<< base << endl;
        setSize = all.size();
        int sum= 0;
        int tmp = num;
        while (tmp)
        {
            sum += (tmp%base) * (tmp%base);
            tmp /= base;
        }
        all.insert(sum);
        num = sum;
    } while (all.size() > setSize && all.find(1) == all.end());
    return all.find(1) != all.end(); 
}

int main()
{
    //cout << isHappy(2, 2) << endl;
    int caseNum;
    cin >> caseNum;
    string line;
    getline(cin, line);
    for (int caseId=1; caseId<=caseNum; caseId++)
    {
        vector<int> base;
        int b;
        getline(cin, line);
        stringstream ss(line);
        while (ss.good())
        {
            ss >> b;
            base.push_back(b);
        }
        int ret = 2;
        for (int i=2; ; i++)
        {
            bool allHappy = true;
            for (int j=0; j<base.size(); j++)
            {
                if (!isHappy(i, base[j]))
                {
                    allHappy = false;
                    break;
                }
            }
            if (allHappy)
            {
                ret = i;
                break;
            }
        }
        cout << "Case #" << caseId << ": " << ret << endl;
    }
    return 0;
}
