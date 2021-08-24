using System;
using System.Collections.Generic;
using System.Text;
using System.Text.RegularExpressions;
using System.IO;

namespace GoogleCodeJam {
    class Program {
        static void Main(string[] args) {
            ProcessFile();
        }

        public static void ProcessFile() {
            string path = @"D:\Repository\tests\codejam\";
            StreamReader sr = new StreamReader(path + "A-small-attempt0.in");
            StreamWriter sw = new StreamWriter(path + "A-small-attempt0.out");

            int cases = int.Parse(sr.ReadLine());

            for (int i = 0; i < cases; i++) {
                string res = ProcessCase(sr);
                sw.WriteLine(string.Format("Case #{0}: {1}", i + 1, res));
            }

            sw.Flush();
            sw.Close();
        }


        //private static string ProcessCase(StreamReader sr) {
        //    string[] values = sr.ReadLine().Split(' ');


        private static string ProcessCase(StreamReader sr) {
            string[] values = sr.ReadLine().Split(' ');
            List<int> bases = new List<int>();
            foreach (string s in values)
                bases.Add(int.Parse(s));

            long testedValue = 1;
            bool found = false;
            do {
                testedValue++;
                found = true;
                foreach (int b in bases) {
                    string convertedValue = Convert(testedValue, b);
                    List<long> used = new List<long>();
                    if (!IsHappy(convertedValue, ref used, b)) {
                        found = false;
                        break;
                    }
                }
            } while (!found);

            return testedValue.ToString();

        }

        private static bool IsHappy(string value, ref List<long> used, int currBase) {
            long newValue = 0;
            foreach (char v in value) {
                newValue += (long)Math.Pow(long.Parse(v.ToString()), 2);
            }
            if (newValue == 1)
                return true;
            else if (used.Contains(newValue))
                return false;
            else {
                used.Add(newValue);
                return IsHappy(Convert(newValue, currBase), ref used, currBase);
            }

        }
        private static string Convert(long from, int newBase) {
            StringBuilder newValue = new StringBuilder();
            long remainder = 0;
            while (from != 0) {
                remainder = from % newBase;
                from = from / newBase;
                newValue.Insert(0, remainder.ToString());
            }
            return newValue.ToString();

        }


    }
}
