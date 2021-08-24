using System;
using System.Collections.Generic;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;

namespace Round1A
{
    class ProblemA
    {
        static string[] text;
        static int at;
        static TextWriter output;

        static void Main(string[] args)
        {
            using (output = new StreamWriter("output.txt"))
            {
                text = File.ReadAllLines("A.in");
                at = 0;
                int n = ReadInt();
                for (int i = 0; i < n; i++)
                    Solve(i + 1);
            }
        }

        static void Solve(int caseNumber)
        {
            int[] bases = ReadInts();
            long currentTest = 2;
            while (true)
            {
                bool isGood=true;
                foreach (int bas in bases)
                {
                    if (!IsHappy(currentTest, bas))
                    {
                        isGood=false;
                        currentTest++;
                        break;
                    }
                }
                if (isGood)
                {
                    OutputLine("Case #" + caseNumber + ": " + currentTest);
                    return;
                }
            }
        }

        static readonly Dictionary<Pair, bool> Encountered = new Dictionary<Pair, bool>();
        static readonly Dictionary<Pair, bool> Happy = new Dictionary<Pair, bool>();
        static bool IsHappy(long num, long bas)
        {
            Pair np=new Pair{@base=bas, x=num};
            if(Encountered.ContainsKey(np))
            {
                if(!Happy.ContainsKey(np))
                    Happy[np]=false;
                return Happy[np];
            }
            Encountered[np]=true;
            long sum = 0;
            while (num != 0)
            {
                long digit=num%bas;
                sum+=digit*digit;
                num/=bas;
            }
            if (sum == 1)
                Happy[np] = true;
            else
                Happy[np]=IsHappy(sum,bas);
            return Happy[np];
        }

        static int ReadInt()
        {
            return ReadInts()[0];
        }

        static int[] ReadInts()
        {
            string line = text[at++];
            string[] bits = line.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            int[] ret=new int[bits.Length];
            for (int i = 0; i < bits.Length; i++)
                ret[i] = Int32.Parse(bits[i]);
            return ret;
        }

        static void OutputLine(string line)
        {
            Console.WriteLine(line);
            output.WriteLine(line);
        }
    }

    class Pair
    {
        public long x, @base;
        public override int GetHashCode()
        {
            return (int)x + (int)@base;
        }

        public override bool Equals(object obj)
        {
            Pair p=(Pair)obj;
            return p.x==x && p.@base==@base;
        }
    }
}
