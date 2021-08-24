using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Numeric;
using System.IO;

namespace MultiBaseHappiness
{
    class Program
    {
        static void Main(string[] args)
        {
            MultiBaseHappiness(args);
        }

        static void MultiBaseHappiness(string[] args)
        {
            string inFileName = "A-small-attempt0.in";
            string outFileName = "outputHappy.txt";
            StreamReader inputReader = new StreamReader(inFileName);
            StreamWriter outputWriter = new StreamWriter(outFileName);
            string f1 = inputReader.ReadLine();
            int noOfCases = int.Parse(f1);
            for (int i = 0; i < noOfCases; i++)
            {
                string testcase = inputReader.ReadLine();
                string[] basesSplit = testcase.Split(' ');
                int[] allBases = new int[basesSplit.Length];
                for(int j=0; j<basesSplit.Length; j++)
                {
                    allBases[j] = int.Parse(basesSplit[j]);
                }
                long happyNumber = FindHappiness(allBases);
                outputWriter.WriteLine(
                    string.Format("Case #{0}: {1}", i + 1, happyNumber));
            }
            outputWriter.Flush();
            outputWriter.Close();
        }

        static long FindHappiness(int[] allBases)
        {
            long nextHappy = 2;
            while (!AllHappy(nextHappy, allBases))
            {
                nextHappy++;
            }
            return nextHappy;
        }

        static bool AllHappy(long nextHappy, int[] allBases)
        {
            bool allHappy = true;
            foreach (int tBase in allBases)
            {
                allHappy &= IsHappy(nextHappy, tBase);
                if (!allHappy)
                {
                    return allHappy;
                }
            }
            return allHappy;
        }

        static bool IsHappy(long a, long tBase)
        {
            HashSet<long> seqSoFar = new HashSet<long>();
            long nextHappy = a;
            while (nextHappy > 1 && !seqSoFar.Contains(nextHappy))
            {
                seqSoFar.Add(nextHappy);
                nextHappy = GetNextHappy(nextHappy, tBase);
            }
            return nextHappy == 1;
        }
        static long GetNextHappy(long a, long tBase)
        {
            long nextHappy = 0;
            while (a > 0)
            {
                long remainder;
                a = Math.DivRem(a, tBase, out remainder);
                nextHappy += remainder * remainder;
            }
            return nextHappy;
        }
    }
}
