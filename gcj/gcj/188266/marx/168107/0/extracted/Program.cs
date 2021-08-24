using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace a
{
  class Program
  {
    const string inputFile = "input.in";

    const string outputFile = "output.out";

    static List<string> dict = new List<string>();
    static List<string> msg = new List<string>();

    static void Main(string[] args)
    {
      StreamReader sr = new StreamReader(inputFile);
      StreamWriter sw = new StreamWriter(outputFile);

      int T = int.Parse(sr.ReadLine());

      for(int i = 0; i < T; i++)
      {
        List<int> bases = new List<int>();
        stringToIntList(bases, sr.ReadLine());
        sw.WriteLine(String.Format("Case #{0}: {1}", i + 1, calc(bases)));
      }

      sw.Close();
    }

    static int calc(List<int> bases)
    {
      int result = 1;

      bool happyInAll = false;

      while(!happyInAll)
      {
        result++;
        
        happyInAll = true;

        foreach(int b in bases)
        {
          if(! isHappy(result, b))
          {
            happyInAll = false;
            break;
          }
        }
        
      }

      return result;
    }

    static void stringToIntList(List<int> bases, string p)
    {
      string[] sa = p.Split(' ');
      foreach(string s in sa)
      {
        bases.Add(int.Parse(s));
      }
    }

    static List<int> decToBaseN(int inDec, int b)
    {
      List<int> result = new List<int>();

      int rest = 0;
      int n = inDec;
      while(n != 0)
      {
        rest = n % b;
        n = n / b;
        result.Add(rest);
      }

      return result;
    }

    static bool isHappy(int n, int b)
    {
      List<int> a = decToBaseN(n, b);
      List<int> prevSums = new List<int>();

      int sum = sum2(a);
      prevSums.Add(sum);

      while(sum != 1)
      {
        a = decToBaseN(sum, b);
        
        int nextSum = sum2(a);

        if(prevSums.Contains(nextSum))
        {
          return false;
        }
        sum = nextSum;
        prevSums.Add(sum);
      }

      return true;
    }

    static int sum2(List<int> num)
    {
      int result = 0;
      foreach(int n in num)
      {
        result += n * n;
      }

      return result;
    }
 
  }
}
