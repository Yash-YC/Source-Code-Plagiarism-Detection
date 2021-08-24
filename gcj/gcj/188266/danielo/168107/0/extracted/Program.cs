using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace MBH {
    class Program {
        static void Main(string[] args) {
            //string res = processFile("..\\..\\A.in");
            //File.WriteAllLines("..\\..\\A.out", new string[] { res });
            string res = processFile("..\\..\\A-small-attempt0.in");
            File.WriteAllLines("..\\..\\A-small-attempt0.out", new string[] { res });
            //string res = Vectors.ProcessFile("..\\..\\A-large.in");
            //File.WriteAllLines("..\\..\\A-large.out", new string[] { res });
            //Console.Write(res);
            Console.WriteLine("Press any key...");
            Console.ReadKey();
        }

        public static string processFile(string filePath) {
            StringBuilder b = new StringBuilder();
            List<string> fileContent = getFileContent(filePath);
            string line = null;
            int T = int.Parse(fileContent[0]);
            for (int tt = 1;tt <= T;tt++) {
                line = fileContent[tt];
                int res = solveCase(line);
                b.AppendLine(string.Format("Case #{0}: {1}", tt, res));
            }
            return b.ToString();
        }

        static int solveCase(string line) {
            string [] _bases = line.Split(' ');
            List<int> bases = new List<int>();
            foreach(string s in _bases){
                bases.Add(int.Parse(s));
            }
            for (int i = 2;i < 100000;i++) {
                bool isHappy = true;
                foreach (int b in bases) {
                    isHappy = isHappy && IsHappy(i, b);
                }
                if (isHappy) {
                    return i;
                }
            }
            return 0;
        }

        static bool IsHappy(int v, int b) {
            List<int> passed = new List<int>();
            char[] s = changeBase(v, b); //v.ToString("F0").ToCharArray();
            for (int i = 0;i < int.MaxValue;i++) {
                int res = 0;
                foreach (char c in s) {
                    res += (int.Parse(c.ToString()) * int.Parse(c.ToString()));
                }
                if (res == 1) {
                    return true;
                }
                if (passed.Contains(res)) {
                    return false;
                }
                passed.Add(res);
                s = changeBase(res, b);//res.ToString("F0").ToCharArray();
            }
            return false;
        }

        /// <summary>
        /// 4, 2
        /// 4%2 = 0
        /// 2%2 = 0
        /// 1   = 1
        /// </summary>
        /// <param name="v"></param>
        /// <param name="b"></param>
        /// <returns></returns>
        static char[] changeBase(int v, int b) {
            StringBuilder builder = new StringBuilder();
            int res = v;
            while (res >= b) {
                builder.Append(res % b);
                res = res / b;
            }
            builder.Append(res);
            char[] r = builder.ToString().ToCharArray();
            Array.Reverse(r);
            return r;
        }

        public static List<string> getFileContent(string filePath) {
            return new List<string>(System.IO.File.ReadAllLines(filePath));
        }
    }
}
