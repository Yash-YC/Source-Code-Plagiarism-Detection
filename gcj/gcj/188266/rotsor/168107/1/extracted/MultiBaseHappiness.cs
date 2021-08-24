using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;
using System.IO;

namespace CodeJam
{
    class MultiBaseHappiness
    {
        static StreamWriter writer;
        static StreamReader reader;

        static Dictionary<String, int> precalc = new Dictionary<string, int>();

        static Dictionary<int, Dictionary<int, List<int>>> happies2 = new Dictionary<int, Dictionary<int, List<int>>>();

        static void fillPrecalc(String s, int next)
        {
            if (next > 10)
            {
                if (s != "")
                    precalc[s] = calcPrecalc(s);
            }
            else
            {
                fillPrecalc(s, next + 1);
                fillPrecalc((s == "" ? "" : s + " ") + next, next + 1);
            }
        }

        static private int calcPrecalc(string s)
        {
            Console.WriteLine("calculating " + s);
            return processCase(s);
        }
        
        public static void Main()
        {
            fillPrecalc("", 2);

            Console.WriteLine("Precalced");

            while (true)
            {
                Console.ReadLine();

                reader = File.OpenText("a.in");
                writer = File.CreateText("a.out");


                var tc = Int32.Parse(reader.ReadLine());

                for (int i = 0; i < tc; i++)
                {
                    DateTime t = DateTime.Now;
                    writer.WriteLine("Case #{0}: {1}", i + 1, precalc[reader.ReadLine()]);
                    Console.WriteLine(500 * (DateTime.Now - t).TotalMinutes);
                }

                reader.Close();
                writer.Close();
            }
        }

        static void addIfHappy(int i, int b, HashSet<int> hb)
        {
            if (i == 1)
                return;
            int sumSq = 0;
            int tmp = i;
            while (tmp > 0)
            {
                int d = tmp % b;
                sumSq += d * d;
                tmp = tmp / b;
            }
            if (sumSq == 1 || happies[b].Contains(sumSq))
                hb.Add(i);
        }

        static Dictionary<int, HashSet<int>> happies;

        private static int processCase(String str)
        {
            int[] bases = Array.ConvertAll(str.Split(" ".ToCharArray()), s => Int32.Parse(s));
            int maxBase = bases.Max();

                for (int i = 2; i < 30000000; i++)
                    if (isHappy(i, bases))
                        return i;

                return 888888;
                Console.WriteLine(":( for " + str);
        }

        private static bool isHappy(int i, int[] bases)
        {
            foreach (int b in bases)
            {
                unhappy = new HashSet<int>();
                if (!isHappy(i, b))
                    return false;
            }
            return true;
        }

        static HashSet<int> unhappy;

        private static bool isHappy(int i, int b)
        {
            //if (b >= 7)
            //    return happies[b].Contains(i);
            if (unhappy.Contains(i))
                return false;
            //Console.Write("i: {0}, b: {1}   ", i, b);
            if (i == 1)
                return true;
            //if (i < b)
            //    return false;
            int sumSq = 0;
            int tmp = i;
            while (tmp > 0)
            {
                int d = tmp % b;
                sumSq += d*d;
                tmp = tmp / b;
            }
            if (sumSq == i)
                return false;
            unhappy.Add(i);
            bool reallyHappy = isHappy(sumSq, b);
            if (reallyHappy)
                unhappy.Remove(i);
            return reallyHappy;
        }

    }
}
