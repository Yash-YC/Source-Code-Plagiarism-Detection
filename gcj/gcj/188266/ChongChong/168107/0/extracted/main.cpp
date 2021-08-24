#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

static ifstream in("in.txt");
static ofstream out("out.txt");

static int visited[100000];
vector<int> Nums;

void ChangeBase(int num, int base)
{
      Nums.clear();
      while(num)
      {
            Nums.push_back(num%base);
            num/=base;
      }     
}

int Sum(int num, int base)
{
      int i,size;
      int sum(0);

      ChangeBase(num, base);
      size=(int)Nums.size();
      for(i=0;i<size;++i)
      {
            sum+=Nums[i]*Nums[i];
      }
      return sum;
}

int Cal(vector<int> &base)
{
      int num,tmp;
      int sum;
      int size;
      int i,flag;

      num=2;
      size=(int)base.size();
      while(true)
      {
            for(i=0;i<size;++i)
            {
                  tmp=num;
                  memset(visited, 0, sizeof(visited));
                  while(true)
                  {
                       sum=Sum(tmp, base[i]);
                       if(visited[sum]==1)
                       {
                             flag=0;
                             break;
                       }
                       if(sum==1)
                       {
                             flag=1;
                             break;
                       }
                       visited[sum]=1;
                       tmp=sum;
                  }
                  if(flag==0)
                  {
                        break;
                  }
            }
            if(i==size)
            {
                  return num;
            }
            num++;
      }

      return num;
}

int main()
{
      int N;
      int i,b;
      char c;
      vector<int> base;

      cin >> N;
      for(i=0;i<N;++i)
      {
            base.clear();
            while(true)
            {
                  cin >> b;
                  base.push_back(b);
                  c=getchar();
                  if(c=='\n')
                  {
                        break;
                  }
            }
            out << "Case #" << i+1 << ": ";
            out << Cal(base) << endl;
      }

      return 0;
}