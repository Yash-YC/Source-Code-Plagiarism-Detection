using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Pro1
{
    class Program
    {
        public static SortedList<int, bool>[] cacheHappy = new SortedList<int, bool>[11];

        public static string GetValueString(List<int> value)
        {
            StringBuilder sb = new StringBuilder(value.Count);
            foreach (int v in value)
                sb.Append(v);
            return sb.ToString();
        }

        public static List<int> ConvertBase(int value, int baseN)
        {
            int remainder, div = value;
            List<int> valueBase = new List<int>(100);

            while (div >= baseN)
            {
                remainder = div % baseN;
                div = div / baseN;
                valueBase.Insert(0, remainder);
            }
            valueBase.Insert(0, div);
            return valueBase;
        }

        public static bool IsHappy(int value, int baseN)
        {
            SortedList<int, bool> cacheH = cacheHappy[baseN];
            
            bool result;
            if (cacheH.TryGetValue(value, out result))
                return result;

            SortedList<int, bool> cache = new SortedList<int, bool>(50);
            
            int res = value;;

            List<int> num;
            num = ConvertBase(value, baseN);

            do
            {
                cache.Add(res, false);
                res = 0;
                foreach (int digit in num)
                {
                    res += digit * digit;
                }

                if (res == 1)
                    return MoveCache(cacheH, true, cache);
                if (cacheH.TryGetValue(res, out result))
                {
                    return MoveCache(cacheH, result, cache);
                }
                if (cache.TryGetValue(res, out result))
                {
                    return MoveCache(cacheH, false, cache);
                }
                num = ConvertBase(res, baseN);
            }
            while (true);
        }

        private static bool MoveCache(SortedList<int, bool> cacheH, bool result, SortedList<int, bool> cache)
        {
            foreach (int val2 in cache.Keys)
            {
                cacheH.Add(val2, result);
            }
            return result;
        }

        static void Main(string[] args)
        {
            //string input = "input.txt";
            string input = "A-small-attempt0.txt";
            string output = "output.txt";

            for (int i = 2; i <= 10; i++)
            {
                cacheHappy[i] = new SortedList<int, bool>(100);
            }

            using (StreamReader reader = File.OpenText(input))
            {
                using (StreamWriter writer = File.CreateText(output))
                {
                    string line = reader.ReadLine();
                    int T = int.Parse(line);
                    for (int t = 1; t <= T; t++)
                    {
                        line = reader.ReadLine();
                        string[] splitted = line.Split(' ');
                        int[] bases = new int[splitted.Length];
                        for (int i = 0 ; i < bases.Length; i++)
                        {
                            bases[i] = int.Parse(splitted[i]); 
                        }

                        int val = 1;
                        bool happy;
                        do
                        {
                            val++;
                            happy = true;
                            for (int i = 0; i < bases.Length; i++)
                            {
                                happy = IsHappy(val, bases[i]);
                                if (!happy) break;
                            }
                        }
                        while (!happy);

                        writer.WriteLine("Case #" + t.ToString() + ": " + val.ToString()); 
                    }
                    writer.Flush();
                }
            }

        }
    }
}
